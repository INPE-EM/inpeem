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
		gSLUTErrorTitle = "Error - Use Types";
		gSLUTError = "All values realted to the use types must be fulfilled.";
		gSEquationRelationTitle = "Error - Equations Relationship";
		gSEquationRelation = "The equations must be selcted for each use in Use Types.";
		gSFETitle = "Error - Files Generation";
		gSFE = "Error recording the file.";
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
		gSLUTErrorTitle = "Erro - Tipos de Uso";
		gSLUTError = "Todos os valores relativo aos usos devem ser preenchidos em Tipos de Uso";
		gSEquationRelationTitle = "Erro - Relação das Equações";
		gSEquationRelation = "As equações devem ser selecionadas por uso em Equações.";
		gSFETitle = "Erro - Geração de Arquivo";
		gSFE = "Erro na geração do arquivo .lua.";
	}
}

System::Void INPEEM::NovoModelo::checkEquations()
{
	String^ fileName = "D:\\_SVN\\INPE-EM\\branches\\Diego\\IPCC\\Debug\\equations.dat";
	try {
		StreamReader^ din = File::OpenText(fileName);
		int eqIndex = 0;

		while (din->EndOfStream == false) {
			gEquations[eqIndex] = din->ReadLine()->Replace(" ", "");
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

System::Void INPEEM::NovoModelo::comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	System::Windows::Forms::ComboBox^ thisComboBox = safe_cast<System::Windows::Forms::ComboBox^>(sender);
	int lutNumber = dgLUT->RowCount - 1;
	int numberDigits = lutNumber.ToString()->Length;
	int x = 0;
	int y = 0;
	String^ aux = thisComboBox->Name;
	
	String^ pattern = "[a-zA-Z]*";
	System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(pattern);
	
	aux = aux->Replace(regex->Match(aux)->ToString(), "");

	int dif = aux->Length - numberDigits;

	if (dif == 0) {
		y = Convert::ToInt16(aux->Substring(0, numberDigits - 1));
		x = Convert::ToInt16(aux->Substring(numberDigits - 1));
	}
	else {
		if (aux[numberDigits] != 0 && numberDigits != 1) {
			y = Convert::ToInt16(aux->Substring(0, numberDigits - 1));
			x = Convert::ToInt16(aux->Substring(numberDigits - 1));
		}
		else {
			y = Convert::ToInt16(aux->Substring(0, numberDigits));
			x = Convert::ToInt16(aux->Substring(numberDigits));
		}
	}

	gEquationsRelation[x, y] = thisComboBox->SelectedItem->ToString();
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

System::Void INPEEM::NovoModelo::addEquations()
{
	for (int i = 0; i < gEquationsOut->Length; i++) {
		if (gEquationsOut[i] != nullptr) {
			bool hasEquations = false;
			for (int j = 0; j < dgLUT->RowCount - 1; j++) {
				for (int k = 0; k < dgLUT->RowCount - 1; k++) {
					ComboBox^ auxComboBox = safe_cast<System::Windows::Forms::ComboBox^>(Controls->Find("cbSelectFormula" + j + "" + k, true)[0]);
					String^ formulaNumber = "";

					if (i < TWODIGITS) {
						formulaNumber = "f0" + (i + 1) + ": ";
					}
					else {
						formulaNumber = "f" + (i + 1) + ": ";
					}

					for (int w = 0; w < auxComboBox->Items->Count; w++) {
						if (auxComboBox->Items[w]->Equals(formulaNumber + gEquationsOut[i])) {
							hasEquations = true;
						}
					}

					if (!hasEquations) {
						auxComboBox->Items->Add(formulaNumber + gEquationsOut[i]);
					}
				}
			}
		}
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

	addEquations();
	NovoModelo::Update();
}

System::Void INPEEM::NovoModelo::tNovoModelo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	gLUTNumber = dgLUT->RowCount - 1;
	checkLUTNames();

	if (tNovoModelo->SelectedIndex == EQUATIONS && gLUTNumber != gLUTNumberDrawn) {
		int lutCount = 0;

		while (lutCount != dgLUT->RowCount - 1) {
			Label^ lutLabel = gcnew Label();
			lutLabel->Name = "lutLabel" + lutCount;
			lutLabel->Text = dgLUT->Rows[lutCount]->Cells[0]->Value->ToString();
			lutLabel->Location = Point(75 + (lutCount * XOFFSET), 200);
			tabEquations->Controls->Add(lutLabel);

			Label^ lutLabel2 = gcnew Label();
			lutLabel2->Name = "lutLabel2" + lutCount;
			lutLabel2->Text = dgLUT->Rows[lutCount]->Cells[0]->Value->ToString();
			lutLabel2->Location = Point(0, 230 + (lutCount * YOFFSET));
			tabEquations->Controls->Add(lutLabel2);

			for (int i = 0; i < dgLUT->RowCount - 1; i++) {
				ComboBox^ selectFormula = gcnew ComboBox();
				selectFormula->Name = "cbSelectFormula" + lutCount + i;
				selectFormula->Location = Point(75 + (lutCount * XOFFSET), 225 + (i * YOFFSET));
				selectFormula->SelectedIndexChanged += gcnew System::EventHandler(this, &NovoModelo::comboBox_SelectedIndexChanged);
				selectFormula->DropDownStyle = ComboBoxStyle::DropDownList;
				tabEquations->Controls->Add(selectFormula);
				selectFormula->BringToFront();
			}

			lutCount++;
		}

		addEquations();
		gLUTNumberDrawn = lutCount;
		drawn = true;
		
		for (int i = 0; i < MAXEQUATIONS; i++) {
			for (int j = 0; j < MAXEQUATIONS; j++) {
				if (gEquationsRelation[i, j] != nullptr) {
					ComboBox^ auxComboBox = safe_cast<System::Windows::Forms::ComboBox^>(Controls->Find("cbSelectFormula" + i + "" + j, true)[0]);
					
					for (int k = 0; k < auxComboBox->Items->Count; k++) {
						if (auxComboBox->Items[k]->Equals(gEquationsRelation[i, j])) {
							auxComboBox->SelectedIndex = k;
							break;
						}
					}
				}
			}
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
	else if (lSelectedFile->Text == "") {
		MessageBox::Show(gSSFile, gSSFileTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
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
	else if (dgLUT->RowCount - 1 > 0) {
		for (int i = 0; i < dgLUT->RowCount - 1; i++) {
			for (int j = 0; j < dgLUT->RowCount - 1; j++) {
				if (dgLUT->Rows[i]->Cells[0]->Value == nullptr || dgLUT->Rows[i]->Cells[1]->Value == nullptr) {
					MessageBox::Show(gSLUTError, gSLUTErrorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					checked = false;
					break;
				}

				if (gEquationsRelation[i, j] == nullptr) {
					MessageBox::Show(gSEquationRelation, gSEquationRelationTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
					checked = false;
				}
			}
		}
	}

	if (checked) {
		bool mainFile = false;
	
		DateTime now = DateTime::Now;
		String^ dateTime = now.ToString("d") + " at " + now.ToString("T");

		//Creating main File
		String^ path = lSelectedFolder->Text->Replace("\\", "\\\\") + "\\\\" + tModelName->Text->ToLower() + ".lua";
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
				sw->WriteLine("--------------------------------------------------------------------");
				sw->WriteLine("-- This file contains a INPE-EM IPCC APPLICATION MODEL definition --");
				sw->WriteLine("--                 Compatible with INPE-EM 3.0                    --");
				sw->WriteLine("--       Generated with INPE-EM IPCC Model Configurator           --");
				sw->WriteLine("--                    " + dateTime + "                       --");
				sw->WriteLine("--------------------------------------------------------------------\n");

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
				sw->WriteLine("-- INPE-EM IPCC APPLICATION MODEL DEFINITION                --");
				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("import(\"inpeemipcc\")");
				sw->WriteLine("");

				sw->WriteLine(tModelName->Text + " = LuccMEModel");
				sw->WriteLine("{");
				sw->WriteLine("\tname = \"" + tModelName->Text + "\",\n");

				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Temporal dimension definition                   --");
				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\tstartTime = " + tInitialYear->Text + ",");
				sw->WriteLine("\tendTime = " + tFinalYear->Text + ",\n");
				sw->WriteLine("");

				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Spatial dimension definition                    --");
				sw->WriteLine("\t-----------------------------------------------------");

				if (shape) {
					sw->WriteLine("\tcs = CellularSpace");
					sw->WriteLine("\t{");
					sw->WriteLine("\t\tproject = \"t3mp.tview\",");
					sw->WriteLine("\t\tlayer = \"" + tSpatialLayerName->Text + "\",");
					sw->WriteLine("\t\tcellArea = " + tSpatialCellArea->Text + ",");
					sw->WriteLine("\t},");
				}
				else {
					sw->WriteLine("\tcs = CellularSpace");
					sw->WriteLine("\t{");
					sw->WriteLine("\t\tproject = \"" + lSelectedFile->Text->Replace("\\", "\\\\") + "\",");
					sw->WriteLine("\t\tlayer = \"" + tSpatialLayerName->Text + "\",");
					sw->WriteLine("\t\tcellArea = " + tSpatialCellArea->Text + ",");
					sw->WriteLine("\t},");
				}
				
				sw->WriteLine("");

				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Land use values definition                      --");
				sw->WriteLine("\t-----------------------------------------------------");

				String^ lutNames = "";
				String^ lutValues = "";

				for (int i = 0; i < dgLUT->RowCount; i++) {
					if (i + 1 < dgLUT->RowCount - 1) {
						lutNames += dgLUT->Rows[i]->Cells[0]->Value + ",";
						lutValues += dgLUT->Rows[i]->Cells[1]->Value + ",";
					}
					else {
						lutNames += dgLUT->Rows[i]->Cells[0]->Value;
						lutValues += dgLUT->Rows[i]->Cells[1]->Value;
					}
				}

				sw->WriteLine("\tlandUseValues = {" + lutValues + "}, \t--" + lutNames);
				sw->WriteLine("");
				sw->WriteLine("\ttransitionMatrix = ");
				sw->WriteLine("\t{");

				for (int i = 0; i < gLUTNumber; i++) {
					String^ auxLine = "{";
					
					for (int j = 0; j < gLUTNumber; j++) {
						if (j + 1 < gLUTNumber) {
							auxLine += "\"" + gEquationsRelation[i, j] + "\",";
						}
						else {
							auxLine += "\"" + gEquationsRelation[i, j] + "\"";
						}
					}
					if (i + 1 < gLUTNumber) {
						auxLine += "},";
					}
					else {
						auxLine += "}";
					}

					sw->WriteLine("\t\t" + auxLine);
				}
				sw->WriteLine("\t}");
				sw->WriteLine("}  -- END INPE-EM IPCC application model definition\n");

				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("-- ENVIROMMENT DEFINITION                          --");
				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("timer = Timer");
				sw->WriteLine("{");
				sw->WriteLine("\tEvent");
				sw->WriteLine("\t{");
				sw->WriteLine("\t\tstart = " + tModelName->Text + ".startTime,");
				sw->WriteLine("\t\taction = function(event)");
				sw->WriteLine("\t\t\t\t\t" + tModelName->Text + ":run(event)");
				sw->WriteLine("\t\t\t\t  end");
				sw->WriteLine("\t}");
				sw->WriteLine("}\n");

				sw->WriteLine("env_" + tModelName->Text + " = Environment{}");
				sw->WriteLine("env_" + tModelName->Text + ":add(timer)\n");

				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("-- ENVIROMMENT EXECUTION                           --");
				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("if " + tModelName->Text + ".isCoupled == false then");
				sw->WriteLine("\ttsave = databaseSave(" + tModelName->Text + ")");
				sw->WriteLine("\tenv_" + tModelName->Text + ":add(tsave)");
				sw->WriteLine("\tenv_" + tModelName->Text + ":run(" + tModelName->Text + ".endTime)");
				sw->WriteLine("\tsaveSingleTheme(" + tModelName->Text + ", true)");

				if (shape) {
					sw->WriteLine("\tprojFile = File(\"t3mp.tview\")");
					sw->WriteLine("\tif(projFile:exists()) then");
					sw->WriteLine("\t\tprojFile:delete()");
					sw->WriteLine("\tend");
				}

				sw->WriteLine("end");
				sw->Close();

				if (File::Exists(path))
				{
					if (lSelectedFolder->Text->Length > ROOTDIR) {
						MessageBox::Show(gSSuccess + lSelectedFolder->Text + "\\" + tModelName->Text->ToLower() + ".lua", gSSuccessTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else {
						MessageBox::Show(gSSuccess + lSelectedFolder->Text + tModelName->Text->ToLower() + "_.lua", gSSuccessTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
					}

					lRunModel->Visible = true;
					bRun->Visible = true;
					runnable = true;
				}
			}
		}
		catch (Exception^) {
			if (!mainFile) {
				if (forceWriting) {
					MessageBox::Show(gSFE + lSelectedFolder->Text, gSFETitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
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

System::Void INPEEM::NovoModelo::dgLUT_RowsRemoved(System::Object^  sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^  e)
{
	bool deleted = false;
	for (int i = 0; i < gLUTNumber; i++) {
		Label^ auxLabel1 = safe_cast<System::Windows::Forms::Label^>(Controls->Find("lutLabel" + i, true)[0]);
		Label^ auxLabel2 = safe_cast<System::Windows::Forms::Label^>(Controls->Find("lutLabel2" + i, true)[0]);


		if (auxLabel1 != nullptr) {
			deleted = true;
			drawn = false;
			tabEquations->Controls->Remove(Controls->Find(auxLabel1->Name, true)[0]);
			tabEquations->Controls->Remove(Controls->Find(auxLabel2->Name, true)[0]);

			for (int j = 0; j < gLUTNumber; j++) {
				ComboBox^ auxComboBox = safe_cast<System::Windows::Forms::ComboBox^>(Controls->Find("cbSelectFormula" + i + "" + j, true)[0]);
				tabEquations->Controls->Remove(Controls->Find(auxComboBox->Name, true)[0]);
			}
		}
	}

	//Redrawn the screen
	if (deleted) {
		for (int i = 0; i < MAXEQUATIONS; i++) {
			gEquationsRelation[e->RowIndex, i] = nullptr;
			gEquationsRelation[i, e->RowIndex] = nullptr;
		}

		for (int i = e->RowIndex; i < MAXEQUATIONS; i++) {
			for (int j = 0; j < MAXEQUATIONS; j++) {
				if (i + 1 < MAXEQUATIONS) {
					if (gEquationsRelation[i + 1, j] != nullptr) {
						gEquationsRelation[i, j] = gEquationsRelation[i + 1, j];
						gEquationsRelation[i + 1, j] = nullptr;
					}
				}
			}
		}
		for (int i = 0; i < MAXEQUATIONS; i++) {
			for (int k = e->RowIndex; k < MAXEQUATIONS; k++) {
				if (k + 1 < MAXEQUATIONS) {
					if (gEquationsRelation[i, k] == nullptr) {
						gEquationsRelation[i, k] = gEquationsRelation[i, k + 1];
						gEquationsRelation[i, k + 1] = nullptr;
					}
				}
			}
		}
	}
}

System::Void INPEEM::NovoModelo::checkLUTNames()
{
	if (dgLUT->RowCount - 1 == gLUTNumberDrawn && drawn) {
		for (int i = 0; i < gLUTNumber; i++) {
			Label^ auxLut1 = safe_cast<System::Windows::Forms::Label^>(Controls->Find("lutLabel" + i, true)[0]);
			Label^ auxLut2 = safe_cast<System::Windows::Forms::Label^>(Controls->Find("lutLabel2" + i, true)[0]);

			if (auxLut1->Text != dgLUT->Rows[i]->Cells[0]->Value->ToString()) {
				auxLut1->Text = dgLUT->Rows[i]->Cells[0]->Value->ToString();
				auxLut2->Text = dgLUT->Rows[i]->Cells[0]->Value->ToString();
			}
		}
	}

	NovoModelo::Update();
}