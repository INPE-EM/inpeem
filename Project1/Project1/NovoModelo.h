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
		String^ gBiomass;
		String^ gDegradation;
		String^ gSecondaryVegetation;
		String^ gVegetationRemoval;
		String^ gNonSpatialTables;

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
	private: System::Windows::Forms::TextBox^  tNonSpatialName;
	private: System::Windows::Forms::Label^  lNonSpatialName;
	private: System::Windows::Forms::TextBox^  tbTableData;

	private: System::Windows::Forms::Button^  bTableData;
	private: System::Windows::Forms::TextBox^  tNonSpatialInitialYear;
	private: System::Windows::Forms::Label^  lNonSpatialInitialYear;
	private: System::Windows::Forms::TextBox^  tNonSpatialFinalYear;
	private: System::Windows::Forms::Label^  lNonSpatialFinalYear;
	private: System::Windows::Forms::Label^  lNonSpatialComponentSelection;

	private: System::Windows::Forms::CheckBox^  cbNonSpatialSecondaryVegetation;
	private: System::Windows::Forms::CheckBox^  cbNonSpatialVegetationRemoval;
	private: System::Windows::Forms::CheckBox^  cbNonSpatialBiomass;
	private: System::Windows::Forms::CheckBox^  cbNonSpatialDeforest;
	private: System::Windows::Forms::TextBox^  tNonSpatialArea;

	private: System::Windows::Forms::Label^  lNonSpatialArea;

	private: System::Windows::Forms::CheckBox^  cbNonSpatialDegradation;
	private: System::Windows::Forms::Label^  lSpatialComponentSelection;
	private: System::Windows::Forms::CheckBox^  cbSpatialDegradation;


	private: System::Windows::Forms::CheckBox^  cbSpatialSecondaryVegetation;

	private: System::Windows::Forms::CheckBox^  cbSpatialVegetationRemoval;

	private: System::Windows::Forms::CheckBox^  cbSpatialBiomass;

	private: System::Windows::Forms::CheckBox^  cbSpatialDeforest;





	private: System::Windows::Forms::TextBox^  tSpatialFinalYear;

	private: System::Windows::Forms::Label^  lSpatialFinalYear;

	private: System::Windows::Forms::TextBox^  tSpatialInitialYear;

	private: System::Windows::Forms::Label^  lSpatialInitialYear;

	private: System::Windows::Forms::TextBox^  tSpatialName;

	private: System::Windows::Forms::Label^  lSpatialName;
	private: System::Windows::Forms::Label^  lTerraview;
	private: System::Windows::Forms::Label^  lShape;
	private: System::Windows::Forms::Button^  bShape;
	private: System::Windows::Forms::TextBox^  tbSelectedBatabase;
	private: System::Windows::Forms::Button^  bSelectDatabase;
	private: System::Windows::Forms::TextBox^  tSpatialCellArea;
	private: System::Windows::Forms::Label^  lSpatialCellArea;
	private: System::Windows::Forms::TextBox^  tSpatialLayerName;
	private: System::Windows::Forms::Label^  lSpatialLayerName;
	private: System::Windows::Forms::Label^  lDatabase;


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
			this->tabComponents = (gcnew System::Windows::Forms::TabPage());
			this->tbBiomass = (gcnew System::Windows::Forms::TextBox());
			this->bBiomass = (gcnew System::Windows::Forms::Button());
			this->tbDegrad = (gcnew System::Windows::Forms::TextBox());
			this->bDegrad = (gcnew System::Windows::Forms::Button());
			this->tbSecondVegetation = (gcnew System::Windows::Forms::TextBox());
			this->bSecondVegetation = (gcnew System::Windows::Forms::Button());
			this->tbVegetationRemoval = (gcnew System::Windows::Forms::TextBox());
			this->bVegetationRemoval = (gcnew System::Windows::Forms::Button());
			this->tbDeforest = (gcnew System::Windows::Forms::TextBox());
			this->bDeforest = (gcnew System::Windows::Forms::Button());
			this->lComponentes = (gcnew System::Windows::Forms::Label());
			this->tabNonSpatial = (gcnew System::Windows::Forms::TabPage());
			this->lNonSpatialComponentSelection = (gcnew System::Windows::Forms::Label());
			this->cbNonSpatialDegradation = (gcnew System::Windows::Forms::CheckBox());
			this->cbNonSpatialSecondaryVegetation = (gcnew System::Windows::Forms::CheckBox());
			this->cbNonSpatialVegetationRemoval = (gcnew System::Windows::Forms::CheckBox());
			this->cbNonSpatialBiomass = (gcnew System::Windows::Forms::CheckBox());
			this->cbNonSpatialDeforest = (gcnew System::Windows::Forms::CheckBox());
			this->tNonSpatialArea = (gcnew System::Windows::Forms::TextBox());
			this->lNonSpatialArea = (gcnew System::Windows::Forms::Label());
			this->tNonSpatialFinalYear = (gcnew System::Windows::Forms::TextBox());
			this->lNonSpatialFinalYear = (gcnew System::Windows::Forms::Label());
			this->tNonSpatialInitialYear = (gcnew System::Windows::Forms::TextBox());
			this->lNonSpatialInitialYear = (gcnew System::Windows::Forms::Label());
			this->tNonSpatialName = (gcnew System::Windows::Forms::TextBox());
			this->lNonSpatialName = (gcnew System::Windows::Forms::Label());
			this->tbTableData = (gcnew System::Windows::Forms::TextBox());
			this->bTableData = (gcnew System::Windows::Forms::Button());
			this->tabSpatial = (gcnew System::Windows::Forms::TabPage());
			this->lTerraview = (gcnew System::Windows::Forms::Label());
			this->lShape = (gcnew System::Windows::Forms::Label());
			this->bShape = (gcnew System::Windows::Forms::Button());
			this->tbSelectedBatabase = (gcnew System::Windows::Forms::TextBox());
			this->bSelectDatabase = (gcnew System::Windows::Forms::Button());
			this->tSpatialCellArea = (gcnew System::Windows::Forms::TextBox());
			this->lSpatialCellArea = (gcnew System::Windows::Forms::Label());
			this->tSpatialLayerName = (gcnew System::Windows::Forms::TextBox());
			this->lSpatialLayerName = (gcnew System::Windows::Forms::Label());
			this->lDatabase = (gcnew System::Windows::Forms::Label());
			this->lSpatialComponentSelection = (gcnew System::Windows::Forms::Label());
			this->cbSpatialDegradation = (gcnew System::Windows::Forms::CheckBox());
			this->cbSpatialSecondaryVegetation = (gcnew System::Windows::Forms::CheckBox());
			this->cbSpatialVegetationRemoval = (gcnew System::Windows::Forms::CheckBox());
			this->cbSpatialBiomass = (gcnew System::Windows::Forms::CheckBox());
			this->cbSpatialDeforest = (gcnew System::Windows::Forms::CheckBox());
			this->tSpatialFinalYear = (gcnew System::Windows::Forms::TextBox());
			this->lSpatialFinalYear = (gcnew System::Windows::Forms::Label());
			this->tSpatialInitialYear = (gcnew System::Windows::Forms::TextBox());
			this->lSpatialInitialYear = (gcnew System::Windows::Forms::Label());
			this->tSpatialName = (gcnew System::Windows::Forms::TextBox());
			this->lSpatialName = (gcnew System::Windows::Forms::Label());
			this->tabFileMaker = (gcnew System::Windows::Forms::TabPage());
			this->bRun = (gcnew System::Windows::Forms::Button());
			this->lRunModel = (gcnew System::Windows::Forms::Label());
			this->bGerarArquivos = (gcnew System::Windows::Forms::Button());
			this->lFileMaker = (gcnew System::Windows::Forms::Label());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->tNovoModelo->SuspendLayout();
			this->tabDefModel->SuspendLayout();
			this->tabComponents->SuspendLayout();
			this->tabNonSpatial->SuspendLayout();
			this->tabSpatial->SuspendLayout();
			this->tabFileMaker->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
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
			// bBiomass
			// 
			this->bBiomass->Location = System::Drawing::Point(395, 75);
			this->bBiomass->Name = L"bBiomass";
			this->bBiomass->Size = System::Drawing::Size(171, 39);
			this->bBiomass->TabIndex = 78;
			this->bBiomass->Text = L"Biomassa";
			this->bBiomass->UseVisualStyleBackColor = true;
			this->bBiomass->Click += gcnew System::EventHandler(this, &NovoModelo::bBiomass_Click);
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
			// bDegrad
			// 
			this->bDegrad->Location = System::Drawing::Point(504, 261);
			this->bDegrad->Name = L"bDegrad";
			this->bDegrad->Size = System::Drawing::Size(171, 39);
			this->bDegrad->TabIndex = 78;
			this->bDegrad->Text = L"Degradação";
			this->bDegrad->UseVisualStyleBackColor = true;
			this->bDegrad->Click += gcnew System::EventHandler(this, &NovoModelo::bDegrad_Click);
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
			// bSecondVegetation
			// 
			this->bSecondVegetation->Location = System::Drawing::Point(263, 261);
			this->bSecondVegetation->Name = L"bSecondVegetation";
			this->bSecondVegetation->Size = System::Drawing::Size(171, 39);
			this->bSecondVegetation->TabIndex = 78;
			this->bSecondVegetation->Text = L"Vegetação Secundária";
			this->bSecondVegetation->UseVisualStyleBackColor = true;
			this->bSecondVegetation->Click += gcnew System::EventHandler(this, &NovoModelo::bSecondVegetation_Click);
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
			// bVegetationRemoval
			// 
			this->bVegetationRemoval->Location = System::Drawing::Point(25, 261);
			this->bVegetationRemoval->Name = L"bVegetationRemoval";
			this->bVegetationRemoval->Size = System::Drawing::Size(171, 39);
			this->bVegetationRemoval->TabIndex = 78;
			this->bVegetationRemoval->Text = L"Vegetação Primária";
			this->bVegetationRemoval->UseVisualStyleBackColor = true;
			this->bVegetationRemoval->Click += gcnew System::EventHandler(this, &NovoModelo::bVegetationRemoval_Click);
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
			// tabNonSpatial
			// 
			this->tabNonSpatial->Controls->Add(this->lNonSpatialComponentSelection);
			this->tabNonSpatial->Controls->Add(this->cbNonSpatialDegradation);
			this->tabNonSpatial->Controls->Add(this->cbNonSpatialSecondaryVegetation);
			this->tabNonSpatial->Controls->Add(this->cbNonSpatialVegetationRemoval);
			this->tabNonSpatial->Controls->Add(this->cbNonSpatialBiomass);
			this->tabNonSpatial->Controls->Add(this->cbNonSpatialDeforest);
			this->tabNonSpatial->Controls->Add(this->tNonSpatialArea);
			this->tabNonSpatial->Controls->Add(this->lNonSpatialArea);
			this->tabNonSpatial->Controls->Add(this->tNonSpatialFinalYear);
			this->tabNonSpatial->Controls->Add(this->lNonSpatialFinalYear);
			this->tabNonSpatial->Controls->Add(this->tNonSpatialInitialYear);
			this->tabNonSpatial->Controls->Add(this->lNonSpatialInitialYear);
			this->tabNonSpatial->Controls->Add(this->tNonSpatialName);
			this->tabNonSpatial->Controls->Add(this->lNonSpatialName);
			this->tabNonSpatial->Controls->Add(this->tbTableData);
			this->tabNonSpatial->Controls->Add(this->bTableData);
			this->tabNonSpatial->Location = System::Drawing::Point(4, 22);
			this->tabNonSpatial->Name = L"tabNonSpatial";
			this->tabNonSpatial->Padding = System::Windows::Forms::Padding(3);
			this->tabNonSpatial->Size = System::Drawing::Size(717, 455);
			this->tabNonSpatial->TabIndex = 1;
			this->tabNonSpatial->Text = L"Modelo Não Espacial";
			this->tabNonSpatial->UseVisualStyleBackColor = true;
			// 
			// lNonSpatialComponentSelection
			// 
			this->lNonSpatialComponentSelection->AutoSize = true;
			this->lNonSpatialComponentSelection->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lNonSpatialComponentSelection->Location = System::Drawing::Point(436, 126);
			this->lNonSpatialComponentSelection->Name = L"lNonSpatialComponentSelection";
			this->lNonSpatialComponentSelection->Size = System::Drawing::Size(209, 23);
			this->lNonSpatialComponentSelection->TabIndex = 87;
			this->lNonSpatialComponentSelection->Text = L"Seleção de Componentes";
			this->lNonSpatialComponentSelection->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cbNonSpatialDegradation
			// 
			this->cbNonSpatialDegradation->AutoSize = true;
			this->cbNonSpatialDegradation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbNonSpatialDegradation->Location = System::Drawing::Point(388, 301);
			this->cbNonSpatialDegradation->Name = L"cbNonSpatialDegradation";
			this->cbNonSpatialDegradation->Size = System::Drawing::Size(122, 27);
			this->cbNonSpatialDegradation->TabIndex = 86;
			this->cbNonSpatialDegradation->Text = L"Degradação";
			this->cbNonSpatialDegradation->UseVisualStyleBackColor = true;
			// 
			// cbNonSpatialSecondaryVegetation
			// 
			this->cbNonSpatialSecondaryVegetation->AutoSize = true;
			this->cbNonSpatialSecondaryVegetation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbNonSpatialSecondaryVegetation->Location = System::Drawing::Point(388, 268);
			this->cbNonSpatialSecondaryVegetation->Name = L"cbNonSpatialSecondaryVegetation";
			this->cbNonSpatialSecondaryVegetation->Size = System::Drawing::Size(202, 27);
			this->cbNonSpatialSecondaryVegetation->TabIndex = 86;
			this->cbNonSpatialSecondaryVegetation->Text = L"Vegetação Secundária";
			this->cbNonSpatialSecondaryVegetation->UseVisualStyleBackColor = true;
			// 
			// cbNonSpatialVegetationRemoval
			// 
			this->cbNonSpatialVegetationRemoval->AutoSize = true;
			this->cbNonSpatialVegetationRemoval->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbNonSpatialVegetationRemoval->Location = System::Drawing::Point(388, 233);
			this->cbNonSpatialVegetationRemoval->Name = L"cbNonSpatialVegetationRemoval";
			this->cbNonSpatialVegetationRemoval->Size = System::Drawing::Size(182, 27);
			this->cbNonSpatialVegetationRemoval->TabIndex = 86;
			this->cbNonSpatialVegetationRemoval->Text = L"Vegetação Primária";
			this->cbNonSpatialVegetationRemoval->UseVisualStyleBackColor = true;
			// 
			// cbNonSpatialBiomass
			// 
			this->cbNonSpatialBiomass->AutoSize = true;
			this->cbNonSpatialBiomass->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbNonSpatialBiomass->Location = System::Drawing::Point(388, 200);
			this->cbNonSpatialBiomass->Name = L"cbNonSpatialBiomass";
			this->cbNonSpatialBiomass->Size = System::Drawing::Size(104, 27);
			this->cbNonSpatialBiomass->TabIndex = 86;
			this->cbNonSpatialBiomass->Text = L"Biomassa";
			this->cbNonSpatialBiomass->UseVisualStyleBackColor = true;
			// 
			// cbNonSpatialDeforest
			// 
			this->cbNonSpatialDeforest->AutoSize = true;
			this->cbNonSpatialDeforest->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbNonSpatialDeforest->Location = System::Drawing::Point(388, 167);
			this->cbNonSpatialDeforest->Name = L"cbNonSpatialDeforest";
			this->cbNonSpatialDeforest->Size = System::Drawing::Size(151, 27);
			this->cbNonSpatialDeforest->TabIndex = 86;
			this->cbNonSpatialDeforest->Text = L"Desmatamento";
			this->cbNonSpatialDeforest->UseVisualStyleBackColor = true;
			// 
			// tNonSpatialArea
			// 
			this->tNonSpatialArea->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tNonSpatialArea->Location = System::Drawing::Point(116, 207);
			this->tNonSpatialArea->Name = L"tNonSpatialArea";
			this->tNonSpatialArea->Size = System::Drawing::Size(103, 20);
			this->tNonSpatialArea->TabIndex = 85;
			this->tNonSpatialArea->Text = L"528125000";
			this->tNonSpatialArea->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lNonSpatialArea
			// 
			this->lNonSpatialArea->AutoSize = true;
			this->lNonSpatialArea->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lNonSpatialArea->Location = System::Drawing::Point(24, 206);
			this->lNonSpatialArea->Name = L"lNonSpatialArea";
			this->lNonSpatialArea->Size = System::Drawing::Size(90, 23);
			this->lNonSpatialArea->TabIndex = 84;
			this->lNonSpatialArea->Text = L"Área Total";
			this->lNonSpatialArea->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tNonSpatialFinalYear
			// 
			this->tNonSpatialFinalYear->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tNonSpatialFinalYear->Location = System::Drawing::Point(160, 167);
			this->tNonSpatialFinalYear->Name = L"tNonSpatialFinalYear";
			this->tNonSpatialFinalYear->Size = System::Drawing::Size(59, 20);
			this->tNonSpatialFinalYear->TabIndex = 85;
			this->tNonSpatialFinalYear->Text = L"2050";
			this->tNonSpatialFinalYear->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lNonSpatialFinalYear
			// 
			this->lNonSpatialFinalYear->AutoSize = true;
			this->lNonSpatialFinalYear->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lNonSpatialFinalYear->Location = System::Drawing::Point(24, 167);
			this->lNonSpatialFinalYear->Name = L"lNonSpatialFinalYear";
			this->lNonSpatialFinalYear->Size = System::Drawing::Size(134, 23);
			this->lNonSpatialFinalYear->TabIndex = 84;
			this->lNonSpatialFinalYear->Text = L"Ano de Término";
			this->lNonSpatialFinalYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tNonSpatialInitialYear
			// 
			this->tNonSpatialInitialYear->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tNonSpatialInitialYear->Location = System::Drawing::Point(160, 130);
			this->tNonSpatialInitialYear->Name = L"tNonSpatialInitialYear";
			this->tNonSpatialInitialYear->Size = System::Drawing::Size(59, 20);
			this->tNonSpatialInitialYear->TabIndex = 85;
			this->tNonSpatialInitialYear->Text = L"1960";
			this->tNonSpatialInitialYear->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lNonSpatialInitialYear
			// 
			this->lNonSpatialInitialYear->AutoSize = true;
			this->lNonSpatialInitialYear->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lNonSpatialInitialYear->Location = System::Drawing::Point(24, 128);
			this->lNonSpatialInitialYear->Name = L"lNonSpatialInitialYear";
			this->lNonSpatialInitialYear->Size = System::Drawing::Size(113, 23);
			this->lNonSpatialInitialYear->TabIndex = 84;
			this->lNonSpatialInitialYear->Text = L"Ano de Início";
			this->lNonSpatialInitialYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tNonSpatialName
			// 
			this->tNonSpatialName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tNonSpatialName->Location = System::Drawing::Point(276, 54);
			this->tNonSpatialName->Name = L"tNonSpatialName";
			this->tNonSpatialName->Size = System::Drawing::Size(194, 20);
			this->tNonSpatialName->TabIndex = 85;
			this->tNonSpatialName->Text = L"NonSpatialModel";
			this->tNonSpatialName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lNonSpatialName
			// 
			this->lNonSpatialName->AutoSize = true;
			this->lNonSpatialName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lNonSpatialName->Location = System::Drawing::Point(24, 52);
			this->lNonSpatialName->Name = L"lNonSpatialName";
			this->lNonSpatialName->Size = System::Drawing::Size(251, 23);
			this->lNonSpatialName->TabIndex = 84;
			this->lNonSpatialName->Text = L"Nome do Modelo Não Espacial";
			this->lNonSpatialName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tbTableData
			// 
			this->tbTableData->BackColor = System::Drawing::SystemColors::Control;
			this->tbTableData->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbTableData->Location = System::Drawing::Point(17, 313);
			this->tbTableData->Multiline = true;
			this->tbTableData->Name = L"tbTableData";
			this->tbTableData->ReadOnly = true;
			this->tbTableData->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbTableData->Size = System::Drawing::Size(171, 126);
			this->tbTableData->TabIndex = 83;
			this->tbTableData->WordWrap = false;
			// 
			// bTableData
			// 
			this->bTableData->Location = System::Drawing::Point(17, 268);
			this->bTableData->Name = L"bTableData";
			this->bTableData->Size = System::Drawing::Size(171, 39);
			this->bTableData->TabIndex = 82;
			this->bTableData->Text = L"Tabela de Dados Não Espaciais";
			this->bTableData->UseVisualStyleBackColor = true;
			this->bTableData->Click += gcnew System::EventHandler(this, &NovoModelo::bTableData_Click);
			// 
			// tabSpatial
			// 
			this->tabSpatial->Controls->Add(this->lTerraview);
			this->tabSpatial->Controls->Add(this->lShape);
			this->tabSpatial->Controls->Add(this->bShape);
			this->tabSpatial->Controls->Add(this->tbSelectedBatabase);
			this->tabSpatial->Controls->Add(this->bSelectDatabase);
			this->tabSpatial->Controls->Add(this->tSpatialCellArea);
			this->tabSpatial->Controls->Add(this->lSpatialCellArea);
			this->tabSpatial->Controls->Add(this->tSpatialLayerName);
			this->tabSpatial->Controls->Add(this->lSpatialLayerName);
			this->tabSpatial->Controls->Add(this->lDatabase);
			this->tabSpatial->Controls->Add(this->lSpatialComponentSelection);
			this->tabSpatial->Controls->Add(this->cbSpatialDegradation);
			this->tabSpatial->Controls->Add(this->cbSpatialSecondaryVegetation);
			this->tabSpatial->Controls->Add(this->cbSpatialVegetationRemoval);
			this->tabSpatial->Controls->Add(this->cbSpatialBiomass);
			this->tabSpatial->Controls->Add(this->cbSpatialDeforest);
			this->tabSpatial->Controls->Add(this->tSpatialFinalYear);
			this->tabSpatial->Controls->Add(this->lSpatialFinalYear);
			this->tabSpatial->Controls->Add(this->tSpatialInitialYear);
			this->tabSpatial->Controls->Add(this->lSpatialInitialYear);
			this->tabSpatial->Controls->Add(this->tSpatialName);
			this->tabSpatial->Controls->Add(this->lSpatialName);
			this->tabSpatial->Location = System::Drawing::Point(4, 22);
			this->tabSpatial->Name = L"tabSpatial";
			this->tabSpatial->Size = System::Drawing::Size(717, 455);
			this->tabSpatial->TabIndex = 6;
			this->tabSpatial->Text = L"Modelo Espacial";
			this->tabSpatial->UseVisualStyleBackColor = true;
			// 
			// lTerraview
			// 
			this->lTerraview->AutoSize = true;
			this->lTerraview->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lTerraview->Location = System::Drawing::Point(100, 196);
			this->lTerraview->Name = L"lTerraview";
			this->lTerraview->Size = System::Drawing::Size(151, 23);
			this->lTerraview->TabIndex = 111;
			this->lTerraview->Text = L"Projeto Terraview";
			this->lTerraview->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lShape
			// 
			this->lShape->AutoSize = true;
			this->lShape->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lShape->Location = System::Drawing::Point(277, 196);
			this->lShape->Name = L"lShape";
			this->lShape->Size = System::Drawing::Size(58, 23);
			this->lShape->TabIndex = 110;
			this->lShape->Text = L"Shape";
			this->lShape->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// bShape
			// 
			this->bShape->Location = System::Drawing::Point(269, 222);
			this->bShape->Name = L"bShape";
			this->bShape->Size = System::Drawing::Size(75, 23);
			this->bShape->TabIndex = 109;
			this->bShape->Text = L"Selecionar";
			this->bShape->UseVisualStyleBackColor = true;
			// 
			// tbSelectedBatabase
			// 
			this->tbSelectedBatabase->BackColor = System::Drawing::SystemColors::Control;
			this->tbSelectedBatabase->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbSelectedBatabase->Location = System::Drawing::Point(14, 256);
			this->tbSelectedBatabase->Multiline = true;
			this->tbSelectedBatabase->Name = L"tbSelectedBatabase";
			this->tbSelectedBatabase->Size = System::Drawing::Size(355, 98);
			this->tbSelectedBatabase->TabIndex = 108;
			// 
			// bSelectDatabase
			// 
			this->bSelectDatabase->Location = System::Drawing::Point(133, 222);
			this->bSelectDatabase->Name = L"bSelectDatabase";
			this->bSelectDatabase->Size = System::Drawing::Size(75, 23);
			this->bSelectDatabase->TabIndex = 103;
			this->bSelectDatabase->Text = L"Selecionar";
			this->bSelectDatabase->UseVisualStyleBackColor = true;
			// 
			// tSpatialCellArea
			// 
			this->tSpatialCellArea->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSpatialCellArea->Location = System::Drawing::Point(177, 422);
			this->tSpatialCellArea->Name = L"tSpatialCellArea";
			this->tSpatialCellArea->Size = System::Drawing::Size(80, 20);
			this->tSpatialCellArea->TabIndex = 107;
			this->tSpatialCellArea->Text = L"6.25";
			this->tSpatialCellArea->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lSpatialCellArea
			// 
			this->lSpatialCellArea->AutoSize = true;
			this->lSpatialCellArea->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpatialCellArea->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lSpatialCellArea->Location = System::Drawing::Point(12, 421);
			this->lSpatialCellArea->Name = L"lSpatialCellArea";
			this->lSpatialCellArea->Size = System::Drawing::Size(157, 23);
			this->lSpatialCellArea->TabIndex = 106;
			this->lSpatialCellArea->Text = L"Tamanho da Célula";
			this->lSpatialCellArea->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tSpatialLayerName
			// 
			this->tSpatialLayerName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSpatialLayerName->Location = System::Drawing::Point(177, 379);
			this->tSpatialLayerName->Name = L"tSpatialLayerName";
			this->tSpatialLayerName->Size = System::Drawing::Size(192, 20);
			this->tSpatialLayerName->TabIndex = 105;
			this->tSpatialLayerName->Text = L"layer_name";
			this->tSpatialLayerName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lSpatialLayerName
			// 
			this->lSpatialLayerName->AutoSize = true;
			this->lSpatialLayerName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpatialLayerName->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lSpatialLayerName->Location = System::Drawing::Point(12, 378);
			this->lSpatialLayerName->Name = L"lSpatialLayerName";
			this->lSpatialLayerName->Size = System::Drawing::Size(127, 23);
			this->lSpatialLayerName->TabIndex = 104;
			this->lSpatialLayerName->Text = L"Nome do Tema";
			this->lSpatialLayerName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lDatabase
			// 
			this->lDatabase->AutoSize = true;
			this->lDatabase->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDatabase->Location = System::Drawing::Point(12, 222);
			this->lDatabase->Name = L"lDatabase";
			this->lDatabase->Size = System::Drawing::Size(78, 23);
			this->lDatabase->TabIndex = 102;
			this->lDatabase->Text = L"Arquivo:";
			this->lDatabase->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lSpatialComponentSelection
			// 
			this->lSpatialComponentSelection->AutoSize = true;
			this->lSpatialComponentSelection->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpatialComponentSelection->Location = System::Drawing::Point(451, 126);
			this->lSpatialComponentSelection->Name = L"lSpatialComponentSelection";
			this->lSpatialComponentSelection->Size = System::Drawing::Size(209, 23);
			this->lSpatialComponentSelection->TabIndex = 101;
			this->lSpatialComponentSelection->Text = L"Seleção de Componentes";
			this->lSpatialComponentSelection->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// cbSpatialDegradation
			// 
			this->cbSpatialDegradation->AutoSize = true;
			this->cbSpatialDegradation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbSpatialDegradation->Location = System::Drawing::Point(423, 301);
			this->cbSpatialDegradation->Name = L"cbSpatialDegradation";
			this->cbSpatialDegradation->Size = System::Drawing::Size(122, 27);
			this->cbSpatialDegradation->TabIndex = 96;
			this->cbSpatialDegradation->Text = L"Degradação";
			this->cbSpatialDegradation->UseVisualStyleBackColor = true;
			// 
			// cbSpatialSecondaryVegetation
			// 
			this->cbSpatialSecondaryVegetation->AutoSize = true;
			this->cbSpatialSecondaryVegetation->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbSpatialSecondaryVegetation->Location = System::Drawing::Point(423, 268);
			this->cbSpatialSecondaryVegetation->Name = L"cbSpatialSecondaryVegetation";
			this->cbSpatialSecondaryVegetation->Size = System::Drawing::Size(202, 27);
			this->cbSpatialSecondaryVegetation->TabIndex = 97;
			this->cbSpatialSecondaryVegetation->Text = L"Vegetação Secundária";
			this->cbSpatialSecondaryVegetation->UseVisualStyleBackColor = true;
			// 
			// cbSpatialVegetationRemoval
			// 
			this->cbSpatialVegetationRemoval->AutoSize = true;
			this->cbSpatialVegetationRemoval->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbSpatialVegetationRemoval->Location = System::Drawing::Point(423, 233);
			this->cbSpatialVegetationRemoval->Name = L"cbSpatialVegetationRemoval";
			this->cbSpatialVegetationRemoval->Size = System::Drawing::Size(182, 27);
			this->cbSpatialVegetationRemoval->TabIndex = 98;
			this->cbSpatialVegetationRemoval->Text = L"Vegetação Primária";
			this->cbSpatialVegetationRemoval->UseVisualStyleBackColor = true;
			// 
			// cbSpatialBiomass
			// 
			this->cbSpatialBiomass->AutoSize = true;
			this->cbSpatialBiomass->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbSpatialBiomass->Location = System::Drawing::Point(423, 200);
			this->cbSpatialBiomass->Name = L"cbSpatialBiomass";
			this->cbSpatialBiomass->Size = System::Drawing::Size(104, 27);
			this->cbSpatialBiomass->TabIndex = 99;
			this->cbSpatialBiomass->Text = L"Biomassa";
			this->cbSpatialBiomass->UseVisualStyleBackColor = true;
			// 
			// cbSpatialDeforest
			// 
			this->cbSpatialDeforest->AutoSize = true;
			this->cbSpatialDeforest->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbSpatialDeforest->Location = System::Drawing::Point(423, 167);
			this->cbSpatialDeforest->Name = L"cbSpatialDeforest";
			this->cbSpatialDeforest->Size = System::Drawing::Size(151, 27);
			this->cbSpatialDeforest->TabIndex = 100;
			this->cbSpatialDeforest->Text = L"Desmatamento";
			this->cbSpatialDeforest->UseVisualStyleBackColor = true;
			// 
			// tSpatialFinalYear
			// 
			this->tSpatialFinalYear->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSpatialFinalYear->Location = System::Drawing::Point(160, 152);
			this->tSpatialFinalYear->Name = L"tSpatialFinalYear";
			this->tSpatialFinalYear->Size = System::Drawing::Size(59, 20);
			this->tSpatialFinalYear->TabIndex = 93;
			this->tSpatialFinalYear->Text = L"2050";
			this->tSpatialFinalYear->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lSpatialFinalYear
			// 
			this->lSpatialFinalYear->AutoSize = true;
			this->lSpatialFinalYear->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpatialFinalYear->Location = System::Drawing::Point(24, 152);
			this->lSpatialFinalYear->Name = L"lSpatialFinalYear";
			this->lSpatialFinalYear->Size = System::Drawing::Size(134, 23);
			this->lSpatialFinalYear->TabIndex = 89;
			this->lSpatialFinalYear->Text = L"Ano de Término";
			this->lSpatialFinalYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tSpatialInitialYear
			// 
			this->tSpatialInitialYear->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSpatialInitialYear->Location = System::Drawing::Point(160, 115);
			this->tSpatialInitialYear->Name = L"tSpatialInitialYear";
			this->tSpatialInitialYear->Size = System::Drawing::Size(59, 20);
			this->tSpatialInitialYear->TabIndex = 94;
			this->tSpatialInitialYear->Text = L"1960";
			this->tSpatialInitialYear->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lSpatialInitialYear
			// 
			this->lSpatialInitialYear->AutoSize = true;
			this->lSpatialInitialYear->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpatialInitialYear->Location = System::Drawing::Point(24, 113);
			this->lSpatialInitialYear->Name = L"lSpatialInitialYear";
			this->lSpatialInitialYear->Size = System::Drawing::Size(113, 23);
			this->lSpatialInitialYear->TabIndex = 90;
			this->lSpatialInitialYear->Text = L"Ano de Início";
			this->lSpatialInitialYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tSpatialName
			// 
			this->tSpatialName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSpatialName->Location = System::Drawing::Point(245, 54);
			this->tSpatialName->Name = L"tSpatialName";
			this->tSpatialName->Size = System::Drawing::Size(194, 20);
			this->tSpatialName->TabIndex = 95;
			this->tSpatialName->Text = L"NonSpatialModel";
			this->tSpatialName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lSpatialName
			// 
			this->lSpatialName->AutoSize = true;
			this->lSpatialName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpatialName->Location = System::Drawing::Point(24, 52);
			this->lSpatialName->Name = L"lSpatialName";
			this->lSpatialName->Size = System::Drawing::Size(215, 23);
			this->lSpatialName->TabIndex = 91;
			this->lSpatialName->Text = L"Nome do Modelo Espacial";
			this->lSpatialName->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
			this->pbLogo1->Location = System::Drawing::Point(178, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 20;
			this->pbLogo1->TabStop = false;
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
			this->tabComponents->ResumeLayout(false);
			this->tabComponents->PerformLayout();
			this->tabNonSpatial->ResumeLayout(false);
			this->tabNonSpatial->PerformLayout();
			this->tabSpatial->ResumeLayout(false);
			this->tabSpatial->PerformLayout();
			this->tabFileMaker->ResumeLayout(false);
			this->tabFileMaker->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bDeforest_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bBiomass_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bVegetationRemoval_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSecondVegetation_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bDegrad_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bTableData_Click(System::Object^  sender, System::EventArgs^  e);
};
}
