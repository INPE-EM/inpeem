#include "stdafx.h"
#include "EquationForm.h"

using namespace System::IO;

System::Void INPEEM::EquationForm::tEquation_Enter(System::Object^  sender, System::EventArgs^  e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::EquationForm::EquationForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	if (lLanguage == "en") {
		this->Text = "Equations Manager";
		lEquation->Text = "Equation";
		bAddEquation->Text = "Add";
		bRemEquation->Text = "Remove";
		bSalvar->Text = "Save";

		gSImportEquationErrorTitle = "Error - Importing Equations";
		gSImportEquationError = "The equations file (equations.dat) was not found.";
		gSEquations = "Equations";
		gSUnauthorized = "You do not have writting permission on the selected folder.\nTry a different one or run LuccME as admin.";
		gSUnauthorizedTitle = "Error - Writting Permimission";
		gSEquationUpdate = "The equations was updated successfully.";
		gSEquationUpdateTitle = "Equations Manager";
	}
	else {
		this->Text = "Gerenciador de Equações";
		lEquation->Text = "Equação";
		bAddEquation->Text = "Adicionar";
		bRemEquation->Text = "Remover";
		bSalvar->Text = "Salvar";
		
		gSImportEquationErrorTitle = "Erro - Importando as equações";
		gSImportEquationError = "O arquivo com as equações não foi localizado (equations.dat).";
		gSEquations = "Equações";
		gSUnauthorized = "Você não possui permissão de escrita no diretório selecionado.\nEscolha outro diretório ou execute o LuccME como administrador.";
		gSUnauthorizedTitle = "Erro - Permissão de escrita";
		gSEquationUpdate = "As equações foram atualizadas com sucesso.";
		gSEquationUpdateTitle = "Gerenciador de Equações";
	}

	lvEquation->View = View::Details;
	lvEquation->GridLines = true;
	lvEquation->Columns->Add(gSEquations, lvEquation->Width - 5, HorizontalAlignment::Left);

	String^ fileName = EQUATIONADDRESS;
	
	try {
		StreamReader^ din = File::OpenText(fileName);
		String^ aux = "";

		while (din->EndOfStream == false) {
			aux = din->ReadLine();
			lvEquation->Items->Add(aux);
			oldEquations->Items->Add(aux);
		}

		din->Close();
	}
	catch (Exception^)
	{
		MessageBox::Show(gSImportEquationError, gSImportEquationErrorTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->Close();
	}
}

System::Void INPEEM::EquationForm::bUpLUT_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ aux = gcnew String("");
	for (int i = 0; i < lvEquation->Items->Count; i++) {
		if (lvEquation->Items[i]->Selected) {
			aux = lvEquation->Items[i - 1]->Text;
			lvEquation->Items[i - 1]->Text = lvEquation->Items[i]->Text;
			lvEquation->Items[i]->Text = aux;
			lvEquation->Items[i - 1]->Selected = true;
		}
	}
}

System::Void INPEEM::EquationForm::bDownLUT_Click(System::Object^  sender, System::EventArgs^  e)
{
	String^ aux = gcnew String("");
	for (int i = 0; i < lvEquation->Items->Count; i++) {
		if (lvEquation->Items[i]->Selected) {
			aux = lvEquation->Items[i + 1]->Text;
			lvEquation->Items[i + 1]->Text = lvEquation->Items[i]->Text;
			lvEquation->Items[i]->Text = aux;
			lvEquation->Items[i + 1]->Selected = true;
			lvEquation->Update();
			break;
		}
	}
}

System::Void INPEEM::EquationForm::bRemLUT_Click(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 0; i < lvEquation->Items->Count; i++) {
		if (lvEquation->Items[i]->Selected) {
			lvEquation->Items->RemoveAt(i);
		}
	}
}

System::Void INPEEM::EquationForm::EquationForm_Click(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 0; i < lvEquation->Items->Count; i++) {
		lvEquation->Items[i]->Selected = false;
	}
	bUpEquation->Visible = false;
	bDownEquation->Visible = false;
	bRemEquation->Visible = false;
	this->Update();
}

System::Void INPEEM::EquationForm::lvEquation_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	bUpEquation->Visible = false;
	bDownEquation->Visible = false;
	bRemEquation->Visible = false;

	this->Update();
	
	Boolean checked = false;
	
	for (int i = 0; i < lvEquation->Items->Count; i++) {
		if (lvEquation->Items[i]->Selected) {
			checked = true;
		}
	}
	if (checked) {
		if (!lvEquation->Items[0]->Selected) {
			bUpEquation->Visible = true;
		}
		if (!lvEquation->Items[lvEquation->Items->Count - 1]->Selected) {
			bDownEquation->Visible = true;
		}
		bRemEquation->Visible = true;
	}

	this->Update();
}

System::Void INPEEM::EquationForm::bAddEquation_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (tEquation->Text != "") {
		this->lvEquation->Items->Add(tEquation->Text);
		tEquation->Text = "";
		bUpEquation->Visible = false;
		bDownEquation->Visible = false;
		bRemEquation->Visible = false;
		tEquation->TabIndex = 1;
		this->Update();
	}
}

System::Void INPEEM::EquationForm::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool equal = true;
	bool sameData = true;
	
	if (oldEquations->Items->Count != lvEquation->Items->Count) {
		equal = false;
	}

	if (equal) {
		for (int i = 0; i < oldEquations->Items->Count; i++) {
			if (oldEquations->Items[i]->Text != lvEquation->Items[i]->Text) {
				sameData = false;
				break;
			}
		}
	}

	if (!equal || !sameData) {
		String^ path = EQUATIONADDRESS;
		StreamWriter^ sw = nullptr;

		try
		{
			if (File::Exists(path))
			{
				File::Delete(path);
			}
			
			sw = File::CreateText(path);

			for (int i = 0; i < lvEquation->Items->Count; i++) {
				sw->WriteLine(lvEquation->Items[i]->Text);
			}

			sw->Close();		
			MessageBox::Show(gSEquationUpdate, gSEquationUpdateTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (UnauthorizedAccessException^)
		{
			MessageBox::Show(gSUnauthorized, gSUnauthorizedTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	this->Close();
}