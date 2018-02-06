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
		bool shape = false;
		bool drawn = false;

		int gLUTNumber = 0;
		int gLUTNumberDrawn = 0;

		String^ lLanguage = "";
		String^ gSelectedFile = "";
		String^ gSProjTitle = "";
		String^ gSProjFilter = "";
		String^ gSShapeTitle = "";
		String^ gSShapeFilter = "";
		String^ gSDefaultTime = "";
		String^ gStringDefaultTimeTitle = "";
		String^ gSTimeNotDef = "";
		String^ gSTimeNotDefTitle = "";
		String^ gSFolderTitle = "";
		String^ gSFolder = "";
		String^ gSModelNameTitle = "";
		String^ gSModelName = "";
		String^ gSStartTime = "";
		String^ gSStopTime = "";
		String^ gSCellAreaTitle = "";
		String^ gSCellArea = "";
		String^ gSLayerNameTitle = "";
		String^ gSLayerName = "";
		String^ gSSFileTitle = "";
		String^ gSSFile = "";
		String^ gSUnauthorized = "";
		String^ gSUnauthorizedTitle = "";
		String^ gSExitTitle = "";
		String^ gSExit = "";
		String^ gSSuccessTitle = "";
		String^ gSSuccess = "";
		String^ gSEditing = "";
		String^ gSNewModelTitle = "";
		String^ gSNewModel = "";
		String^ gSOpenModelTitle = "";
		String^ gSMainImportTitle = "";
		String^	gSMainImport = "";
		String^	gSSubModelImportTitle = "";
		String^	gSSubmodelImport = "";
		String^	gSMainLoadTitle = "";
		String^	gSMainLoad = "";
		String^	gSMainFile = "";
		String^	gSSubmodelFile = "";
		String^	gSLuaFile = "";
		String^	gSImportErrorTitle = "";
		String^	gSImportError = "";
		String^ gSImportEquationErrorTitle = "";
		String^ gSImportEquationError = "";
		String^ gSLUTErrorTitle = "";
		String^ gSLUTError = "";
		String^ gSEquationRelationTitle = "";
		String^ gSEquationRelation = "";
		String^ gSFE = "";
		String^ gSFETitle = "";

		array<String^>^ gEquations = gcnew array<String^>(50);
		array<String^>^ gEquationsOut = gcnew array<String^>(50);
		array<String^, 2>^ gEquationsRelation = gcnew array<String^, 2>(50, 50);
		array<String^>^ gParametersValues = gcnew array<String^>(24);
		//[0] = lSelectedFolder->Text;
		//[1] = tModelName->Text;
		//[2] = tNonSpatialName->Text;
		//[3] = tNonSpatialInitialYear->Text;
		//[4] = tNonSpatialFinalYear->Text;
		//[5] = tNonSpatialArea->Text;
		//[6] = cbNonSpatialDeforest->Checked->ToString();
		//[7] = cbNonSpatialBiomass->Checked->ToString();
		//[8] = cbNonSpatialVegetationRemoval->Checked->ToString();
		//[9] = cbNonSpatialSecondaryVegetation->Checked->ToString();
		//[10] = cbNonSpatialDegradation->Checked->ToString();
		//[11] = cbNonSpatialVerbose->Checked->ToString();
		//[12] = tSpatialName->Text;
		//[13] = tSpatialInitialYear->Text;
		//[14] = tSpatialFinalYear->Text;
		//[15] = lSelectedFile->Text;
		//[16] = tSpatialLayerName->Text;
		//[17] = tSpatialCellArea->Text;
		//[18] = cbSpatialDeforest->Checked->ToString();
		//[19] = cbSpatialBiomass->Checked->ToString();
		//[20] = cbSpatialVegetationRemoval->Checked->ToString();
		//[21] = cbSpatialSecondaryVegetation->Checked->ToString();
		//[22] = cbSpatialDegradation->Checked->ToString();
		//[23] = cbSpatialVerbose->Checked->ToString();

	private: System::Windows::Forms::TabControl^  tNovoModelo;
	private: System::Windows::Forms::TabPage^  tabDefModel;
	private: System::Windows::Forms::Label^  lDefinicoesModelo;
	private: System::Windows::Forms::Label^  lArquivos;
	private: System::Windows::Forms::TextBox^  tModelName;
	private: System::Windows::Forms::Label^  lModelName;
	private: System::Windows::Forms::Label^  lSelectedFolder;
	private: System::Windows::Forms::Button^  bSelectFolder;
	private: System::Windows::Forms::Label^  lDirProj;
	private: System::Windows::Forms::TabPage^  tabFileMaker;
	private: System::Windows::Forms::Button^  bRun;
	private: System::Windows::Forms::Label^  lRunModel;
	private: System::Windows::Forms::Button^  bGerarArquivos;
	private: System::Windows::Forms::Label^  lFileMaker;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::TabPage^  tabSpatial;
	private: System::Windows::Forms::TabPage^  tabEquations;
	private: System::Windows::Forms::Label^  lEquations;
	private: System::Windows::Forms::Label^  lTerraview;
	private: System::Windows::Forms::Label^  lShape;
	private: System::Windows::Forms::Button^  bShape;
	private: System::Windows::Forms::Button^  bSelectProject;
	private: System::Windows::Forms::TextBox^  tSpatialCellArea;
	private: System::Windows::Forms::Label^  lSpatialCellArea;
	private: System::Windows::Forms::TextBox^  tSpatialLayerName;
	private: System::Windows::Forms::Label^  lSpatialLayerName;
	private: System::Windows::Forms::Label^  lDatabase;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  arquivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  novoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  abrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sairToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preferênciasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  idiomaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ajudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  luccMEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sobreToolStripMenuItem;
	private: System::Windows::Forms::Label^  lSelectedFile;
	private: System::Windows::Forms::Label^  lHa;
	private: System::Windows::Forms::TextBox^  tFinalYear;
	private: System::Windows::Forms::Label^  lFinalYear;
	private: System::Windows::Forms::TextBox^  tInitialYear;
	private: System::Windows::Forms::Label^  lInitialYear;
	private: System::Windows::Forms::Label^  lSpatialDefinition;
	private: System::Windows::Forms::TabPage^  tabLUT;
	private: System::Windows::Forms::Label^  lLUTLarge;
	private: System::Windows::Forms::DataGridView^  dgLUT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LUTColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ValueColumn;
	private: System::Windows::Forms::Button^  bEquationsManager;
	private: System::Windows::Forms::Label^  lEquationsManager;
	private: System::Windows::Forms::Label^  lTransitions;

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
			this->tFinalYear = (gcnew System::Windows::Forms::TextBox());
			this->lFinalYear = (gcnew System::Windows::Forms::Label());
			this->tInitialYear = (gcnew System::Windows::Forms::TextBox());
			this->lInitialYear = (gcnew System::Windows::Forms::Label());
			this->lDefinicoesModelo = (gcnew System::Windows::Forms::Label());
			this->lArquivos = (gcnew System::Windows::Forms::Label());
			this->tModelName = (gcnew System::Windows::Forms::TextBox());
			this->lModelName = (gcnew System::Windows::Forms::Label());
			this->lSelectedFolder = (gcnew System::Windows::Forms::Label());
			this->bSelectFolder = (gcnew System::Windows::Forms::Button());
			this->lDirProj = (gcnew System::Windows::Forms::Label());
			this->tabSpatial = (gcnew System::Windows::Forms::TabPage());
			this->lHa = (gcnew System::Windows::Forms::Label());
			this->lTerraview = (gcnew System::Windows::Forms::Label());
			this->lShape = (gcnew System::Windows::Forms::Label());
			this->bShape = (gcnew System::Windows::Forms::Button());
			this->bSelectProject = (gcnew System::Windows::Forms::Button());
			this->tSpatialCellArea = (gcnew System::Windows::Forms::TextBox());
			this->lSpatialCellArea = (gcnew System::Windows::Forms::Label());
			this->tSpatialLayerName = (gcnew System::Windows::Forms::TextBox());
			this->lSpatialLayerName = (gcnew System::Windows::Forms::Label());
			this->lDatabase = (gcnew System::Windows::Forms::Label());
			this->lSelectedFile = (gcnew System::Windows::Forms::Label());
			this->lSpatialDefinition = (gcnew System::Windows::Forms::Label());
			this->tabLUT = (gcnew System::Windows::Forms::TabPage());
			this->dgLUT = (gcnew System::Windows::Forms::DataGridView());
			this->LUTColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ValueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lLUTLarge = (gcnew System::Windows::Forms::Label());
			this->tabEquations = (gcnew System::Windows::Forms::TabPage());
			this->lTransitions = (gcnew System::Windows::Forms::Label());
			this->bEquationsManager = (gcnew System::Windows::Forms::Button());
			this->lEquationsManager = (gcnew System::Windows::Forms::Label());
			this->lEquations = (gcnew System::Windows::Forms::Label());
			this->tabFileMaker = (gcnew System::Windows::Forms::TabPage());
			this->bRun = (gcnew System::Windows::Forms::Button());
			this->lRunModel = (gcnew System::Windows::Forms::Label());
			this->bGerarArquivos = (gcnew System::Windows::Forms::Button());
			this->lFileMaker = (gcnew System::Windows::Forms::Label());
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
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
			this->tNovoModelo->SuspendLayout();
			this->tabDefModel->SuspendLayout();
			this->tabSpatial->SuspendLayout();
			this->tabLUT->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgLUT))->BeginInit();
			this->tabEquations->SuspendLayout();
			this->tabFileMaker->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tNovoModelo
			// 
			this->tNovoModelo->Controls->Add(this->tabDefModel);
			this->tNovoModelo->Controls->Add(this->tabSpatial);
			this->tNovoModelo->Controls->Add(this->tabLUT);
			this->tNovoModelo->Controls->Add(this->tabEquations);
			this->tNovoModelo->Controls->Add(this->tabFileMaker);
			this->tNovoModelo->Location = System::Drawing::Point(12, 173);
			this->tNovoModelo->Name = L"tNovoModelo";
			this->tNovoModelo->SelectedIndex = 0;
			this->tNovoModelo->Size = System::Drawing::Size(725, 481);
			this->tNovoModelo->TabIndex = 19;
			this->tNovoModelo->SelectedIndexChanged += gcnew System::EventHandler(this, &NovoModelo::tNovoModelo_SelectedIndexChanged);
			// 
			// tabDefModel
			// 
			this->tabDefModel->Controls->Add(this->tFinalYear);
			this->tabDefModel->Controls->Add(this->lFinalYear);
			this->tabDefModel->Controls->Add(this->tInitialYear);
			this->tabDefModel->Controls->Add(this->lInitialYear);
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
			// tFinalYear
			// 
			this->tFinalYear->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tFinalYear->Location = System::Drawing::Point(248, 296);
			this->tFinalYear->Name = L"tFinalYear";
			this->tFinalYear->Size = System::Drawing::Size(59, 20);
			this->tFinalYear->TabIndex = 91;
			this->tFinalYear->Text = L"2050";
			this->tFinalYear->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tFinalYear->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lFinalYear
			// 
			this->lFinalYear->AutoSize = true;
			this->lFinalYear->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lFinalYear->Location = System::Drawing::Point(58, 295);
			this->lFinalYear->Name = L"lFinalYear";
			this->lFinalYear->Size = System::Drawing::Size(134, 23);
			this->lFinalYear->TabIndex = 88;
			this->lFinalYear->Text = L"Ano de Término";
			this->lFinalYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tInitialYear
			// 
			this->tInitialYear->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tInitialYear->Location = System::Drawing::Point(248, 255);
			this->tInitialYear->Name = L"tInitialYear";
			this->tInitialYear->Size = System::Drawing::Size(59, 20);
			this->tInitialYear->TabIndex = 90;
			this->tInitialYear->Text = L"1960";
			this->tInitialYear->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tInitialYear->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lInitialYear
			// 
			this->lInitialYear->AutoSize = true;
			this->lInitialYear->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lInitialYear->Location = System::Drawing::Point(58, 254);
			this->lInitialYear->Name = L"lInitialYear";
			this->lInitialYear->Size = System::Drawing::Size(113, 23);
			this->lInitialYear->TabIndex = 89;
			this->lInitialYear->Text = L"Ano de Início";
			this->lInitialYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
			this->tModelName->Location = System::Drawing::Point(248, 214);
			this->tModelName->Name = L"tModelName";
			this->tModelName->Size = System::Drawing::Size(194, 20);
			this->tModelName->TabIndex = 66;
			this->tModelName->Text = L"INPEEM_model";
			this->tModelName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tModelName->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lModelName
			// 
			this->lModelName->AutoSize = true;
			this->lModelName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lModelName->Location = System::Drawing::Point(58, 213);
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
			this->lSelectedFolder->Location = System::Drawing::Point(20, 117);
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
			this->bSelectFolder->Click += gcnew System::EventHandler(this, &NovoModelo::bSelectFolder_Click);
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
			// tabSpatial
			// 
			this->tabSpatial->Controls->Add(this->lHa);
			this->tabSpatial->Controls->Add(this->lTerraview);
			this->tabSpatial->Controls->Add(this->lShape);
			this->tabSpatial->Controls->Add(this->bShape);
			this->tabSpatial->Controls->Add(this->bSelectProject);
			this->tabSpatial->Controls->Add(this->tSpatialCellArea);
			this->tabSpatial->Controls->Add(this->lSpatialCellArea);
			this->tabSpatial->Controls->Add(this->tSpatialLayerName);
			this->tabSpatial->Controls->Add(this->lSpatialLayerName);
			this->tabSpatial->Controls->Add(this->lDatabase);
			this->tabSpatial->Controls->Add(this->lSelectedFile);
			this->tabSpatial->Controls->Add(this->lSpatialDefinition);
			this->tabSpatial->Location = System::Drawing::Point(4, 22);
			this->tabSpatial->Name = L"tabSpatial";
			this->tabSpatial->Size = System::Drawing::Size(717, 455);
			this->tabSpatial->TabIndex = 6;
			this->tabSpatial->Text = L"Dados Espaciais";
			this->tabSpatial->UseVisualStyleBackColor = true;
			// 
			// lHa
			// 
			this->lHa->AutoSize = true;
			this->lHa->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lHa->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lHa->Location = System::Drawing::Point(396, 285);
			this->lHa->Name = L"lHa";
			this->lHa->Size = System::Drawing::Size(29, 23);
			this->lHa->TabIndex = 114;
			this->lHa->Text = L"ha";
			this->lHa->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lTerraview
			// 
			this->lTerraview->AutoSize = true;
			this->lTerraview->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lTerraview->Location = System::Drawing::Point(230, 105);
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
			this->lShape->Location = System::Drawing::Point(410, 105);
			this->lShape->Name = L"lShape";
			this->lShape->Size = System::Drawing::Size(58, 23);
			this->lShape->TabIndex = 110;
			this->lShape->Text = L"Shape";
			this->lShape->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// bShape
			// 
			this->bShape->Location = System::Drawing::Point(400, 131);
			this->bShape->Name = L"bShape";
			this->bShape->Size = System::Drawing::Size(75, 23);
			this->bShape->TabIndex = 99;
			this->bShape->Text = L"Selecionar";
			this->bShape->UseVisualStyleBackColor = true;
			this->bShape->Click += gcnew System::EventHandler(this, &NovoModelo::bShape_Click);
			// 
			// bSelectProject
			// 
			this->bSelectProject->Location = System::Drawing::Point(264, 131);
			this->bSelectProject->Name = L"bSelectProject";
			this->bSelectProject->Size = System::Drawing::Size(75, 23);
			this->bSelectProject->TabIndex = 98;
			this->bSelectProject->Text = L"Selecionar";
			this->bSelectProject->UseVisualStyleBackColor = true;
			this->bSelectProject->Click += gcnew System::EventHandler(this, &NovoModelo::bSelectProject_Click);
			// 
			// tSpatialCellArea
			// 
			this->tSpatialCellArea->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSpatialCellArea->Location = System::Drawing::Point(308, 286);
			this->tSpatialCellArea->Name = L"tSpatialCellArea";
			this->tSpatialCellArea->Size = System::Drawing::Size(80, 20);
			this->tSpatialCellArea->TabIndex = 101;
			this->tSpatialCellArea->Text = L"6.25";
			this->tSpatialCellArea->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tSpatialCellArea->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lSpatialCellArea
			// 
			this->lSpatialCellArea->AutoSize = true;
			this->lSpatialCellArea->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpatialCellArea->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lSpatialCellArea->Location = System::Drawing::Point(143, 285);
			this->lSpatialCellArea->Name = L"lSpatialCellArea";
			this->lSpatialCellArea->Size = System::Drawing::Size(157, 23);
			this->lSpatialCellArea->TabIndex = 106;
			this->lSpatialCellArea->Text = L"Tamanho da Célula";
			this->lSpatialCellArea->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tSpatialLayerName
			// 
			this->tSpatialLayerName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tSpatialLayerName->Location = System::Drawing::Point(308, 243);
			this->tSpatialLayerName->Name = L"tSpatialLayerName";
			this->tSpatialLayerName->Size = System::Drawing::Size(192, 20);
			this->tSpatialLayerName->TabIndex = 100;
			this->tSpatialLayerName->Text = L"layer_name";
			this->tSpatialLayerName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tSpatialLayerName->Enter += gcnew System::EventHandler(this, &NovoModelo::textBox_Enter);
			// 
			// lSpatialLayerName
			// 
			this->lSpatialLayerName->AutoSize = true;
			this->lSpatialLayerName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpatialLayerName->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->lSpatialLayerName->Location = System::Drawing::Point(143, 242);
			this->lSpatialLayerName->Name = L"lSpatialLayerName";
			this->lSpatialLayerName->Size = System::Drawing::Size(129, 23);
			this->lSpatialLayerName->TabIndex = 104;
			this->lSpatialLayerName->Text = L"Nome do Layer";
			this->lSpatialLayerName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lDatabase
			// 
			this->lDatabase->AutoSize = true;
			this->lDatabase->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDatabase->Location = System::Drawing::Point(143, 131);
			this->lDatabase->Name = L"lDatabase";
			this->lDatabase->Size = System::Drawing::Size(78, 23);
			this->lDatabase->TabIndex = 102;
			this->lDatabase->Text = L"Arquivo:";
			this->lDatabase->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lSelectedFile
			// 
			this->lSelectedFile->AutoSize = true;
			this->lSelectedFile->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSelectedFile->Location = System::Drawing::Point(146, 180);
			this->lSelectedFile->Name = L"lSelectedFile";
			this->lSelectedFile->Size = System::Drawing::Size(0, 19);
			this->lSelectedFile->TabIndex = 112;
			// 
			// lSpatialDefinition
			// 
			this->lSpatialDefinition->AutoSize = true;
			this->lSpatialDefinition->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lSpatialDefinition->Location = System::Drawing::Point(264, 19);
			this->lSpatialDefinition->Name = L"lSpatialDefinition";
			this->lSpatialDefinition->Size = System::Drawing::Size(184, 26);
			this->lSpatialDefinition->TabIndex = 115;
			this->lSpatialDefinition->Text = L"Definições Espaciais";
			this->lSpatialDefinition->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabLUT
			// 
			this->tabLUT->Controls->Add(this->dgLUT);
			this->tabLUT->Controls->Add(this->lLUTLarge);
			this->tabLUT->Location = System::Drawing::Point(4, 22);
			this->tabLUT->Name = L"tabLUT";
			this->tabLUT->Size = System::Drawing::Size(717, 455);
			this->tabLUT->TabIndex = 8;
			this->tabLUT->Text = L"Tipos de Uso";
			this->tabLUT->UseVisualStyleBackColor = true;
			// 
			// dgLUT
			// 
			this->dgLUT->AllowUserToResizeColumns = false;
			this->dgLUT->AllowUserToResizeRows = false;
			this->dgLUT->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgLUT->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->LUTColumn, this->ValueColumn });
			this->dgLUT->Location = System::Drawing::Point(173, 101);
			this->dgLUT->Name = L"dgLUT";
			this->dgLUT->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgLUT->Size = System::Drawing::Size(369, 246);
			this->dgLUT->TabIndex = 88;
			this->dgLUT->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &NovoModelo::dgLUT_RowsRemoved);
			// 
			// LUTColumn
			// 
			this->LUTColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->LUTColumn->HeaderText = L"Nome do Uso";
			this->LUTColumn->MinimumWidth = 20;
			this->LUTColumn->Name = L"LUTColumn";
			// 
			// ValueColumn
			// 
			this->ValueColumn->HeaderText = L"Valor Espacial";
			this->ValueColumn->Name = L"ValueColumn";
			// 
			// lLUTLarge
			// 
			this->lLUTLarge->AutoSize = true;
			this->lLUTLarge->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lLUTLarge->Location = System::Drawing::Point(259, 20);
			this->lLUTLarge->Name = L"lLUTLarge";
			this->lLUTLarge->Size = System::Drawing::Size(196, 26);
			this->lLUTLarge->TabIndex = 78;
			this->lLUTLarge->Text = L"Tipos de Uso da Terra";
			this->lLUTLarge->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabEquations
			// 
			this->tabEquations->AutoScroll = true;
			this->tabEquations->Controls->Add(this->lTransitions);
			this->tabEquations->Controls->Add(this->bEquationsManager);
			this->tabEquations->Controls->Add(this->lEquationsManager);
			this->tabEquations->Controls->Add(this->lEquations);
			this->tabEquations->Location = System::Drawing::Point(4, 22);
			this->tabEquations->Name = L"tabEquations";
			this->tabEquations->Size = System::Drawing::Size(717, 455);
			this->tabEquations->TabIndex = 7;
			this->tabEquations->Text = L"Equações";
			this->tabEquations->UseVisualStyleBackColor = true;
			// 
			// lTransitions
			// 
			this->lTransitions->AutoSize = true;
			this->lTransitions->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lTransitions->Location = System::Drawing::Point(301, 149);
			this->lTransitions->Name = L"lTransitions";
			this->lTransitions->Size = System::Drawing::Size(93, 23);
			this->lTransitions->TabIndex = 105;
			this->lTransitions->Text = L"Transições";
			this->lTransitions->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// bEquationsManager
			// 
			this->bEquationsManager->Location = System::Drawing::Point(311, 95);
			this->bEquationsManager->Name = L"bEquationsManager";
			this->bEquationsManager->Size = System::Drawing::Size(75, 23);
			this->bEquationsManager->TabIndex = 104;
			this->bEquationsManager->Text = L"Gerenciar";
			this->bEquationsManager->UseVisualStyleBackColor = true;
			this->bEquationsManager->Click += gcnew System::EventHandler(this, &NovoModelo::bEquationsManager_Click);
			// 
			// lEquationsManager
			// 
			this->lEquationsManager->AutoSize = true;
			this->lEquationsManager->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lEquationsManager->Location = System::Drawing::Point(64, 93);
			this->lEquationsManager->Name = L"lEquationsManager";
			this->lEquationsManager->Size = System::Drawing::Size(166, 23);
			this->lEquationsManager->TabIndex = 103;
			this->lEquationsManager->Text = L"Gerenciar Equações";
			this->lEquationsManager->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lEquations
			// 
			this->lEquations->AutoSize = true;
			this->lEquations->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lEquations->Location = System::Drawing::Point(229, 26);
			this->lEquations->Name = L"lEquations";
			this->lEquations->Size = System::Drawing::Size(236, 26);
			this->lEquations->TabIndex = 76;
			this->lEquations->Text = L"Configuração de Formulas";
			this->lEquations->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->bRun->Location = System::Drawing::Point(263, 281);
			this->bRun->Name = L"bRun";
			this->bRun->Size = System::Drawing::Size(185, 47);
			this->bRun->TabIndex = 91;
			this->bRun->Text = L"Rodar Modelo";
			this->bRun->UseVisualStyleBackColor = true;
			this->bRun->Visible = false;
			this->bRun->Click += gcnew System::EventHandler(this, &NovoModelo::bRun_Click);
			// 
			// lRunModel
			// 
			this->lRunModel->AutoSize = true;
			this->lRunModel->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lRunModel->Location = System::Drawing::Point(280, 234);
			this->lRunModel->Name = L"lRunModel";
			this->lRunModel->Size = System::Drawing::Size(151, 26);
			this->lRunModel->TabIndex = 90;
			this->lRunModel->Text = L"Rodar o Modelo";
			this->lRunModel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lRunModel->Visible = false;
			// 
			// bGerarArquivos
			// 
			this->bGerarArquivos->Location = System::Drawing::Point(263, 74);
			this->bGerarArquivos->Name = L"bGerarArquivos";
			this->bGerarArquivos->Size = System::Drawing::Size(185, 47);
			this->bGerarArquivos->TabIndex = 89;
			this->bGerarArquivos->Text = L"Gerar Arquivos";
			this->bGerarArquivos->UseVisualStyleBackColor = true;
			this->bGerarArquivos->Click += gcnew System::EventHandler(this, &NovoModelo::bGerarArquivos_Click);
			// 
			// lFileMaker
			// 
			this->lFileMaker->AutoSize = true;
			this->lFileMaker->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lFileMaker->Location = System::Drawing::Point(273, 29);
			this->lFileMaker->Name = L"lFileMaker";
			this->lFileMaker->Size = System::Drawing::Size(165, 26);
			this->lFileMaker->TabIndex = 87;
			this->lFileMaker->Text = L"Gerar os Arquivos";
			this->lFileMaker->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(178, 25);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 20;
			this->pbLogo1->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->arquivoToolStripMenuItem,
					this->preferênciasToolStripMenuItem, this->ajudaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(745, 24);
			this->menuStrip1->TabIndex = 21;
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
			this->novoToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::novoToolStripMenuItem_Click);
			// 
			// abrirToolStripMenuItem
			// 
			this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			this->abrirToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->abrirToolStripMenuItem->Text = L"Abrir";
			this->abrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::abrirToolStripMenuItem_Click);
			// 
			// sairToolStripMenuItem
			// 
			this->sairToolStripMenuItem->Name = L"sairToolStripMenuItem";
			this->sairToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->sairToolStripMenuItem->Text = L"Sair";
			this->sairToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::sairToolStripMenuItem_Click);
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
			this->idiomaToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::idiomaToolStripMenuItem_Click);
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
			this->luccMEToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::luccMEToolStripMenuItem_Click);
			// 
			// sobreToolStripMenuItem
			// 
			this->sobreToolStripMenuItem->Name = L"sobreToolStripMenuItem";
			this->sobreToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->sobreToolStripMenuItem->Text = L"Sobre";
			this->sobreToolStripMenuItem->Click += gcnew System::EventHandler(this, &NovoModelo::sobreToolStripMenuItem_Click);
			// 
			// NovoModelo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(745, 677);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pbLogo1);
			this->Controls->Add(this->tNovoModelo);
			this->Name = L"NovoModelo";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Criando um Novo Modelo";
			this->Load += gcnew System::EventHandler(this, &NovoModelo::NovoModelo_Load);
			this->tNovoModelo->ResumeLayout(false);
			this->tabDefModel->ResumeLayout(false);
			this->tabDefModel->PerformLayout();
			this->tabSpatial->ResumeLayout(false);
			this->tabSpatial->PerformLayout();
			this->tabLUT->ResumeLayout(false);
			this->tabLUT->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgLUT))->EndInit();
			this->tabEquations->ResumeLayout(false);
			this->tabEquations->PerformLayout();
			this->tabFileMaker->ResumeLayout(false);
			this->tabFileMaker->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void checkLanguage();
		System::Void checkEquations();
		System::Void addEquations();
		System::Void checkLUTNames();
		System::Int16 countCaracter(String^ source, char caracter);
		System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
		System::Void comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void bSelectFolder_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void bSelectProject_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void NovoModelo_Load(System::Object^  sender, System::EventArgs^  e);
		System::Void bShape_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void idiomaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void novoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void abrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void bGerarArquivos_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void bRun_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void luccMEToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void tNovoModelo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void bEquationsManager_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void dgLUT_RowsRemoved(System::Object^  sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^  e);
	};
}
