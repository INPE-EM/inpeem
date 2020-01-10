#include "stdafx.h"
#include "ComponentSecondaryVegetation.h"

System::Void INPEEM::ComponentSecondaryVegetation::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::ComponentSecondaryVegetation::ComponentSecondaryVegetation_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		lName->Text = "Name";
		lDescription->Text = "Description";
		lDescription->Location = System::Drawing::Point(47, 181);
		bSalvar->Text = "Save";
		gSDataMissingTitle = "Error - Data missing";
		gSDataMissing = "All the parameters must be fulfilled.";
		cbSave->Text = "Save into file"; 
		cbSave->Location = System::Drawing::Point(180, 600);
	}
	else {
		lName->Text = "Nome";
		lDescription->Text = "Descrição";
		lDescription->Location = System::Drawing::Point(62, 181);
		bSalvar->Text = "Salvar";
		gSDataMissingTitle = "Erro - Dados não preenchidos";
		gSDataMissing = "Todos os parâmetros devem ser preenchidos.";
		cbSave->Text = "Salvar em aquivo";
		cbSave->Location = System::Drawing::Point(160, 600);
	}

	if (lReturn->Return != "") {
		array<String^>^ auxSecondaryVegetation = lReturn->Return->Split(';');

		tName->Text = auxSecondaryVegetation[0];
		tName->ForeColor = System::Drawing::Color::Black;

		tDescription->Text = auxSecondaryVegetation[1];
		tDescription->ForeColor = System::Drawing::Color::Black;

		if (auxSecondaryVegetation[2]->ToLower()->Contains("true")) {
			cbSave->Checked = true;
		}
		else {
			cbSave->Checked = false;
		}

		taverHalfLife->Text = auxSecondaryVegetation[3];
		taverHalfLife->ForeColor = System::Drawing::Color::Black;

		tAverAreaPercVegSec->Text = auxSecondaryVegetation[4];
		tAverAreaPercVegSec->ForeColor = System::Drawing::Color::Black;

		tAverAreaAccPercVegSec->Text = auxSecondaryVegetation[5];
		tAverAreaAccPercVegSec->ForeColor = System::Drawing::Color::Black;

		tAverRecoveryPeriod1Perc->Text = auxSecondaryVegetation[6];
		tAverRecoveryPeriod1Perc->ForeColor = System::Drawing::Color::Black;

		tAverRecoveryPeriod1->Text = auxSecondaryVegetation[7];
		tAverRecoveryPeriod1->ForeColor = System::Drawing::Color::Black;

		tAverRecoveryPeriod2Perc->Text = auxSecondaryVegetation[8];
		tAverRecoveryPeriod2Perc->ForeColor = System::Drawing::Color::Black;

		tAverRecoveryPeriod2->Text = auxSecondaryVegetation[9];
		tAverRecoveryPeriod2->ForeColor = System::Drawing::Color::Black;

		tAverAgriculturalUseCycle->Text = auxSecondaryVegetation[10];
		tAverAgriculturalUseCycle->ForeColor = System::Drawing::Color::Black;

		tAverInitialAbandonmentCycle->Text = auxSecondaryVegetation[11];
		tAverInitialAbandonmentCycle->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::ComponentSecondaryVegetation::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;

	if (tName->Text == "" || tAverAgriculturalUseCycle->Text == "" || tAverAreaAccPercVegSec->Text == "" || tAverAreaPercVegSec->Text == "" || 
		taverHalfLife->Text == "" || tAverInitialAbandonmentCycle->Text == "" || tAverRecoveryPeriod1->Text == "" || tAverRecoveryPeriod1Perc->Text == "" ||
		tAverRecoveryPeriod2->Text == "" || tAverRecoveryPeriod2Perc->Text == "") {
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

		lReturn->Return += taverHalfLife->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverAreaPercVegSec->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverAreaAccPercVegSec->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverRecoveryPeriod1Perc->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverRecoveryPeriod1->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverRecoveryPeriod2Perc->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverRecoveryPeriod2->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverAgriculturalUseCycle->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverInitialAbandonmentCycle->Text->Replace(",", ".");
		
		this->Close();
	}
}