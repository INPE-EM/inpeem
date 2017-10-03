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
		tabFileMaker->Text = "Files Maker";
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
		gSExitTitle = "Exiting - Data not saved";
		gSExit = "The data changed will be lost.\nDo you want to proceed?";
		gSSuccessTitle = "Files successfully generate";
		gSSuccess = "Files successfully recorded:\n";
		gSEditing = "LuccME - Editing a model";
		gSNewModelTitle = "Create a New Model";
		gSNewModel = "All the data will be lost.\nDo you want to proceed?";
		gSOpenModelTitle = "Open a New Model";
		gSMainImportTitle = "Main File Loaded, Select Submodel";
		gSMainImport = "Main file imported with sucess.\nSelect the Submodel File.";
		gSSubModelImportTitle = "Submodel File Loaded, Select Non Spatial Data";
		gSSubmodelImport = "Submodel file imported with sucess.\nSelect the Non Spatial Data File.";
		gSMainLoadTitle = "Main File to Import";
		gSMainLoad = "Select the Main File.";
		gSMainFile = "Select Main File";
		gSSubmodelFile = "Select Submodel File";
		gSNSDFile = "Select Non Spatial Data File";
		gSFileMissingTitle = "Make Files Error";
		gSFileMissing = "Error writing the main File.\nCheck the path:";
		gSFileMissing2 = "Error writing the submodel File.\nCheck the path:";
		gSFileMissing3 = "Error writing the nsData File.\nCheck the path:";
		gSMFETitle = "Error - Files Generation";
		gSFE = "An unexpected error while recording the files.";
		gSMFE = "Error recording the main file.";
		gSSMFE = "Error recording the submodel file.";
		gSNSDFE = "Error recording the nsdata file.";
		gSCoponentTitle = "Error - Component select but not defined";
		gStbBiomass = "Biomass Component not defined in Component, but selected in ";
		gStbDeforest = "Deforest Component not defined in Component, but selected in ";
		gSDegradation = "Degradation Component not defined in Component, but selected in ";
		gSSecondaryVegetation = "Secondary Vegetation Component not defined in Component, but selected in ";
		gSVegetationRemoval = "Vegetation Removal Component not defined in Component, but selected in ";
		gSNSModel = "Non Spatial Model.";
		gSSModel = "Spatial Model.";
		gSLuaFile = "Lua File(*.lua)|*.lua";
		gSImportErrorTitle = "Error - Importing Files";
		gSImportError = "Incloplete file, can't import it.";
		
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
		cbSpatialVerbose->Text = "Verboso";
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
		tabFileMaker->Text = "Gerar Arquivos";
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
		gSExitTitle = "Saindo - Dados não salvos";
		gSExit = "Os dados alterados serão perdidos.\nDeseja Continuar?";
		gSSuccessTitle = "Arquivos gerados com Sucesso";
		gSSuccess = "Arquivos gravados com sucesso:\n";
		gSEditing = "INPE-EM - Editando um modelo";
		gSNewModelTitle = "Criar um Novo Modelo";
		gSNewModel = "Todos os dados serão perdidos.\nDeseja Continuar?";
		gSOpenModelTitle = "Abrir um Novo Modelo";
		gSMainImportTitle = "Arquivo Main Carregado, Selecione o Submodelo";
		gSMainImport = "Arquivo Main importado com sucesso.\nSelecione o Arquivo do Submodelo.";
		gSSubModelImportTitle = "Arquivo Submodel Carregado, Selecione o Dado Não Espacial";
		gSSubmodelImport = "Arquivo Submodel importado com sucesso.\nSelecione o Arquivo do Dado Não Espacial.";
		gSMainLoadTitle = "Arquivo Main a ser Importado";
		gSMainLoad = "Selecione o Arquivo Main.";
		gSMainFile = "Selecione o arquivo Main";
		gSSubmodelFile = "Selecione o arquivo Submodel";
		gSNSDFile = "Selecione o arquivo de Dados Não Espaciais";
		gSFileMissingTitle = "Erro na geração dos Arquivos";
		gSFileMissing = "Erro na gravação do arquivo Principal.\nVerifique o caminho:";
		gSFileMissing2 = "Erro na gravação do arquivo de Sub-Modelo.\nVerifique o caminho:";
		gSFileMissing3 = "Erro na gravação do arquivo de Dados Não Espaciais.\nVerifique o caminho:";
		gSMFETitle = "Erro - Geração dos Arquivos";
		gSFE = "Erro não esperado gravando os arquivos.";
		gSMFE = "Erro na gravação do arquivo Main.";
		gSSMFE = "Erro na gravação do arquivo Submodel.";
		gSNSDFE = "Erro na gravação do arquivo Non Spatial Data.";
		gSCoponentTitle = "Erro - Componente selecionado, mas não preenchido";
		gStbBiomass = "O Componente de Biomassa não foi preenchindo, mas foi selecionado em ";
		gStbDeforest = "O Componente de Desmatamento não foi preenchindo, mas foi selecionado em ";
		gSDegradation = "O Componente de Degradação não foi preenchindo, mas foi selecionado em ";
		gSSecondaryVegetation = "O Componente de Vegetação Secundária não foi preenchindo, mas foi selecionado em ";
		gSVegetationRemoval = "O Componente de Vegetação Primária não foi preenchindo, mas foi selecionado em ";
		gSNSModel = "Modelo Não Espacial.";
		gSSModel = "Modelo Espacial.";
		gSLuaFile = "Arquivo Lua (*.lua)|*.lua";
		gSImportErrorTitle = "Erro - Importando Arquivos";
		gSImportError = "Arquivo incompleto, não pode ser carregado.";

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

System::Void INPEEM::NovoModelo::novoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	lReturn = NEWMODEL;
	this->Close();
}

Void INPEEM::NovoModelo::abrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	lReturn = OPENMODEL;
	this->Close();
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

Void INPEEM::NovoModelo::sobreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	AboutForm^ aboutForm = gcnew AboutForm(lLanguage);
	aboutForm->ShowInTaskbar = false;
	aboutForm->ShowDialog();
}

System::Void INPEEM::NovoModelo::sairToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Exit();
}

System::Void INPEEM::NovoModelo::NovoModelo_Load(System::Object^  sender, System::EventArgs^  e)
{
	checkLanguage();
	NovoModelo::Update();

	if (lOpen) {
		try {
			bool main = false;
			bool submodel = false;
			bool nsData = false;
			bool hasNonSpatialData = false;
			bool imported = true;
			int cbSelection = 0;

			MessageBox::Show(gSMainLoad, gSMainLoadTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);

			INPEEM::OpenFileDialog^ mainFile = gcnew OpenFileDialog;
			mainFile->Title = gSMainFile;
			mainFile->Multiselect = false;
			mainFile->Filter = gSLuaFile;
			mainFile->FilterIndex = 1;
			mainFile->ShowHelp = true;

			if (mainFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ fileName = mainFile->FileName;
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(fileName);
				bool found = false;

				String^ line = sw->ReadLine();
				line = sw->ReadLine();

				while (sw->EndOfStream == false) {
					if (line->Contains("import(\"gis\")") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						shape = true;
						break;
					}
				}

				sw->Close();
				
				sw = gcnew System::IO::StreamReader(fileName);
				line = sw->ReadLine();

				while (sw->EndOfStream == false) {
					if (line->Contains("MODELDIR") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				String^ tempLine = "";

				if (found) {
					tempLine = line;
					tempLine = tempLine->Replace("MODELDIR = ", "");
					tempLine = tempLine->Replace("\"", "");
					tempLine = tempLine->Replace("\\\\", "\\");

					if (tempLine->Length > OPENROOTDIR) {
						lSelectedFolder->Text = tempLine->Substring(0, tempLine->Length - 1);
					}
					else {
						lSelectedFolder->Text = tempLine;
					}
				}

				gParametersValues[0] = lSelectedFolder->Text;
				found = false;
				sw->Close();
				
				sw = gcnew System::IO::StreamReader(fileName);
				line = sw->ReadLine();

				while (sw->EndOfStream == false) {
					if (line->Contains("submodel") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				tempLine = "";

				if (found) {
					tempLine = line;
					tempLine = tempLine->Replace("dofile(MODELDIR..", "");
					tempLine = tempLine->Replace("_submodel.lua\")", "");
					tempLine = tempLine->Replace("\"", "");

					tModelName->Text = tempLine;
					tModelName->ForeColor = System::Drawing::Color::Black;
				}

				gParametersValues[1] = tModelName->Text;

				String^ path = "";
				path = lSelectedFolder->Text + "\\" + tModelName->Text + "_main.lua";

				if (!File::Exists(path))
				{
					imported = false;
					lSelectedFolder->Text = "";
				}

				found = false;
				sw->Close();

				//Non Spatial Model
				sw = gcnew System::IO::StreamReader(fileName);
				line = sw->ReadLine();

				while (sw->EndOfStream == false) {
					if (line->Contains("nonSpatialModel") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("}") != TRUE) {
						line = sw->ReadLine();
						tempLine += line + "#";
					}

					tempLine = tempLine->Replace("##", "#");
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\r", "");
					tempLine = tempLine->Substring(0, tempLine->Length - 1);
					
					array<String^>^ auxNonSpatialModel = tempLine->Split('#');
					
					auxNonSpatialModel[1] = auxNonSpatialModel[1]->Replace("name = \"", "");
					auxNonSpatialModel[1] = auxNonSpatialModel[1]->Replace("\",", "");

					tNonSpatialName->Text = auxNonSpatialModel[1];
					tNonSpatialName->ForeColor = System::Drawing::Color::Black;

					auxNonSpatialModel[2] = auxNonSpatialModel[2]->Replace("yearInit = ", "");
					auxNonSpatialModel[2] = auxNonSpatialModel[2]->Replace(",", "");

					tNonSpatialInitialYear->Text = auxNonSpatialModel[2];
					tNonSpatialInitialYear->ForeColor = System::Drawing::Color::Black;

					auxNonSpatialModel[3] = auxNonSpatialModel[3]->Replace("yearFinal = ", "");
					auxNonSpatialModel[3] = auxNonSpatialModel[3]->Replace(",", "");

					tNonSpatialFinalYear->Text = auxNonSpatialModel[3];
					tNonSpatialFinalYear->ForeColor = System::Drawing::Color::Black;

					for (int i = 4; i < auxNonSpatialModel->Length; i++) {
						if (auxNonSpatialModel[i]->Contains("componentB =")) {
							cbNonSpatialBiomass->Checked = true;
						}

						else if (auxNonSpatialModel[i]->Contains("componentD =")) {
							cbNonSpatialDeforest->Checked = true;
						}

						else if (auxNonSpatialModel[i]->Contains("componentVR =")) {
							cbNonSpatialVegetationRemoval->Checked = true;
						}

						else if (auxNonSpatialModel[i]->Contains("componentSV =")) {
							cbNonSpatialSecondaryVegetation->Checked = true;
						}

						else if (auxNonSpatialModel[i]->Contains("componentSV =")) {
							cbNonSpatialSecondaryVegetation->Checked = true;
						}

						else if (auxNonSpatialModel[i]->Contains("componentDEGRAD =")) {
							cbNonSpatialDegradation->Checked = true;
						}

						else if (auxNonSpatialModel[i]->Contains("dataTable =")) {
							hasNonSpatialData = true;
						}

						else if (auxNonSpatialModel[i]->Contains("verbose = true")) {
							cbNonSpatialVerbose->Checked = true;
						}

						else if (auxNonSpatialModel[i]->Contains("area =")) {
							auxNonSpatialModel[i] = auxNonSpatialModel[i]->Replace("area = ", "");
							auxNonSpatialModel[i] = auxNonSpatialModel[i]->Replace(",", "");

							tNonSpatialArea->Text = auxNonSpatialModel[i];
							tNonSpatialArea->ForeColor = System::Drawing::Color::Black;
						}
					}

					cbSelection = NSPATIALTYPE;
				}

				found = false;
				sw->Close();

				//Spatial Model
				sw = gcnew System::IO::StreamReader(fileName);
				line = sw->ReadLine();

				while (sw->EndOfStream == false) {
					if (line->Contains("spatialModel") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("}") != TRUE) {
						line = sw->ReadLine();
						tempLine += line + "#";
					}

					tempLine = tempLine->Replace("##", "#");
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\r", "");
					tempLine = tempLine->Substring(0, tempLine->Length - 1);

					array<String^>^ auxSpatialModel = tempLine->Split('#');

					auxSpatialModel[1] = auxSpatialModel[1]->Replace("name = \"", "");
					auxSpatialModel[1] = auxSpatialModel[1]->Replace("\",", "");

					tSpatialName->Text = auxSpatialModel[1];
					tSpatialName->ForeColor = System::Drawing::Color::Black;

					auxSpatialModel[2] = auxSpatialModel[2]->Replace("yearInit = ", "");
					auxSpatialModel[2] = auxSpatialModel[2]->Replace(",", "");

					tSpatialInitialYear->Text = auxSpatialModel[2];
					tSpatialInitialYear->ForeColor = System::Drawing::Color::Black;

					auxSpatialModel[3] = auxSpatialModel[3]->Replace("yearFinal = ", "");
					auxSpatialModel[3] = auxSpatialModel[3]->Replace(",", "");

					tSpatialFinalYear->Text = auxSpatialModel[3];
					tSpatialFinalYear->ForeColor = System::Drawing::Color::Black;

					auxSpatialModel[4] = auxSpatialModel[4]->Replace("cellarea = ", "");
					auxSpatialModel[4] = auxSpatialModel[4]->Replace(",", "");

					tSpatialCellArea->Text = auxSpatialModel[4];
					tSpatialCellArea->ForeColor = System::Drawing::Color::Black;

					for (int i = 4; i < auxSpatialModel->Length; i++) {
						if (auxSpatialModel[i]->Contains("componentB =")) {
							cbSpatialBiomass->Checked = true;
						}

						else if (auxSpatialModel[i]->Contains("componentD =")) {
							cbSpatialDeforest->Checked = true;
						}

						else if (auxSpatialModel[i]->Contains("componentVR =")) {
							cbSpatialVegetationRemoval->Checked = true;
						}

						else if (auxSpatialModel[i]->Contains("componentSV =")) {
							cbSpatialSecondaryVegetation->Checked = true;
						}

						else if (auxSpatialModel[i]->Contains("componentSV =")) {
							cbSpatialSecondaryVegetation->Checked = true;
						}

						else if (auxSpatialModel[i]->Contains("componentDEGRAD =")) {
							cbSpatialDegradation->Checked = true;
						}

						else if (auxSpatialModel[i]->Contains("verbose = true")) {
							cbSpatialVerbose->Checked = true;
						}

						else if (auxSpatialModel[i]->Contains("project =")) {
							auxSpatialModel[i] = auxSpatialModel[i]->Replace("project = ", "");
							auxSpatialModel[i] = auxSpatialModel[i]->Replace("\"", "");
							auxSpatialModel[i] = auxSpatialModel[i]->Replace(",", "");

							if (!shape) {
								lSelectedFile->Text = auxSpatialModel[i]->Replace("\\\\","\\");
							}
						}

						else if (auxSpatialModel[i]->Contains("layer =")) {
							auxSpatialModel[i] = auxSpatialModel[i]->Replace("layer = ", "");
							auxSpatialModel[i] = auxSpatialModel[i]->Replace("\"", "");
							auxSpatialModel[i] = auxSpatialModel[i]->Replace(",", "");

							tSpatialLayerName->Text = auxSpatialModel[i];
							tSpatialLayerName->ForeColor = System::Drawing::Color::Black;

							if (shape) {
								lSpatialLayerName->Enabled = false;
								tSpatialLayerName->Enabled = false;
							}
						}
					}
					
					found = false;
					sw->Close();

					if (shape) {
						sw = gcnew System::IO::StreamReader(fileName);

						line = sw->ReadLine();
						while (sw->EndOfStream == false) {
							if (line->Contains("Layer {") != TRUE) {
								line = sw->ReadLine();
							}
							else {
								while (line->Contains("file =") != TRUE) {
									line = sw->ReadLine();
								}
								line = line->Replace("file = ", "");
								line = line->Replace("\"", "");
								line = line->Replace("\\\\", "\\");
								line = line->Replace("\t", "");
								line = line->Replace("\r", "");

								lSelectedFile->Text = line;
							}
						}

						if (lSelectedFile->Text->Length >= 90) {
							lSelectedFile->Font = gcnew System::Drawing::Font(L"Calibri", 7);
						}
						else if (lSelectedFile->Text->Length >= 80) {
							lSelectedFile->Font = gcnew System::Drawing::Font(L"Calibri", 8);
						}
						else if (lSelectedFile->Text->Length >= 50) {
							lSelectedFile->Font = gcnew System::Drawing::Font(L"Calibri", 10);
						}
						else {
							lSelectedFile->Font = gcnew System::Drawing::Font(L"Calibri", 12);
						}

						sw->Close();
					}
					
					if (!File::Exists(lSelectedFile->Text))
					{
						imported = false;
						lSelectedFile->Text = "";
					}
					cbSelection = SPATIALTYPE;
				}
				
				//Combine Model
				sw = gcnew System::IO::StreamReader(fileName);
				line = sw->ReadLine();

				while (sw->EndOfStream == false) {
					if (line->Contains("combineModel") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("}") != TRUE) {
						line = sw->ReadLine();
						tempLine += line + "#";
					}

					tempLine = tempLine->Replace("##", "#");
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\r", "");
					tempLine = tempLine->Substring(0, tempLine->Length - 1);

					array<String^>^ auxCombineModel = tempLine->Split('#');

					auxCombineModel[1] = auxCombineModel[1]->Replace("name = ", "");
					auxCombineModel[1] = auxCombineModel[1]->Replace("\"", "");
					auxCombineModel[1] = auxCombineModel[1]->Replace(",", "");

					tModelName->Text = auxCombineModel[1];
					cbSelection = COMBINETYPE;
				}

				sw->Close();
				main = true;
				MessageBox::Show(gSMainImport, gSMainImportTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			//Submodel File
			INPEEM::OpenFileDialog^ submodelFile = gcnew OpenFileDialog;
			submodelFile->Title = gSSubmodelFile;
			submodelFile->Multiselect = false;
			submodelFile->Filter = gSLuaFile;
			submodelFile->FilterIndex = 1;
			submodelFile->ShowHelp = true;

			if (submodelFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ fileName = submodelFile->FileName;
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(fileName);
				String^ line = sw->ReadLine();
				String^ tempLine = "";
				bool found = false;

				//Biomass Component
				while (sw->EndOfStream == false) {
					if (line->Contains("B1 =") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("}") != TRUE) {
						tempLine += line + ";";
						line = sw->ReadLine();
					}
					
					tempLine += line + ";";
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\r", "");
					tempLine = tempLine->Replace("\"", "");
					tempLine = tempLine->Replace(",", "");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}", "");
					tempLine = tempLine->Replace("B1 = ", "");
					tempLine = tempLine->Replace("name = ", "");
					tempLine = tempLine->Replace("description = ", "");
					tempLine = tempLine->Replace("averAGB = ", "");
					tempLine = tempLine->Replace("averBGBPercAGB = ", "");
					tempLine = tempLine->Replace("averLitterPercAGB = ", "");
					tempLine = tempLine->Replace("averDeadWoodPercAGB = ", "");
					tempLine = tempLine->Replace("averFactorB_C = ", "");
					tempLine = tempLine->Replace("averFactorB_CO2 = ", "");
					tempLine = tempLine->Replace("averFactorB_CO2_fire = ", "");
					tempLine = tempLine->Replace("averFactorB_CH4_fire = ", "");
					tempLine = tempLine->Replace("averFactorB_N2O_fire = ", "");
					tempLine = tempLine->Replace("averFactorB_NOx_fire = ", "");
					tempLine = tempLine->Replace("averFactorB_CO_fire = ", "");
					tempLine = tempLine->Replace(";;", ";");

					tempLine = tempLine->Substring(1, tempLine->Length - 1);

					gBiomass = tempLine;
					showReturnBiomass();
				}
				
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);
				line = sw->ReadLine();
				tempLine = "";
				found = false;

				//Deforest Component
				while (sw->EndOfStream == false) {
					if (line->Contains("D1 =") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("}") != TRUE) {
						tempLine += line + ";";
						line = sw->ReadLine();
					}

					tempLine += line + ";";
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\r", "");
					tempLine = tempLine->Replace("\"", "");
					tempLine = tempLine->Replace(",", "");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}", "");
					tempLine = tempLine->Replace("D1 = ", "");
					tempLine = tempLine->Replace("name = ", "");
					tempLine = tempLine->Replace("description = ", "");
					tempLine = tempLine->Replace("initialArea = ", "");
					tempLine = tempLine->Replace(";;", ";");

					tempLine = tempLine->Substring(1, tempLine->Length - 1);

					gDeforest = tempLine;
					showReturnDeforest();
				}

				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);
				line = sw->ReadLine();
				tempLine = "";
				found = false;

				//Vegetation Removal Component
				while (sw->EndOfStream == false) {
					if (line->Contains("VR1 =") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("}") != TRUE) {
						tempLine += line + ";";
						line = sw->ReadLine();
					}

					tempLine += line + ";";
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\r", "");
					tempLine = tempLine->Replace("\"", "");
					tempLine = tempLine->Replace(",", "");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}", "");
					tempLine = tempLine->Replace("VR1 = ", "");
					tempLine = tempLine->Replace("name = ", "");
					tempLine = tempLine->Replace("description = ", "");
					tempLine = tempLine->Replace("save = ", "");
					tempLine = tempLine->Replace("averAGBPercAGB = ", "");
					tempLine = tempLine->Replace("averAGBPercWoodProducts = ", "");
					tempLine = tempLine->Replace("averAGBPercInstantaneous = ", "");
					tempLine = tempLine->Replace("averAGBPercDecomposition = ", "");
					tempLine = tempLine->Replace("averBGBPercBGB = ", "");
					tempLine = tempLine->Replace("averBGBPercInstantaneous = ", "");
					tempLine = tempLine->Replace("averBGBPercDecompositionAbove = ", "");
					tempLine = tempLine->Replace("averBGBPercDecompositionUnder = ", "");
					tempLine = tempLine->Replace("averDecompositionFireCyclePeriod = ", "");
					tempLine = tempLine->Replace("averDecompositonPercElementalCarbon = ", "");
					tempLine = tempLine->Replace("averLitterPercInstantaneous = ", "");
					tempLine = tempLine->Replace("averLitterPercDecomposition = ", "");
					tempLine = tempLine->Replace("averDeadWoodPercInstantaneous = ", "");
					tempLine = tempLine->Replace("averDeadWoodPercDecomposition = ", "");
					tempLine = tempLine->Replace("averDecayRateWoodProducts = ", "");
					tempLine = tempLine->Replace("averDecayRateElementalCarbon = ", "");
					tempLine = tempLine->Replace("averDecayRateAGBDecomposition = ", "");
					tempLine = tempLine->Replace("averDecayRateBGBDecompositionAbove = ", "");
					tempLine = tempLine->Replace("averDecayRateBGBDecompositionUnder = ", "");
					tempLine = tempLine->Replace("averDecayRateLitterDecomposition = ", "");
					tempLine = tempLine->Replace("averDecayRateDeadWoodDecomposition = ", "");
					tempLine = tempLine->Replace(";;", ";");

					tempLine = tempLine->Substring(1, tempLine->Length - 1);

					gVegetationRemoval = tempLine;
					showReturnVegetationRemoval();
				}

				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);
				line = sw->ReadLine();
				tempLine = "";
				found = false;

				//Secondary Vegetation Component
				while (sw->EndOfStream == false) {
					if (line->Contains("SV1 =") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("}") != TRUE) {
						tempLine += line + ";";
						line = sw->ReadLine();
					}

					tempLine += line + ";";
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\r", "");
					tempLine = tempLine->Replace("\"", "");
					tempLine = tempLine->Replace(",", "");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}", "");
					tempLine = tempLine->Replace("SV1 = ", "");
					tempLine = tempLine->Replace("name = ", "");
					tempLine = tempLine->Replace("description = ", "");
					tempLine = tempLine->Replace("save = ", "");
					tempLine = tempLine->Replace("averHalfLife = ", "");
					tempLine = tempLine->Replace("averAreaPercVegSec = ", "");
					tempLine = tempLine->Replace("averAreaAccPercVegSec = ", "");
					tempLine = tempLine->Replace("averRecoveryPeriod1Perc = ", "");
					tempLine = tempLine->Replace("averRecoveryPeriod1 = ", "");
					tempLine = tempLine->Replace("averRecoveryPeriod2Perc = ", "");
					tempLine = tempLine->Replace("averRecoveryPeriod2 = ", "");
					tempLine = tempLine->Replace("averAgriculturalUseCycle = ", "");
					tempLine = tempLine->Replace("averInitialAbandonmentCycle = ", "");
					tempLine = tempLine->Replace(";;", ";");

					tempLine = tempLine->Substring(1, tempLine->Length - 1);

					gSecondaryVegetation = tempLine;
					showReturnSecondaryVegetation();
				}

				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);
				line = sw->ReadLine();
				tempLine = "";
				found = false;

				//Degradation Component
				while (sw->EndOfStream == false) {
					if (line->Contains("DG1 =") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				if (found) {
					tempLine = "";
					while (line->Contains("}") != TRUE) {
						tempLine += line + ";";
						line = sw->ReadLine();
					}

					tempLine += line + ";";
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace("\r", "");
					tempLine = tempLine->Replace("\"", "");
					tempLine = tempLine->Replace(",", "");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}", "");
					tempLine = tempLine->Replace("DG1 = ", "");
					tempLine = tempLine->Replace("name = ", "");
					tempLine = tempLine->Replace("description = ", "");
					tempLine = tempLine->Replace("save = ", "");
					tempLine = tempLine->Replace("averAGB_loss = ", "");
					tempLine = tempLine->Replace("averBGB_loss = ", "");
					tempLine = tempLine->Replace("averDeadWood_loss = ", "");
					tempLine = tempLine->Replace("averLitter_loss = ", "");
					tempLine = tempLine->Replace("averAGB_percReduction = ", "");
					tempLine = tempLine->Replace("averPeriodRegrow = ", "");
					tempLine = tempLine->Replace("averLimiarDegradYears = ", "");
					tempLine = tempLine->Replace("averLimiarDegradLoss = ", "");
					tempLine = tempLine->Replace(";;", ";");

					tempLine = tempLine->Substring(1, tempLine->Length - 1);

					gDegradation = tempLine;
					showReturnDegradation();
				}

				sw->Close();
				submodel = true;

				if (hasNonSpatialData) {
					MessageBox::Show(gSSubmodelImport, gSSubModelImportTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
				}

			}

			//Non Spatial Data File
			if (hasNonSpatialData) {
				INPEEM::OpenFileDialog^ nsDataFile = gcnew OpenFileDialog;
				nsDataFile->Title = gSNSDFile;
				nsDataFile->Multiselect = false;
				nsDataFile->Filter = gSLuaFile;
				nsDataFile->FilterIndex = 1;
				nsDataFile->ShowHelp = true;

				if (nsDataFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					String^ fileName = nsDataFile->FileName;
					System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(fileName);
					String^ line = sw->ReadLine();
					String^ tempLine = "";
					bool found = false;
					
					while (sw->EndOfStream == false) {
						if (line->Contains("Area =") != TRUE) {
							line = sw->ReadLine();
						}
						else {
							found = true;
							break;
						}
					}

					if (found) {
						tempLine = "";
						while (line->Contains("}") != TRUE) {
							tempLine += line;
							line = sw->ReadLine();
						}
						
						tempLine = tempLine->Replace("\t", ""); 
						tempLine = tempLine->Replace("\r", "");
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("Area =", "");
						tempLine = tempLine->Replace("{", "");
						tempLine = tempLine->Replace("}", "");
					}
				
					gNonSpatialTables += tempLine + ";";
					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);
					line = sw->ReadLine();
					tempLine = "";
					found = false;

					while (sw->EndOfStream == false) {
						if (line->Contains("HalfLife =") != TRUE) {
							line = sw->ReadLine();
						}
						else {
							found = true;
							break;
						}
					}

					if (found) {
						tempLine = "";
						while (line->Contains("}") != TRUE) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace("\r", "");
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("HalfLife =", "");
						tempLine = tempLine->Replace("{", "");
						tempLine = tempLine->Replace("}", "");
					}

					gNonSpatialTables += tempLine + ";";
					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);
					line = sw->ReadLine();
					tempLine = "";
					found = false;

					while (sw->EndOfStream == false) {
						if (line->Contains("Degrad =") != TRUE) {
							line = sw->ReadLine();
						}
						else {
							found = true;
							break;
						}
					}

					if (found) {
						tempLine = "";
						while (line->Contains("}") != TRUE) {
							tempLine += line;
							line = sw->ReadLine();
						}

						tempLine = tempLine->Replace("\t", "");
						tempLine = tempLine->Replace("\r", "");
						tempLine = tempLine->Replace("\n", "");
						tempLine = tempLine->Replace("Degrad =", "");
						tempLine = tempLine->Replace("{", "");
						tempLine = tempLine->Replace("}", "");
					}
					
					gNonSpatialTables += tempLine;
					showReturnNonSpatialDataTable();
					sw->Close();
				}
			}

			if (main && submodel && imported) {
				lRunModel->Visible = true;
				bRun->Visible = true;
				runnable = true;
			}

			checkLanguage();
			this->Text = gSEditing;
			cbModelType->SelectedIndex = cbSelection;
		}
		catch (Exception^ e) {
			if (e->GetType()->ToString() == "System.IndexOutOfRangeException") {
				MessageBox::Show(gSImportError, gSImportErrorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
				closing = true;
				this->Close();
			}
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
		
		if (lSelectedFile->Text->Length >= 90) {
			lSelectedFile->Font = gcnew System::Drawing::Font(L"Calibri", 7);
		}
		else if (lSelectedFile->Text->Length >= 80) {
			lSelectedFile->Font = gcnew System::Drawing::Font(L"Calibri", 8);
		}
		else if (lSelectedFile->Text->Length >= 50) {
			lSelectedFile->Font = gcnew System::Drawing::Font(L"Calibri", 10);
		}
		else {
			lSelectedFile->Font = gcnew System::Drawing::Font(L"Calibri", 12);
		}

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
	lines[4] = "initialArea = " + auxDeforest[2];
	lines[5] = "}";

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
	lines[9] = "averLitter_loss = " + auxDegradation[6] + ",";
	lines[10] = "";
	lines[11] = "averAGB_percReduction = 0,";		//auxDegradation[7] + ",";
	lines[12] = "averPeriodRegrow = " + auxDegradation[8] + ",";
	lines[13] = "averLimiarDegradYears = 0,";		//auxDegradation[9]
	lines[14] = "averLimiarDegradLoss = 0";			//auxDegradation[10]
	lines[15] = "}";

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
	lines[14] = "averInitialAbandonmentCycle = " + auxSecondaryVegetatin[11];
	lines[15] = "}";

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

		else if (cbNonSpatialBiomass->Checked && tbBiomass->Lines->Length == NONE) {
			MessageBox::Show(gStbBiomass + gSNSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
		
		else if (cbNonSpatialDeforest->Checked && tbDeforest->Lines->Length == NONE) {
			MessageBox::Show(gStbDeforest + gSNSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
		
		else if (cbNonSpatialDegradation->Checked && tbDegrad->Lines->Length == NONE) {
			MessageBox::Show(gSDegradation + gSNSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
		
		else if (cbNonSpatialSecondaryVegetation->Checked && tbSecondVegetation->Lines->Length == NONE) {
			MessageBox::Show(gSSecondaryVegetation + gSNSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}
		
		else if (cbNonSpatialVegetationRemoval->Checked && tbVegetationRemoval->Lines->Length == NONE) {
			MessageBox::Show(gSVegetationRemoval + gSNSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
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

		else if (cbSpatialBiomass->Checked && tbBiomass->Lines->Length == NONE) {
			MessageBox::Show(gStbBiomass + gSSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (cbSpatialDeforest->Checked && tbDeforest->Lines->Length == NONE) {
			MessageBox::Show(gStbDeforest + gSSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (cbSpatialDegradation->Checked && tbDegrad->Lines->Length == NONE) {
			MessageBox::Show(gSDegradation + gSSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (cbSpatialSecondaryVegetation->Checked && tbSecondVegetation->Lines->Length == NONE) {
			MessageBox::Show(gSSecondaryVegetation + gSSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			checked = false;
		}

		else if (cbSpatialVegetationRemoval->Checked && tbVegetationRemoval->Lines->Length == NONE) {
			MessageBox::Show(gSVegetationRemoval + gSSModel, gSCoponentTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
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
		String^ path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\\\" + tModelName->Text->ToLower() + "_main.lua";
		path = path->Replace("\\\\\\\\", "\\\\");
		path = path->Replace("\t", "");
		path = path->Replace("\n", "");
		
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
					sw->WriteLine("import(\"gis\")\n");
					sw->WriteLine("proj = Project {");
					sw->WriteLine("\tfile = \"t3mp.tview\",");
					sw->WriteLine("\tclean = true");
					sw->WriteLine("}\n");

					sw->WriteLine("l1 = Layer {");
					sw->WriteLine("\tproject = proj,");
					sw->WriteLine("\tname = \"" + tSpatialLayerName->Text + "\",");
					sw->WriteLine("\tfile = \"" + lSelectedFile->Text->Replace("\\", "\\\\") + "\"");
					sw->WriteLine("}\n");
				}
	
				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("-- INPE-EM Model                                            --");
				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("");
								
				String^ folderAux = lSelectedFolder->Text->Replace("\\", "\\\\");
				
				if (folderAux->Length > ROOTDIR) {
					sw->WriteLine("MODELDIR = \"" + folderAux + "\\\\\"");
					sw->WriteLine("dofile(\"C:\\\\INPE-EM\\\\TerraME\\\\bin\\\\packages\\\\inpeem\\\\inpeEM.lua\")");
					sw->WriteLine("dofile(MODELDIR..\"" + tModelName->Text->ToLower() + "_submodel.lua\")");
					
					if (cbModelType->SelectedIndex == NSPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
						sw->WriteLine("dofile(MODELDIR..\"" + tModelName->Text->ToLower() + "_nsdata.lua\")");
					}
				}
				else {
					sw->WriteLine("MODELDIR = \"" + folderAux + "\"");
					sw->WriteLine("dofile(\"C:\\\\INPE-EM\\\\TerraME\\\\bin\\\\packages\\\\inpeem\\\\inpeEM.lua\")");
					sw->WriteLine("dofile(MODELDIR..\"" + tModelName->Text->ToLower() + "_submodel.lua\")");
					
					if (cbModelType->SelectedIndex == NSPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
						sw->WriteLine("dofile(MODELDIR..\"" + tModelName->Text->ToLower() + "_nsdata.lua\")");
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
					
					if (cbNonSpatialBiomass->Checked) {
						sw->WriteLine("\tcomponentB = B1,");
					}

					if (cbNonSpatialDeforest->Checked) {
						sw->WriteLine("\tcomponentD = D1,");
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

					if (cbSpatialBiomass->Checked) {
						sw->WriteLine("\tcomponentB = B1,");
					}

					if (cbSpatialDeforest->Checked) {
						sw->WriteLine("\tcomponentD = D1,");
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
						sw->WriteLine("\tproject = \"" + lSelectedFile->Text->Replace("\\","\\\\") + "\",");
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
					sw->WriteLine("\tmode = \"combine\",");
					
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
				path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\\\" + tModelName->Text->ToLower() + "_submodel.lua";
				path = path->Replace("\\\\\\\\", "\\\\");
				path = path->Replace("\t", "");
				path = path->Replace("\n", "");

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

				if (cbModelType->SelectedIndex == SPATIALTYPE) {
					nsFile = true;
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
				if (mainFile && subFile && nsFile) {
					if (cbModelType->SelectedIndex == SPATIALTYPE) {
						if (lSelectedFolder->Text->Length > ROOTDIR) {
							MessageBox::Show(gSSuccess + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + "_main.lua" + "\n" + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + "_submodel.lua", gSSuccessTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
						}
						else {
							MessageBox::Show(gSSuccess + lSelectedFolder->Text + tModelName->Text->ToLower() + "_main.lua" + "\n" + lSelectedFolder->Text + tModelName->Text->ToLower() + "_submodel.lua", gSSuccessTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
						}
					}
					else {
						if (lSelectedFolder->Text->Length > ROOTDIR) {
							MessageBox::Show(gSSuccess + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + "_main.lua" + "\n" + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + "_submodel.lua" +
								"\n" + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + "_nsdata.lua", gSSuccessTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
						}
						else {
							MessageBox::Show(gSSuccess + lSelectedFolder->Text + tModelName->Text->ToLower() + "_main.lua" + "\n" + lSelectedFolder->Text + tModelName->Text->ToLower() + "_submodel.lua" +
								"\n" + lSelectedFolder->Text + tModelName->Text->ToLower() + "_nsdata.lua", gSSuccessTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
						}
					}

					lRunModel->Visible = true;
					bRun->Visible = true;
					runnable = true;

					gParametersValues[0] = lSelectedFolder->Text;
					gParametersValues[1] = tModelName->Text;
					
					if (cbModelType->SelectedIndex == NSPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
						gParametersValues[2] = tNonSpatialName->Text;
						gParametersValues[3] = tNonSpatialInitialYear->Text;
						gParametersValues[4] = tNonSpatialFinalYear->Text;
						gParametersValues[5] = tNonSpatialArea->Text;
						gParametersValues[6] = cbNonSpatialDeforest->Checked.ToString();
						gParametersValues[7] = cbNonSpatialBiomass->Checked.ToString();
						gParametersValues[8] = cbNonSpatialVegetationRemoval->Checked.ToString();
						gParametersValues[9] = cbNonSpatialSecondaryVegetation->Checked.ToString();
						gParametersValues[10] = cbNonSpatialDegradation->Checked.ToString();
						gParametersValues[11] = cbNonSpatialVerbose->Checked.ToString();
					}
					if (cbModelType->SelectedIndex == SPATIALTYPE || cbModelType->SelectedIndex == COMBINETYPE) {
						gParametersValues[12] = tSpatialName->Text;
						gParametersValues[13] = tSpatialInitialYear->Text;
						gParametersValues[14] = tSpatialFinalYear->Text;
						gParametersValues[15] = lSelectedFile->Text;
						gParametersValues[16] = tSpatialLayerName->Text;
						gParametersValues[17] = tSpatialCellArea->Text;
						gParametersValues[18] = cbSpatialDeforest->Checked.ToString();
						gParametersValues[19] = cbSpatialBiomass->Checked.ToString();
						gParametersValues[20] = cbSpatialVegetationRemoval->Checked.ToString();
						gParametersValues[21] = cbSpatialSecondaryVegetation->Checked.ToString();
						gParametersValues[22] = cbSpatialDegradation->Checked.ToString();
						gParametersValues[23] = cbSpatialVerbose->Checked.ToString();
					}
				}
				else {
					if (!mainFile) {
						MessageBox::Show(gSFileMissing + lSelectedFolder->Text, gSFileMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					else {
						MessageBox::Show(gSFileMissing2 + lSelectedFolder->Text, gSFileMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
		}
		catch (Exception^) {
			if (!mainFile) {
				if (forceWriting) {
					MessageBox::Show(gSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					closing = true;
					this->Close();
				}
				else {
					System::Threading::Thread::Sleep(SECOND);
					if (File::Exists(path))
					{
						File::Delete(path);
					}

					forceWriting = true;
					bGerarArquivos_Click(sender, e);
				}
			}
			else if (!subFile) {
				if (forceWriting) {
					MessageBox::Show(gSSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					closing = true;
					this->Close();
				}
				else {
					System::Threading::Thread::Sleep(SECOND);
					if (File::Exists(path))
					{
						File::Delete(path);
					}

					forceWriting = true;
					bGerarArquivos_Click(sender, e);
				}
			}
			else if (!nsFile) {
				if (forceWriting) {
					MessageBox::Show(gSNSDFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					closing = true;
					this->Close();
				}
				else {
					System::Threading::Thread::Sleep(SECOND);
					if (File::Exists(path))
					{
						File::Delete(path);
					}

					forceWriting = true;
					bGerarArquivos_Click(sender, e);
				}
			}
			else {
				if (forceWriting) {
					MessageBox::Show(gSFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					closing = true;
					this->Close();
				}
				else {
					System::Threading::Thread::Sleep(SECOND);
					if (File::Exists(path))
					{
						File::Delete(path);
					}

					forceWriting = true;
					bGerarArquivos_Click(sender, e);
				}
			}
		}
	}
}

System::Void INPEEM::NovoModelo::bRun_Click(System::Object^  sender, System::EventArgs^  e)
{
	Environment::SetEnvironmentVariable("TME_PATH", "C:\\INPE-EM\\Terrame\\bin");
	Environment::SetEnvironmentVariable("PATH", "C:\\INPE-EM\\Terrame\\bin");

	String^ arguments = "";

	if (lSelectedFolder->Text[lSelectedFolder->Text->Length - 1] != '\\') {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + "\\\\" + tModelName->Text->ToLower() + "_main.lua\"";
	}
	else {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + tModelName->Text->ToLower() + "_main.lua\"";
	}

	System::Diagnostics::Process^ cmd = gcnew System::Diagnostics::Process;
	cmd->StartInfo->FileName = "C:\\INPE-EM\\TerraME\\bin\\inpeem.bat";
	cmd->StartInfo->Arguments = arguments;
	cmd->Start();
	cmd->WaitForExit();
	cmd->Close();

	cmd = gcnew System::Diagnostics::Process;
	arguments = "";
}

System::Void INPEEM::NovoModelo::luccMEToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (lLanguage == "en") {
		Help::ShowHelp(this, "help.chm");
	}
	else {
		Help::ShowHelp(this, "ajuda.chm");
	}
}