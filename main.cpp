#include <AppCore/AppCore.h>
#include <iostream>
#include <fstream>
#include "json.hpp"

namespace ul = ultralight;

using json = nlohmann::json;
bool close_about = false;

class About : public ul::WindowListener, public ul::LoadListener, public ul::ViewListener {
    ul::RefPtr<ul::Window> window;
    ul::RefPtr<ul::Overlay> overlay;
public:
    About(ul::Monitor* monitor)
    : window{ ul::Window::Create(monitor, 600, 720, false, ul::kWindowFlags_Titled) }
    , overlay{ ul::Overlay::Create(window, 1, 1, 0, 0) }
    {
        window->set_listener(this);
        overlay->view()->set_load_listener(this);
        overlay->view()->set_view_listener(this);

        window->MoveToCenter();
        overlay->Resize(window->width(), window->height());
#include "resources/about.inl"
        overlay->view()->LoadHTML(rawData);
        overlay->Focus();
    }

    void OnChangeTitle(ultralight::View *caller, const ultralight::String &title) override {
        window->SetTitle(title.utf8().data());
    }

    void OnResize(ultralight::Window *, uint32_t width_px, uint32_t height_px) override {
        overlay->Resize(width_px, height_px);
    }

    void OnDOMReady(ul::View *caller, uint64_t frame_id, bool is_main_frame, const ul::String &url) override {
        using ul::JSCallback, ul::JSCallbackWithRetval;
        ul::SetJSContext(caller->LockJSContext()->ctx());
        auto global = ul::JSGlobalObject();

        global["closeAbout"] = BindJSCallback(&About::close);
    }

    void OnClose(ul::Window *w) override {
        //w->Close();
        close_about = true;
    }

    bool OnKeyEvent(const ul::KeyEvent &evt) override {
        switch (evt.virtual_key_code) {
            case 27:
                OnClose(window.get());
                break;
        }
        return true;
    }

    void close(const ul::JSObject&, const ul::JSArgs&) {
        OnClose(window.get());
    }
};

class App : public ul::AppListener, public ul::WindowListener, public ul::LoadListener, public ul::ViewListener {
    ul::RefPtr<ul::App> app;
    ul::RefPtr<ul::Window> window;
    ul::RefPtr<ul::Overlay> overlay;

    About* about_ptr{};

    json config = json::array();
public:
    App()
    : app{ ul::App::Create() }
    , window{ ul::Window::Create(app->main_monitor(), 800, 600, false, ul::kWindowFlags_Resizable | ul::kWindowFlags_Maximizable) }
    , overlay{ ul::Overlay::Create(window, 1, 1, 0, 0) }
    {
        app->set_listener(this);
        window->set_listener(this);
        overlay->view()->set_load_listener(this);
        overlay->view()->set_view_listener(this);

        window->MoveToCenter();
        overlay->Resize(window->width(), window->height());
#include "resources/app.inl"
        overlay->view()->LoadHTML(rawData);
        overlay->Focus();

        if (std::ifstream file("config.json"); file) {
            file >> config;
        }
    }

    inline void run() {
        app->Run();
    }

    void OnUpdate() override {
        if (close_about) {
            ul::SetJSContext(overlay->view()->LockJSContext()->ctx());
            delete about_ptr;
            close_about = false;
        }
    }

    bool OnKeyEvent(const ul::KeyEvent &evt) override {
        switch (evt.virtual_key_code) {
            case 112: // F1
                openAbout();
                break;
        }
        return true;
    }

    void OnClose(ul::Window*) override {
        auto starredTimezones = ul::JSEval("[...pinned.children].map(e => +[...e.children][1].getAttribute('data-timezone'))").ToArray();

        auto timezones = json::array();
        for (int i = 0; i < starredTimezones.length(); i++) {
            timezones.push_back(starredTimezones[i].ToInteger());
        }

        std::ofstream("config.json") << timezones << std::endl;

        std::exit(0);
    }

    void OnResize(ul::Window*, uint32_t width, uint32_t height) override {
        overlay->Resize(width, height);
    }

    void OnDOMReady(ul::View *caller, uint64_t frame_id, bool is_main_frame, const ul::String &url) override {
        using ul::JSCallback, ul::JSCallbackWithRetval;
        ul::SetJSContext(caller->LockJSContext()->ctx());
        auto global = ul::JSGlobalObject();

        global["openAbout"] = BindJSCallback(&App::openAbout);
        global["shutdown"] = ul::JSCallback([](const ul::JSObject&, const ul::JSArgs&) {
            std::exit(0);
        });

        auto addStarredTimezone = global["addStarredTimezone"].ToFunction();
        if (config.is_array()) for (auto& timezone : config) {
            if (timezone.is_number()) {
                addStarredTimezone({(int) timezone});
            }
        }
    }

    void OnChangeCursor(ul::View *caller, ul::Cursor cursor) override {
        window->SetCursor(cursor);
    }

    void OnChangeTitle(ul::View *caller, const ul::String &title) override {
        window->SetTitle(title.utf8().data());
    }

    void OnAddConsoleMessage(ul::View*, ul::MessageSource, ul::MessageLevel, const ul::String &message,
                             uint32_t line_number, uint32_t column_number, const ul::String &) override {
        std::cout << "Console: " << message.utf8().data() << " at line: " << line_number << ", column: " << column_number << std::endl;
    }

    void openAbout(const ul::JSObject& = {}, const ul::JSArgs& = {}) {
        about_ptr = new About(app->main_monitor());
    }
};

auto main() -> int {
    App().run();
}
