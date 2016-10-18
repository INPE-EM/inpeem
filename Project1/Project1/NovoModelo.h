#pragma once

namespace INPEEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System;
	using namespace System::IO;

	/// <summary>
	/// Summary for NovoModelo
	/// </summary>
	public ref class NovoModelo : public System::Windows::Forms::Form
	{
	public:
		bool closing = false;
		bool forceWriting = false;
		bool runnable = false;
		bool lOpen = false;
		String^ lLanguage;
		String^ gDeforest;

	private: System::Windows::Forms::TabControl^  tNovoModelo;
	private: System::Windows::Forms::TabPage^  tabDefModel;
	private: System::Windows::Forms::Label^  lDefinicoesModelo;
	private: System::Windows::Forms::Label^  lArquivos;
	private: System::Windows::Forms::TextBox^  tModelName;
	private: System::Windows::Forms::Label^  lModelName;
	private: System::Windows::Forms::Label^  lSelectedFolder;
	private: System::Windows::Forms::Button^  bSelectFolder;
	private: System::Windows::Forms::Label^  lDirProj;
	private: System::Windows::Forms::TabPage^  tabNonSpatial;
	private: System::Windows::Forms::TabPage^  tabFileMaker;
	private: System::Windows::Forms::Button^  bRun;
	private: System::Windows::Forms::Label^  lRunModel;
	private: System::Windows::Forms::Button^  bGerarArquivos;
	private: System::Windows::Forms::Label^  lFileMaker;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::TabPage^  tabSpatial;
	private: System::Windows::Forms::TabPage^  tabComponents;
	private: System::Windows::Forms::TextBox^  tbBiomass;
	private: System::Windows::Forms::Button^  bBiomass;
	private: System::Windows::Forms::TextBox^  tbDegrad;
	private: System::Windows::Forms::Button^  bDegrad;
	private: System::Windows::Forms::TextBox^  tbSecondVegetation;
	private: System::Windows::Forms::Button^  bSecondVegetation;
	private: System::Windows::Forms::TextBox^  tbVegetationRemoval;
	private: System::Windows::Forms::Button^  bVegetationRemoval;
	private: System::Windows::Forms::TextBox^  tbDeforest;
	private: System::Windows::Forms::Button^  bDeforest;
	private: System::Windows::Forms::Label^  lComponentes;

	public:
		int lReturn;
		NovoModelo(String^ pLanguage, bool pOpen, int pReturn)
		{
			InitializeComponent();
			lLanguage = pLanguage;
			lOpen = pOpen;
			lReturn = pReturn;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NovoModelo()
		{
			if (components)
			{
				delete components;
			}
		}
	
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NovoModelo::typeid));
			this->tNovoModelo = (gcnew System::Windows::Forms::TabControl());
			this->tabDefModel = (gcnew System::Windows::Forms::TabPage());
			this->lDefinicoesModelo = (gcnew System::Windows::Forms::Label());
			this->lArquivos = (gcnew System::Windows::Forms::Label());
			this->tModelName = (gcnew System::Windows::Forms::TextBox());
			this->lModelName = (gcnew System::Windows::Forms::Label());
			this->lSelectedFolder = (gcnew System::Windows::Forms::Label());
			this->bSelectFolder = (gcnew System::Windows::Forms::Button());
			this->lDirProj = (gcnew System::Windows::Forms::Label());
			this->tabNonSpatial = (gcnew System::Windows::Forms::TabPage());
			this->tabSpatial = (gcnew System::Windows::Forms::TabPage());
			this->tabFileMaker = (gcnew System::Windows::Forms::TabPage());
			this->bRun = (gcnew System::Windows::Forms::Button());
			this->lRunModel = (gcnew System::Windows::Forms::Label());
			this->bGerarArquivos = (gcnew System::Windows::Forms::Button());
			this->lFileMaker = (gcnew System::Windows::Forms::Label());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabComponents = (gcnew System::Windows::Forms::TabPage());
			this->lComponentes = (gcnew System::Windows::Forms::Label());
			this->bDeforest = (gcnew System::Windows::Forms::Button());
			this->tbDeforest = (gcnew System::Windows::Forms::TextBox());
			this->bBiomass = (gcnew System::Windows::Forms::Button());
			this->tbBiomass = (gcnew System::Windows::Forms::TextBox());
			this->bVegetationRemoval = (gcnew System::Windows::Forms::Button());
			this->tbVegetationRemoval = (gcnew System::Windows::Forms::TextBox());
			this->bSecondVegetation = (gcnew System::Windows::Forms::Button());
			this->tbSecondVegetation = (gcnew System::Windows::Forms::TextBox());
			this->bDegrad = (gcnew System::Windows::Forms::Button());
			this->tbDegrad = (gcnew System::Windows::Forms::TextBox());
			this->tNovoModelo->SuspendLayout();
			this->tabDefModel->SuspendLayout();
			this->tabFileMaker->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->tabComponents->SuspendLayout();
			this->SuspendLayout();
			// 
			// tNovoModelo
			// 
			this->tNovoModelo->Controls->Add(this->tabDefModel);
			this->tNovoModelo->Controls->Add(this->tabComponents);
			this->tNovoModelo->Controls->Add(this->tabNonSpatial);
			this->tNovoModelo->Controls->Add(this->tabSpatial);
			this->tNovoModelo->Controls->Add(this->tabFileMaker);
			this->tNovoModelo->Location = System::Drawing::Point(12, 173);
			this->tNovoModelo->Name = L"tNovoModelo";
			this->tNovoModelo->SelectedIndex = 0;
			this->tNovoModelo->Size = System::Drawing::Size(725, 481);
			this->tNovoModelo->TabIndex = 19;
			// 
			// tabDefModel
			// 
			this->tabDefModel->Controls->Add(this->lDefinicoesModelo);
			this->tabDefModel->Controls->Add(this->lArquivos);
			this->tabDefModel->Controls->Add(this->tModelName);
			this->tabDefModel->Controls->Add(this->lModelName);
			this->tabDefModel->Controls->Add(this->lSelectedFolder);
			this->tabDefModel->Controls->Add(this->bSelectFolder);
			this->tabDefModel->Controls->Add(this->lDirProj);
			this->tabDefModel->Location = System::Drawing::Point(4, 22);
			this->tabDefModel->Name = L"tabDefModel";
			this->tabDefModel->Padding = System::Windows::Forms::Padding(3);
			this->tabDefModel->Size = System::Drawing::Size(717, 455);
			this->tabDefModel->TabIndex = 0;
			this->tabDefModel->Text = L"Definições do Modelo";
			this->tabDefModel->UseVisualStyleBackColor = true;
			// 
			// lDefinicoesModelo
			// 
			this->lDefinicoesModelo->AutoSize = true;
			this->lDefinicoesModelo->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDefinicoesModelo->Location = System::Drawing::Point(244, 171);
			this->lDefinicoesModelo->Name = L"lDefinicoesModelo";
			this->lDefinicoesModelo->Size = System::Drawing::Size(202, 26);
			this->lDefinicoesModelo->TabIndex = 70;
			this->lDefinicoesModelo->Text = L"Definições do Modelo";
			this->lDefinicoesModelo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lArquivos
			// 
			this->lArquivos->AutoSize = true;
			this->lArquivos->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lArquivos->Location = System::Drawing::Point(303, 26);
			this->lArquivos->Name = L"lArquivos";
			this->lArquivos->Size = System::Drawing::Size(88, 26);
			this->lArquivos->TabIndex = 69;
			this->lArquivos->Text = L"Arquivos";
			this->lArquivos->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tModelName
			// 
			this->tModelName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tModelName->Location = System::Drawing::Point(249, 214);
			this->tModelName->Name = L"tModelName";
			this->tModelName->Size = System::Drawing::Size(194, 20);
			this->tModelName->TabIndex = 66;
			this->tModelName->Text = L"INPEEM_model";
			this->tModelName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lModelName
			// 
			this->lModelName->AutoSize = true;
			this->lModelName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lModelName->Location = System::Drawing::Point(23, 213);
			this->lModelName->Name = L"lModelName";
			this->lModelName->Size = System::Drawing::Size(148, 23);
			this->lModelName->TabIndex = 65;
			this->lModelName->Text = L"Nome do Modelo";
			this->lModelName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lSelectedFolder
			// 
			this->lSelectedFolder->AutoSize = true;
			this->lSelectedFolder->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSelectedFolder->Location = System::Drawing::Point(23, 132);
			this->lSelectedFolder->Name = L"lSelectedFolder";
			this->lSelectedFolder->Size = System::Drawing::Size(0, 19);
			this->lSelectedFolder->TabIndex = 64;
			// 
			// bSelectFolder
			// 
			this->bSelectFolder->Location = System::Drawing::Point(308, 78);
			this->bSelectFolder->Name = L"bSelectFolder";
			this->bSelectFolder->Size = System::Drawing::Size(75, 23);
			this->bSelectFolder->TabIndex = 63;
			this->bSelectFolder->Text = L"Selecionar";
			this->bSelectFolder->UseVisualStyleBackColor = true;
			// 
			// lDirProj
			// 
			this->lDirProj->AutoSize = true;
			this->lDirProj->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDirProj->Location = System::Drawing::Point(18, 78);
			this->lDirProj->Name = L"lDirProj";
			this->lDirProj->Size = System::Drawing::Size(224, 23);
			this->lDirProj->TabIndex = 62;
			this->lDirProj->Text = L"Pasta para Salvar o Modelo";
			this->lDirProj->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tabNonSpatial
			// 
			this->tabNonSpatial->Location = System::Drawing::Point(4, 22);
			this->tabNonSpatial->Name = L"tabNonSpatial";
			this->tabNonSpatial->Padding = System::Windows::Forms::Padding(3);
			this->tabNonSpatial->Size = System::Drawing::Size(717, 455);
			this->tabNonSpatial->TabIndex = 1;
			this->tabNonSpatial->Text = L"Modelo Não Espacial";
			this->tabNonSpatial->UseVisualStyleBackColor = true;
			// 
			// tabSpatial
			// 
			this->tabSpatial->Location = System::Drawing::Point(4, 22);
			this->tabSpatial->Name = L"tabSpatial";
			this->tabSpatial->Size = System::Drawing::Size(717, 455);
			this->tabSpatial->TabIndex = 6;
			this->tabSpatial->Text = L"Modelo Espacial";
			this->tabSpatial->UseVisualStyleBackColor = true;
			// 
			// tabFileMaker
			// 
			this->tabFileMaker->Controls->Add(this->bRun);
			this->tabFileMaker->Controls->Add(this->lRunModel);
			this->tabFileMaker->Controls->Add(this->bGerarArquivos);
			this->tabFileMaker->Controls->Add(this->lFileMaker);
			this->tabFileMaker->Location = System::Drawing::Point(4, 22);
			this->tabFileMaker->Name = L"tabFileMaker";
			this->tabFileMaker->Padding = System::Windows::Forms::Padding(3);
			this->tabFileMaker->Size = System::Drawing::Size(717, 455);
			this->tabFileMaker->TabIndex = 5;
			this->tabFileMaker->Text = L"Gerar Arquivo";
			this->tabFileMaker->UseVisualStyleBackColor = true;
			// 
			// bRun
			// 
			this->bRun->Location = System::Drawing::Point(264, 260);
			this->bRun->Name = L"bRun";
			this->bRun->Size = System::Drawing::Size(185, 47);
			this->bRun->TabIndex = 91;
			this->bRun->Text = L"Rodar Modelo";
			this->bRun->UseVisualStyleBackColor = true;
			this->bRun->Visible = false;
			// 
			// lRunModel
			// 
			this->lRunModel->AutoSize = true;
			this->lRunModel->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRunModel->Location = System::Drawing::Point(281, 213);
			this->lRunModel->Name = L"lRunModel";
			this->lRunModel->Size = System::Drawing::Size(151, 26);
			this->lRunModel->TabIndex = 90;
			this->lRunModel->Text = L"Rodar o Modelo";
			this->lRunModel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lRunModel->Visible = false;
			// 
			// bGerarArquivos
			// 
			this->bGerarArquivos->Location = System::Drawing::Point(264, 78);
			this->bGerarArquivos->Name = L"bGerarArquivos";
			this->bGerarArquivos->Size = System::Drawing::Size(185, 47);
			this->bGerarArquivos->TabIndex = 89;
			this->bGerarArquivos->Text = L"Gerar Arquivos";
			this->bGerarArquivos->UseVisualStyleBackColor = true;
			// 
			// lFileMaker
			// 
			this->lFileMaker->AutoSize = true;
			this->lFileMaker->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lFileMaker->Location = System::Drawing::Point(274, 29);
			this->lFileMaker->Name = L"lFileMaker";
			this->lFileMaker->Size = System::Drawing::Size(165, 26);
			this->lFileMaker->TabIndex = 87;
			this->lFileMaker->Text = L"Gerar os Arquivos";
			this->lFileMaker->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(178, 33);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 20;
			this->pbLogo1->TabStop = false;
			// 
			// tabComponents
			// 
			this->tabComponents->Controls->Add(this->tbBiomass);
			this->tabComponents->Controls->Add(this->bBiomass);
			this->tabComponents->Controls->Add(this->tbDegrad);
			this->tabComponents->Controls->Add(this->bDegrad);
			this->tabComponents->Controls->Add(this->tbSecondVegetation);
			this->tabComponents->Controls->Add(this->bSecondVegetation);
			this->tabComponents->Controls->Add(this->tbVegetationRemoval);
			this->tabComponents->Controls->Add(this->bVegetationRemoval);
			this->tabComponents->Controls->Add(this->tbDeforest);
			this->tabComponents->Controls->Add(this->bDeforest);
			this->tabComponents->Controls->Add(this->lComponentes);
			this->tabComponents->Location = System::Drawing::Point(4, 22);
			this->tabComponents->Name = L"tabComponents";
			this->tabComponents->Size = System::Drawing::Size(717, 455);
			this->tabComponents->TabIndex = 7;
			this->tabComponents->Text = L"Componentes";
			this->tabComponents->UseVisualStyleBackColor = true;
			// 
			// lComponentes
			// 
			this->lComponentes->AutoSize = true;
			this->lComponentes->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lComponentes->Location = System::Drawing::Point(229, 26);
			this->lComponentes->Name = L"lComponentes";
			this->lComponentes->Size = System::Drawing::Size(245, 26);
			this->lComponentes->TabIndex = 76;
			this->lComponentes->Text = L"Configure os Componentes";
			this->lComponentes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bDeforest
			// 
			this->bDeforest->Location = System::Drawing::Point(140, 75);
			this->bDeforest->Name = L"bDeforest";
			this->bDeforest->Size = System::Drawing::Size(171, 39);
			this->bDeforest->TabIndex = 78;
			this->bDeforest->Text = L"Desmatamento";
			this->bDeforest->UseVisualStyleBackColor = true;
			this->bDeforest->Click += gcnew System::EventHandler(this, &NovoModelo::bDeforest_Click);
			// 
			// tbDeforest
			// 
			this->tbDeforest->BackColor = System::Drawing::SystemColors::Control;
			this->tbDeforest->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbDeforest->Location = System::Drawing::Point(140, 120);
			this->tbDeforest->Multiline = true;
			this->tbDeforest->Name = L"tbDeforest";
			this->tbDeforest->ReadOnly = true;
			this->tbDeforest->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbDeforest->Size = System::Drawing::Size(171, 126);
			this->tbDeforest->TabIndex = 81;
			this->tbDeforest->WordWrap = false;
			// 
			// bBiomass
			// 
			this->bBiomass->Location = System::Drawing::Point(395, 75);
			this->bBiomass->Name = L"bBiomass";
			this->bBiomass->Size = System::Drawing::Size(171, 39);
			this->bBiomass->TabIndex = 78;
			this->bBiomass->Text = L"Biomassa";
			this->bBiomass->UseVisualStyleBackColor = true;
			// 
			// tbBiomass
			// 
			this->tbBiomass->BackColor = System::Drawing::SystemColors::Control;
			this->tbBiomass->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbBiomass->Location = System::Drawing::Point(395, 120);
			this->tbBiomass->Multiline = true;
			this->tbBiomass->Name = L"tbBiomass";
			this->tbBiomass->ReadOnly = true;
			this->tbBiomass->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbBiomass->Size = System::Drawing::Size(171, 126);
			this->tbBiomass->TabIndex = 81;
			this->tbBiomass->WordWrap = false;
			// 
			// bVegetationRemoval
			// 
			this->bVegetationRemoval->Location = System::Drawing::Point(25, 261);
			this->bVegetationRemoval->Name = L"bVegetationRemoval";
			this->bVegetationRemoval->Size = System::Drawing::Size(171, 39);
			this->bVegetationRemoval->TabIndex = 78;
			this->bVegetationRemoval->Text = L"Vegetação Primária";
			this->bVegetationRemoval->UseVisualStyleBackColor = true;
			// 
			// tbVegetationRemoval
			// 
			this->tbVegetationRemoval->BackColor = System::Drawing::SystemColors::Control;
			this->tbVegetationRemoval->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbVegetationRemoval->Location = System::Drawing::Point(25, 306);
			this->tbVegetationRemoval->Multiline = true;
			this->tbVegetationRemoval->Name = L"tbVegetationRemoval";
			this->tbVegetationRemoval->ReadOnly = true;
			this->tbVegetationRemoval->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbVegetationRemoval->Size = System::Drawing::Size(171, 126);
			this->tbVegetationRemoval->TabIndex = 81;
			this->tbVegetationRemoval->WordWrap = false;
			// 
			// bSecondVegetation
			// 
			this->bSecondVegetation->Location = System::Drawing::Point(263, 261);
			this->bSecondVegetation->Name = L"bSecondVegetation";
			this->bSecondVegetation->Size = System::Drawing::Size(171, 39);
			this->bSecondVegetation->TabIndex = 78;
			this->bSecondVegetation->Text = L"Vegetação Secundária";
			this->bSecondVegetation->UseVisualStyleBackColor = true;
			// 
			// tbSecondVegetation
			// 
			this->tbSecondVegetation->BackColor = System::Drawing::SystemColors::Control;
			this->tbSecondVegetation->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSecondVegetation->Location = System::Drawing::Point(263, 306);
			this->tbSecondVegetation->Multiline = true;
			this->tbSecondVegetation->Name = L"tbSecondVegetation";
			this->tbSecondVegetation->ReadOnly = true;
			this->tbSecondVegetation->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbSecondVegetation->Size = System::Drawing::Size(171, 126);
			this->tbSecondVegetation->TabIndex = 81;
			this->tbSecondVegetation->WordWrap = false;
			// 
			// bDegrad
			// 
			this->bDegrad->Location = System::Drawing::Point(504, 261);
			this->bDegrad->Name = L"bDegrad";
			this->bDegrad->Size = System::Drawing::Size(171, 39);
			this->bDegrad->TabIndex = 78;
			this->bDegrad->Text = L"Degradação";
			this->bDegrad->UseVisualStyleBackColor = true;
			// 
			// tbDegrad
			// 
			this->tbDegrad->BackColor = System::Drawing::SystemColors::Control;
			this->tbDegrad->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbDegrad->Location = System::Drawing::Point(504, 306);
			this->tbDegrad->Multiline = true;
			this->tbDegrad->Name = L"tbDegrad";
			this->tbDegrad->ReadOnly = true;
			this->tbDegrad->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbDegrad->Size = System::Drawing::Size(171, 126);
			this->tbDegrad->TabIndex = 81;
			this->tbDegrad->WordWrap = false;
			// 
			// NovoModelo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(745, 677);
			this->Controls->Add(this->pbLogo1);
			this->Controls->Add(this->tNovoModelo);
			this->Name = L"NovoModelo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Criando um Novo Modelo";
			this->tNovoModelo->ResumeLayout(false);
			this->tabDefModel->ResumeLayout(false);
			this->tabDefModel->PerformLayout();
			this->tabFileMaker->ResumeLayout(false);
			this->tabFileMaker->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->tabComponents->ResumeLayout(false);
			this->tabComponents->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bDeforest_Click(System::Object^  sender, System::EventArgs^  e);
};
}
