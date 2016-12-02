#include "stdafx.h"
#include "NovoModelo.h"
#include "Function.h"
#include "LanguageForm.h"
#include "AboutForm.h"
#include "ComponentDeforest.h"
#include "ComponentBiomass.h"
#include "ComponentDegradation.h"
#include "ComponentSecondaryVegetation.h"
#include "ComponentVegetationRemoval.h"
#include "NonSpatialDataTableForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

System::Void INPEEM::NovoModelo::checkLanguage()
{
	//Select Strings according to the selected language
	if (lLanguage == "en") {
		//Form
		this->Text = "INPE-EM - Creating a new model";

		//Menu
		arquivoToolStripMenuItem->Text = "File";
		novoToolStripMenuItem->Text = "New";
		abrirToolStripMenuItem->Text = "Open";
		sairToolStripMenuItem->Text = "Exit";
		preferênciasToolStripMenuItem->Text = "Preferences";
		idiomaToolStripMenuItem->Text = "Language";
		ajudaToolStripMenuItem->Text = "Help";
		sobreToolStripMenuItem->Text = "About";
		
		//tabModel
		tabDefModel->Text = "Model Definitions";
		lArquivos->Text = "    Files";
		lDirProj->Text = "Folder to Save the Model";
		bSelectFolder->Text = "Select";
		lDefinicoesModelo->Text = "   Model Definitions";
		lModelName->Text = "Model Name";
		
		//tabComponents
		tabComponents->Text = "Components";
		lComponentes->Text = "Components Configuration";
		bDeforest->Text = "Deforest";
		bBiomass->Text = "Biomass";
		bVegetationRemoval->Text = "Vegetation Removal";
		bSecondVegetation->Text = "Secondary Vegetation";
		bDegrad->Text = "Degradation";

		//tabNonSpatialModel
		tabNonSpatial->Text = "Non Spatial Model";
		lNonSpatialName->Text = "Name of Non Spatial Model";
		cbNonSpatialVerbose->Text = "Verbose";
		lNonSpatialInitialYear->Text = "Initial Year";
		lNonSpatialFinalYear->Text = "Final Year";
		lNonSpatialArea->Text = "Total Area";
		lNonSpatialComponentSelection->Text = "Components Selection";
		cbNonSpatialBiomass->Text = "Biomass";
		cbNonSpatialDeforest->Text = "Deforest";
		cbNonSpatialDegradation->Text = "Degradation";
		cbNonSpatialSecondaryVegetation->Text = "Secondary Vegetation";
		cbNonSpatialVegetationRemoval->Text = "Vegetation Removal";
		bTableData->Text = "Non Spatial Data Table";
		
		//tabSpatialModel
		tabSpatial->Text = "Spatial Model";
		lSpatialName->Text = "Name of Spatial Model";
		cbNonSpatialVerbose->Text = "Verbose";
		lSpatialInitialYear->Text = "Initial Year";
		lSpatialFinalYear->Text = "Final Year";
		lDatabase->Text = "File:";
		lTerraview->Text = "Terraview Project";
		lSpatialLayerName->Text = "Layer Name";
		lSpatialCellArea->Text = "Cell Size";
		lSpatialComponentSelection->Text = "Components Selection";
		cbSpatialBiomass->Text = "Biomass";
		cbSpatialDeforest->Text = "Deforest";
		cbSpatialDegradation->Text = "Degradation";
		cbSpatialSecondaryVegetation->Text = "Secondary Vegetation";
		cbSpatialVegetationRemoval->Text = "Vegetation Removal";
				
		//tabFileMaker
		lFileMaker->Text = "     Files Maker";
		bGerarArquivos->Text = "Make Files";
		lRunModel->Text = "       Run Model";
		bRun->Text = "Run Model";

		//Strings
		gSProjTitle = "Select a Project File";
		gSProjFilter = "Terraview Project (*.tview)|*.tview";
		gSShape = "Shape File";
		gSShapeTitle = "Select a Shape File";
		gSShapeFilter = "Shape File (*.shp)|*.shp";
		gSDefaultTime = "Using defalut time for the simulation.\nDo you want to proceed?";
		gStringDefaultTimeTitle = "Using Default Time";
		gSTimeNotDef = "The suimulation time (start and end) must be defined.";
		gSTimeNotDefTitle = "Error - Initial and Final time not informed";
		gSCBiomassName = "Component - Biomass";
		gSCDeforestName = "Component - Deforest";
		gSCVRName = "Component - Vegetation Removal";
		gSCSVName = "Component - Secondary Vegetation";
		gSCDegradName = "Component - Degradation";
		gSModelSelectTitle = "Error - Model Type not Selected";
		gSModelSelect = "A Model Type Must be Selected on Files Maker.";
		gSFolderTitle = "Error - Project folder is missing";
		gSFolder = "Project folder not selected in Model Definition.";
		gSModelNameTitle = "Error - Model Name is missing";
		gSModelName = "Model Name not defined in Model Definition.";
		gSNSModelName = "Non Spatial Model Name not defined in Non Spatial Model.";
		gSSModelName = "Spatial Model Name not defined in Spatial Model.";
		gSStartTimeTitle = "Error - Initial Year is missing";
		gSNSStartTime = "Initial Year not defined in Non Spatial Model.";
		gSStartTime = "Initial Year not defined in Spatial Model.";
		gSStopTimeTitle = "Error - Final Year is missing";
		gSNSStopTime = "Final Year not defined in Non Spatial Model.";
		gSStopTime = "Final Year not defined in Spatial Model.";
		gSNSAreaTitle = "Error - Non Spatial Model Total Area is missing";
		gSNSArea = "Total Area not defined";
		gSNSTableDataTitle = "Error - Non Spatial Data Table is missing";
		gSNSTableData = "Non Spatial Data Table not defined in Non Spatial Model"; 
		gSSFileTitle = "Error - Spatial Data is missing";
		gSSFile = "A Shape file or Terraview Project must be selected in Spatial Model.";
		gSCellAreaTitle = "Error - Cell Area is missing";
		gSCellArea = "Cell Are not define in Spatial Model.";
		gSLayerNameTitle = "Error - Layer Name is missing";
		gSLayerName = "Layer Name not defined in Spatial Model";
		gSUnauthorized = "You do not have writting permission on the selected folder.\nTry a different one or run LuccME as admin.";
		gSUnauthorizedTitle = "Error - Writting Permimission";

		//Combo Box
		cbModelType->Items->Clear();
		cbModelType->Items->Add("Non Spatial Model");
		cbModelType->Items->Add("Spatial Model");
		cbModelType->Items->Add("Combine Model");
	}
	else {
		//Form
		this->Text = "INPE-EM - Criando um novo modelo";
		
		//Menu
		arquivoToolStripMenuItem->Text = "Arquivo";
		novoToolStripMenuItem->Text = "Novo";
		abrirToolStripMenuItem->Text = "Abrir";
		sairToolStripMenuItem->Text = "Sair";
		preferênciasToolStripMenuItem->Text = "Preferências";
		idiomaToolStripMenuItem->Text = "Idioma";
		ajudaToolStripMenuItem->Text = "Ajuda";
		sobreToolStripMenuItem->Text = "Sobre";
		
		//tabModel
		tabDefModel->Text = "Definições do Modelo";
		lArquivos->Text = "Arquivos";
		lDirProj->Text = "Pasta para Salvar o Modelo";
		bSelectFolder->Text = "Selecionar";
		lDefinicoesModelo->Text = "Definições do Modelo";
		lModelName->Text = "Nome do Modelo";
		
		//tabComponents
		tabComponents->Text = "Componentes";
		lComponentes->Text = "Configure os Componentes";
		bDeforest->Text = "Desmatamento";
		bBiomass->Text = "Biomassa";
		bVegetationRemoval->Text = "Vegetação Primária";
		bSecondVegetation->Text = "Vegetação Secundária";
		bDegrad->Text = "Degradação";
		
		//tabNonSpatialModel
		tabNonSpatial->Text = "Modelo Não Espacial";
		lNonSpatialName->Text = "Nome do Modelo Não Espacial";
		cbNonSpatialVerbose->Text = "Verboso";
		lNonSpatialInitialYear->Text = "Ano de Início";
		lNonSpatialFinalYear->Text = "Ano de Término";
		lNonSpatialArea->Text = "Área Total";
		lNonSpatialComponentSelection->Text = "Seleção de Componentes";
		cbNonSpatialBiomass->Text = "Biomassa";
		cbNonSpatialDeforest->Text = "Desmatamento";
		cbNonSpatialDegradation->Text = "Degradação";
		cbNonSpatialSecondaryVegetation->Text = "Vegetação Secundária";
		cbNonSpatialVegetationRemoval->Text = "Vegetação Primária";
		bTableData->Text = "Tabela de Dados Não Espaciais";
		
		//tabSpatialModel
		tabSpatial->Text = "Modelo Espacial";
		lSpatialName->Text = "Nome do Modelo Espacial";
		cbNonSpatialVerbose->Text = "Verboso";
		lSpatialInitialYear->Text = "Ano de Início";
		lSpatialFinalYear->Text = "Ano de Término";
		lTerraview->Text = "Projeto Terraview";
		lDatabase->Text = "Arquivo:";
		lSpatialLayerName->Text = "Nome do Layer";
		lSpatialCellArea->Text = "Tamanho da Célula";
		lSpatialComponentSelection->Text = "Seleção de Componentes";
		cbSpatialBiomass->Text = "Biomassa";
		cbSpatialDeforest->Text = "Desmatamento";
		cbSpatialDegradation->Text = "Degradação";
		cbSpatialSecondaryVegetation->Text = "Vegetação Secundária";
		cbSpatialVegetationRemoval->Text = "Vegetação Primária";
	
		//tabFileMaker
		lFileMaker->Text = "Gerar os Arquivos";
		bGerarArquivos->Text = "Gerar Arquivos";
		lRunModel->Text = "Rodar o Modelo";
		bRun->Text = "Rodar Modelo";

		//String
		gSProjTitle = "Selecione um Arquivo de Projeto";
		gSProjFilter = "Projeto Terraview (*.tview)|*.tview";
		gSShape = "Arquivo Shape";
		gSShapeTitle = "Escolha o arquivo Shape";
		gSShapeFilter = "Arquivo Shape (*.shp)|*.shp";
		gSDefaultTime = "Utilizando tempo de simulação padrão.\nDeseja continuar?";
		gStringDefaultTimeTitle = "Utilizando Tempo Padrão";
		gSTimeNotDef = "Os tempos da Simulação (inicial e final) devem ser definidos.";
		gSTimeNotDefTitle = "Erro - Tempos inicial e final não informados.";
		gSCBiomassName = "Componente - Biomassa";
		gSCDeforestName = "Componente - Desmatamento";
		gSCVRName = "Componente - Vegetação Primária";
		gSCSVName = "Componente - Vegetação Secundária";
		gSCDegradName = "Componente - Degradação";
		gSModelSelectTitle = "Erro - Tipo de Modelo não Selecionado";
		gSModelSelect = "Um Tipo de Modelo deve ser selecionado em Gerar Arquivos.";
		gSFolderTitle = "Erro - Pasta do projeto não selecionada";
		gSFolder = "Pasta do projeto não selecionada em Definições do Modelo.";
		gSModelNameTitle = "Erro - Nome do Modelo não definido";
		gSModelName = "Nome do Modelo não definido em Definições do Modelo.";
		gSNSModelName = "Nome do Modelo Não Espacial não definido em Modelo Não Espacial.";
		gSSModelName = "Nome do Modelo Espacial não definido em Modelo Espacial.";
		gSStartTimeTitle = "Erro - Ano de Início não preenchido";
		gSNSStartTime = "Ano de Início não definido em Modelo Não Espacial.";
		gSStartTime = "Ano de Início não definido em Modelo Espacial.";
		gSStopTimeTitle = "Erro - Ano de Termino não preenchido";
		gSNSStopTime = "Ano de Termino não definido em Modelo Não Espacial.";
		gSStopTime = "Ano de Termino não definido em Modelo Espacial.";
		gSNSAreaTitle = "Erro - Área Total do Modelo Não Espacial não definido";
		gSNSArea = "Área Total não definida em Modelo Não Espacial.";
		gSNSTableDataTitle = "Erro - Non Spatial Data Table não preenchido";
		gSNSTableData = "Non Spatial Data Table não definida em Modelo Não Espacial.";
		gSSFileTitle = "Erro - Dado espacial não selecionado";
		gSSFile = "Um arquivo Shape ou um Projeto Terraview deve ser selecionado em Modelo Espacial";
		gSCellAreaTitle = "Erro - Cell Area não definido";
		gSCellArea = "Cell Are não definido no Modelo Espacial.";
		gSLayerNameTitle = "Erro - Nome do Layer não preenchido";
		gSLayerName = "Nome do Layer não definido em MOdelo Espacial";
		gSUnauthorized = "Você não possui permissão de escrita no diretório selecionado.\nEscolha outro diretório ou execute o LuccME como administrador.";
		gSUnauthorizedTitle = "Erro - Permissão de escrita";

		//Combo Box
		cbModelType->Items->Clear();
		cbModelType->Items->Add("Modelo Não Spacial");
		cbModelType->Items->Add("Modelo Espacial");
		cbModelType->Items->Add("Modelo Combinado");
	}
}

System::Void INPEEM::NovoModelo::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::NovoModelo::NovoModelo_Load(System::Object^  sender, System::EventArgs^  e)
{
	checkLanguage();
	NovoModelo::Update();
}

Void INPEEM::NovoModelo::bDeforest_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lDeforest = gcnew cReturn();
	lDeforest->Language = lLanguage;
	
	if (gDeforest != "") {
		lDeforest->Return = gDeforest;
	}
	
	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lDeforest);
	deforestForm->Text = gSCDeforestName;
	deforestForm->ShowDialog();

	if (lDeforest->Return != "") {
		gDeforest = lDeforest->Return;
		showReturnDeforest();
	}
}

Void INPEEM::NovoModelo::bBiomass_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lBiomass = gcnew cReturn();
	lBiomass->Language = lLanguage;

	if (gBiomass != "") {
		lBiomass->Return = gBiomass;
	}

	ComponentBiomass^ biomassForm = gcnew ComponentBiomass(lBiomass);
	biomassForm->Text = gSCBiomassName;
	biomassForm->ShowDialog();

	if (lBiomass->Return != "") {
		gBiomass = lBiomass->Return;
		showReturnBiomass();
	}
}

Void INPEEM::NovoModelo::bVegetationRemoval_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lVegetationRemoval = gcnew cReturn();
	lVegetationRemoval->Language = lLanguage;

	if (gVegetationRemoval != "") {
		lVegetationRemoval->Return = gVegetationRemoval;
	}

	ComponentVegetationRemoval^ vegetationRemovalForm = gcnew ComponentVegetationRemoval(lVegetationRemoval);
	vegetationRemovalForm->Text = gSCVRName;
	vegetationRemovalForm->ShowDialog();

	if (lVegetationRemoval->Return != "") {
		gVegetationRemoval = lVegetationRemoval->Return;
		showReturnVegetationRemoval();
	}
}

Void INPEEM::NovoModelo::bSecondVegetation_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lSecondaryVegetation = gcnew cReturn();
	lSecondaryVegetation->Language = lLanguage;

	if (gSecondaryVegetation != "") {
		lSecondaryVegetation->Return = gSecondaryVegetation;
	}

	ComponentSecondaryVegetation^ secondaryVegetationForm = gcnew ComponentSecondaryVegetation(lSecondaryVegetation);
	secondaryVegetationForm->Text = gSCSVName;
	secondaryVegetationForm->ShowDialog();

	if (lSecondaryVegetation->Return != "") {
		gSecondaryVegetation = lSecondaryVegetation->Return;
		showReturnSecondaryVegetation();
	}
}

Void INPEEM::NovoModelo::bDegrad_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lDegradation = gcnew cReturn();
	lDegradation->Language = lLanguage;

	if (gDegradation != "") {
		lDegradation->Return = gDegradation;
	}

	ComponentDegradation^ degradForm = gcnew ComponentDegradation(lDegradation);
	degradForm->Text = gSCDegradName;
	degradForm->ShowDialog();

	if (lDegradation->Return != "") {
		gDegradation = lDegradation->Return;
		showReturnDegradation();
	}
}

Void INPEEM::NovoModelo::bTableData_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturnNSDTF^ lNonSpatialTables = gcnew cReturnNSDTF();
	bool check = true;
	
	if (tNonSpatialInitialYear->Text != "" && tNonSpatialFinalYear->Text != "") {
		if (tNonSpatialInitialYear->ForeColor != System::Drawing::Color::Black || tNonSpatialFinalYear->ForeColor != System::Drawing::Color::Black) {
			if (MessageBox::Show(gSDefaultTime, gStringDefaultTimeTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == INPEEM::DialogResult::No) {
				check = false;
			}
		}
	}
	else {
		MessageBox::Show(gSTimeNotDef, gSTimeNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		check = false;

	}

	if (check) {
		lNonSpatialTables->StartTime = tNonSpatialInitialYear->Text;
		lNonSpatialTables->YearsForSimulation = Convert::ToInt16(tNonSpatialFinalYear->Text) - Convert::ToInt16(tNonSpatialInitialYear->Text) + 1;
		lNonSpatialTables->Language = lLanguage;

		if (gNonSpatialTables != "") {
			lNonSpatialTables->Return = gNonSpatialTables;
		}
		
		NonSpatialDataTableForm^ nonSpatialDataTableForm = gcnew NonSpatialDataTableForm(lNonSpatialTables);
		nonSpatialDataTableForm->ShowDialog();

		if (lNonSpatialTables->Return != "") {
			gNonSpatialTables = lNonSpatialTables->Return;
			showReturnNonSpatialDataTable();
		}
	}
}

Void INPEEM::NovoModelo::bSelectFolder_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Open the dialog to select a folder and return the path
	INPEEM::FolderBrowserDialog^ modelFolder = gcnew FolderBrowserDialog();

	if (modelFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		lSelectedFolder->Text = modelFolder->SelectedPath;
	}
}

Void INPEEM::NovoModelo::sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	AboutForm^ aboutForm = gcnew AboutForm(lLanguage);
	aboutForm->ShowInTaskbar = false;
	aboutForm->ShowDialog();
}

Void INPEEM::NovoModelo::bSelectProject_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Open the dialog to select the access database and return the path
	INPEEM::OpenFileDialog^ projFile = gcnew OpenFileDialog;
	projFile->Title = gSProjTitle;
	projFile->Multiselect = false;
	projFile->Filter = gSProjFilter;
	projFile->FilterIndex = 1;
	projFile->ShowHelp = true;

	if (projFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		gSelectedFile = projFile->FileName;
		lSelectedFile->Text = gSelectedFile;
		shape = false;
		tSpatialLayerName->Enabled = true;
	}
}

System::Void INPEEM::NovoModelo::bShape_Click(System::Object^  sender, System::EventArgs^  e)
{
	//Open the dialog to select the access database and return the path
	INPEEM::OpenFileDialog^ shapeFile = gcnew OpenFileDialog;
	shapeFile->Title = gSShapeTitle;
	shapeFile->Multiselect = false;
	shapeFile->Filter = gSShapeFilter;
	shapeFile->FilterIndex = 1;
	shapeFile->ShowHelp = true;

	if (shapeFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		gSelectedFile = shapeFile->FileName;
		lSelectedFile->Text = gSelectedFile;
		shape = true;
		tSpatialLayerName->Enabled = false;
	}
}

System::Void INPEEM::NovoModelo::showReturnNonSpatialDataTable()
{
	array<String^>^ auxNonSpatialTable = gNonSpatialTables->Split(';'); //Will divide in area, halflife and degrad (2 semicons)

	bool nsArea = false;
	bool nsHalfLife = false;
	bool nsDegrad = false;

	int numberNSDataTableUsed = 0;
	int sizeNSData = 0;
	int sizeNSArea = auxNonSpatialTable[NSAREA]->Length;
	int sizeNSHalfLife = auxNonSpatialTable[NSHALFLIFE]->Length;
	int sizeNSDegrad = auxNonSpatialTable[NSDEGRAD]->Length;

	if (sizeNSArea > 0) {
		sizeNSData = auxNonSpatialTable[NSAREA]->Split(',')->Length;
	} else if (sizeNSHalfLife > 0) {
		sizeNSData = auxNonSpatialTable[NSHALFLIFE]->Split(',')->Length;
	} else if (sizeNSDegrad > 0) {
		sizeNSData = auxNonSpatialTable[NSDEGRAD]->Split(',')->Length;
	}

	if (sizeNSArea > 0) {
		nsArea = true;
		numberNSDataTableUsed++;
	}

	if (sizeNSHalfLife > 0) {
		nsHalfLife = true;
		numberNSDataTableUsed++;
	}

	if (sizeNSDegrad > 0) {
		nsDegrad = true;
		numberNSDataTableUsed++;
	}

	int count = 0;
	array<String^>^ lines = gcnew array<String^>((sizeNSData * numberNSDataTableUsed) + (numberNSDataTableUsed * NSHEADER));

	if (nsArea) {
		lines[count] = "Area =";
		count++;
		lines[count] = "{";
		count++;
		for (int i = 0; i < sizeNSArea; i++) {
			lines[count] += auxNonSpatialTable[NSAREA][i];
			if (auxNonSpatialTable[NSAREA][i] == ',') {
				count++;
			}
		}
		count++;
		if (nsHalfLife || nsDegrad) {
			lines[count] = "},";
			count++;
		}
		else {
			lines[count] = "}";
		}
	}

	if (nsHalfLife) {
		lines[count] = "HalfLife =";
		count++;
		lines[count] = "{";
		count++;
		for (int i = 0; i < sizeNSHalfLife; i++) {
			lines[count] += auxNonSpatialTable[NSHALFLIFE][i];
			if (auxNonSpatialTable[NSHALFLIFE][i] == ',') {
				count++;
			}
		}
		count++;
		if (nsDegrad) {
			lines[count] = "},";
			count++;
		}
		else {
			lines[count] = "}";
		}
	}

	if (nsDegrad) {
		lines[count] = "Degrad =";
		count++;
		lines[count] = "{";
		count++;
		for (int i = 0; i < sizeNSDegrad; i++) {
			lines[count] += auxNonSpatialTable[NSDEGRAD][i];
			if (auxNonSpatialTable[NSDEGRAD][i] == ',') {
				count++;
			}
		}
		count++;
		lines[count] = "}";
	}

	tbTableData->Lines = lines;
}

System::Void INPEEM::NovoModelo::showReturnBiomass()
{
	array<String^>^ auxBiomass = gBiomass->Split(';');
	array<String^>^ lines = gcnew array<String^>(BIOMASSLINES);

	lines[0] = "B1 = ";
	lines[1] = "{";
	lines[2] = "name = \"" + auxBiomass[0] + "\",";
	lines[3] = "description = \"" + auxBiomass[1] + "\",";
	lines[4] = "";
	lines[5] = "averAGB = " + auxBiomass[2] + ",";
	lines[6] = "averBGBPercAGB = " + auxBiomass[3] + ",";
	lines[7] = "averLitterPercAGB = " + auxBiomass[4] + ",";
	lines[8] = "averDeadWoodPercAGB = " + auxBiomass[5] + ",";
	lines[9] = "";
	lines[10] = "averFactorB_C = " + auxBiomass[6] + ",";
	lines[11] = "averFactorB_CO2 = " + auxBiomass[7] + ",";
	lines[12] = "averFactorB_CO2_fire = " + auxBiomass[8] + ",";
	lines[13] = "averFactorB_CH4_fire = " + auxBiomass[9] + ",";
	lines[14] = "averFactorB_N2O_fire = " + auxBiomass[10] + ",";
	lines[15] = "averFactorB_NOx_fire = " + auxBiomass[11] + ",";
	lines[16] = "averFactorB_CO_fire = " + auxBiomass[12];
	lines[17] = "}";

	tbBiomass->Lines = lines;
}

System::Void INPEEM::NovoModelo::showReturnDeforest()
{
	array<String^>^ auxDeforest = gDeforest->Split(';');
	array<String^>^ lines = gcnew array<String^>(DEFORESTLINES);

	lines[0] = "D1 = ";
	lines[1] = "{";
	lines[2] = "name = \"" + auxDeforest[0] + "\",";
	lines[3] = "description = \"" + auxDeforest[1] + "\",";
	lines[4] = "initialArea = " + auxDeforest[2] + ",";
	lines[5] = "TotalNoData = " + auxDeforest[3];
	lines[6] = "}";

	tbDeforest->Lines = lines;
}

System::Void INPEEM::NovoModelo::showReturnDegradation()
{
	array<String^>^ auxDegradation = gDegradation->Split(';');
	array<String^>^ lines = gcnew array<String^>(DEGRADATIONLINES);

	lines[0] = "DG1 = ";
	lines[1] = "{";
	lines[2] = "name = \"" + auxDegradation[0] + "\",";
	lines[3] = "description = \"" + auxDegradation[1] + "\",";
	
	if (auxDegradation[2] == "true") {
		lines[4] = "save = true,";
	}
	else {
		lines[4] = "save = false,";
	}
	
	lines[5] = "";
	lines[6] = "averAGB_loss = " + auxDegradation[3] + ",";
	lines[7] = "averBGB_loss = " + auxDegradation[4] + ",";
	lines[8] = "averDeadWood_loss = " + auxDegradation[5] + ",";
	lines[9] = "";
	lines[10] = "averAGB_percReduction = " + auxDegradation[6] + ",";
	lines[11] = "averPeriodRegrow = " + auxDegradation[7] + ",";
	lines[12] = "averLimiarDegradYears = " + auxDegradation[8] + ",";
	lines[13] = "averLimiarDegradLoss = " + auxDegradation[9];
	lines[14] = "}";

	tbDegrad->Lines = lines;
}

System::Void INPEEM::NovoModelo::showReturnSecondaryVegetation()
{
	array<String^>^ auxSecondaryVegetatin = gSecondaryVegetation->Split(';');
	array<String^>^ lines = gcnew array<String^>(SECONDARYVEGETATIONLINES);

	lines[0] = "SV1 = ";
	lines[1] = "{";
	lines[2] = "name = \"" + auxSecondaryVegetatin[0] + "\",";
	lines[3] = "description = \"" + auxSecondaryVegetatin[1] + "\",";

	if (auxSecondaryVegetatin[2] == "true") {
		lines[4] = "save = true,";
	}
	else {
		lines[4] = "save = false,";
	}

	lines[5] = "";
	lines[6] = "averHalfLife = " + auxSecondaryVegetatin[3] + ",";
	lines[7] = "averAreaPercVegSec = " + auxSecondaryVegetatin[4] + ",";
	lines[8] = "averAreaAccPercVegSec = " + auxSecondaryVegetatin[5] + ",";
	lines[9] = "averRecoveryPeriod1Perc = " + auxSecondaryVegetatin[6] + ",";
	lines[10] = "averRecoveryPeriod1 = " + auxSecondaryVegetatin[7] + ",";
	lines[11] = "averRecoveryPeriod2Perc = " + auxSecondaryVegetatin[8] + ",";
	lines[12] = "averRecoveryPeriod2 = " + auxSecondaryVegetatin[9] + ",";
	lines[13] = "averAgriculturalUseCycle = " + auxSecondaryVegetatin[10] + ",";
	lines[14] = "averInitialAbandonmentCycle = " + auxSecondaryVegetatin[11] + ",";
	lines[15] = "averBGBpercBGB = " + auxSecondaryVegetatin[12];
	lines[16] = "}";

	tbSecondVegetation->Lines = lines;
}

System::Void INPEEM::NovoModelo::showReturnVegetationRemoval()
{
	array<String^>^ auxVegetationRemoval = gVegetationRemoval->Split(';');
	array<String^>^ lines = gcnew array<String^>(VEGETATIONREMOVALLINES);

	lines[0] = "VR1 = ";
	lines[1] = "{";
	lines[2] = "name = \"" + auxVegetationRemoval[0] + "\",";
	lines[3] = "description = \"" + auxVegetationRemoval[1] + "\",";

	if (auxVegetationRemoval[2] == "true") {
		lines[4] = "save = true,";
	}
	else {
		lines[4] = "save = false,";
	}

	lines[5] = "";
	lines[6] = "averAGBPercAGB = " + auxVegetationRemoval[3] + ",";
	lines[7] = "averAGBPercWoodProducts = " + auxVegetationRemoval[4] + ",";
	lines[8] = "averAGBPercInstantaneous = " + auxVegetationRemoval[5] + ",";
	lines[9] = "averAGBPercDecomposition = " + auxVegetationRemoval[6] + ",";
	lines[10] = "";
	lines[11] = "averBGBPercBGB = " + auxVegetationRemoval[7] + ",";
	lines[12] = "averBGBPercInstantaneous = " + auxVegetationRemoval[8] + ",";
	lines[13] = "averBGBPercDecompositionAbove = " + auxVegetationRemoval[9] + ",";
	lines[14] = "averBGBPercDecompositionUnder = " + auxVegetationRemoval[10] + ",";
	lines[15] = "";
	lines[16] = "averDecompositionFireCyclePeriod = " + auxVegetationRemoval[11] + ",";
	lines[17] = "averDecompositonPercElementalCarbon = " + auxVegetationRemoval[12] + ",";
	lines[18] = "";
	lines[19] = "averLitterPercInstantaneous = " + auxVegetationRemoval[13] + ",";
	lines[20] = "averLitterPercDecomposition = " + auxVegetationRemoval[14] + ",";
	lines[21] = "averDeadWoodPercInstantaneous = " + auxVegetationRemoval[15] + ",";
	lines[22] = "averDeadWoodPercDecomposition = " + auxVegetationRemoval[16] + ",";
	lines[23] = "";
	lines[24] = "averDecayRateWoodProducts = " + auxVegetationRemoval[17] + ",";
	lines[25] = "averDecayRateElementalCarbon = " + auxVegetationRemoval[18] + ",";
	lines[26] = "averDecayRateAGBDecomposition = " + auxVegetationRemoval[19] + ",";
	lines[27] = "averDecayRateBGBDecompositionAbove = " + auxVegetationRemoval[20] + ",";
	lines[28] = "averDecayRateBGBDecompositionUnder = " + auxVegetationRemoval[21] + ",";
	lines[29] = "averDecayRateLitterDecomposition = " + auxVegetationRemoval[22] + ",";
	lines[30] = "averDecayRateDeadWoodDecomposition = " + auxVegetationRemoval[23];
	lines[31] = "}";

	tbVegetationRemoval->Lines = lines;
}

System::Void INPEEM::NovoModelo::sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}

System::Void INPEEM::NovoModelo::idiomaToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	LanguageForm^ languageForm = gcnew LanguageForm(lLanguage);
	languageForm->ShowInTaskbar = false;
	languageForm->MinimizeBox = false;
	languageForm->MaximizeBox = false;
	languageForm->ShowDialog();
	lLanguage = languageForm->lLanguage;
	checkLanguage();
	NovoModelo::Update();
}

System::Void INPEEM::NovoModelo::novoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	lReturn = NEWMODEL;
	this->Close();
}

System::Void INPEEM::NovoModelo::bGerarArquivos_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool checked = true;

	if (!cbModelType->SelectedItem) {
		MessageBox::Show(gSModelSelect, gSModelSelectTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (lSelectedFolder->Text == "") {
		MessageBox::Show(gSFolder, gSFolderTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	else if (tModelName->Text == "") {
		MessageBox::Show(gSModelName, gSModelNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	if (cbModelType->SelectedIndex == NSPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
		if (tNonSpatialName->Text == "") {
			MessageBox::Show(gSNSModelName, gSModelNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (tNonSpatialInitialYear->Text == "") {
			MessageBox::Show(gSNSStartTime, gSStartTimeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (tNonSpatialFinalYear->Text == "") {
			MessageBox::Show(gSNSStopTime, gSStopTimeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (tNonSpatialArea->Text == "") {
			MessageBox::Show(gSNSArea, gSNSAreaTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (tbTableData->Lines->Length == NONE) {
			MessageBox::Show(gSNSTableData, gSNSTableDataTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
	}

	if (cbModelType->SelectedIndex == SPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
		if (tSpatialName->Text == "") {
			MessageBox::Show(gSSModelName, gSModelNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (tSpatialInitialYear->Text == "") {
			MessageBox::Show(gSStartTime, gSStartTimeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (tSpatialFinalYear->Text == "") {
			MessageBox::Show(gSStopTime, gSStopTimeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (lSelectedFile->Text == "") {
			MessageBox::Show(gSSFile, gSSFileTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (!shape) {
			if (tSpatialLayerName->Text == "") {
				MessageBox::Show(gSLayerName, gSLayerNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				checked = false;
			}
		}

		else if (tSpatialCellArea->Text == "") {
			MessageBox::Show(gSCellArea, gSCellAreaTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
	}
	
	if (checked) {
		bool mainFile = false;
		bool subFile = false;
		bool nsFile = false;

		DateTime now = DateTime::Now;
		String^ dateTime = now.ToString("d") + " at " + now.ToString("T");

		//Creating main File
		String^ path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\" + tModelName->Text->ToLower() + "_main.lua";
		path = path->Replace("\\\\\\\\", "\\\\");


		StreamWriter^ sw = nullptr;

		try {
			//Sometimes Widows got and error to access the file, this force to retry
			try
			{
				if (File::Exists(path))
				{
					File::Delete(path);
				}
				sw = File::CreateText(path);
			}
			catch (UnauthorizedAccessException^)
			{
				MessageBox::Show(gSUnauthorized, gSUnauthorizedTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				checked = false;
			}

			if (checked) {
				sw->WriteLine("---------------------------------------------------------------");
				sw->WriteLine("-- This file contains a INPE-EM APPLICATION MODEL definition --");
				sw->WriteLine("--              Compatible with INPE-EM 3.0                  --");
				sw->WriteLine("--       Generated with INPE-EM Model Configurator           --");
				sw->WriteLine("--                 " + dateTime + "                    --");
				sw->WriteLine("---------------------------------------------------------------\n");

				if (shape && (cbModelType->SelectedIndex == SPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE)) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- Creating Terraview Project                               --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("");
					sw->WriteLine("import(\"terralib\")\n");
					sw->WriteLine("proj = Project {");
					sw->WriteLine("\tfile = \"t3mp.tview\",");
					sw->WriteLine("\tclean = true");
					sw->WriteLine("}\n");

					sw->WriteLine("l1 = Layer{");
					sw->WriteLine("\tproject = proj,");
					sw->WriteLine("\tname = \"" + tSpatialLayerName->Text + "\",");
					sw->WriteLine("\tfile = \"" + lSelectedFile->Text->Replace("\\", "\\\\") + "\"");
					sw->WriteLine("}\n");
				}
	
				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("-- INPE-EM Model                                            --");
				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("");
				sw->WriteLine("dofile(\"C:\\\\INPE-EM\\\\Source\\\\inpeEM.lua\\\")");
				
				String^ folderAux = lSelectedFolder->Text->Replace("\\", "\\\\");
				
				if (folderAux->Length > ROOTDIR) {
					sw->WriteLine("dofile(\"" + folderAux + "\\\\" + tModelName->Text->ToLower() + "_submodel.lua\")");
					
					if (cbModelType->SelectedIndex == NSPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
						sw->WriteLine("dofile(\"" + folderAux + "\\\\" + tModelName->Text->ToLower() + "_nsdata.lua\")");
					}
				}
				else {
					sw->WriteLine("dofile(\"" + folderAux + tModelName->Text->ToLower() + "_submodel.lua\")");
					
					if (cbModelType->SelectedIndex == NSPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
						sw->WriteLine("dofile(\"" + folderAux + tModelName->Text->ToLower() + "_nsdata.lua\")");
					}
				}

				sw->WriteLine();

				if (cbModelType->SelectedIndex == NSPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- INPE-EM NON SPATIAL MODEL DEFINITION                     --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("nonSpatialModel =");
					sw->WriteLine("{");
					sw->WriteLine("\tname = \"" + tNonSpatialName->Text + "\",");
					sw->WriteLine("");
					sw->WriteLine("\tyearInit = " + tNonSpatialInitialYear->Text + ",");
					sw->WriteLine("\tyearFinal = " + tNonSpatialFinalYear->Text + ",");
					sw->WriteLine("");
					
					if (cbNonSpatialDeforest->Checked) {
						sw->WriteLine("\tcomponentD = D1,");
					}

					if (cbNonSpatialBiomass->Checked) {
						sw->WriteLine("\tcomponentB = B1,");
					}

					if (cbNonSpatialVegetationRemoval->Checked) {
						sw->WriteLine("\tcomponentVR = VR1,");
					}

					if (cbNonSpatialSecondaryVegetation->Checked) {
						sw->WriteLine("\tcomponentSV = SV1,");
					}

					if (cbNonSpatialDegradation->Checked) {
						sw->WriteLine("\tcomponentDEGRAD = DG1,");
					}

					sw->WriteLine("");
					sw->WriteLine("\tdataTable = NSDATA1,");
					sw->WriteLine("\tarea = " + tNonSpatialArea->Text + ",");
					sw->WriteLine("");
					sw->WriteLine("\tmode = \"non_spatial\",");
					
					if (cbNonSpatialVerbose->Checked) {
						sw->WriteLine("\tverbose = true");
					}
					else {
						sw->WriteLine("\tverbose = false");
					}

					sw->WriteLine("}");
				}

				if (cbModelType->SelectedIndex == SPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- INPE-EM SPATIAL MODEL DEFINITION                         --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("spatialModel =");
					sw->WriteLine("{");
					sw->WriteLine("\tname = \"" + tSpatialName->Text + "\",");
					sw->WriteLine("");
					sw->WriteLine("\tyearInit = " + tSpatialInitialYear->Text + ",");
					sw->WriteLine("\tyearFinal = " + tSpatialFinalYear->Text + ",");
					sw->WriteLine("\tcellarea = " + tSpatialCellArea->Text + ",");
					sw->WriteLine("");

					if (cbSpatialDeforest->Checked) {
						sw->WriteLine("\tcomponentD = D1,");
					}

					if (cbSpatialBiomass->Checked) {
						sw->WriteLine("\tcomponentB = B1,");
					}

					if (cbSpatialVegetationRemoval->Checked) {
						sw->WriteLine("\tcomponentVR = VR1,");
					}

					if (cbSpatialSecondaryVegetation->Checked) {
						sw->WriteLine("\tcomponentSV = SV1,");
					}

					if (cbSpatialDegradation->Checked) {
						sw->WriteLine("\tcomponentDEGRAD = DG1,");
					}

					sw->WriteLine("");
					if (!shape) {
						sw->WriteLine("\tproject = \"" + lSelectedFile + "\",");
					}
					else {
						sw->WriteLine("\tproject = \"t3mp.tview\",");
					}

					sw->WriteLine("\tlayer = \"" + tSpatialLayerName->Text + "\",");
					sw->WriteLine("");
					sw->WriteLine("\tmode = \"spatial\",");

					if (cbSpatialVerbose->Checked) {
						sw->WriteLine("\tverbose = true,");
					}
					else {
						sw->WriteLine("\tverbose = false,");
					}

					bool saveModel = false;
					if (cbSpatialVegetationRemoval->Checked) {
						if (tbVegetationRemoval->Lines[4] != nullptr) {
							if (tbVegetationRemoval->Lines[4]->Contains("true")) {
								saveModel = true;
							}
						}
					}

					if (cbSpatialSecondaryVegetation->Checked) {
						if (tbSecondVegetation->Lines[4] != nullptr) {
							if (tbSecondVegetation->Lines[4]->Contains("true")) {
								saveModel = true;
							}
						}
					}

					if (cbSpatialDegradation->Checked) {
						if (tbDegrad->Lines[4] != nullptr) {
							if (tbDegrad->Lines[4]->Contains("true")) {
								saveModel = true;
							}
						}
					}

					if (saveModel) {
						sw->WriteLine("\tsave = true");
					}
					else {
						sw->WriteLine("\tsave = false");
					}

					sw->WriteLine("}");
				}

				if (cbModelType->SelectedIndex == COMBINETYPE) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- INPE-EM COMBINE MODEL DEFINITION                         --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("combineModel =");
					sw->WriteLine("{");
					sw->WriteLine("\tname = \"" + tModelName->Text + "\",");
					sw->WriteLine("");
					sw->WriteLine("\tmodel_ns = nonSpatialModel,");
					sw->WriteLine("\tmodel_s = spatialModel,");
					sw->WriteLine("");
					sw->WriteLine("\tmode = \"combine\"");
					
					if (cbNonSpatialVerbose->Checked || cbSpatialVerbose->Checked) {
						sw->WriteLine("\tverbose = true,");
					}
					else {
						sw->WriteLine("\tverbose = false");
					}

					sw->WriteLine("}");
				}

				sw->WriteLine("");
				if (cbModelType->SelectedIndex == NSPATIALTYPE) {
					sw->WriteLine("inpeEM_execute(nonSpatialModel)");
				} else if (cbModelType->SelectedIndex == SPATIALTYPE) {
					sw->WriteLine("inpeEM_execute(spatialModel)");
				} else if (cbModelType->SelectedIndex == COMBINETYPE) {
					sw->WriteLine("inpeEM_execute(combineModel)");
				}

				if (shape && (cbModelType->SelectedIndex == SPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE)) {
					sw->WriteLine("");
					sw->WriteLine("local projFile = File(\"t3mp.tview\")");
					sw->WriteLine("if(projFile:exists()) then");
					sw->WriteLine("\tprojFile:delete()");
					sw->WriteLine("end");
				}

				sw->Close();

				if (File::Exists(path))
				{
					mainFile = true;
				}

				//Creating Submodel File
				path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\" + tModelName->Text->ToLower() + "_submodel.lua";
				path = path->Replace("\\\\\\\\", "\\\\");

				if (File::Exists(path))
				{
					File::Delete(path);
				}

				sw = File::CreateText(path);

				sw->WriteLine("---------------------------------------------------------------");
				sw->WriteLine("--       This file contains the COMPONENTS definition        --");
				sw->WriteLine("--              Compatible with INPE-EM 3.0                  --");
				sw->WriteLine("--       Generated with INPE-EM Model Configurator           --");
				sw->WriteLine("--                 " + dateTime + "                    --");
				sw->WriteLine("---------------------------------------------------------------\n");

				if (cbNonSpatialDeforest->Checked || cbSpatialDeforest->Checked) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- DEFOREST COMPONENT DEFINITION                            --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine(tbDeforest->Lines[0]); 
					sw->WriteLine(tbDeforest->Lines[1]);
					
					for (int i = 2; i < tbDeforest->Lines->Length - 1; i++) {
						sw->WriteLine("\t" + tbDeforest->Lines[i]);
					}

					sw->WriteLine(tbDeforest->Lines[tbDeforest->Lines->Length - 1]);
					sw->WriteLine("");
				}

				if (cbNonSpatialBiomass->Checked || cbSpatialBiomass->Checked) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- BIOMASS COMPONENT DEFINITION                             --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine(tbBiomass->Lines[0]);
					sw->WriteLine(tbBiomass->Lines[1]);

					for (int i = 2; i < tbBiomass->Lines->Length - 1; i++) {
						sw->WriteLine("\t" + tbBiomass->Lines[i]);
					}

					sw->WriteLine(tbBiomass->Lines[tbBiomass->Lines->Length - 1]);
					sw->WriteLine("");
				}

				if (cbNonSpatialVegetationRemoval->Checked || cbSpatialVegetationRemoval->Checked) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- VEGETATION REMOVAL COMPONENT DEFINITION                  --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine(tbVegetationRemoval->Lines[0]);
					sw->WriteLine(tbVegetationRemoval->Lines[1]);

					for (int i = 2; i < tbVegetationRemoval->Lines->Length - 1; i++) {
						sw->WriteLine("\t" + tbVegetationRemoval->Lines[i]);
					}

					sw->WriteLine(tbVegetationRemoval->Lines[tbVegetationRemoval->Lines->Length - 1]);
					sw->WriteLine("");
				}

				if (cbNonSpatialSecondaryVegetation->Checked || cbSpatialSecondaryVegetation->Checked) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- SECONDARY VEGETATION COMPONENT DEFINITION                --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine(tbSecondVegetation->Lines[0]);
					sw->WriteLine(tbSecondVegetation->Lines[1]);

					for (int i = 2; i < tbSecondVegetation->Lines->Length - 1; i++) {
						sw->WriteLine("\t" + tbSecondVegetation->Lines[i]);
					}

					sw->WriteLine(tbSecondVegetation->Lines[tbSecondVegetation->Lines->Length - 1]);
					sw->WriteLine("");
				}

				if (cbNonSpatialDegradation->Checked || cbSpatialDegradation->Checked) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- DEGRADATION COMPONENT DEFINITION                         --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine(tbDegrad->Lines[0]);
					sw->WriteLine(tbDegrad->Lines[1]);

					for (int i = 2; i < tbDegrad->Lines->Length - 1; i++) {
						sw->WriteLine("\t" + tbDegrad->Lines[i]);
					}

					sw->WriteLine(tbDegrad->Lines[tbDegrad->Lines->Length - 1]);
					sw->WriteLine("");
				}

				sw->Close();

				if (File::Exists(path))
				{
					subFile = true;

				}

				//Creating Non Spatial Data File
				if (cbModelType->SelectedIndex == NSPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
					path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\" + tModelName->Text->ToLower() + "_nsdata.lua";
					path = path->Replace("\\\\\\\\", "\\\\");

					if (File::Exists(path))
					{
						File::Delete(path);
					}

					sw = File::CreateText(path);

					sw->WriteLine("---------------------------------------------------------------");
					sw->WriteLine("--    This file contains the Non Statial Data definition     --");
					sw->WriteLine("--              Compatible with INPE-EM 3.0                  --");
					sw->WriteLine("--       Generated with INPE-EM Model Configurator           --");
					sw->WriteLine("--                 " + dateTime + "                    --");
					sw->WriteLine("---------------------------------------------------------------\n");

					sw->WriteLine("NSDATA1 =");
					sw->WriteLine("{");

					int countTables = 0;
					
					for (int i = 0; i < tbTableData->Lines->Length; i++) {
						if (tbTableData->Lines[i]->Contains("Area")) {
							countTables++;
						} else if(tbTableData->Lines[i]->Contains("HalfLife")) {
							countTables++;
						} else if (tbTableData->Lines[i]->Contains("Degrad")) {
							countTables++;
						}
					}

					int j = 0;

					for (int i = 0; i < countTables; i++) {
						sw->WriteLine("\t" + tbTableData->Lines[j]);
						j++;
						sw->WriteLine("\t" + tbTableData->Lines[j]);
						j++;
						while (!tbTableData->Lines[j]->Contains("}")) {
							sw->WriteLine("\t\t" + tbTableData->Lines[j]);
							j++;
						}
						sw->WriteLine("\t" + tbTableData->Lines[j]);
						if (j + 1 < tbTableData->Lines->Length) {
							sw->WriteLine("");
						}
						j++;
					}


					sw->WriteLine(tbTableData->Lines[tbTableData->Lines->Length - 1]);
					sw->WriteLine("");

					sw->Close();

					if (File::Exists(path))
					{
						nsFile = true;

					}
				}
	//			if (mainFile && subFile) {
	//				if (lSelectedFolder->Text->Length > ROOTDIR) {
	//					MessageBox::Show(gSSuccess + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + "_main.lua" +
	//						"\n" + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + "_submodel.lua", gSSuccessTitle,
	//						MessageBoxButtons::OK, MessageBoxIcon::Information);
	//				}
	//				else {
	//					MessageBox::Show(gSSuccess + lSelectedFolder->Text + tModelName->Text->ToLower() + "_main.lua" +
	//						"\n" + lSelectedFolder->Text + tModelName->Text->ToLower() + "_submodel.lua", gSSuccessTitle,
	//						MessageBoxButtons::OK, MessageBoxIcon::Information);
	//				}

	//				lRunModel->Visible = true;
	//				bRun->Visible = true;
	//				runnable = true;

	//				gParametersValues[0] = lSelectedFolder->Text;
	//				gParametersValues[1] = tModelName->Text;
	//				gParametersValues[2] = tStartTime->Text;
	//				gParametersValues[3] = tEndTime->Text;
	//				gParametersValues[4] = tThemeName->Text;
	//				gParametersValues[5] = tbSelectedBatabase->Lines[1]->ToString();
	//				gParametersValues[6] = tCellArea->Text;
	//				gParametersValues[7] = lDynamicConfirm->Text;
	//				gParametersValues[8] = tScenariosStartTime->Text;
	//				gParametersValues[9] = tScenarioName->Text;
	//				gParametersValues[10] = lLUTShow->Text;
	//				gParametersValues[11] = lLUNDShow->Text;
	//				gParametersValues[12] = tOutputTheme->Text;
	//				gParametersValues[13] = lYearsToSave->Text;
	//				gParametersValues[14] = lAttrToSave->Text;
	//				gParametersValues[15] = tbDemand->Lines[0]->ToString();
	//				gParametersValues[16] = tbPotential->Lines[0]->ToString();
	//				gParametersValues[17] = tbAllocation->Lines[0]->ToString();
	//			}
	//			else {
	//				if (!mainFile) {
	//					MessageBox::Show(gSFileMissing + lSelectedFolder->Text, gSFileMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//				}
	//				else {
	//					MessageBox::Show(gSFileMissing2 + lSelectedFolder->Text, gSFileMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//				}
	//			}
			}
		}
		catch (Exception^) {
			//if (!mainFile) {
			//	if (forceWriting) {
			//		MessageBox::Show(gSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			//		closing = true;
			//		this->Close();
			//	}
			//	else {
			//		System::Threading::Thread::Sleep(SECOND);
			//		if (File::Exists(path))
			//		{
			//			File::Delete(path);
			//		}

			//		forceWriting = true;
			//		bGerarArquivos_Click(sender, e);
			//	}
			//}
			//else if (!subFile) {
			//	if (forceWriting) {
			//		MessageBox::Show(gSSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			//		closing = true;
			//		this->Close();
			//	}
			//	else {
			//		System::Threading::Thread::Sleep(SECOND);
			//		if (File::Exists(path))
			//		{
			//			File::Delete(path);
			//		}

			//		forceWriting = true;
			//		bGerarArquivos_Click(sender, e);
			//	}
			//}
			//else {
			//	if (forceWriting) {
			//		MessageBox::Show(gSFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			//		closing = true;
			//		this->Close();
			//	}
			//	else {
			//		System::Threading::Thread::Sleep(SECOND);
			//		if (File::Exists(path))
			//		{
			//			File::Delete(path);
			//		}

			//		forceWriting = true;
			//		bGerarArquivos_Click(sender, e);
			//	}
			//}
		}
	}
}