#include "stdafx.h"
#include "NovoModelo.h"
#include "Function.h"
#include "LanguageForm.h"
#include "AboutForm.h"

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
		this->Text = "INPE-EM LUCC - Creating a new model";

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
		lShape->Text = "Spatial Database (.shp)";

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
		gSUnauthorized = "You do not have writting permission on the selected folder.\nTry a different one or run LuccME as admin.";
		gSUnauthorizedTitle = "Error - Writting Permimission";
		gSExitTitle = "Exiting - Data not saved";
		gSExit = "The data changed will be lost.\nDo you want to proceed?";
		gSSuccessTitle = "Files successfully generate";
		gSSuccess = "Files successfully recorded:\n";
		gSEditing = "INPE-EM - Editing a model";
		gSNewModelTitle = "Create a New Model";
		gSNewModel = "All the data will be lost.\nDo you want to proceed?";
		gSOpenModelTitle = "Open a New Model";
		gSScriptLoadTitle = "Script File to Import";
		gSScriptLoad = "Select the Script File.";
		gSScriptFile = "Select Script File";
		gSLuaFile = "Lua File(*.lua)|*.lua";
		gSImportTitle = "Model File Loaded";
		gSImport = "Mdodel file imported with sucess.";
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
		this->Text = "INPE-EM LUCC - Criando um novo modelo";
		
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
		lShape->Text = "Banco de Dados Espacial (.shp)";

		//tabFileMaker
		tabFileMaker->Text = "Gerar Arquivos";
		lFileMaker->Text = "Gerar os Arquivos";
		bGerarArquivos->Text = "Gerar Arquivos";
		lRunModel->Text = "Rodar o Modelo";
		bRun->Text = "Rodar Modelo";

		//String
		gSImportEquationErrorTitle = "Erro - Importando as equações";
		gSImportEquationError = "O arquivo com as equações não foi localizado (equations.dat).";
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
		gSScriptLoadTitle = "Script a ser Importado";
		gSScriptLoad = "Selecione o Script.";
		gSScriptFile = "Selecione o Script";
		gSLuaFile = "Arquivo Lua (*.lua)|*.lua";
		gSImportTitle = "Modelo Carregado";
		gSImport = "Modelo importado com sucesso.";
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
	String^ fileName = EQUATIONADDRESS;
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

	aux = thisComboBox->SelectedItem->ToString();
	aux = aux->Substring(aux->IndexOf(":") + 2);
	aux = aux->Replace(" ", "");
	gEquationsRelation[x, y] = aux;
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
	for (int i = 0; i < gEquations->Length; i++) {
		if (gEquations[i] != nullptr) {
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
						if (auxComboBox->Items[w]->Equals(formulaNumber + gEquations[i])) {
							hasEquations = true;
						}
					}

					if (!hasEquations) {
						auxComboBox->Items->Add(formulaNumber + gEquations[i]);
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
			bool imported = true;

			INPEEM::OpenFileDialog^ scriptFile = gcnew OpenFileDialog;
			scriptFile->Title = gSScriptFile;
			scriptFile->Multiselect = false;
			scriptFile->Filter = gSLuaFile;
			scriptFile->FilterIndex = 1;
			scriptFile->ShowHelp = true;

			//If a script is selected
			if (scriptFile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ fileName = scriptFile->FileName;
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(fileName);
				String^ line = sw->ReadLine();
				String^ tempLine = "";
				int lastSlash = 0;

				//Capture the folder where the script is 
				line = scriptFile->FileName;

				for (int i = 0; i < line->Length; i++) {
					if (line[i] != '\\') {
						tempLine += line[i];
					}
					else {
						if (line[i] == '\\') {
							tempLine += line[i];
							lastSlash = i;
						}
					}
				}

				lSelectedFolder->Text = tempLine->Substring(0, lastSlash);

				//If the folder is a root address like C: or D:, a slash must be inserted
				if (lSelectedFolder->Text->Length == 2) {
					lSelectedFolder->Text += "\\";
				}

				gParametersValues[0] = lSelectedFolder->Text;

				int modelBegin = 0;
				int j = 0;
				bool found = false;
				tempLine = "";

				//Find where the model begins
				while (sw->EndOfStream == false) {
					if (line->Contains("INPEEMLUCCModel") != TRUE) {
						modelBegin++;
						line = sw->ReadLine();
					}
					else {
						break;
					}
				}

				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				//Consume script until the model starts
				for (int i = 0; i < modelBegin; i++) {
					line = sw->ReadLine();
				}

				//Capture the model name
				while (sw->EndOfStream == false) {
					if (line->Contains("name =") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				//Select only the name
				if (found) {
					j = 0;

					while (line[j] != '\"') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != '\"') {
							tempLine += line[i];
						}
						else {
							break;
						}
					}

					tModelName->Text = tempLine;
					tModelName->ForeColor = System::Drawing::Color::Black;
					gParametersValues[1] = tModelName->Text;
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				//Capture the Simulation Start Time
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("startTime") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				//Select only the year
				if (found) {
					j = 0;

					while (line[j] != '=') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != ',') {
							if (line[i] != ' ') {
								tempLine += line[i];
							}
						}
						else {
							break;
						}
					}

					tInitialYear->Text = tempLine;
					tInitialYear->ForeColor = System::Drawing::Color::Black;
					gParametersValues[2] = tInitialYear->Text;
				}
				
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				//Capture the Simulation End Time
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("endTime") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				//Select only the year
				if (found) {
					j = 0;

					while (line[j] != '=') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != ',') {
							if (line[i] != ' ') {
								tempLine += line[i];
							}
						}
						else {
							break;
						}
					}

					tFinalYear->Text = tempLine;
					tFinalYear->ForeColor = System::Drawing::Color::Black;
					gParametersValues[3] = tFinalYear->Text;
				}
				
				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				//Find the Cellular Space, to search for the data
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("CellularSpace") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						break;
					}
				}

				//Capture project
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("project") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				//Select the project name
				if (found) {
					j = 0;

					while (line[j] != '=') {
						j++;
					}

					j++;
					tempLine = "";

					for (int i = j; i < line->Length; i++) {
						if (line[i] != ',') {
							if (line[i] != ' ') {
								tempLine += line[i];
							}
						}
						else {
							break;
						}
					}
										
				}
				
				//If project is equal to t3mp.tview, its using shape
				tempLine = tempLine->Replace("\"", "");
				if (tempLine == "t3mp.tview") {
					found = false;
					sw->Close();
					sw = gcnew System::IO::StreamReader(fileName);

					//Find the Cellular Space layer
					line = sw->ReadLine();
					while (sw->EndOfStream == false) {
						if (line->Contains("l1 = Layer") != TRUE) {
							line = sw->ReadLine();
						}
						else {
							found = true;
							break;
						}
					}

					//Capture the file address
					while (sw->EndOfStream == false) {
						if (line->Contains("file =") != TRUE) {
							line = sw->ReadLine();
						}
						else {
							found = true;
							break;
						}
					}

					//Select the address
					if (found) {
						j = 0;

						while (line[j] != '=') {
							j++;
						}

						j++;
						tempLine = "";

						for (int i = j; i < line->Length; i++) {
							if (line[i] != ',') {
								if (line[i] != ' ') {
									tempLine += line[i];
								}
							}
							else {
								break;
							}
						}

						tempLine = tempLine->Replace("\"", "");
						tempLine = tempLine->Replace("\\\\", "\\");
						lSelectedFile->Text = tempLine;
						lSelectedFile->ForeColor = System::Drawing::Color::Black;
						gParametersValues[4] = lSelectedFile->Text;
						shape = true;
					}
					else {
						//Address selected already
						tempLine = tempLine->Replace("\"", "");
						tempLine = tempLine->Replace("\\\\", "\\");
						lSelectedFile->Text = tempLine;
						lSelectedFile->ForeColor = System::Drawing::Color::Black;
						gParametersValues[4] = lSelectedFile->Text;
					}
				}

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				//Capture land use values
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("landUseValues") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				//Select the values and lut names
				if (found) {
					line = line->Replace(" ", "");
					line = line->Replace("\t", "");
					line = line->Replace("landUseValues={", "");
					
					String^ values = "";
					String^ lutNames = "";

					for (int i = 0; i < line->Length - 1; i++) {
						if (line[i] != '}') {
							values += line[i];
						}
						else {
							lutNames = line->Substring(i);
							break;
						}
					}

					int index = 0;
					lutNames = lutNames->Replace("},", "");
					lutNames = lutNames->Replace("--", "");
					String^ aux = "";

					for (int i = 0; i < lutNames->Length; i++) {
						if (lutNames[i] != ',') {
							aux += lutNames[i];
						}
						else {
							dgLUT->Rows->Add(aux);
							gLUTNames += aux + ",";
							aux = "";
						}
					}

					if (aux != "") {
						dgLUT->Rows->Add(aux);
						gLUTNames += aux;
						aux = "";
					}

					for (int i = 0; i < values->Length; i++) {
						if (values[i] != ',') {
							aux += values[i];
						}
						else {
							dgLUT->Rows[index]->Cells[1]->Value = aux;
							gLUTValues += aux + ",";
							index++;
							aux = "";
						}
					}

					if (aux != "") {
						dgLUT->Rows[index]->Cells[1]->Value = aux;
						gLUTValues += aux;
						aux = "";
					}
				}

				gParametersValues[5] = gLUTNames;
				gParametersValues[6] = gLUTValues;

				found = false;
				sw->Close();
				sw = gcnew System::IO::StreamReader(fileName);

				//Capture transition matrix
				line = sw->ReadLine();
				while (sw->EndOfStream == false) {
					if (line->Contains("transitionMatrix") != TRUE) {
						line = sw->ReadLine();
					}
					else {
						found = true;
						break;
					}
				}

				tempLine = "";

				while (sw->EndOfStream == false) {
					if (line->Equals("}") != TRUE) {
						tempLine += line;
						line = sw->ReadLine();
						line = line->Replace("\"", "");
						line = line->Replace("\t", "");
						line = line->Replace(" ", "");
					}
					else {
						found = true;
						break;
					}
				}

				//Select in Combo Box with formula
				if (found) {
					tempLine = tempLine->Replace("\t", "");
					tempLine = tempLine->Replace(" ", "");
					tempLine = tempLine->Replace("transitionMatrix=", "");
					tempLine = tempLine->Replace("transitionMatrix=", "");
					tempLine = tempLine->Replace("{", "");
					tempLine = tempLine->Replace("}", "");

					String^ aux = "";
					int lutNumber = dgLUT->RowCount - 1;
					int x = 0;
					int y = 0;

					for (int i = 0; i < tempLine->Length; i++) {
						if (tempLine[i] != ',') {
							aux += tempLine[i];
						}
						else {
							gEquationsRelation[x, y] = aux;
							aux = "";

							if (y + 1 < lutNumber) {
								y++;
							}
							else {
								x++;
								y = 0;
							}
						}
					}

					if (aux != "") {
						gEquationsRelation[x, y] = aux;
					}

					//Check if the Script equations are in equations.dat
					bool hasChange = false;
					for (int i = 0; i < MAXEQUATIONS; i++) {
						for (int j = 0; j < MAXEQUATIONS; j++) {
							if (gEquationsRelation[i, j] != nullptr) {
								bool hasEquation = true;
								int indexEquation = 0;

								for (int k = 0; k < MAXEQUATIONS; k++) {
									if (gEquations[k] != nullptr) {
										if (gEquationsRelation[i, j] == gEquations[k]) {
											indexEquation = k;
											break;
										}
									}
									else {
										hasEquation = false;
										indexEquation = k;
										break;
									}
								}

								if (!hasEquation) {
									gEquations[indexEquation] = gEquationsRelation[i, j];
									hasChange = true;
								}
							}
						}
					}

					if (hasChange) {
						StreamWriter^ sw = nullptr;
						String^ path = EQUATIONADDRESS;
						try
						{
							if (File::Exists(path))
							{
								File::Delete(path);
							}

							sw = File::CreateText(path);

							for (int i = 0; i < MAXEQUATIONS; i++) {
								if (gEquations[i] != nullptr) {
									if (gEquations[i] != "") {
										sw->WriteLine(gEquations[i]);
									}
								}
								else {
									break;
								}
							}

							sw->Close();
						}
						catch (UnauthorizedAccessException^)
						{
							MessageBox::Show(gSUnauthorized, gSUnauthorizedTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
						}
					}


					//Enter on Equations Tab to create the ComboBox dinamically and return to Definition (like a function call)
					tNovoModelo->SelectedIndex = EQUATIONS;
					tNovoModelo->SelectedIndex = DEFINITION;

					//Select the Equation in each ComboBox
					for (int i = 0; i < MAXEQUATIONS; i++) {
						for (int j = 0; j < MAXEQUATIONS; j++) {
							if (gEquationsRelation[i, j] != nullptr) {
								ComboBox^ auxComboBox = safe_cast<System::Windows::Forms::ComboBox^>(Controls->Find("cbSelectFormula" + i + "" + j, true)[0]);

								for (int k = 0; k < auxComboBox->Items->Count; k++) {
									String^ auxFormula = auxComboBox->Items[k]->ToString();
									auxFormula = auxFormula->Substring(auxFormula->IndexOf(":"));
									auxFormula = auxFormula->Replace(":", "");
									auxFormula = auxFormula->Replace(" ", "");
									if (auxFormula->Equals(gEquationsRelation[i, j])) {
										auxComboBox->SelectedIndex = k;
										break;
									}
								}
							}
						}
					}
				}
			}

			MessageBox::Show(gSImport, gSImportTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);

			lRunModel->Visible = true;
			bRun->Visible = true;
			runnable = true;
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
	}
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
		NovoModelo::Update();
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

	//Show the eaqutions on the form via label
	if (tNovoModelo->SelectedIndex == EQUATIONS) {
		if (lEquationsList->Text == "") {
			int index = 0;
			int breakLine = 1;
			
			while (gEquations[index] != nullptr) {
				lEquationsList->Text += gEquations[index];
				index++;
				if (gEquations[index] != nullptr) {
					if (lEquationsList->Text->Length >= (90 * breakLine)) {
						lEquationsList->Text += "\n";
						breakLine++;
					}
					else {
						lEquationsList->Text += "  |  ";
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
	else if (lSelectedFile->Text == "") {
		MessageBox::Show(gSSFile, gSSFileTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
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
				sw->WriteLine("-- This file contains a INPE-EM LUCC APPLICATION MODEL definition --");
				sw->WriteLine("--                 Compatible with INPE-EM 3.0                    --");
				sw->WriteLine("--       Generated with INPE-EM LUCC Model Configurator           --");
				sw->WriteLine("--                    " + dateTime + "                      --");
				sw->WriteLine("--------------------------------------------------------------------\n");

				if (shape) {
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("-- Creating Terraview Project                               --");
					sw->WriteLine("--------------------------------------------------------------");
					sw->WriteLine("import(\"gis\")");
					sw->WriteLine("");
					sw->WriteLine("projFile = File(\"t3mp.tview\")");
					sw->WriteLine("if(projFile:exists()) then");
					sw->WriteLine("\tprojFile:delete()");
					sw->WriteLine("end");
					sw->WriteLine("");
					sw->WriteLine("proj = Project {");
					sw->WriteLine("\tfile = \"t3mp.tview\",");
					sw->WriteLine("\tclean = true");
					sw->WriteLine("}\n");

					sw->WriteLine("l1 = Layer {");
					sw->WriteLine("\tproject = proj,");
					sw->WriteLine("\tname = \"layer\",");
					sw->WriteLine("\tfile = \"" + lSelectedFile->Text->Replace("\\", "\\\\") + "\"");
					sw->WriteLine("}\n");
				}

				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("-- INPE-EM LUCC APPLICATION MODEL DEFINITION                --");
				sw->WriteLine("--------------------------------------------------------------");
				sw->WriteLine("import(\"inpeemlucc\")");
				sw->WriteLine("");

				sw->WriteLine(tModelName->Text + " = INPEEMLUCCModel");
				sw->WriteLine("{");
				sw->WriteLine("\tname = \"" + tModelName->Text + "\",\n");

				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Temporal dimension definition                   --");
				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\tstartTime = " + tInitialYear->Text + ",");
				sw->WriteLine("\tendTime = " + tFinalYear->Text + ",\n");

				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Spatial dimension definition                    --");
				sw->WriteLine("\t-----------------------------------------------------");

				if (shape) {
					sw->WriteLine("\tcs = CellularSpace");
					sw->WriteLine("\t{");
					sw->WriteLine("\t\tproject = \"t3mp.tview\",");
					sw->WriteLine("\t\tlayer = \"layer\",");
					sw->WriteLine("\t},");
				}
				else {
					sw->WriteLine("\tcs = CellularSpace");
					sw->WriteLine("\t{");
					sw->WriteLine("\t\tproject = \"" + lSelectedFile->Text->Replace("\\", "\\\\") + "\",");
					sw->WriteLine("\t\tlayer = \"layer\",");
					sw->WriteLine("\t},");
				}

				sw->WriteLine("");
				sw->WriteLine("\t-----------------------------------------------------");
				sw->WriteLine("\t-- Land use values definition                      --");
				sw->WriteLine("\t-----------------------------------------------------");

				gLUTNames = "";
				gLUTValues = "";

				for (int i = 0; i < dgLUT->RowCount; i++) {
					if (i + 1 < dgLUT->RowCount - 1) {
						gLUTNames += dgLUT->Rows[i]->Cells[0]->Value + ", ";
						gLUTValues += dgLUT->Rows[i]->Cells[1]->Value + ", ";
					}
					else {
						gLUTNames += dgLUT->Rows[i]->Cells[0]->Value;
						gLUTValues += dgLUT->Rows[i]->Cells[1]->Value;
					}
				}

				sw->WriteLine("\tlandUseValues = {" + gLUTValues + "}, \t--" + gLUTNames);
				sw->WriteLine("");
				sw->WriteLine("\ttransitionMatrix = ");
				sw->WriteLine("\t{");

				for (int i = 0; i < gLUTNumber; i++) {
					String^ auxLine = "{";
					
					for (int j = 0; j < gLUTNumber; j++) {
						if (j + 1 < gLUTNumber) {
							auxLine += "\"" + gEquationsRelation[i, j] + "\", ";
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
				sw->WriteLine("}  -- END INPE-EM LUCC application model definition\n");

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
				sw->WriteLine("\t\t\t\t end");
				sw->WriteLine("\t}");
				sw->WriteLine("}\n");

				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("-- ENVIROMMENT EXECUTION                           --");
				sw->WriteLine("-----------------------------------------------------");
				sw->WriteLine("env_" + tModelName->Text + " = Environment{}");
				sw->WriteLine("env_" + tModelName->Text + ":add(timer)");
				sw->WriteLine("env_" + tModelName->Text + ":run(" + tModelName->Text + ".endTime)");

				if (shape) {
					sw->WriteLine("");
					sw->WriteLine("projFile = File(\"t3mp.tview\")");
					sw->WriteLine("if(projFile:exists()) then");
					sw->WriteLine("\tprojFile:delete()");
					sw->WriteLine("end");
				}

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

					gParametersValues[0] = lSelectedFolder->Text;
					gParametersValues[1] = tModelName->Text;
					gParametersValues[2] = tInitialYear->Text;
					gParametersValues[3] = tFinalYear->Text;
					gParametersValues[4] = lSelectedFile->Text;
					gParametersValues[5] = gLUTNames;
					gParametersValues[6] = gLUTValues;
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
	Environment::SetEnvironmentVariable("TME_PATH", TERRAMEADDRESS);
	Environment::SetEnvironmentVariable("PATH", TERRAMEADDRESS);

	String^ arguments = "";

	if (lSelectedFolder->Text[lSelectedFolder->Text->Length - 1] != '\\') {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + "\\\\" + tModelName->Text->ToLower() + ".lua\"";
	}
	else {
		arguments = "\"" + lSelectedFolder->Text->Replace("\\", "\\\\") + tModelName->Text->ToLower() + ".lua\"";
	}

	System::Diagnostics::Process^ cmd = gcnew System::Diagnostics::Process;
	cmd->StartInfo->FileName = BATADDRESS;
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

System::Void INPEEM::NovoModelo::NovoModelo_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	gLUTNames = "";
	gLUTValues = "";

	for (int i = 0; i < dgLUT->RowCount; i++) {
		if (i + 1 < dgLUT->RowCount - 1) {
			gLUTNames += dgLUT->Rows[i]->Cells[0]->Value + ",";
			gLUTValues += dgLUT->Rows[i]->Cells[1]->Value + ",";
		}
		else {
			gLUTNames += dgLUT->Rows[i]->Cells[0]->Value;
			gLUTValues += dgLUT->Rows[i]->Cells[1]->Value;
		}
	}

	if (!closing && !runnable) {
		if (lSelectedFolder->Text != "" ||tModelName->ForeColor == System::Drawing::Color::Black || tInitialYear->ForeColor == System::Drawing::Color::Black || tFinalYear->ForeColor == System::Drawing::Color::Black ||
			lSelectedFile->Text != "" ||  dgLUT->RowCount > 1) {
			if (MessageBox::Show(gSExit, gSExitTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == INPEEM::DialogResult::No) {
				e->Cancel = true;
			}
		}
	}
	else if (!closing && runnable) {
		if (gParametersValues[0] != lSelectedFolder->Text || gParametersValues[1] != tModelName->Text || gParametersValues[2] != tInitialYear->Text ||
			gParametersValues[3] != tFinalYear->Text || gParametersValues[4] != lSelectedFile->Text || gParametersValues[5] != gLUTNames || gParametersValues[6] != gLUTValues) {
			if (MessageBox::Show(gSExit, gSExitTitle, MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == INPEEM::DialogResult::No) {
				e->Cancel = true;
			}
		}
	}
}
