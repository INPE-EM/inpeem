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
	}
	else {
		lName->Text = "Nome";
		lDescription->Text = "Descri��o";
		lDescription->Location = System::Drawing::Point(62, 181);
		bSalvar->Text = "Salvar";
		gSDataMissingTitle = "Erro - Dados n�o preenchidos";
		gSDataMissing = "Todos os par�metros devem ser preenchidos.";
		cbSave->Text = "Salvar em aquivo";
	}
}

System::Void INPEEM::ComponentSecondaryVegetation::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;

	if (tName->Text == "" || tAverAgriculturalUseCycle->Text == "" || tAverAreaAccPercVegSec->Text == "" || tAverAreaPercVegSec->Text == "" || tAverBGBpercBGB->Text == "" ||
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

		lReturn->Return += taverHalfLife->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverAreaPercVegSec->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverAreaAccPercVegSec->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverRecoveryPeriod1Perc->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverRecoveryPeriod1->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverRecoveryPeriod2Perc->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverRecoveryPeriod2->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverAgriculturalUseCycle->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverInitialAbandonmentCycle->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverBGBpercBGB->Text;
		
		this->Close();
	}
}