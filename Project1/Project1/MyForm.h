#pragma once

#define DEFAULTLANGUAGE "br"

namespace INPEEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		String^ lLanguage = "DEFAULTLANGUAGE";
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bNovoModelo;
	protected:
	private: System::Windows::Forms::Button^  bAbrirModelo;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::PictureBox^  pbLogo2;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  arquivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  novoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  luccMEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preferênciasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  idiomaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;


	private:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->bNovoModelo = (gcnew System::Windows::Forms::Button());
			this->bAbrirModelo = (gcnew System::Windows::Forms::Button());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->pbLogo2 = (gcnew System::Windows::Forms::PictureBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->arquivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->novoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sairToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preferênciasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->idiomaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ajudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->luccMEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sobreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// bNovoModelo
			// 
			this->bNovoModelo->Location = System::Drawing::Point(152, 208);
			this->bNovoModelo->Name = L"bNovoModelo";
			this->bNovoModelo->Size = System::Drawing::Size(185, 47);
			this->bNovoModelo->TabIndex = 13;
			this->bNovoModelo->Text = L"Novo Modelo";
			this->bNovoModelo->UseVisualStyleBackColor = true;
			this->bNovoModelo->Click += gcnew System::EventHandler(this, &MyForm::bNovoModelo_Click);
			// 
			// bAbrirModelo
			// 
			this->bAbrirModelo->Location = System::Drawing::Point(152, 286);
			this->bAbrirModelo->Name = L"bAbrirModelo";
			this->bAbrirModelo->Size = System::Drawing::Size(185, 47);
			this->bAbrirModelo->TabIndex = 14;
			this->bAbrirModelo->Text = L"Abrir Modelo";
			this->bAbrirModelo->UseVisualStyleBackColor = true;
			this->bAbrirModelo->Click += gcnew System::EventHandler(this, &MyForm::bAbrirModelo_Click);
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(60, 39);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 12;
			this->pbLogo1->TabStop = false;
			// 
			// pbLogo2
			// 
			this->pbLogo2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pbLogo2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo2.Image")));
			this->pbLogo2->Location = System::Drawing::Point(163, 384);
			this->pbLogo2->Name = L"pbLogo2";
			this->pbLogo2->Size = System::Drawing::Size(166, 62);
			this->pbLogo2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo2->TabIndex = 11;
			this->pbLogo2->TabStop = false;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 462);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(486, 22);
			this->statusStrip1->TabIndex = 15;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->arquivoToolStripMenuItem,
					this->preferênciasToolStripMenuItem, this->ajudaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(486, 24);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// arquivoToolStripMenuItem
			// 
			this->arquivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->novoToolStripMenuItem,
					this->abrirToolStripMenuItem, this->sairToolStripMenuItem
			});
			this->arquivoToolStripMenuItem->Name = L"arquivoToolStripMenuItem";
			this->arquivoToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->arquivoToolStripMenuItem->Text = L"Arquivo";
			// 
			// novoToolStripMenuItem
			// 
			this->novoToolStripMenuItem->Name = L"novoToolStripMenuItem";
			this->novoToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->novoToolStripMenuItem->Text = L"Novo";
			this->novoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::bNovoModelo_Click);
			// 
			// abrirToolStripMenuItem
			// 
			this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			this->abrirToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->abrirToolStripMenuItem->Text = L"Abrir";
			this->abrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::bAbrirModelo_Click);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sairToolStripMenuItem_Click);
			// 
			// preferênciasToolStripMenuItem
			// 
			this->preferênciasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->idiomaToolStripMenuItem });
			this->preferênciasToolStripMenuItem->Name = L"preferênciasToolStripMenuItem";
			this->preferênciasToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->preferênciasToolStripMenuItem->Text = L"Preferências";
			// 
			// idiomaToolStripMenuItem
			// 
			this->idiomaToolStripMenuItem->Name = L"idiomaToolStripMenuItem";
			this->idiomaToolStripMenuItem->Size = System::Drawing::Size(111, 22);
			this->idiomaToolStripMenuItem->Text = L"Idioma";
			this->idiomaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::idiomaToolStripMenuItem_Click);
			// 
			// ajudaToolStripMenuItem
			// 
			this->ajudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->luccMEToolStripMenuItem,
					this->sobreToolStripMenuItem
			});
			this->ajudaToolStripMenuItem->Name = L"ajudaToolStripMenuItem";
			this->ajudaToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->ajudaToolStripMenuItem->Text = L"Ajuda";
			// 
			// luccMEToolStripMenuItem
			// 
			this->luccMEToolStripMenuItem->Name = L"luccMEToolStripMenuItem";
			this->luccMEToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->luccMEToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->luccMEToolStripMenuItem->Text = L"INPE-EM";
			this->luccMEToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::luccMEToolStripMenuItem_Click);
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sobreToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(486, 484);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->bNovoModelo);
			this->Controls->Add(this->bAbrirModelo);
			this->Controls->Add(this->pbLogo1);
			this->Controls->Add(this->pbLogo2);
			this->HelpButton = true;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gerenciador de Modelos";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bNovoModelo_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void checkLanguage();
	private: System::Void idiomaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bAbrirModelo_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void luccMEToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
}
