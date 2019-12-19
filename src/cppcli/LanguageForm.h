#pragma once

namespace INPEEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LanguageForm
	/// </summary>
	public ref class LanguageForm : public System::Windows::Forms::Form
	{
	public:
		String^ lLanguage;
		LanguageForm(String^ pLanguage)
		{
			InitializeComponent();
			lLanguage = pLanguage;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LanguageForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::RadioButton^  rLBr;
	private: System::Windows::Forms::RadioButton^  rLEn;
	private: System::Windows::Forms::Button^  bSelectLanguage;
	private: System::Windows::Forms::PictureBox^  pbLogo1;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LanguageForm::typeid));
			this->rLBr = (gcnew System::Windows::Forms::RadioButton());
			this->rLEn = (gcnew System::Windows::Forms::RadioButton());
			this->bSelectLanguage = (gcnew System::Windows::Forms::Button());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// rLBr
			// 
			this->rLBr->AutoSize = true;
			this->rLBr->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->rLBr->Location = System::Drawing::Point(58, 184);
			this->rLBr->Name = L"rLBr";
			this->rLBr->Size = System::Drawing::Size(109, 27);
			this->rLBr->TabIndex = 14;
			this->rLBr->TabStop = true;
			this->rLBr->Text = L"Portugu�s";
			this->rLBr->UseVisualStyleBackColor = true;
			// 
			// rLEn
			// 
			this->rLEn->AutoSize = true;
			this->rLEn->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->rLEn->Location = System::Drawing::Point(58, 227);
			this->rLEn->Name = L"rLEn";
			this->rLEn->Size = System::Drawing::Size(84, 27);
			this->rLEn->TabIndex = 15;
			this->rLEn->TabStop = true;
			this->rLEn->Text = L"English";
			this->rLEn->UseVisualStyleBackColor = true;
			// 
			// bSelectLanguage
			// 
			this->bSelectLanguage->Location = System::Drawing::Point(204, 304);
			this->bSelectLanguage->Name = L"bSelectLanguage";
			this->bSelectLanguage->Size = System::Drawing::Size(75, 23);
			this->bSelectLanguage->TabIndex = 64;
			this->bSelectLanguage->Text = L"Selecionar";
			this->bSelectLanguage->UseVisualStyleBackColor = true;
			this->bSelectLanguage->Click += gcnew System::EventHandler(this, &LanguageForm::bSelectLanguage_Click);
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(45, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 65;
			this->pbLogo1->TabStop = false;
			// 
			// LanguageForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(471, 352);
			this->Controls->Add(this->pbLogo1);
			this->Controls->Add(this->bSelectLanguage);
			this->Controls->Add(this->rLEn);
			this->Controls->Add(this->rLBr);
			this->Name = L"LanguageForm";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sele��o de Idioma";
			this->Shown += gcnew System::EventHandler(this, &LanguageForm::LanguageForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LanguageForm_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSelectLanguage_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
