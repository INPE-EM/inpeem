#include "stdafx.h"
#include "ComponentDeforest.h"
#include "Function.h"

System::Void INPEEM::ComponentDeforest::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::ComponentDeforest::ComponentDeforest_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		lName->Text = "Name";
		lDescription->Text = "Description";
		lDescription->Location = System::Drawing::Point(42, 268);
		bSalvar->Text = "Save";
		gSDataMissingTitle = "Error - Data missing";
		gSDataMissing = "All the parameters must be fulfilled.";
	}
	else {
		lName->Text = "Nome";
		lDescription->Text = "Descrição";
		lDescription->Location = System::Drawing::Point(57, 268);
		bSalvar->Text = "Salvar";
		gSDataMissingTitle = "Erro - Dados não preenchidos";
		gSDataMissing = "Todos os parâmetros devem ser preenchidos.";
	}

	if (lReturn->Return != "") {
		array<String^>^ auxDeforest = lReturn->Return->Split(';');

		tName->Text = auxDeforest[0];
		tName->ForeColor = System::Drawing::Color::Black;
		
		tDescription->Text = auxDeforest[1];
		tDescription->ForeColor = System::Drawing::Color::Black;

		tInitialArea->Text = auxDeforest[2];
		tInitialArea->ForeColor = System::Drawing::Color::Black;

		tInitialForest->Text = auxDeforest[3];
		tInitialForest->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::ComponentDeforest::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;

	if (tName->Text == "" || tInitialArea->Text == "" || tInitialForest->Text == "") {
		MessageBox::Show(gSDataMissing, gSDataMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
		check = false;
	}

	if (check) {
		lReturn->Return = "";
		lReturn->Return += tName->Text;
		lReturn->Return += ";";
		lReturn->Return += tDescription->Text;
		lReturn->Return += ";";
		lReturn->Return += tInitialArea->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tInitialForest->Text->Replace(",", ".");

		this->Close();
	}
}