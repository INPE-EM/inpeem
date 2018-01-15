#include "stdafx.h"
#include "NovoModelo.h"
#include "Function.h"
#include "LanguageForm.h"
#include "AboutForm.h"
#include "EquationsForm.h"

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
		
		//tabSpatial
		tabSpatial->Text = "Spatial Model";
		lDatabase->Text = "File:";
		lTerraview->Text = "Terraview Project";
		lSpatialLayerName->Text = "Layer Name";
		lSpatialCellArea->Text = "Cell Size";

		//tabLUT
		tabLUT->Text = "Land Use Type";
		lLUTLarge->Text = "Land Use Types";

		//tabFileMaker
		tabFileMaker->Text = "Files Maker";
		lFileMaker->Text = "     Files Maker";
		bGerarArquivos->Text = "Make Files";
		lRunModel->Text = "       Run Model";
		bRun->Text = "Run Model";

		//Strings
		gSImportEquationErrorTitle = "Error - Importing Equations";
		gSImportEquationError = "The equations file (equations.dat) was not found.";
		gSProjTitle = "Select a Project File";
		gSProjFilter = "Terraview Project (*.tview)|*.tview";
		gSShape = "Shape File";
		gSShapeTitle = "Select a Shape File";
		gSShapeFilter = "Shape File (*.shp)|*.shp";
		gSDefaultTime = "Using defalut time for the simulation.\nDo you want to proceed?";
		gStringDefaultTimeTitle = "Using Default Time";
		gSTimeNotDef = "The suimulation time (start and end) must be defined.";
		gSTimeNotDefTitle = "Error - Initial and Final time not informed";
		gSFolderTitle = "Error - Project folder is missing";
		gSFolder = "Project folder not selected in Model Definition.";
		gSModelNameTitle = "Error - Model Name is missing";
		gSModelName = "Model Name not defined in Model Definition.";
		gSStartTime = "Initial Year not defined in Spatial Model.";
		gSStopTime = "Final Year not defined in Spatial Model.";
		gSSFileTitle = "Error - Spatial Data is missing";
		gSSFile = "A Shape file or Terraview Project must be selected in Spatial Model.";
		gSCellAreaTitle = "Error - Cell Area is missing";
		gSCellArea = "Cell Are not define in Spatial Data.";
		gSLayerNameTitle = "Error - Layer Name is missing";
		gSLayerName = "Layer Name not defined in Spatial Data";
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
		gSLuaFile = "Lua File(*.lua)|*.lua";
		gSImportErrorTitle = "Error - Importing Files";
		gSImportError = "Incloplete file, can't import it.";
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
		
		//tabSpatialModel
		tabSpatial->Text = "Modelo Espacial";

		lTerraview->Text = "Projeto Terraview";
		lDatabase->Text = "Arquivo:";
		lSpatialLayerName->Text = "Nome do Layer";
		lSpatialCellArea->Text = "Tamanho da Célula";
	
		//tabFileMaker
		tabFileMaker->Text = "Gerar Arquivos";
		lFileMaker->Text = "Gerar os Arquivos";
		bGerarArquivos->Text = "Gerar Arquivos";
		lRunModel->Text = "Rodar o Modelo";
		bRun->Text = "Rodar Modelo";

		//String
		gSImportEquationErrorTitle = "Erro - Importndo as equações";
		gSImportEquationError = "O arquivo com as equações não foi localizado (equations.dat).";
		gSProjTitle = "Selecione um Arquivo de Projeto";
		gSProjFilter = "Projeto Terraview (*.tview)|*.tview";
		gSShape = "Arquivo Shape";
		gSShapeTitle = "Escolha o arquivo Shape";
		gSShapeFilter = "Arquivo Shape (*.shp)|*.shp";
		gSDefaultTime = "Utilizando tempo de simulação padrão.\nDeseja continuar?";
		gStringDefaultTimeTitle = "Utilizando Tempo Padrão";
		gSTimeNotDef = "Os tempos da Simulação (inicial e final) devem ser definidos.";
		gSTimeNotDefTitle = "Erro - Tempos inicial e final não informados.";
		gSFolderTitle = "Erro - Pasta do projeto não selecionada";
		gSFolder = "Pasta do projeto não selecionada em Definições do Modelo.";
		gSModelNameTitle = "Erro - Nome do Modelo não definido";
		gSModelName = "Nome do Modelo não definido em Definições do Modelo.";
		gSSFileTitle = "Erro - Dado espacial não selecionado";
		gSSFile = "Um arquivo Shape ou um Projeto Terraview deve ser selecionado em Modelo Espacial";
		gSCellAreaTitle = "Erro - Cell Area não definido";
		gSCellArea = "Cell Area não definido em Dados Espaciais.";
		gSLayerNameTitle = "Erro - Nome do Layer não preenchido";
		gSLayerName = "Nome do Layer não definido em Dados Espaciais";
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
		gSLuaFile = "Arquivo Lua (*.lua)|*.lua";
		gSImportErrorTitle = "Erro - Importando Arquivos";
		gSImportError = "Arquivo incompleto, não pode ser carregado.";
	}
}

System::Void INPEEM::NovoModelo::checkEquations()
{
	String^ fileName = "D:\\_SVN\\INPE-EM\\branches\\Diego\\IPCC\\Debug\\equations.dat";
	try {
		StreamReader^ din = File::OpenText(fileName);
		int eqIndex = 0;

		while (din->EndOfStream == false) {
			gEquations[eqIndex] = din->ReadLine();
			eqIndex++;
		}

		din->Close();
	}
	catch (Exception^)
	{
		MessageBox::Show(gSImportEquationError, gSImportEquationErrorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		closing = true;
		this->Close();
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

/*
Count a number of a caracter on a String
*/
System::Int16 INPEEM::NovoModelo::countCaracter(String^ source, char caracter)
{
	int count = 0;
	for (int i = 0; i < source->Length; i++) {
		if (source[i] == caracter) {
			count++;
		}
	}
	return count;
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
	checkEquations();
	NovoModelo::Update();

	if (lOpen) {
		try {
			
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

System::Void INPEEM::NovoModelo::bEquationsManager_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lEquationReturn = gcnew cReturn();
	lEquationReturn->Language = lLanguage;

	EquationsForm^ equationForm = gcnew EquationsForm(lEquationReturn, gEquations, gEquationsOut);
	equationForm->MinimizeBox = false;
	equationForm->MaximizeBox = false;
	equationForm->ShowInTaskbar = false;
	equationForm->ShowDialog();

	tNovoModelo->SelectedIndex = 0;
	tNovoModelo->SelectedIndex = 3;
}

System::Void INPEEM::NovoModelo::tNovoModelo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (tNovoModelo->SelectedIndex == 3) {
		int lutCount = 0;

		while (lutCount < dgLUT->RowCount - 1) {
			for (int i = 0; i < dgLUT->RowCount - 1; i++) {
				Label^ lutLabel = gcnew Label();
				lutLabel->Name = "lutLabel" + i;
				lutLabel->Text = dgLUT->Rows[i]->Cells[0]->Value->ToString();
				lutLabel->Location = Point(75 + (i * 125), 200);
				tabEquations->Controls->Add(lutLabel);

				Label^ lutLabel2 = gcnew Label();
				lutLabel2->Name = "lutLabel2" + i;
				lutLabel2->Text = dgLUT->Rows[i]->Cells[0]->Value->ToString();
				lutLabel2->Location = Point(5, 230 + (i * 30));
				tabEquations->Controls->Add(lutLabel2);

				ComboBox^ selectFormula = gcnew ComboBox();
				selectFormula->Name = "cbSelectFormula" + lutCount + i;
				selectFormula->Location = Point(75 + (lutCount * 125), 225 + (i * 30));

				for (int j = 0; j < gEquationsOut->Length; j++) {
					if (gEquationsOut[j] == nullptr) {
						break;
					}
					else {
						String^ formulaNumber = "f0" + (j + 1) + " - ";
						selectFormula->Items->Add(formulaNumber + gEquationsOut[j]);
					}
				}

				tabEquations->Controls->Add(selectFormula);
				selectFormula->BringToFront();
				selectFormula->DropDownStyle = ComboBoxStyle::DropDownList;
			}
			lutCount++;
		}
	}
}

System::Void INPEEM::NovoModelo::bGerarArquivos_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool checked = true;
	
	if (lSelectedFolder->Text == "") {
		MessageBox::Show(gSFolder, gSFolderTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}
	else if (tModelName->Text == "") {
		MessageBox::Show(gSModelName, gSModelNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}
	else if (tInitialYear->Text == "" || tFinalYear->Text == "") {
		MessageBox::Show(gSTimeNotDef, gSTimeNotDefTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}
	else if (tSpatialLayerName->Text == "") {
		MessageBox::Show(gSLayerName, gSLayerNameTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}
	else if (tSpatialCellArea->Text == "") {
		MessageBox::Show(gSCellArea, gSCellAreaTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		checked = false;
	}

	//Try to retrieve data
	{
		int lutNumber = dgLUT->RowCount;
		int indexToFill = 0;
		array<String^>^ lutValue = gcnew array<String^>(dgLUT->RowCount);
		array<String^>^ equationMatrix = gcnew array<String^>(dgLUT->RowCount * dgLUT->RowCount);

		for (int i = 0; i < dgLUT->RowCount - 1; i++) {
			lutValue[i] = dgLUT->Rows[i]->Cells[1]->Value->ToString();
			for (int j = 0; j < dgLUT->RowCount - 1; j++) {
				ComboBox^ selectedEquation = safe_cast<System::Windows::Forms::ComboBox^>(Controls->Find("cbSelectFormula" + j + i, true)[0]);
				equationMatrix[indexToFill] = selectedEquation->SelectedItem->ToString();
				indexToFill++;
			}
		}

		int a = 0;
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

				if (shape) {
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
				sw->WriteLine("-- INPE-EM IPCC Model                                       --");
				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("");

				String^ folderAux = lSelectedFolder->Text->Replace("\\", "\\\\");

				if (folderAux->Length > ROOTDIR) {
					sw->WriteLine("MODELDIR = \"" + folderAux + "\\\\\"");
					sw->WriteLine("dofile(\"C:\\\\INPE-EM\\\\TerraME\\\\bin\\\\packages\\\\inpeem\\\\inpeEM.lua\")");
					sw->WriteLine("dofile(MODELDIR..\"" + tModelName->Text->ToLower() + "_submodel.lua\")");
				}
				else {
					sw->WriteLine("MODELDIR = \"" + folderAux + "\"");
					sw->WriteLine("dofile(\"C:\\\\INPE-EM\\\\TerraME\\\\bin\\\\packages\\\\inpeem\\\\inpeEM.lua\")");
					sw->WriteLine("dofile(MODELDIR..\"" + tModelName->Text->ToLower() + "_submodel.lua\")");
				}

				sw->WriteLine();
				sw->Close();
			}
		}
		catch (Exception^) {
			if (!mainFile) {
				if (forceWriting) {
					//MessageBox::Show(gSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
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
					//MessageBox::Show(gSSMFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
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
					//MessageBox::Show(gSFE + lSelectedFolder->Text, gSMFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
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

