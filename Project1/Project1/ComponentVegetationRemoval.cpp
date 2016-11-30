#include "stdafx.h"
#include "ComponentVegetationRemoval.h"

System::Void INPEEM::ComponentVegetationRemoval::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::ComponentVegetationRemoval::ComponentVegetationRemoval_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		lName->Text = "Name";
		lDescription->Text = "Description";
		lDescription->Location = System::Drawing::Point(64, 186);
		bSalvar->Text = "Save";
		gSDataMissingTitle = "Error - Data missing";
		gSDataMissing = "All the parameters must be fulfilled.";
		cbSave->Text = "Save into file";
	}
	else {
		lName->Text = "Nome";
		lDescription->Text = "Descrição";
		lDescription->Location = System::Drawing::Point(79, 186);
		bSalvar->Text = "Salvar";
		gSDataMissingTitle = "Erro - Dados não preenchidos";
		gSDataMissing = "Todos os parâmetros devem ser preenchidos.";
		cbSave->Text = "Salvar em aquivo";
	}
}

System::Void INPEEM::ComponentVegetationRemoval::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;

	if (tName->Text == "" || tAverAGBPercAGB->Text == "" || tAverAGBPercDecomposition->Text == "" || tAverAGBPercInstantaneous->Text == "" || tAverAGBPercWoodProducts->Text == "" ||
		tAverBGBPercBGB->Text == "" || tAverBGBPercDecompositionUnder->Text == "" || tAverBGBPercInstantaneous->Text == "" || tAverDeadWoodPercDecomposition->Text == "" ||
		tAverDeadWoodPercInstantaneous->Text == "" || tAverDecayRateAGBDecomposition->Text == "" || tAverDecayRateBGBDecompositionAbove->Text == "" || tAverDecayRateBGBDecompositionUnder->Text == "" ||
		tAverDecayRateDeadWoodDecomposition->Text == "" || tAverDecayRateElementalCarbon->Text == "" || tAverDecayRateLitterDecomposition->Text == "" || tAverDecayRateWoodProducts->Text == "" || 
		tAverDecompositionFireCyclePeriod->Text == "" || tAverDecompositonPercElementalCarbon->Text == "" || tAverDecayRateLitterDecomposition->Text == "" || tAverLitterPercInstantaneous->Text == "" ||
		tAverBGBPercDecompositionAbove->Text == "") {
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

		lReturn->Return += tAverAGBPercAGB->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverAGBPercWoodProducts->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverAGBPercInstantaneous->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverAGBPercDecomposition->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercBGB->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercInstantaneous->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercDecompositionAbove->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercDecompositionUnder->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDecompositionFireCyclePeriod->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDecompositonPercElementalCarbon->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverLitterPercInstantaneous->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverLitterPercDecomposition->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDeadWoodPercInstantaneous->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDeadWoodPercDecomposition->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateWoodProducts->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateElementalCarbon->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateAGBDecomposition->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateBGBDecompositionAbove->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateBGBDecompositionUnder->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateLitterDecomposition->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateDeadWoodDecomposition->Text;

		this->Close();
	}
}
