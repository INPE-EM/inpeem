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
	if (gDeforest != "") {
		lDeforest->Return = gDeforest;
	}
	
	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lDeforest);
	deforestForm->ShowDialog();

	if (lDeforest->Return != "") {
		gDeforest = lDeforest->Return;
	}
}

Void INPEEM::NovoModelo::bBiomass_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lBiomass = gcnew cReturn();
	if (gBiomass != "") {
		lBiomass->Return = gBiomass;
	}

	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lBiomass);
	deforestForm->ShowDialog();

	if (lBiomass->Return != "") {
		gBiomass = lBiomass->Return;
	}
}

Void INPEEM::NovoModelo::bVegetationRemoval_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lVegetationRemoval = gcnew cReturn();
	if (gVegetationRemoval != "") {
		lVegetationRemoval->Return = gVegetationRemoval;
	}

	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lVegetationRemoval);
	deforestForm->ShowDialog();

	if (lVegetationRemoval->Return != "") {
		gVegetationRemoval = lVegetationRemoval->Return;
	}
}

Void INPEEM::NovoModelo::bSecondVegetation_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lSecondaryVegetation = gcnew cReturn();
	if (gSecondaryVegetation != "") {
		lSecondaryVegetation->Return = gSecondaryVegetation;
	}

	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lSecondaryVegetation);
	deforestForm->ShowDialog();

	if (lSecondaryVegetation->Return != "") {
		gSecondaryVegetation = lSecondaryVegetation->Return;
	}
}

Void INPEEM::NovoModelo::bDegrad_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lDegradation = gcnew cReturn();
	if (gDegradation != "") {
		lDegradation->Return = gDegradation;
	}

	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lDegradation);
	deforestForm->ShowDialog();

	if (lDegradation->Return != "") {
		gDegradation = lDegradation->Return;
	}
}

Void INPEEM::NovoModelo::bTableData_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lNonSpatialTables = gcnew cReturn();
	if (gNonSpatialTables != "") {
		lNonSpatialTables->Return = gNonSpatialTables;
	}

	NonSpatialDataTableForm^ nonSpatialDataTableForm = gcnew NonSpatialDataTableForm(lNonSpatialTables);
	nonSpatialDataTableForm->ShowDialog();

	if (lNonSpatialTables->Return != "") {
		gNonSpatialTables = lNonSpatialTables->Return;
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