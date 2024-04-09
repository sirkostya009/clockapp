#include <AppCore/AppCore.h>
#include <iostream>
#include <functional>
#include <map>
#include <chrono>
#include <fstream>
#include "json.hpp"

namespace ul = ultralight;

using json = nlohmann::json;

class Info : public ul::WindowListener, public ul::LoadListener, public ul::ViewListener {
    ul::RefPtr<ul::Window> window;
    ul::RefPtr<ul::Overlay> overlay;

    std::function<void()> onClose;
public:
    Info(ul::Monitor* monitor, std::function<void()> onClose)
    : window{ ul::Window::Create(monitor, 450, 450, false, ul::kWindowFlags_Resizable | ul::kWindowFlags_Maximizable) }
    , overlay{ ul::Overlay::Create(window, 1, 1, 0, 0) }
    , onClose{ std::move(onClose) }
    {
        window->set_listener(this);
        overlay->view()->set_load_listener(this);
        overlay->view()->set_view_listener(this);

        window->MoveToCenter();
        overlay->Resize(window->width(), window->height());
        overlay->view()->LoadURL("file:///info.html");
        overlay->Focus();
    }

    void OnClose(ul::Window *w) override {
        w->Close();
        onClose();
    }

    bool OnKeyEvent(const ul::KeyEvent &evt) override {
        switch (evt.virtual_key_code) {
            case 27: // Escape
                OnClose(window.get());
                break;
        }
        return true;
    }
};

class App : public ul::AppListener, public ul::WindowListener, public ul::LoadListener, public ul::ViewListener {
    ul::RefPtr<ul::App> app;
    ul::RefPtr<ul::Window> window;
    ul::RefPtr<ul::Overlay> overlay;

    Info* info_ptr{};
    bool rizza = false;

    std::map<long long, std::string> timeZones{
        { -12, "'Etc/GMT-12'" },
        { -11, "'Etc/GMT-11'" },
        { -10, "'Etc/GMT-10'" },
        { -9, "'Etc/GMT-9'" },
        { -8, "'Etc/GMT-8'" },
        { -7, "'Etc/GMT-7'" },
        { -6, "'Etc/GMT-6'" },
        { -5, "'Etc/GMT-5'" },
        { -4, "'Etc/GMT-4'" },
        { -3, "'Etc/GMT-3'" },
        { -2, "'Etc/GMT-2'" },
        { -1, "'Etc/GMT-1'" },
        { 0, "'Etc/GMT'" },
        { +1, "'Etc/GMT+1'" },
        { +2, "'Etc/GMT+2'" },
        { +3, "'Etc/GMT+3'" },
        { +4, "'Etc/GMT+4'" },
        { +5, "'Etc/GMT+5'" },
        { +6, "'Etc/GMT+6'" },
        { +7, "'Etc/GMT+7'" },
        { +8, "'Etc/GMT+8'" },
        { +9, "'Etc/GMT+9'" },
        { +10, "'Etc/GMT+10'" },
        { +11, "'Etc/GMT+11'" },
        { +12, "'Etc/GMT+12'" },
    };

    std::map<long long, std::string> shortTimezone{
        { -12, "GMT-12" },
        { -11, "GMT-11" },
        { -10, "GMT-10" },
        { -9, "GMT-9" },
        { -8, "GMT-8" },
        { -7, "GMT-7" },
        { -6, "GMT-6" },
        { -5, "GMT-5" },
        { -4, "GMT-4" },
        { -3, "GMT-3" },
        { -2, "GMT-2" },
        { -1, "GMT-1" },
        { 0, "GMT" },
        { +1, "GMT+1" },
        { +2, "GMT+2" },
        { +3, "GMT+3" },
        { +4, "GMT+4" },
        { +5, "GMT+5" },
        { +6, "GMT+6" },
        { +7, "GMT+7" },
        { +8, "GMT+8" },
        { +9, "GMT+9" },
        { +10, "GMT+10" },
        { +11, "GMT+11" },
        { +12, "GMT+12" },
    };

    std::chrono::time_point<std::chrono::tai_clock> time;
    long long timezone = 0;

    json config{
        "timezone", 0,
        "starred", {}
    };
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
        overlay->view()->LoadURL("file:///app.html");
        overlay->Focus();

        time = std::chrono::tai_clock::now();
        std::cout << time << std::endl;

        if (std::ifstream file("config.json"); file) {
            file >> config;
            timezone = config["timezone"];
        }
    }

    inline void run() {
        app->Run();
    }

    void OnUpdate() override {
        if (rizza) {
            delete info_ptr;
            rizza = false;
        }
    }

    bool OnKeyEvent(const ul::KeyEvent &evt) override {
        switch (evt.virtual_key_code) {
        case 112: // F1
            openInfo();
            break;
        case 13: // Enter
            ul::JSEval("process(input.value)");
            break;
        }
        return true;
    }

    void OnClose(ul::Window*) override {
        std::exit(0);
    }

    void OnResize(ul::Window*, uint32_t width, uint32_t height) override {
        overlay->Resize(width, height);
    }

    void OnDOMReady(ul::View *caller, uint64_t frame_id, bool is_main_frame, const ul::String &url) override {
        using ul::JSCallback, ul::JSCallbackWithRetval;
        ul::SetJSContext(caller->LockJSContext()->ctx());
        auto global = ul::JSGlobalObject();

        global["changeTime"] = BindJSCallback(&App::changeTime);
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

    void openInfo(const ul::JSObject& = {}, const ul::JSArgs& = {}) {
        info_ptr = new Info(app->main_monitor(), [this] { rizza = true; });
    }

    void changeTime(const ul::JSObject&, const ul::JSArgs& args) {
        timezone = (long long) args[0].ToNumber();

        ul::JSEval(("timezoneLabel.innerText = " + timeZones[timezone]).c_str());
    }
};

auto main() -> int {
    App().run();
}
