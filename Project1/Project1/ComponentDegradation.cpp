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
		lDescription->Text = "Descri��o";
		lDescription->Location = System::Drawing::Point(64, 183);
		bSalvar->Text = "Salvar";
		gSDataMissingTitle = "Erro - Dados n�o preenchidos";
		gSDataMissing = "Todos os par�metros devem ser preenchidos.";
		cbSave->Text = "Salvar em aquivo";
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

		lReturn->Return += tAverAGB_loss->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverBGB_loss->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDeadWood_loss->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverLitter_loss->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverAGB_percReduction->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverLimiarDegradYears->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverLimiarDegradLoss->Text;
		
		this->Close();
	}
}