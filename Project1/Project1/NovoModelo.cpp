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
		lArquivos->Text = "     Files";
		lDirProj->Text = "Folder to Save the Model";
		bSelectFolder->Text = "Select";
		lDefinicoesModelo->Text = "   Model Definitions";
		lModelName->Text = "Model Name";
		//tabComponents
		tabComponents->Text = "Componentes";
		lComponentes->Text = "Configure os Componentes";
		bDeforest->Text = "Deforest";
		bBiomass->Text = "Biomass";
		bVegetationRemoval->Text = "Vegetation Removal";
		bSecondVegetation->Text = "Secondary Vegetation";
		bDegrad->Text = "Degradation";
		lDatabase->Text = "File:";
		lTerraview->Text = "Terraview Project";
		lComponentes->Text = "   Select the Components";
		//tabFileMaker
		lFileMaker->Text = "       Files Maker";
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
		gSModelSelect = "A Model Type Must be Selected on Files Maker.";
		gSModelSelectTitle = "Error - Model Type not Selected";
		gSFolder = "Project folder not selected in Model Definition.";
		gSFolderTitle = "Error - Project folder is missing";
		gSModelName = "Model Name not defined in Model Definition.";
		gSModelNameTitle = "Error - Model Name is missing";

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

		lDatabase->Text = "Arquivo:";
		lComponentes->Text = "Selecione os Componentes";
	
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
		gSModelSelect = "Um Tipo de Modelo deve ser selecionado em Gerar Arquivos.";
		gSModelSelectTitle = "Erro - TIpo de Modelo não Selecionado";
		gSFolder = "Pasta do projeto não selecionada em Definições do Modelo.";
		gSFolderTitle = "Erro - Pasta do projeto não selecionada";
		gSModelName = "Nome do Modelo não definido em Definições do Modelo.";
		gSModelNameTitle = "Erro - Nome do Modelo não definido";

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
	lines[13] = "averLimiarDegradLoss = " + auxDegradation[9] + ",";
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
	lines[15] = "averBGBpercBGB = " + auxSecondaryVegetatin[12] + ",";
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
	lines[30] = "averDecayRateDeadWoodDecomposition = " + auxVegetationRemoval[23] + ",";
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

	//else if (tStartTime->Text == "") {
	//	MessageBox::Show(gSStartTime, gSStartTimeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (tEndTime->Text == "") {
	//	MessageBox::Show(gSEndTime, gSEndTimeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (tbSelectedBatabase->Text == "") {
	//	MessageBox::Show(gSDBSave, gSDBSaveTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (tThemeName->Text == "") {
	//	MessageBox::Show(gSThemeName, gSThemeNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (tCellArea->Text == "") {
	//	MessageBox::Show(gSCellArea, gSCellAreaTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (lLUTShow->Text == "") {
	//	MessageBox::Show(gSLUTShow, gSLUTShowTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (lLUNDShow->Text == "") {
	//	MessageBox::Show(gSLUTNDShow, gSLUTNDShowTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (gDemandComponent == NONE) {
	//	MessageBox::Show(gSDemandnS, gSDemandnSTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (gPotentialComponent == NONE) {
	//	MessageBox::Show(gSPotentialnS, gSPotentialnSTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (gAllocationComponent == NONE) {
	//	MessageBox::Show(gSAllocationnS, gSAllocationnSTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (tOutputTheme->Text == "") {
	//	MessageBox::Show(gSOutputTheme, gSOutputThemeTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (lYearsToSave->Text == "" && cSaveYearly->Checked == false) {
	//	MessageBox::Show(gSYearSave, gSYearSaveTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if ((lYearsToSave->Text != "" || cSaveYearly->Checked == true) && (lAttrToSave->Text == "")) {
	//	MessageBox::Show(gSAttribToSave, gSAttribToSaveTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (gPotentialComponent > NUMDISCPOTCOMP && (gAllocationComponent > NONE && gAllocationComponent <= NUMDISCALLOCCOMP)) {
	//	MessageBox::Show(gSPotContAlocDisc, gSPotContAlocDiscTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if ((gPotentialComponent > NONE && gPotentialComponent <= NUMDISCPOTCOMP) && gAllocationComponent > NUMDISCALLOCCOMP) {
	//	MessageBox::Show(gSPotDiscAlocCont, gSPotContAlocDiscTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//	checked = false;
	//}

	//else if (cDynamicVariables->Checked == true) {
	//	if (lDynamicConfirm->Text == "") {
	//		MessageBox::Show(gSCheckDyn, gSCheckDynTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//		checked = false;
	//	}
	//}

	//else if (cScenario->Checked == true) {
	//	if (cDynamicVariables->Checked == false) {
	//		MessageBox::Show(gSCheckDyn, gSCheckDynTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//		checked = false;
	//	}
	//	else if (tScenarioName->Text == "") {
	//		MessageBox::Show(gSScenName, gSScenNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//		checked = false;
	//	}
	//	else if (tScenariosStartTime->Text == "") {
	//		MessageBox::Show(gSScenST, gSScenSTTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//		checked = false;
	//	}
	//	else if (shape) {
	//		if (lScenarioYearsConfirm->Text == "") {
	//			MessageBox::Show(gSScenSYU, gSScenSYUTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//			checked = false;
	//		}
	//	}
	//}

	//if (checked) {
	//	bool mainFile = false;
	//	bool subFile = false;

	//	DateTime now = DateTime::Now;
	//	String^ dateTime = now.ToString("d") + " at " + now.ToString("T");

	//	//Creating main File
	//	String^ path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\" + tModelName->Text->ToLower() + "_main.lua";
	//	path = path->Replace("\\\\\\\\", "\\\\");


	//	StreamWriter^ sw = nullptr;

	//	try {
	//		//Sometimes Widows got and error to access the file, this force to retry
	//		try
	//		{
	//			if (File::Exists(path))
	//			{
	//				File::Delete(path);
	//			}
	//			sw = File::CreateText(path);
	//		}
	//		catch (UnauthorizedAccessException^)
	//		{
	//			MessageBox::Show(gSUnauthorized, gSUnauthorizedTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//			checked = false;
	//		}

	//		if (checked) {
	//			sw->WriteLine("--------------------------------------------------------------");
	//			sw->WriteLine("-- This file contains a LUCCME APPLICATION MODEL definition --");
	//			sw->WriteLine("--               Compatible with LuccME 3.0                 --");
	//			sw->WriteLine("--        Generated with LuccMe Model Configurator          --");
	//			sw->WriteLine("--               " + dateTime + "                     --");
	//			sw->WriteLine("--------------------------------------------------------------\n");

	//			if (shape) {
	//				sw->WriteLine("--------------------------------------------------------------");
	//				sw->WriteLine("-- Creating Terraview Project                               --");
	//				sw->WriteLine("--------------------------------------------------------------");
	//				sw->WriteLine("");
	//				sw->WriteLine("import(\"terralib\")\n");
	//				sw->WriteLine("proj = Project {");
	//				sw->WriteLine("\tfile = \"t3mp.tview\",");
	//				sw->WriteLine("\tclean = true");
	//				sw->WriteLine("}\n");

	//				sw->WriteLine("l1 = Layer{");
	//				sw->WriteLine("\tproject = proj,");
	//				sw->WriteLine("\tname = \"" + tThemeName->Text + "\",");
	//				sw->WriteLine("\tfile = \"" + tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\") + "\"");
	//				sw->WriteLine("}\n");

	//				int dynamicVariables = 0;
	//				if (cDynamicVariables->Checked == true && lDynamicConfirm->Text != "") {
	//					int updateYearsCount = countCaracter(lDynamicConfirm->Text, ',') + 1;
	//					array<String^>^ updateYearsArray = gcnew array<String^>(updateYearsCount);
	//					String^ layerName = tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\");
	//					layerName = layerName->Replace(".shp", "");
	//					int caracter = 0;

	//					for (int i = 0; i < updateYearsArray->Length; i++) {
	//						while (lDynamicConfirm->Text[caracter] != ',') {
	//							updateYearsArray[i] += lDynamicConfirm->Text[caracter];
	//							caracter++;
	//							if (caracter == lDynamicConfirm->Text->Length) {
	//								break;
	//							}
	//						}
	//						caracter++;
	//					}

	//					for (int i = 0; i < updateYearsArray->Length; i++) {
	//						sw->WriteLine("l" + (i + 2) + " = Layer{");
	//						sw->WriteLine("\tproject = proj,");
	//						sw->WriteLine("\tname = \"" + tThemeName->Text + "_" + updateYearsArray[i]->Replace(" ", "") + "\",");
	//						sw->WriteLine("\tfile = \"" + layerName + "_" + updateYearsArray[i]->Replace(" ", "") + ".shp\"");
	//						sw->WriteLine("}\n");
	//					}
	//					dynamicVariables = updateYearsCount;
	//				}

	//				if (cScenario->Checked == true && lScenarioYearsConfirm->Text != "" && tScenarioName->Text != "") {
	//					int updateYearsCount = countCaracter(lScenarioYearsConfirm->Text, ',') + 1;
	//					array<String^>^ updateYearsArray = gcnew array<String^>(updateYearsCount);
	//					String^ layerName = tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\");
	//					layerName = layerName->Replace(".shp", "");
	//					int caracter = 0;

	//					for (int i = 0; i < updateYearsArray->Length; i++) {
	//						while (lScenarioYearsConfirm->Text[caracter] != ',') {
	//							updateYearsArray[i] += lScenarioYearsConfirm->Text[caracter];
	//							caracter++;
	//							if (caracter == lScenarioYearsConfirm->Text->Length) {
	//								break;
	//							}
	//						}
	//						caracter++;
	//					}

	//					for (int i = 0; i < updateYearsArray->Length; i++) {
	//						sw->WriteLine("l" + (i + 2 + dynamicVariables) + " = Layer{");
	//						sw->WriteLine("\tproject = proj,");
	//						sw->WriteLine("\tname = \"" + tThemeName->Text + "_" + tScenarioName->Text + "_" + updateYearsArray[i]->Replace(" ", "") + "\",");
	//						sw->WriteLine("\tfile = \"" + layerName + "_" + tScenarioName->Text + "_" + updateYearsArray[i]->Replace(" ", "") + ".shp\"");
	//						sw->WriteLine("}\n");
	//					}
	//				}
	//				sw->WriteLine("--------------------------------------------------------------");
	//				sw->WriteLine("-- LuccME Model                                             --");
	//				sw->WriteLine("--------------------------------------------------------------");
	//			}

	//			sw->WriteLine("");
	//			sw->WriteLine("import(\"luccme\")\n");
	//			String^ folderAux = lSelectedFolder->Text->Replace("\\", "\\\\");
	//			if (folderAux->Length > ROOTDIR) {
	//				sw->WriteLine("dofile(\"" + folderAux + "\\\\" + tModelName->Text->ToLower() + "_submodel.lua\")\n");
	//			}
	//			else {
	//				sw->WriteLine("dofile(\"" + folderAux + tModelName->Text->ToLower() + "_submodel.lua\")\n");
	//			}
	//			sw->WriteLine();

	//			sw->WriteLine("--------------------------------------------------------------");
	//			sw->WriteLine("-- LuccME APPLICATION MODEL DEFINITION                      --");
	//			sw->WriteLine("--------------------------------------------------------------");

	//			sw->WriteLine(tModelName->Text + " = LuccMEModel");
	//			sw->WriteLine("{");
	//			sw->WriteLine("\tname = \"" + tModelName->Text + "\",\n");

	//			sw->WriteLine("\t-----------------------------------------------------");
	//			sw->WriteLine("\t-- Temporal dimension definition                   --");
	//			sw->WriteLine("\t-----------------------------------------------------");
	//			sw->WriteLine("\tstartTime = " + tStartTime->Text + ",");
	//			sw->WriteLine("\tendTime = " + tEndTime->Text + ",\n");

	//			sw->WriteLine("\t-----------------------------------------------------");
	//			sw->WriteLine("\t-- Spatial dimension definition                    --");
	//			sw->WriteLine("\t-----------------------------------------------------");

	//			if (tbSelectedBatabase->Lines[0]->ToString() == gSShape) {
	//				sw->WriteLine("\tcs = CellularSpace");
	//				sw->WriteLine("\t{");
	//				sw->WriteLine("\t\tproject = \"t3mp.tview\",");
	//				sw->WriteLine("\t\tlayer = \"" + tThemeName->Text + "\",");
	//				sw->WriteLine("\t\tcellArea = " + tCellArea->Text + ",");
	//				sw->WriteLine("\t},");
	//			}
	//			else {
	//				sw->WriteLine("\tcs = CellularSpace");
	//				sw->WriteLine("\t{");
	//				sw->WriteLine("\t\tproject = \"" + tbSelectedBatabase->Lines[1]->ToString()->Replace("\\", "\\\\") + "\",");
	//				sw->WriteLine("\t\tlayer = \"" + tThemeName->Text + "\",");
	//				sw->WriteLine("\t\tcellArea = " + tCellArea->Text + ",");
	//				sw->WriteLine("\t},");
	//			}

	//			if (cDynamicVariables->Checked == true) {
	//				sw->WriteLine();
	//				sw->WriteLine("\t-----------------------------------------------------");
	//				sw->WriteLine("\t-- Dynamic variables definition                    --");
	//				sw->WriteLine("\t-----------------------------------------------------");
	//				sw->WriteLine("\tupdateYears = {" + lDynamicConfirm->Text + "},");

	//				if (cScenario->Checked == true) {
	//					sw->WriteLine("\tscenarioStartTime = " + tScenariosStartTime->Text + ",");
	//					sw->WriteLine("\tscenarioName = \"" + tScenarioName->Text + "\",");
	//				}
	//			}

	//			sw->WriteLine();
	//			sw->WriteLine("\t-----------------------------------------------------");
	//			sw->WriteLine("\t-- Land use variables definition                   --");
	//			sw->WriteLine("\t-----------------------------------------------------");
	//			sw->WriteLine("\tlandUseTypes =");
	//			sw->WriteLine("\t{");
	//			sw->WriteLine("\t\t" + lLUTShow->Text->Replace(",", ", "));
	//			sw->WriteLine("\t},\n");
	//			sw->WriteLine("\tlandUseNoData	= " + lLUNDShow->Text->Replace(",", ", ") + ",\n");

	//			sw->WriteLine("\t-----------------------------------------------------");
	//			sw->WriteLine("\t-- Behaviour dimension definition:                 --");
	//			sw->WriteLine("\t-- DEMAND, POTENTIAL AND ALLOCATION COMPONENTS     --");
	//			sw->WriteLine("\t-----------------------------------------------------");
	//			sw->WriteLine("\tdemand = D1,");
	//			sw->WriteLine("\tpotential = P1,");
	//			sw->WriteLine("\tallocation = A1,\n");

	//			sw->WriteLine("\tsave  =");
	//			sw->WriteLine("\t{");
	//			sw->WriteLine("\t\toutputTheme = \"" + tOutputTheme->Text + "\",");
	//			sw->WriteLine("\t\tmode = \"multiple\",");
	//			if (cSaveYearly->Checked) {
	//				int time = Convert::ToInt16(tEndTime->Text) - Convert::ToInt16(tStartTime->Text);
	//				int tempTime = Convert::ToInt16(tStartTime->Text);
	//				String^ tempYears = "";
	//				for (int i = 0; i <= time; i++) {
	//					tempYears += Convert::ToString(tempTime + i);
	//					if (i < time) {
	//						tempYears += ",";
	//					}
	//				}
	//				sw->WriteLine("\t\tsaveYears = {" + tempYears + "},");
	//			}
	//			else {
	//				sw->WriteLine("\t\tsaveYears = {" + lYearsToSave->Text + "},");
	//			}

	//			if (lAttrToSave->Text != "") {
	//				sw->WriteLine("\t\tsaveAttrs = ");
	//				sw->WriteLine("\t\t{");
	//				String^ aux = "";
	//				for (int i = 0; i < lAttrToSave->Text->Length; i++) {
	//					if (lAttrToSave->Text[i] != ',') {
	//						aux += lAttrToSave->Text[i];
	//					}
	//					else {
	//						if (aux[0] == ' ') {
	//							aux = aux->Remove(0, 1);
	//						}
	//						sw->WriteLine("\t\t\t\"" + aux + "_out\",");
	//						if (cChange->Checked) {
	//							sw->WriteLine("\t\t\t\"" + aux + "_chtot\",");
	//							sw->WriteLine("\t\t\t\"" + aux + "_chpast\",");
	//						}
	//						if (cPot->Checked) {
	//							sw->WriteLine("\t\t\t\"" + aux + "_pot\",");
	//						}
	//						if (cReg->Checked) {
	//							sw->WriteLine("\t\t\t\"" + aux + "_reg\",");
	//						}
	//						aux = "";

	//					}
	//				}
	//				if (aux != "") {
	//					if (aux[0] == ' ') {
	//						aux = aux->Remove(0, 1);
	//					}
	//					sw->WriteLine("\t\t\t\"" + aux + "_out\",");
	//					if (cChange->Checked) {
	//						sw->WriteLine("\t\t\t\"" + aux + "_chtot\",");
	//						sw->WriteLine("\t\t\t\"" + aux + "_chpast\",");
	//					}
	//					if (cPot->Checked) {
	//						sw->WriteLine("\t\t\t\"" + aux + "_pot\",");
	//					}
	//					if (cReg->Checked) {
	//						sw->WriteLine("\t\t\t\"" + aux + "_reg\",");
	//					}
	//				}
	//				sw->WriteLine("\t\t},\n");
	//			}
	//			sw->WriteLine("\t},\n");

	//			if (cAuxOut->Checked) {
	//				sw->WriteLine("\thasAuxiliaryOutputs = true,");
	//			}

	//			if (cIsCoupled->Checked) {
	//				sw->WriteLine("\tisCoupled = true");
	//			}
	//			else {
	//				sw->WriteLine("\tisCoupled = false");
	//			}
	//			sw->WriteLine("}  -- END LuccME application model definition\n");

	//			sw->WriteLine("-----------------------------------------------------");
	//			sw->WriteLine("-- ENVIROMMENT DEFINITION                          --");
	//			sw->WriteLine("-----------------------------------------------------");
	//			sw->WriteLine("timer = Timer");
	//			sw->WriteLine("{");
	//			sw->WriteLine("\tEvent");
	//			sw->WriteLine("\t{");
	//			sw->WriteLine("\t\tstart = " + tModelName->Text + ".startTime,");
	//			sw->WriteLine("\t\taction = function(event)");
	//			sw->WriteLine("\t\t\t\t\t" + tModelName->Text + ":run(event)");
	//			sw->WriteLine("\t\t\t\t  end");
	//			sw->WriteLine("\t}");
	//			sw->WriteLine("}\n");

	//			sw->WriteLine("env_" + tModelName->Text + " = Environment{}");
	//			sw->WriteLine("env_" + tModelName->Text + ":add(timer)\n");

	//			sw->WriteLine("-----------------------------------------------------");
	//			sw->WriteLine("-- ENVIROMMENT EXECUTION                           --");
	//			sw->WriteLine("-----------------------------------------------------");
	//			sw->WriteLine("if " + tModelName->Text + ".isCoupled == false then");
	//			sw->WriteLine("\ttsave = databaseSave(" + tModelName->Text + ")");
	//			sw->WriteLine("\tenv_" + tModelName->Text + ":add(tsave)");
	//			sw->WriteLine("\tenv_" + tModelName->Text + ":run(" + tModelName->Text + ".endTime)");
	//			sw->WriteLine("\tsaveSingleTheme (" + tModelName->Text + ", true)");

	//			if (shape) {
	//				sw->WriteLine("\tlocal projFile = File(\"t3mp.tview\")");
	//				sw->WriteLine("\tif(projFile:exists()) then");
	//				sw->WriteLine("\t\tprojFile:delete()");
	//				sw->WriteLine("\tend");
	//			}

	//			sw->WriteLine("end");
	//			sw->Close();

	//			if (File::Exists(path))
	//			{
	//				mainFile = true;
	//			}

	//			//Creating Submodel File
	//			path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\" + tModelName->Text->ToLower() + "_submodel.lua";
	//			path = path->Replace("\\\\\\\\", "\\\\");

	//			if (File::Exists(path))
	//			{
	//				File::Delete(path);
	//			}

	//			sw = File::CreateText(path);

	//			sw->WriteLine("--------------------------------------------------------------");
	//			sw->WriteLine("--       This file contains the COMPONENTS definition       --");
	//			sw->WriteLine("--               Compatible with LuccME 3.0                 --");
	//			sw->WriteLine("--        Generated with LuccMe Model Configurator          --");
	//			sw->WriteLine("--               " + dateTime + "                     --");
	//			sw->WriteLine("--------------------------------------------------------------\n");

	//			if (tbDemand->Lines->Length > 0) {
	//				sw->WriteLine("-----------------------------------------------------");
	//				sw->WriteLine("-- Demand                                          --");
	//				sw->WriteLine("-----------------------------------------------------");

	//				int tempYear = 0;
	//				switch (gDemandComponent)
	//				{
	//				case PCVINPE:
	//					sw->WriteLine("D1 = " + tbDemand->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\tannualDemand =");
	//					sw->WriteLine("\t{");
	//					sw->WriteLine("\t\t-- " + tbDemand->Lines[1]->ToString()->Replace(",", ", "));
	//					tempYear = Convert::ToInt16(tStartTime->Text);
	//					for (int i = 2; i < tbDemand->Lines->Length; i++) {
	//						sw->WriteLine("\t\t" + tbDemand->Lines[i]->ToString()->Replace(",", ", ") + "\t-- " + Convert::ToString(tempYear + i - 2));
	//					}
	//					sw->WriteLine("\t}");
	//					sw->WriteLine("}\n");
	//					break;

	//				case CITWODM:
	//					sw->WriteLine("D1 = " + tbDemand->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\t" + tbDemand->Lines[1]->ToString()->Replace(",", ", ") + ",");
	//					sw->WriteLine("\tfinalLandUseTypesForInterpolation = {" + tbDemand->Lines[3]->ToString()->Replace(",", ", ") + "},");
	//					sw->WriteLine("}\n");
	//					break;

	//				case CITHREEDM:
	//					sw->WriteLine("D1 = " + tbDemand->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\t" + tbDemand->Lines[1]->ToString()->Replace(",", ", ") + ",");
	//					sw->WriteLine("\tmiddleLandUseTypesForInterpolation = {" + tbDemand->Lines[4]->ToString()->Replace(",", ", ") + "},");
	//					sw->WriteLine("\t" + tbDemand->Lines[2]->ToString()->Replace(",", ", ") + ",");
	//					sw->WriteLine("\tfinalLandUseTypesForInterpolation = {" + tbDemand->Lines[5]->ToString()->Replace(",", ", ") + "},");
	//					sw->WriteLine("}\n");
	//					break;

	//				default:
	//					break;
	//				}
	//			}

	//			if (tbPotential->Lines->Length > 0) {
	//				sw->WriteLine("-----------------------------------------------------");
	//				sw->WriteLine("-- Potential                                       --");
	//				sw->WriteLine("-----------------------------------------------------");

	//				array<String^>^ tempLUTs = gcnew array<String^>(50);
	//				int row = 0;
	//				String^ aux = "";
	//				String^ tempBetas = "";
	//				for (int i = 0; i < gLandUseTypes->Length; i++) {
	//					if (gLandUseTypes[i] != ',') {
	//						if (gLandUseTypes[i] != '\"') {
	//							aux += gLandUseTypes[i];
	//						}
	//					}
	//					else {
	//						tempLUTs[row] = aux;
	//						aux = "";
	//						row++;
	//					}
	//				}
	//				if (aux != "") {
	//					tempLUTs[row] = aux;
	//				}

	//				int activeRegion = 1;
	//				int nLut = countCaracter(gPotentialLUT, ',') + 1;
	//				int endRegion = 0;
	//				int activeLUT = 0;
	//				int startAffinity = 0;

	//				switch (gPotentialComponent)
	//				{
	//				case POTENTIALDNEIGHSIMPLERULE:
	//					sw->WriteLine("P1 = " + tbPotential->Lines[0] + "\n");
	//					break;

	//				case POTENTIALDNEIGHINVERSEDISTANCERULE:
	//				case POTENTIALDINVERSEDISTANCERULE:
	//				case POTENTIALDLOGISTICREGRESSION:
	//				case POTENTIALDLOGISTICREGRESSIONNEIGHATTRACT:
	//				case POTENTIALCLINEARREGRESSION:
	//				case POTENTIALCSPATIALLAGREGRESSION:
	//					sw->WriteLine("P1 = " + tbPotential->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\tpotentialData =");
	//					sw->WriteLine("\t{");
	//					if (gPotentialRegression > 1) {
	//						sw->WriteLine("\t\tregionAttr = \"region\",");
	//						sw->WriteLine("");
	//					}
	//					for (int k = 1; k < tbPotential->Lines->Length; k += nLut) {
	//						sw->WriteLine("\t\t-- Region " + activeRegion.ToString());
	//						sw->WriteLine("\t\t{");
	//						if (gPotentialRegression == 1) {
	//							endRegion = (tbPotential->Lines->Length - 1);
	//						}
	//						else {
	//							endRegion = ((tbPotential->Lines->Length - 1) / gPotentialRegression)*activeRegion;
	//						}
	//						for (int i = k; i <= endRegion; i++) {
	//							if (tbPotential->Lines[i]->ToString() != "") {
	//								sw->WriteLine("\t\t\t-- " + tempLUTs[activeLUT]);
	//								activeLUT++;
	//								sw->WriteLine("\t\t\t{");
	//								aux = tbPotential->Lines[i]->ToString()->Replace("betas", "$betas");
	//								int j = 0;
	//								while (aux[j] != '$') {
	//									if (aux[j] != ',') {
	//										if (aux[j] != ' ') {
	//											tempBetas += aux[j];
	//										}
	//									}
	//									else {
	//										sw->WriteLine("\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
	//										tempBetas = "";
	//									}
	//									j++;
	//								}
	//								j++;
	//								sw->WriteLine("\n\t\t\t\t" + aux->Substring(j, 7)); //Betas
	//								sw->WriteLine("\t\t\t\t{");
	//								j += 9;
	//								for (int k = j; k < aux->Length; k++) {
	//									if (aux[k] != ',') {
	//										if (aux[k] != '}') {
	//											if (aux[k] != ' ') {
	//												tempBetas += aux[k];
	//											}
	//										}
	//										else {
	//											sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = "));
	//											sw->WriteLine("\t\t\t\t}");
	//											if (activeLUT != nLut) {
	//												sw->WriteLine("\t\t\t},\n");
	//											}
	//											else {
	//												sw->WriteLine("\t\t\t}");
	//											}
	//											tempBetas = "";
	//											break;
	//										}
	//									}
	//									else {
	//										sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
	//										tempBetas = "";
	//									}
	//								}
	//							}
	//						}
	//						activeRegion++;
	//						activeLUT = 0;
	//						if (activeRegion <= gPotentialRegression) {
	//							sw->WriteLine("\t\t},\n");
	//						}
	//						else {
	//							sw->WriteLine("\t\t}");
	//						}
	//					}

	//					sw->WriteLine("\t}");
	//					sw->WriteLine("}\n");
	//					break;

	//				case POTENTIALDLOGISTICREGRESSIONNEIGHATTRACTREPULSION:
	//					sw->WriteLine("P1 = " + tbPotential->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\tpotentialData =");
	//					sw->WriteLine("\t{");
	//					if (gPotentialRegression > 1) {
	//						sw->WriteLine("\t\tregionAttr = \"region\",");
	//						sw->WriteLine("");
	//					}

	//					for (int k = 1; k < tbPotential->Lines->Length - (nLut*gPotentialRegression) - 2; k += nLut) {
	//						sw->WriteLine("\t\t-- Region " + activeRegion.ToString());
	//						sw->WriteLine("\t\t{");
	//						if (gPotentialRegression == 1) {
	//							endRegion = tbPotential->Lines->Length - (nLut*gPotentialRegression) - 2;
	//						}
	//						else {
	//							endRegion = ((tbPotential->Lines->Length - (nLut*gPotentialRegression) - 2) / gPotentialRegression)*activeRegion;
	//						}
	//						for (int i = k; i <= endRegion; i++) {
	//							if (tbPotential->Lines[i]->ToString() != "") {
	//								sw->WriteLine("\t\t\t-- " + tempLUTs[activeLUT]);
	//								activeLUT++;
	//								sw->WriteLine("\t\t\t{");
	//								aux = tbPotential->Lines[i]->ToString()->Replace("betas", "$betas");
	//								int j = 0;
	//								while (aux[j] != '$') {
	//									if (aux[j] != ',') {
	//										if (aux[j] != ' ') {
	//											tempBetas += aux[j];
	//										}
	//									}
	//									else {
	//										sw->WriteLine("\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
	//										tempBetas = "";
	//									}
	//									j++;
	//								}
	//								j++;
	//								sw->WriteLine("\n\t\t\t\t" + aux->Substring(j, 7)); //Betas
	//								sw->WriteLine("\t\t\t\t{");
	//								j += 9;
	//								for (int k = j; k < aux->Length; k++) {
	//									if (aux[k] != ',') {
	//										if (aux[k] != '}') {
	//											if (aux[k] != ' ') {
	//												tempBetas += aux[k];
	//											}
	//										}
	//										else {
	//											sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = "));
	//											sw->WriteLine("\t\t\t\t}");
	//											if (activeLUT != nLut) {
	//												sw->WriteLine("\t\t\t},\n");
	//											}
	//											else {
	//												sw->WriteLine("\t\t\t}");
	//											}
	//											tempBetas = "";
	//											break;
	//										}
	//									}
	//									else {
	//										sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
	//										tempBetas = "";
	//									}
	//								}
	//							}
	//						}
	//						activeRegion++;
	//						activeLUT = 0;
	//						if (activeRegion <= gPotentialRegression) {
	//							sw->WriteLine("\t\t},\n");
	//						}
	//						else {
	//							sw->WriteLine("\t\t}");
	//						}
	//					}
	//					sw->WriteLine("\t},\n");
	//					sw->WriteLine("\taffinityMatrix = ");
	//					sw->WriteLine("\t{");
	//					activeRegion = 1;
	//					startAffinity = endRegion + 2;
	//					for (int k = startAffinity; k < tbPotential->Lines->Length; k += nLut) {
	//						endRegion = startAffinity + (nLut * activeRegion);
	//						sw->WriteLine("\t\t-- Region " + activeRegion.ToString());
	//						sw->WriteLine("\t\t{");
	//						for (int i = k; i < endRegion; i++) {
	//							if (i + 1 < endRegion) {
	//								sw->WriteLine("\t\t\t{" + tbPotential->Lines[i] + "},");
	//							}
	//							else {
	//								sw->WriteLine("\t\t\t{" + tbPotential->Lines[i] + "}");
	//								break;
	//							}
	//						}
	//						if (k + nLut < tbPotential->Lines->Length) {
	//							sw->WriteLine("\t\t},\n");
	//						}
	//						else {
	//							sw->WriteLine("\t\t}");
	//						}
	//						activeRegion++;
	//					}

	//					sw->WriteLine("\t}");
	//					sw->WriteLine("}\n");
	//					break;
	//				case POTENTIALCSPATIALLAGLINEARREGRESSIONMIX:
	//					sw->WriteLine("P1 = " + tbPotential->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\tpotentialData =");
	//					sw->WriteLine("\t{");
	//					sw->WriteLine("\t\t-- Region 1");
	//					sw->WriteLine("\t\t{");

	//					for (int i = 1; i < tbPotential->Lines->Length; i++) {
	//						if (tbPotential->Lines[i]->ToString() != "") {
	//							sw->WriteLine("\t\t\t-- " + tempLUTs[i - 1]);
	//							sw->WriteLine("\t\t\t{");
	//							aux = tbPotential->Lines[i]->ToString()->Replace("betas", "$betas");
	//							aux = aux->Replace("roadsModel", "%roadsModel");
	//							int j = 0;
	//							while (aux[j] != '$') {
	//								if (aux[j] != ',') {
	//									if (aux[j] != ' ') {
	//										tempBetas += aux[j];
	//									}
	//								}
	//								else {
	//									sw->WriteLine("\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
	//									tempBetas = "";
	//								}
	//								j++;
	//							}
	//							j++;
	//							sw->WriteLine("\n\t\t\t\t" + aux->Substring(j, 9)); //Betas
	//							sw->WriteLine("\t\t\t\t{");
	//							j += 11;
	//							while (aux[j] != '%') {
	//								if (aux[j] != ',') {
	//									if (aux[j] != '}') {
	//										if (aux[j] != ' ') {
	//											tempBetas += aux[j];
	//										}
	//									}
	//									else {
	//										sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = "));
	//										sw->WriteLine("\t\t\t\t},");
	//										tempBetas = "";
	//										break;
	//									}
	//								}
	//								else {
	//									sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
	//									tempBetas = "";
	//								}
	//								j++;
	//							}
	//							j += 4;
	//							sw->WriteLine("\n\t\t\t\t" + aux->Substring(j, 13)); //roadsModel
	//							sw->WriteLine("\t\t\t\t{");
	//							j += 15;
	//							sw->WriteLine("\t\t\t\t\t" + aux->Substring(j, 8)); //attrs
	//							sw->WriteLine("\t\t\t\t\t{");
	//							j += 9;
	//							while (aux[j] != '}') {
	//								if (aux[j] != ',') {
	//									if (aux[j] != ' ') {
	//										tempBetas += aux[j];
	//									}
	//								}
	//								else {
	//									sw->WriteLine("\t\t\t\t\t\t" + tempBetas + ",");
	//									tempBetas = "";
	//								}
	//								j++;
	//							}
	//							if (tempBetas != "") {
	//								sw->WriteLine("\t\t\t\t\t\t" + tempBetas);
	//								tempBetas = "";
	//							}
	//							sw->WriteLine("\t\t\t\t\t},");
	//							j += 2;
	//							while (aux[j] != '$') {
	//								if (aux[j] != ',') {
	//									if (aux[j] != '}') {
	//										if (aux[j] != ' ') {
	//											tempBetas += aux[j];
	//										}
	//									}
	//									else {
	//										sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = "));
	//										sw->WriteLine("\t\t\t\t},");
	//										tempBetas = "";
	//										break;
	//									}
	//								}
	//								else {
	//									sw->WriteLine("\t\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
	//									tempBetas = "";
	//								}
	//								j++;
	//							}
	//							j++;
	//							sw->WriteLine("\n\t\t\t\t\t" + aux->Substring(j, 7)); //Betas
	//							sw->WriteLine("\t\t\t\t\t{");
	//							j += 9;
	//							for (int k = j; k < aux->Length; k++) {
	//								if (aux[k] != ',') {
	//									if (aux[k] != '}') {
	//										if (aux[k] != ' ') {
	//											tempBetas += aux[k];
	//										}
	//									}
	//									else {
	//										sw->WriteLine("\t\t\t\t\t\t" + tempBetas->Replace("=", " = "));
	//										sw->WriteLine("\t\t\t\t\t}");
	//										sw->WriteLine("\t\t\t\t}");
	//										sw->WriteLine("\t\t\t},\n");
	//										tempBetas = "";
	//										break;
	//									}
	//								}
	//								else {
	//									sw->WriteLine("\t\t\t\t\t\t" + tempBetas->Replace("=", " = ") + ",");
	//									tempBetas = "";
	//								}
	//							}

	//						}
	//					}

	//					sw->WriteLine("\t\t}");
	//					sw->WriteLine("\t}");
	//					sw->WriteLine("}\n");
	//					break;

	//				case POTENTIALDSAMPLEBASED:
	//				case POTENTIALCSAMPLEBASED:
	//					sw->WriteLine("P1 = " + tbPotential->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\tpotentialData =");
	//					sw->WriteLine("\t{");
	//					sw->WriteLine("\t\t-- Region 1");
	//					sw->WriteLine("\t\t{");

	//					for (int i = 1; i < tbPotential->Lines->Length; i++) {
	//						if (tbPotential->Lines[i]->ToString() != "") {
	//							sw->WriteLine("\t\t\t-- " + tempLUTs[i - 1]);
	//							sw->WriteLine("\t\t\t{");

	//							aux = tbPotential->Lines[i]->ToString()->Replace("attributesPerc", "$attributesPerc");
	//							aux = aux->Replace(", attributesClass", "attributesClass");

	//							int j = 0;
	//							String^ auxAttributes = "";

	//							//cellUsePercentage
	//							while (aux[j] != '$') {
	//								auxAttributes += aux[j];
	//								j++;
	//							}

	//							sw->WriteLine("\t\t\t\t" + auxAttributes);
	//							sw->WriteLine("");
	//							auxAttributes = "";
	//							j++;


	//							//attributesPerc
	//							while (aux[j] != '{') {
	//								auxAttributes += aux[j];
	//								j++;
	//							}

	//							sw->WriteLine("\t\t\t\t" + auxAttributes);
	//							sw->WriteLine("\t\t\t\t{");
	//							auxAttributes = "";
	//							j++;

	//							while (aux[j] != '}') {
	//								if (aux[j] != ',') {
	//									auxAttributes += aux[j];
	//								}
	//								else {
	//									if (aux[j + 1] != '}') {
	//										sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\"") + ",");
	//									}
	//									else {
	//										sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\""));
	//									}
	//									auxAttributes = "";
	//								}
	//								j++;
	//							}

	//							if (auxAttributes != "") {
	//								sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\""));
	//							}

	//							sw->WriteLine("\t\t\t\t},");
	//							sw->WriteLine("");
	//							auxAttributes = "";
	//							j++;

	//							//attributesClass
	//							while (aux[j] != '{') {
	//								auxAttributes += aux[j];
	//								j++;
	//							}

	//							sw->WriteLine("\t\t\t\t" + auxAttributes);
	//							sw->WriteLine("\t\t\t\t{");
	//							auxAttributes = "";
	//							j++;

	//							while (aux[j] != '}') {
	//								if (aux[j] != ',') {
	//									auxAttributes += aux[j];
	//								}
	//								else {
	//									if (aux[j + 1] != '}') {
	//										sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\"") + ",");
	//									}
	//									else {
	//										sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\""));
	//									}
	//									auxAttributes = "";
	//								}
	//								j++;
	//							}

	//							if (auxAttributes != "") {
	//								sw->WriteLine("\t\t\t\t\t" + auxAttributes->Replace(" \"", "\""));
	//							}

	//							if (aux[j + 1] != '}') {
	//								sw->WriteLine("\t\t\t\t},");
	//							}
	//							else {
	//								sw->WriteLine("\t\t\t\t}");
	//							}
	//							auxAttributes = "";
	//							j++;

	//							if (i + 1 < tbPotential->Lines->Length) {
	//								sw->WriteLine("\t\t\t},");
	//								sw->WriteLine("");
	//							}
	//							else {
	//								sw->WriteLine("\t\t\t}");
	//							}
	//						}
	//					}

	//					sw->WriteLine("\t\t}");
	//					sw->WriteLine("\t}");
	//					sw->WriteLine("}\n");
	//					break;

	//				default:
	//					break;
	//				}
	//			}

	//			if (tbAllocation->Lines->Length > 0) {
	//				sw->WriteLine("-----------------------------------------------------");
	//				sw->WriteLine("-- Allocation                                      --");
	//				sw->WriteLine("-----------------------------------------------------");

	//				array<String^>^ tempLUTs = gcnew array<String^>(50);
	//				int row = 0;
	//				String^ aux = "";
	//				String^ tempBetas = "";
	//				for (int i = 0; i < gLandUseTypes->Length; i++) {
	//					if (gLandUseTypes[i] != ',') {
	//						if (gLandUseTypes[i] != '\"') {
	//							aux += gLandUseTypes[i];
	//						}
	//					}
	//					else {
	//						tempLUTs[row] = aux;
	//						aux = "";
	//						row++;
	//					}
	//				}
	//				if (aux != "") {
	//					tempLUTs[row] = aux;
	//				}

	//				switch (gAllocationComponent)
	//				{
	//				case ALLOCATIONDSIMPLEORDERING:
	//					sw->WriteLine("A1 = " + tbAllocation->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\t" + tbAllocation->Lines[1]);
	//					sw->WriteLine("}\n");
	//					break;

	//				case ALLOCATIONDCLUESNEIGHORDERING:
	//				case ALLOCATIONDCLUESLIKE:
	//					sw->WriteLine("A1 = " + tbAllocation->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\t" + tbAllocation->Lines[1] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[2] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[3] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[4] + " =");
	//					sw->WriteLine("\t{");
	//					sw->WriteLine("\t\t--Region 1");
	//					sw->WriteLine("\t\t{");
	//					for (int i = 5; tbAllocation->Lines->Length - 1; i++) {
	//						if (i + 1 < tbAllocation->Lines->Length) {
	//							sw->WriteLine("\t\t\t{" + tbAllocation->Lines[i] + "},");
	//						}
	//						else {
	//							sw->WriteLine("\t\t\t{" + tbAllocation->Lines[i] + "}");
	//							break;
	//						}
	//					}
	//					sw->WriteLine("\t\t}");
	//					sw->WriteLine("\t}");
	//					sw->WriteLine("}\n");
	//					break;

	//				case ALLOCATIONCCLUELIKE:
	//					sw->WriteLine("A1 = " + tbAllocation->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\t" + tbAllocation->Lines[1] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[2] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[3] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[4] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[5] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[6]->ToString()->Replace("= ", "= \"") + "\",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[7] + " =");
	//					sw->WriteLine("\t{");
	//					for (int i = 8; i < tbAllocation->Lines->Length - 1; i++) {
	//						if (tbAllocation->Lines[i] != "") {
	//							if (i + 1 < tbAllocation->Lines->Length) {
	//								sw->WriteLine("\t\t{" + tbAllocation->Lines[i] + "},\t-- " + tempLUTs[i - 8]);
	//							}
	//							else {
	//								sw->WriteLine("\t\t{" + tbAllocation->Lines[i] + "}\t-- " + tempLUTs[i - 8]);
	//								break;
	//							}
	//						}
	//					}
	//					sw->WriteLine("\t}");
	//					sw->WriteLine("}\n");
	//					break;

	//				case ALLOCATIONCCLUELIKESATURATION:
	//					sw->WriteLine("A1 = " + tbAllocation->Lines[0]);
	//					sw->WriteLine("{");
	//					sw->WriteLine("\t" + tbAllocation->Lines[1] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[2] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[3] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[4] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[5] + ",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[6]->ToString()->Replace("= ", "= \"") + "\",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[7]->ToString()->Replace("= ", "= \"") + "\",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[8]->ToString()->Replace("= ", "= \"") + "\",");
	//					sw->WriteLine("\t" + tbAllocation->Lines[9] + " =");
	//					sw->WriteLine("\t{");
	//					for (int i = 10; i < tbAllocation->Lines->Length; i++) {
	//						if (tbAllocation->Lines[i] != "") {
	//							if (i + 1 < tbAllocation->Lines->Length) {
	//								sw->WriteLine("\t\t{" + tbAllocation->Lines[i] + "},\t-- " + tempLUTs[i - 10]);
	//							}
	//							else {
	//								sw->WriteLine("\t\t{" + tbAllocation->Lines[i] + "}\t-- " + tempLUTs[i - 10]);
	//								break;
	//							}
	//						}
	//					}
	//					sw->WriteLine("\t}");
	//					sw->WriteLine("}\n");
	//					break;
	//				default:
	//					break;
	//				}

	//			}
	//			sw->Close();

	//			if (File::Exists(path))
	//			{
	//				subFile = true;

	//			}

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
	//		}
	//	}
	//	catch (Exception^) {
	//		if (!mainFile) {
	//			if (forceWriting) {
	//				MessageBox::Show(gSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//				closing = true;
	//				this->Close();
	//			}
	//			else {
	//				System::Threading::Thread::Sleep(SECOND);
	//				if (File::Exists(path))
	//				{
	//					File::Delete(path);
	//				}

	//				forceWriting = true;
	//				bGerarArquivos_Click(sender, e);
	//			}
	//		}
	//		else if (!subFile) {
	//			if (forceWriting) {
	//				MessageBox::Show(gSSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//				closing = true;
	//				this->Close();
	//			}
	//			else {
	//				System::Threading::Thread::Sleep(SECOND);
	//				if (File::Exists(path))
	//				{
	//					File::Delete(path);
	//				}

	//				forceWriting = true;
	//				bGerarArquivos_Click(sender, e);
	//			}
	//		}
	//		else {
	//			if (forceWriting) {
	//				MessageBox::Show(gSFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	//				closing = true;
	//				this->Close();
	//			}
	//			else {
	//				System::Threading::Thread::Sleep(SECOND);
	//				if (File::Exists(path))
	//				{
	//					File::Delete(path);
	//				}

	//				forceWriting = true;
	//				bGerarArquivos_Click(sender, e);
	//			}
	//		}
	//	}
	//}
}