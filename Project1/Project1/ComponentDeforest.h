#pragma once
#include "Function.h"

namespace INPEEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ComponentDeforest
	/// </summary>
	public ref class ComponentDeforest : public System::Windows::Forms::Form
	{
	public:
		String^ gSDataMissing = "";
		String^ gSDataMissingTitle = "";

	public:
		cReturn^ lReturn;
		ComponentDeforest(cReturn^ pDeforest)
		{
			InitializeComponent();
			lReturn = pDeforest;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ComponentDeforest()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Label^  lName;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::TextBox^  tName;
	private: System::Windows::Forms::Label^  lDescription;
	private: System::Windows::Forms::TextBox^  tDescription;
	private: System::Windows::Forms::Label^  lInitialArea;
	private: System::Windows::Forms::TextBox^  tInitialArea;
	private: System::Windows::Forms::Label^  lTotalNoData;
	private: System::Windows::Forms::TextBox^  tTotalNoData;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ComponentDeforest::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->lName = (gcnew System::Windows::Forms::Label());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->tName = (gcnew System::Windows::Forms::TextBox());
			this->lDescription = (gcnew System::Windows::Forms::Label());
			this->tDescription = (gcnew System::Windows::Forms::TextBox());
			this->lInitialArea = (gcnew System::Windows::Forms::Label());
			this->tInitialArea = (gcnew System::Windows::Forms::TextBox());
			this->lTotalNoData = (gcnew System::Windows::Forms::Label());
			this->tTotalNoData = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(71, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 21;
			this->pbLogo1->TabStop = false;
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lName->Location = System::Drawing::Point(86, 229);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(58, 23);
			this->lName->TabIndex = 87;
			this->lName->Text = L"Nome";
			this->lName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(212, 500);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 88;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &ComponentDeforest::bSalvar_Click);
			// 
			// tName
			// 
			this->tName->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->tName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tName->Location = System::Drawing::Point(147, 232);
			this->tName->MaxLength = 2;
			this->tName->Name = L"tName";
			this->tName->Size = System::Drawing::Size(53, 20);
			this->tName->TabIndex = 89;
			this->tName->Text = L"d";
			this->tName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tName->Enter += gcnew System::EventHandler(this, &ComponentDeforest::textBox_Enter);
			// 
			// lDescription
			// 
			this->lDescription->AutoSize = true;
			this->lDescription->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDescription->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lDescription->Location = System::Drawing::Point(58, 268);
			this->lDescription->Name = L"lDescription";
			this->lDescription->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->lDescription->Size = System::Drawing::Size(87, 23);
			this->lDescription->TabIndex = 87;
			this->lDescription->Text = L"Descri��o";
			this->lDescription->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tDescription
			// 
			this->tDescription->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tDescription->Location = System::Drawing::Point(147, 271);
			this->tDescription->Name = L"tDescription";
			this->tDescription->Size = System::Drawing::Size(278, 20);
			this->tDescription->TabIndex = 89;
			this->tDescription->Text = L"Descri�ao do Componente";
			this->tDescription->Enter += gcnew System::EventHandler(this, &ComponentDeforest::textBox_Enter);
			// 
			// lInitialArea
			// 
			this->lInitialArea->AutoSize = true;
			this->lInitialArea->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lInitialArea->Location = System::Drawing::Point(51, 307);
			this->lInitialArea->Name = L"lInitialArea";
			this->lInitialArea->Size = System::Drawing::Size(93, 23);
			this->lInitialArea->TabIndex = 87;
			this->lInitialArea->Text = L"initialArea";
			this->lInitialArea->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tInitialArea
			// 
			this->tInitialArea->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tInitialArea->Location = System::Drawing::Point(147, 310);
			this->tInitialArea->Name = L"tInitialArea";
			this->tInitialArea->Size = System::Drawing::Size(89, 20);
			this->tInitialArea->TabIndex = 89;
			this->tInitialArea->Text = L"0";
			this->tInitialArea->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tInitialArea->Enter += gcnew System::EventHandler(this, &ComponentDeforest::textBox_Enter);
			// 
			// lTotalNoData
			// 
			this->lTotalNoData->AutoSize = true;
			this->lTotalNoData->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lTotalNoData->Location = System::Drawing::Point(36, 346);
			this->lTotalNoData->Name = L"lTotalNoData";
			this->lTotalNoData->Size = System::Drawing::Size(108, 23);
			this->lTotalNoData->TabIndex = 87;
			this->lTotalNoData->Text = L"totalNoData";
			this->lTotalNoData->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tTotalNoData
			// 
			this->tTotalNoData->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tTotalNoData->Location = System::Drawing::Point(147, 349);
			this->tTotalNoData->Name = L"tTotalNoData";
			this->tTotalNoData->Size = System::Drawing::Size(89, 20);
			this->tTotalNoData->TabIndex = 89;
			this->tTotalNoData->Text = L"130311562";
			this->tTotalNoData->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tTotalNoData->Enter += gcnew System::EventHandler(this, &ComponentDeforest::textBox_Enter);
			// 
			// ComponentDeforest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->tDescription);
			this->Controls->Add(this->tTotalNoData);
			this->Controls->Add(this->tInitialArea);
			this->Controls->Add(this->tName);
			this->Controls->Add(this->lTotalNoData);
			this->Controls->Add(this->lDescription);
			this->Controls->Add(this->lInitialArea);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->lName);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"ComponentDeforest";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Componente - Desmatamento";
			this->Shown += gcnew System::EventHandler(this, &ComponentDeforest::ComponentDeforest_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ComponentDeforest_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
};
}