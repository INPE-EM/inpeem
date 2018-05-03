#pragma once

namespace INPEEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para EquationForm
	/// </summary>
	public ref class EquationForm : public System::Windows::Forms::Form
	{
	public:
		String^ lLanguage;
		String^ gSImportEquationErrorTitle = "";
		String^ gSImportEquationError = "";
		String^ gSUnauthorized = "";
		String^ gSUnauthorizedTitle = "";
		String^ gSEquationUpdate = "";
		String^ gSEquationUpdateTitle = "";
		ListView^ oldEquations = gcnew ListView();
	
	public:
		String ^ gSEquations = "";

		EquationForm(String^ pLanguage)
		{
			InitializeComponent();
			lLanguage = pLanguage;
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~EquationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::Button^  bDownEquation;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::Button^  bUpEquation;
	private: System::Windows::Forms::Button^  bRemEquation;
	private: System::Windows::Forms::ListView^  lvEquation;
	private: System::Windows::Forms::Button^  bAddEquation;
	private: System::Windows::Forms::TextBox^  tEquation;
	private: System::Windows::Forms::Label^  lEquation;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(EquationForm::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->bDownEquation = (gcnew System::Windows::Forms::Button());
			this->bUpEquation = (gcnew System::Windows::Forms::Button());
			this->bRemEquation = (gcnew System::Windows::Forms::Button());
			this->lvEquation = (gcnew System::Windows::Forms::ListView());
			this->bAddEquation = (gcnew System::Windows::Forms::Button());
			this->tEquation = (gcnew System::Windows::Forms::TextBox());
			this->lEquation = (gcnew System::Windows::Forms::Label());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(149, 28);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 21;
			this->pbLogo1->TabStop = false;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(416, 614);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 48;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &EquationForm::bSalvar_Click);
			// 
			// bDownEquation
			// 
			this->bDownEquation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bDownEquation.Image")));
			this->bDownEquation->Location = System::Drawing::Point(246, 390);
			this->bDownEquation->Name = L"bDownEquation";
			this->bDownEquation->Size = System::Drawing::Size(32, 26);
			this->bDownEquation->TabIndex = 47;
			this->bDownEquation->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bDownEquation->UseVisualStyleBackColor = true;
			this->bDownEquation->Visible = false;
			this->bDownEquation->Click += gcnew System::EventHandler(this, &EquationForm::bDownLUT_Click);
			// 
			// bUpEquation
			// 
			this->bUpEquation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bUpEquation.Image")));
			this->bUpEquation->Location = System::Drawing::Point(246, 361);
			this->bUpEquation->Name = L"bUpEquation";
			this->bUpEquation->Size = System::Drawing::Size(32, 26);
			this->bUpEquation->TabIndex = 46;
			this->bUpEquation->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bUpEquation->UseVisualStyleBackColor = true;
			this->bUpEquation->Visible = false;
			this->bUpEquation->Click += gcnew System::EventHandler(this, &EquationForm::bUpLUT_Click);
			// 
			// bRemEquation
			// 
			this->bRemEquation->Location = System::Drawing::Point(246, 614);
			this->bRemEquation->Name = L"bRemEquation";
			this->bRemEquation->Size = System::Drawing::Size(75, 23);
			this->bRemEquation->TabIndex = 45;
			this->bRemEquation->Text = L"Remover";
			this->bRemEquation->UseVisualStyleBackColor = true;
			this->bRemEquation->Visible = false;
			this->bRemEquation->Click += gcnew System::EventHandler(this, &EquationForm::bRemLUT_Click);
			// 
			// lvEquation
			// 
			this->lvEquation->Location = System::Drawing::Point(9, 184);
			this->lvEquation->MultiSelect = false;
			this->lvEquation->Name = L"lvEquation";
			this->lvEquation->Size = System::Drawing::Size(231, 453);
			this->lvEquation->TabIndex = 42;
			this->lvEquation->UseCompatibleStateImageBehavior = false;
			this->lvEquation->SelectedIndexChanged += gcnew System::EventHandler(this, &EquationForm::lvEquation_SelectedIndexChanged);
			// 
			// bAddEquation
			// 
			this->bAddEquation->Location = System::Drawing::Point(416, 291);
			this->bAddEquation->Name = L"bAddEquation";
			this->bAddEquation->Size = System::Drawing::Size(75, 23);
			this->bAddEquation->TabIndex = 41;
			this->bAddEquation->Text = L"Adicionar";
			this->bAddEquation->UseVisualStyleBackColor = true;
			this->bAddEquation->Click += gcnew System::EventHandler(this, &EquationForm::bAddEquation_Click);
			// 
			// tEquation
			// 
			this->tEquation->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tEquation->Location = System::Drawing::Point(309, 260);
			this->tEquation->Name = L"tEquation";
			this->tEquation->Size = System::Drawing::Size(289, 20);
			this->tEquation->TabIndex = 44;
			this->tEquation->Text = L"(@biomass&)*$f01_teste# ";
			this->tEquation->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tEquation->Enter += gcnew System::EventHandler(this, &EquationForm::tEquation_Enter);
			// 
			// lEquation
			// 
			this->lEquation->AutoSize = true;
			this->lEquation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lEquation->Location = System::Drawing::Point(416, 230);
			this->lEquation->Name = L"lEquation";
			this->lEquation->Size = System::Drawing::Size(75, 23);
			this->lEquation->TabIndex = 43;
			this->lEquation->Text = L"Equação";
			this->lEquation->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 655);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(617, 22);
			this->statusStrip1->TabIndex = 49;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// EquationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(617, 677);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->bDownEquation);
			this->Controls->Add(this->bUpEquation);
			this->Controls->Add(this->bRemEquation);
			this->Controls->Add(this->lvEquation);
			this->Controls->Add(this->bAddEquation);
			this->Controls->Add(this->tEquation);
			this->Controls->Add(this->lEquation);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"EquationForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Equation Manager";
			this->Load += gcnew System::EventHandler(this, &EquationForm::EquationForm_Load);
			this->Click += gcnew System::EventHandler(this, &EquationForm::EquationForm_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EquationForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bRemLUT_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bUpLUT_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bDownLUT_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lvEquation_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void EquationForm_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tEquation_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAddEquation_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
