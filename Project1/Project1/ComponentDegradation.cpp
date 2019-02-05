#include "stdafx.h"
#include "ComponentDegradation.h"

System::Void INPEEM::ComponentDegradation::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::ComponentDegradation::ComponentDegradation_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		lName->Text = "Name";
		lDescription->Text = "Description";
		lDescription->Location = System::Drawing::Point(49, 183);
		bSalvar->Text = "Save";
		gSDataMissingTitle = "Error - Data missing";
		gSDataMissing = "All the parameters must be fulfilled.";
		cbSave->Text = "Save into file";
	}
	else {
		lName->Text = "Nome";
		lDescription->Text = "Descrição";
		lDescription->Location = System::Drawing::Point(64, 183);
		bSalvar->Text = "Salvar";
		gSDataMissingTitle = "Erro - Dados não preenchidos";
		gSDataMissing = "Todos os parâmetros devem ser preenchidos.";
		cbSave->Text = "Salvar em aquivo";
	}

	if (lReturn->Return != "") {
		array<String^>^ auxDegrad = lReturn->Return->Split(';');

		tName->Text = auxDegrad[0];
		tName->ForeColor = System::Drawing::Color::Black;

		tDescription->Text = auxDegrad[1];
		tDescription->ForeColor = System::Drawing::Color::Black;

		if (auxDegrad[2]->ToLower()->Contains("true")) {
			cbSave->Checked = true;
		}
		else {
			cbSave->Checked = false;
		}
		

		tAverAGB_loss->Text = auxDegrad[3];
		tAverAGB_loss->ForeColor = System::Drawing::Color::Black;

		tAverBGB_loss->Text = auxDegrad[4];
		tAverBGB_loss->ForeColor = System::Drawing::Color::Black;

		tAverDeadWood_loss->Text = auxDegrad[5];
		tAverDeadWood_loss->ForeColor = System::Drawing::Color::Black;

		tAverLitter_loss->Text = auxDegrad[6];
		tAverLitter_loss->ForeColor = System::Drawing::Color::Black;
		
		tAverAGB_percReduction->Text = auxDegrad[7];
		tAverAGB_percReduction->ForeColor = System::Drawing::Color::Black;

		tAverPeriodRegrow->Text = auxDegrad[8];
		tAverPeriodRegrow->ForeColor = System::Drawing::Color::Black;

		tAverLimiarDegradYears->Text = auxDegrad[9];		
		tAverLimiarDegradYears->ForeColor = System::Drawing::Color::Black;

		tAverLimiarDegradLoss->Text = auxDegrad[10];		
		tAverLimiarDegradLoss->ForeColor = System::Drawing::Color::Black;

	}
}

System::Void INPEEM::ComponentDegradation::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;

	if (tName->Text == "" || tAverAGB_loss->Text == "" || tAverAGB_percReduction->Text == "" || tAverBGB_loss->Text == "" || tAverDeadWood_loss->Text == "" ||
		tAverLimiarDegradLoss->Text == "" || tAverLimiarDegradYears->Text == "" || tAverLitter_loss->Text == "" || tAverPeriodRegrow->Text == "") {
			MessageBox::Show(gSDataMissing, gSDataMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
			check = false;
	}

	if (check) {
		lReturn->Return = "";
		lReturn->Return += tName->Text;
		lReturn->Return += ";";
		lReturn->Return += tDescription->Text;
		lReturn->Return += ";";
		
		if (cbSave->Checked) {
			lReturn->Return += "true";
			lReturn->Return += ";";
		}
		else {
			lReturn->Return += "false";
			lReturn->Return += ";";
		}

		lReturn->Return += tAverAGB_loss->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverBGB_loss->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDeadWood_loss->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverLitter_loss->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverAGB_percReduction->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverPeriodRegrow->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverLimiarDegradYears->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverLimiarDegradLoss->Text->Replace(",", ".");
		
		this->Close();
	}
}