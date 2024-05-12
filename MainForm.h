#pragma once
#include "AboutForm.h"
#include "Clock.h"

namespace clockapp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	public ref class MainForm : public System::Windows::Forms::Form {
	private:
		AboutForm^ about = gcnew AboutForm();
		array<int>^ timezones = gcnew array<int>(0);

	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ToolStripStatusLabel^ localTimeLabel;
	private: System::ComponentModel::BackgroundWorker^ secondsTicker;
	private: System::Windows::Forms::TrackBar^ timezoneSlider;
	private: System::Windows::Forms::Label^ timeLabel;
	private: System::Windows::Forms::Label^ dateLabel;
	private: System::Windows::Forms::Label^ timezoneLabel;
	private: System::Windows::Forms::ListView^ timezoneList;
	private: System::ComponentModel::BackgroundWorker^ minuteTicker;




	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::MenuStrip^ menuStrip;
			System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ додатиToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ видалитиToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ закритиToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ допомогаToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ проЗастосунокToolStripMenuItem;
			System::Windows::Forms::ToolStrip^ toolStrip;
			System::Windows::Forms::ToolStripButton^ addTimezoneButton;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			System::Windows::Forms::ToolStripButton^ removeTimezoneButton;
			System::Windows::Forms::StatusStrip^ statusStrip;
			System::Windows::Forms::ColumnHeader^ timezone;
			System::Windows::Forms::ColumnHeader^ time;
			this->localTimeLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->secondsTicker = (gcnew System::ComponentModel::BackgroundWorker());
			this->timezoneSlider = (gcnew System::Windows::Forms::TrackBar());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->timezoneLabel = (gcnew System::Windows::Forms::Label());
			this->timezoneList = (gcnew System::Windows::Forms::ListView());
			this->minuteTicker = (gcnew System::ComponentModel::BackgroundWorker());
			menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			додатиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			видалитиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			закритиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			допомогаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			проЗастосунокToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			addTimezoneButton = (gcnew System::Windows::Forms::ToolStripButton());
			removeTimezoneButton = (gcnew System::Windows::Forms::ToolStripButton());
			statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			timezone = (gcnew System::Windows::Forms::ColumnHeader());
			time = (gcnew System::Windows::Forms::ColumnHeader());
			menuStrip->SuspendLayout();
			toolStrip->SuspendLayout();
			statusStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timezoneSlider))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { файлToolStripMenuItem, допомогаToolStripMenuItem });
			menuStrip->Location = System::Drawing::Point(0, 0);
			menuStrip->Name = L"menuStrip";
			menuStrip->Size = System::Drawing::Size(672, 24);
			menuStrip->TabIndex = 0;
			menuStrip->Text = L"menuStrip";
			// 
			// файлToolStripMenuItem
			// 
			файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				додатиToolStripMenuItem,
					видалитиToolStripMenuItem, закритиToolStripMenuItem
			});
			файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			файлToolStripMenuItem->Text = L"Файл";
			// 
			// додатиToolStripMenuItem
			// 
			додатиToolStripMenuItem->Name = L"додатиToolStripMenuItem";
			додатиToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			додатиToolStripMenuItem->Text = L"Додати";
			додатиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::додатиToolStripMenuItem_Click);
			// 
			// видалитиToolStripMenuItem
			// 
			видалитиToolStripMenuItem->Name = L"видалитиToolStripMenuItem";
			видалитиToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			видалитиToolStripMenuItem->Text = L"Видалити";
			видалитиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::видалитиToolStripMenuItem_Click);
			// 
			// закритиToolStripMenuItem
			// 
			закритиToolStripMenuItem->Name = L"закритиToolStripMenuItem";
			закритиToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			закритиToolStripMenuItem->Text = L"Закрити";
			закритиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::закритиToolStripMenuItem_Click);
			// 
			// допомогаToolStripMenuItem
			// 
			допомогаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { проЗастосунокToolStripMenuItem });
			допомогаToolStripMenuItem->Name = L"допомогаToolStripMenuItem";
			допомогаToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			допомогаToolStripMenuItem->Text = L"Допомога";
			// 
			// проЗастосунокToolStripMenuItem
			// 
			проЗастосунокToolStripMenuItem->Name = L"проЗастосунокToolStripMenuItem";
			проЗастосунокToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			проЗастосунокToolStripMenuItem->Text = L"Про застосунок";
			проЗастосунокToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::проЗастосунокToolStripMenuItem_Click);
			// 
			// toolStrip
			// 
			toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { addTimezoneButton, removeTimezoneButton });
			toolStrip->Location = System::Drawing::Point(0, 24);
			toolStrip->Name = L"toolStrip";
			toolStrip->Size = System::Drawing::Size(672, 25);
			toolStrip->TabIndex = 1;
			toolStrip->Text = L"toolStrip";
			// 
			// addTimezoneButton
			// 
			addTimezoneButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			addTimezoneButton->Image = Image::FromFile("./add-button.png");
			addTimezoneButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			addTimezoneButton->Name = L"addTimezoneButton";
			addTimezoneButton->Size = System::Drawing::Size(23, 22);
			addTimezoneButton->Text = L"Додати";
			addTimezoneButton->Click += gcnew System::EventHandler(this, &MainForm::addTimezoneButton_Click);
			// 
			// removeTimezoneButton
			// 
			removeTimezoneButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			removeTimezoneButton->Image = Image::FromFile("./remove-button.png");
			removeTimezoneButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			removeTimezoneButton->Name = L"removeTimezoneButton";
			removeTimezoneButton->Size = System::Drawing::Size(23, 22);
			removeTimezoneButton->Text = L"Прибрати";
			removeTimezoneButton->Click += gcnew System::EventHandler(this, &MainForm::removeTimezoneButton_Click);
			// 
			// statusStrip
			// 
			statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->localTimeLabel });
			statusStrip->Location = System::Drawing::Point(0, 412);
			statusStrip->Name = L"statusStrip";
			statusStrip->Size = System::Drawing::Size(672, 22);
			statusStrip->TabIndex = 2;
			statusStrip->Text = L"statusStrip";
			// 
			// localTimeLabel
			// 
			this->localTimeLabel->Name = L"localTimeLabel";
			this->localTimeLabel->Size = System::Drawing::Size(49, 17);
			this->localTimeLabel->Text = L"00:00:00";
			// 
			// timezone
			// 
			timezone->Text = L"Пояс";
			// 
			// time
			// 
			time->Text = L"Час";
			// 
			// secondsTicker
			// 
			this->secondsTicker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::secondsTicker_DoWork);
			// 
			// timezoneSlider
			// 
			this->timezoneSlider->Location = System::Drawing::Point(260, 143);
			this->timezoneSlider->Maximum = 12;
			this->timezoneSlider->Minimum = -12;
			this->timezoneSlider->Name = L"timezoneSlider";
			this->timezoneSlider->Size = System::Drawing::Size(300, 45);
			this->timezoneSlider->TabIndex = 3;
			this->timezoneSlider->Value = 3;
			this->timezoneSlider->Scroll += gcnew System::EventHandler(this, &MainForm::timezoneSlider_Scroll);
			// 
			// timeLabel
			// 
			this->timeLabel->AutoSize = true;
			this->timeLabel->BackColor = System::Drawing::Color::Transparent;
			this->timeLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeLabel->Location = System::Drawing::Point(266, 191);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(289, 77);
			this->timeLabel->TabIndex = 4;
			this->timeLabel->Text = L"00:00:00";
			this->timeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dateLabel
			// 
			this->dateLabel->AutoSize = true;
			this->dateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateLabel->Location = System::Drawing::Point(265, 282);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(291, 29);
			this->dateLabel->TabIndex = 5;
			this->dateLabel->Text = L"Thursday, January 1, 1970";
			this->dateLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timezoneLabel
			// 
			this->timezoneLabel->AutoSize = true;
			this->timezoneLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timezoneLabel->Location = System::Drawing::Point(327, 120);
			this->timezoneLabel->Name = L"timezoneLabel";
			this->timezoneLabel->Size = System::Drawing::Size(166, 20);
			this->timezoneLabel->TabIndex = 6;
			this->timezoneLabel->Text = L"Israel, Ukraine, Turkey";
			this->timezoneLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timezoneList
			// 
			this->timezoneList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { timezone, time });
			this->timezoneList->HideSelection = false;
			this->timezoneList->Location = System::Drawing::Point(0, 52);
			this->timezoneList->Name = L"timezoneList";
			this->timezoneList->Size = System::Drawing::Size(144, 357);
			this->timezoneList->TabIndex = 8;
			this->timezoneList->UseCompatibleStateImageBehavior = false;
			this->timezoneList->View = System::Windows::Forms::View::Details;
			// 
			// minuteTicker
			// 
			this->minuteTicker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::minuteTicker_DoWork);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(672, 434);
			this->Controls->Add(this->timezoneList);
			this->Controls->Add(this->timezoneLabel);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->timezoneSlider);
			this->Controls->Add(statusStrip);
			this->Controls->Add(toolStrip);
			this->Controls->Add(menuStrip);
			this->HelpButton = true;
			this->MainMenuStrip = menuStrip;
			this->Name = L"MainForm";
			this->Text = L"Супергодин";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			menuStrip->ResumeLayout(false);
			menuStrip->PerformLayout();
			toolStrip->ResumeLayout(false);
			toolStrip->PerformLayout();
			statusStrip->ResumeLayout(false);
			statusStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timezoneSlider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void updateLocalTimeLabel() {
			localTimeLabel->Text = "UTC: " + Clock::Instance.FormatTime("hh:mm:ss");
		}

		private: System::Void updateTimeTable() {
			for each (ListViewItem ^ item in timezoneList->Items) {
				int timezone = Int32::Parse(item->Text->Substring(3));
				item->GetSubItemAt(1, 0)->Text = Clock::Instance.FormatTime("HH:mm", timezone);
			}
		}

		private: System::Void removeSelectedItems() {
		   	for each (ListViewItem^ item in timezoneList->SelectedItems) {
				timezoneList->Items->Remove(item);
			}
		}

		private: System::Void addTimezone() {
			auto currentTimezone = timezoneSlider->Value;

			auto timezone = gcnew ListViewItem();
			timezone->Text = Clock::Instance.GetTimezoneString(currentTimezone);
			timezone->SubItems->Add(Clock::Instance.FormatTime("HH:mm", currentTimezone));

			timezoneList->Items->Add(timezone);
		}

		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			secondsTicker->RunWorkerAsync();
			updateTimeTable();
			minuteTicker->RunWorkerAsync();
			updateLocalTimeLabel();

			timezoneSlider->Value = (DateTime::Now - DateTime::UtcNow).Hours;
			timezoneSlider_Scroll(sender, e);
		}

		private: System::Void закритиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}

		private: System::Void проЗастосунокToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			about->Show();
			about->Focus();
		}

		private: System::Void secondsTicker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
			Thread::Sleep(1000 - System::DateTime::Now.Millisecond);
			while (true) {
				updateLocalTimeLabel();
				timezoneSlider_Scroll(sender, e);

				Thread::Sleep(1000);
			}
		}

		private: System::Void timezoneSlider_Scroll(System::Object^ sender, System::EventArgs^ e) {
			auto timezone = timezoneSlider->Value;
			timezoneLabel->Text = Clock::Instance.GetTimezoneDescription(timezone);
			timeLabel->Text = Clock::Instance.FormatTime("HH:mm:ss", timezone);
			dateLabel->Text = Clock::Instance.FormatTime("dddd, MMMM d, yyyy", timezone);
		}

		private: System::Void addTimezoneButton_Click(System::Object^ sender, System::EventArgs^ e) {
			addTimezone();
		}

		private: System::Void removeTimezoneButton_Click(System::Object^ sender, System::EventArgs^ e) {
			removeSelectedItems();
		}

		private: System::Void додатиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			addTimezone();
		}

		private: System::Void видалитиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			removeSelectedItems();
		}

		private: System::Void minuteTicker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
			Thread::Sleep(60000 - System::DateTime::Now.Second * 1000);
			while (true) {
				updateTimeTable();
				Thread::Sleep(60000);
			}
		}
	};
}
