#pragma once

namespace clockapp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbIcon;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::Label^ lblRights;
			System::Windows::Forms::Label^ lblAuthor;
			System::Windows::Forms::Label^ lblVersion;
			System::Windows::Forms::Label^ lblName;
			System::Windows::Forms::GroupBox^ gbInfo;
			System::Windows::Forms::Label^ lblInfo;
			System::Windows::Forms::Button^ closeButton;
			this->pbIcon = (gcnew System::Windows::Forms::PictureBox());
			lblRights = (gcnew System::Windows::Forms::Label());
			lblAuthor = (gcnew System::Windows::Forms::Label());
			lblVersion = (gcnew System::Windows::Forms::Label());
			lblName = (gcnew System::Windows::Forms::Label());
			gbInfo = (gcnew System::Windows::Forms::GroupBox());
			lblInfo = (gcnew System::Windows::Forms::Label());
			closeButton = (gcnew System::Windows::Forms::Button());
			gbInfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbIcon))->BeginInit();
			this->SuspendLayout();
			// 
			// lblRights
			// 
			lblRights->AutoSize = true;
			lblRights->Location = System::Drawing::Point(160, 110);
			lblRights->Name = L"lblRights";
			lblRights->Size = System::Drawing::Size(104, 13);
			lblRights->TabIndex = 13;
			lblRights->Text = L"Всі права захищені";
			// 
			// lblAuthor
			// 
			lblAuthor->AutoSize = true;
			lblAuthor->Location = System::Drawing::Point(160, 82);
			lblAuthor->Name = L"lblAuthor";
			lblAuthor->Size = System::Drawing::Size(155, 13);
			lblAuthor->TabIndex = 12;
			lblAuthor->Text = L"Розробник: ст. гр. ПІ-21б ПІБ";
			// 
			// lblVersion
			// 
			lblVersion->AutoSize = true;
			lblVersion->Location = System::Drawing::Point(160, 52);
			lblVersion->Name = L"lblVersion";
			lblVersion->Size = System::Drawing::Size(70, 13);
			lblVersion->TabIndex = 11;
			lblVersion->Text = L"Версія: 1.0.0";
			// 
			// lblName
			// 
			lblName->AutoSize = true;
			lblName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			lblName->Location = System::Drawing::Point(160, 23);
			lblName->Name = L"lblName";
			lblName->Size = System::Drawing::Size(76, 13);
			lblName->TabIndex = 10;
			lblName->Text = L"Супергодин";
			// 
			// gbInfo
			// 
			gbInfo->Controls->Add(lblInfo);
			gbInfo->Location = System::Drawing::Point(10, 145);
			gbInfo->Name = L"gbInfo";
			gbInfo->Size = System::Drawing::Size(411, 149);
			gbInfo->TabIndex = 14;
			gbInfo->TabStop = false;
			// 
			// lblInfo
			// 
			lblInfo->AutoSize = true;
			lblInfo->Location = System::Drawing::Point(11, 22);
			lblInfo->Name = L"lblInfo";
			lblInfo->Size = System::Drawing::Size(321, 104);
			lblInfo->TabIndex = 7;
			lblInfo->Text = L"Тема роботи \'\'\r\nЗастосунок виконано відповідно до індивідуального завдання\r\nЗасто"
				L"сунок дозволяє\r\n1. бла бла\r\n2. бла бла\r\n3. бла бла\r\nasdasd\r\n5. бла бла";
			// 
			// closeButton
			// 
			closeButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			closeButton->Location = System::Drawing::Point(183, 312);
			closeButton->Name = L"closeButton";
			closeButton->Size = System::Drawing::Size(75, 23);
			closeButton->TabIndex = 8;
			closeButton->Text = L"Закрити";
			closeButton->UseVisualStyleBackColor = true;
			closeButton->Click += gcnew System::EventHandler(this, &AboutForm::OnCloseButtonClicked);
			// 
			// pbIcon
			// 
			this->pbIcon->Location = System::Drawing::Point(10, 11);
			this->pbIcon->Name = L"pbIcon";
			this->pbIcon->Size = System::Drawing::Size(128, 128);
			this->pbIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbIcon->TabIndex = 9;
			this->pbIcon->TabStop = false;
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = closeButton;
			this->ClientSize = System::Drawing::Size(429, 360);
			this->Controls->Add(gbInfo);
			this->Controls->Add(lblRights);
			this->Controls->Add(lblAuthor);
			this->Controls->Add(lblVersion);
			this->Controls->Add(lblName);
			this->Controls->Add(this->pbIcon);
			this->Controls->Add(closeButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"AboutForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Про застосунок";
			this->TopMost = true;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AboutForm::OnFormClosing);
			this->Load += gcnew System::EventHandler(this, &AboutForm::OnFormLoad);
			gbInfo->ResumeLayout(false);
			gbInfo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbIcon))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void OnCloseButtonClicked(System::Object^ sender, System::EventArgs^ e) {
			Close();
		}

		private: System::Void OnFormLoad(System::Object^ sender, System::EventArgs^ e) {
			pbIcon->Image = Image::FromFile("about.png");
		}

		private: System::Void OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			e->Cancel = true;
			Hide();
		}
	};
}
