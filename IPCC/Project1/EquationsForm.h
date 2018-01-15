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
	/// Sumário para EquationsForm
	/// </summary>
	public ref class EquationsForm : public System::Windows::Forms::Form
	{
	private:
		String^ gSFormula = "";
	public:
		cReturn^ lReturn;
		array<String^>^ gEquations = gcnew array<String^>(50);
	private: System::Windows::Forms::Button^  bAdd;
	public:
		array<String^>^ gEquationsOut = gcnew array<String^>(50);
		EquationsForm(cReturn^ pReturn, array<String^>^ pEquations, array<String^>^ pEquationsOut)
		{
			InitializeComponent();
			lReturn = pReturn;
			gEquations = pEquations;
			gEquationsOut = pEquationsOut;

			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~EquationsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::ListView^  lvEquations;
	private: System::Windows::Forms::TextBox^  tEquation;
	private: System::Windows::Forms::Button^  bSalvar;
	protected:

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EquationsForm::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->lvEquations = (gcnew System::Windows::Forms::ListView());
			this->tEquation = (gcnew System::Windows::Forms::TextBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->bAdd = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(126, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 42;
			this->pbLogo1->TabStop = false;
			// 
			// lvEquations
			// 
			this->lvEquations->Location = System::Drawing::Point(12, 171);
			this->lvEquations->MultiSelect = false;
			this->lvEquations->Name = L"lvEquations";
			this->lvEquations->Size = System::Drawing::Size(171, 336);
			this->lvEquations->TabIndex = 43;
			this->lvEquations->UseCompatibleStateImageBehavior = false;
			this->lvEquations->SelectedIndexChanged += gcnew System::EventHandler(this, &EquationsForm::lvEquations_SelectedIndexChanged);
			// 
			// tEquation
			// 
			this->tEquation->Enabled = false;
			this->tEquation->Location = System::Drawing::Point(12, 171);
			this->tEquation->Name = L"tEquation";
			this->tEquation->Size = System::Drawing::Size(171, 20);
			this->tEquation->TabIndex = 44;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(510, 484);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 45;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &EquationsForm::bSalvar_Click);
			// 
			// bAdd
			// 
			this->bAdd->Location = System::Drawing::Point(392, 484);
			this->bAdd->Name = L"bAdd";
			this->bAdd->Size = System::Drawing::Size(75, 23);
			this->bAdd->TabIndex = 45;
			this->bAdd->Text = L"Adicionar";
			this->bAdd->UseVisualStyleBackColor = true;
			this->bAdd->Visible = false;
			this->bAdd->Click += gcnew System::EventHandler(this, &EquationsForm::bAdd_Click);
			// 
			// EquationsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(609, 535);
			this->Controls->Add(this->bAdd);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->tEquation);
			this->Controls->Add(this->lvEquations);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"EquationsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EquationsForm";
			this->Shown += gcnew System::EventHandler(this, &EquationsForm::EquationsForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Int16 countCaracter(String^ source, char caracter);
	private: System::Void EquationsForm_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lvEquations_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAdd_Click(System::Object^  sender, System::EventArgs^  e);
};
}
