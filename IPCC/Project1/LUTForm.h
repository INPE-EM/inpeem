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
	/// Summary for LUTForm
	/// </summary>
	public ref class LUTForm : public System::Windows::Forms::Form
	{
	private:
		String ^ gSLUT = "";
		String^ gSLUTMod = "";
		String^ gSExit = "";

	public:
		cReturn ^ lReturn;
		String^ aux;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	public:
		bool close;
		LUTForm(cReturn^ pLUT)
		{
			InitializeComponent();
			this->lReturn = pLUT;
			aux = this->lReturn->Return;
			close = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LUTForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  tLUT;
	private: System::Windows::Forms::Label^  lLUT;
	private: System::Windows::Forms::Button^  bAddLUT;
	private: System::Windows::Forms::ListView^  lvLUT;
	private: System::Windows::Forms::Button^  bRemLUT;
	private: System::Windows::Forms::Button^  bUpLUT;
	private: System::Windows::Forms::Button^  bDownLUT;
	private: System::Windows::Forms::Button^  bSalvar;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LUTForm::typeid));
			this->tLUT = (gcnew System::Windows::Forms::TextBox());
			this->lLUT = (gcnew System::Windows::Forms::Label());
			this->bAddLUT = (gcnew System::Windows::Forms::Button());
			this->lvLUT = (gcnew System::Windows::Forms::ListView());
			this->bRemLUT = (gcnew System::Windows::Forms::Button());
			this->bUpLUT = (gcnew System::Windows::Forms::Button());
			this->bDownLUT = (gcnew System::Windows::Forms::Button());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// tLUT
			// 
			this->tLUT->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tLUT->Location = System::Drawing::Point(156, 175);
			this->tLUT->Name = L"tLUT";
			this->tLUT->Size = System::Drawing::Size(194, 20);
			this->tLUT->TabIndex = 36;
			this->tLUT->Text = L"floresta";
			this->tLUT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tLUT->Enter += gcnew System::EventHandler(this, &LUTForm::tLUT_Enter);
			this->tLUT->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LUTForm::tLUT_KeyDown);
			// 
			// lLUT
			// 
			this->lLUT->AutoSize = true;
			this->lLUT->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lLUT->Location = System::Drawing::Point(25, 173);
			this->lLUT->Name = L"lLUT";
			this->lLUT->Size = System::Drawing::Size(107, 23);
			this->lLUT->TabIndex = 35;
			this->lLUT->Text = L"Uso da Terra";
			this->lLUT->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// bAddLUT
			// 
			this->bAddLUT->Location = System::Drawing::Point(383, 173);
			this->bAddLUT->Name = L"bAddLUT";
			this->bAddLUT->Size = System::Drawing::Size(75, 23);
			this->bAddLUT->TabIndex = 3;
			this->bAddLUT->Text = L"Adicionar";
			this->bAddLUT->UseVisualStyleBackColor = true;
			this->bAddLUT->Click += gcnew System::EventHandler(this, &LUTForm::bAddLUT_Click);
			// 
			// lvLUT
			// 
			this->lvLUT->Location = System::Drawing::Point(29, 214);
			this->lvLUT->MultiSelect = false;
			this->lvLUT->Name = L"lvLUT";
			this->lvLUT->Size = System::Drawing::Size(171, 291);
			this->lvLUT->TabIndex = 34;
			this->lvLUT->UseCompatibleStateImageBehavior = false;
			this->lvLUT->SelectedIndexChanged += gcnew System::EventHandler(this, &LUTForm::lvLUT_SelectedIndexChanged);
			// 
			// bRemLUT
			// 
			this->bRemLUT->Location = System::Drawing::Point(206, 214);
			this->bRemLUT->Name = L"bRemLUT";
			this->bRemLUT->Size = System::Drawing::Size(75, 23);
			this->bRemLUT->TabIndex = 37;
			this->bRemLUT->Text = L"Remover";
			this->bRemLUT->UseVisualStyleBackColor = true;
			this->bRemLUT->Visible = false;
			this->bRemLUT->Click += gcnew System::EventHandler(this, &LUTForm::bRemLUT_Click);
			// 
			// bUpLUT
			// 
			this->bUpLUT->Location = System::Drawing::Point(206, 314);
			this->bUpLUT->Name = L"bUpLUT";
			this->bUpLUT->Size = System::Drawing::Size(32, 26);
			this->bUpLUT->TabIndex = 38;
			this->bUpLUT->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bUpLUT->UseVisualStyleBackColor = true;
			this->bUpLUT->Visible = false;
			this->bUpLUT->Click += gcnew System::EventHandler(this, &LUTForm::bUpLUT_Click);
			// 
			// bDownLUT
			// 
			this->bDownLUT->Location = System::Drawing::Point(206, 343);
			this->bDownLUT->Name = L"bDownLUT";
			this->bDownLUT->Size = System::Drawing::Size(32, 26);
			this->bDownLUT->TabIndex = 39;
			this->bDownLUT->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bDownLUT->UseVisualStyleBackColor = true;
			this->bDownLUT->Visible = false;
			this->bDownLUT->Click += gcnew System::EventHandler(this, &LUTForm::bDownLUT_Click);
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(383, 482);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 40;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &LUTForm::bSalvar_Click);
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(64, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 41;
			this->pbLogo1->TabStop = false;
			// 
			// LUTForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(495, 535);
			this->Controls->Add(this->pbLogo1);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->bDownLUT);
			this->Controls->Add(this->bUpLUT);
			this->Controls->Add(this->bRemLUT);
			this->Controls->Add(this->lvLUT);
			this->Controls->Add(this->bAddLUT);
			this->Controls->Add(this->tLUT);
			this->Controls->Add(this->lLUT);
			this->Name = L"LUTForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gerenciar Usos da Terra";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LUTForm::LUTForm_FormClosing);
			this->Shown += gcnew System::EventHandler(this, &LUTForm::LUTForm_Shown);
			this->Click += gcnew System::EventHandler(this, &LUTForm::LUTForm_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bAddLUT_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tLUT_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void LUTForm_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void LUTForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	private: System::Void lvLUT_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bRemLUT_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bUpLUT_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bDownLUT_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void LUTForm_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tLUT_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	};
}
