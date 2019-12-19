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
		cbSave->Location = System::Drawing::Point(766, 172);
		
	}
	else {
		lName->Text = "Nome";
		lDescription->Text = "Descrição";
		lDescription->Location = System::Drawing::Point(79, 186);
		bSalvar->Text = "Salvar";
		gSDataMissingTitle = "Erro - Dados não preenchidos";
		gSDataMissing = "Todos os parâmetros devem ser preenchidos.";
		cbSave->Text = "Salvar em aquivo";
		cbSave->Location = System::Drawing::Point(736, 172);
	}

	if (lReturn->Return != "") {
		array<String^>^ auxVegetationRemoval = lReturn->Return->Split(';');

		tName->Text = auxVegetationRemoval[0];
		tName->ForeColor = System::Drawing::Color::Black;

		tDescription->Text = auxVegetationRemoval[1];
		tDescription->ForeColor = System::Drawing::Color::Black;

		if (auxVegetationRemoval[2]->ToLower()->Contains("true")) {
			cbSave->Checked = true;
		}
		else {
			cbSave->Checked = false;
		}

		tAverAGBPercAGB->Text = auxVegetationRemoval[3];
		tAverAGBPercAGB->ForeColor = System::Drawing::Color::Black;

		tAverAGBPercWoodProducts->Text = auxVegetationRemoval[4];
		tAverAGBPercWoodProducts->ForeColor = System::Drawing::Color::Black;

		tAverAGBPercInstantaneous->Text = auxVegetationRemoval[5];
		tAverAGBPercInstantaneous->ForeColor = System::Drawing::Color::Black;

		tAverAGBPercDecomposition->Text = auxVegetationRemoval[6];
		tAverAGBPercDecomposition->ForeColor = System::Drawing::Color::Black;

		tAverBGBPercBGB->Text = auxVegetationRemoval[7];
		tAverBGBPercBGB->ForeColor = System::Drawing::Color::Black;

		tAverBGBPercInstantaneous->Text = auxVegetationRemoval[8];
		tAverBGBPercInstantaneous->ForeColor = System::Drawing::Color::Black;

		tAverBGBPercDecompositionAbove->Text = auxVegetationRemoval[9];
		tAverBGBPercDecompositionAbove->ForeColor = System::Drawing::Color::Black;

		tAverBGBPercDecompositionUnder->Text = auxVegetationRemoval[10];
		tAverBGBPercDecompositionUnder->ForeColor = System::Drawing::Color::Black;

		tAverDecompositionFireCyclePeriod->Text = auxVegetationRemoval[11];
		tAverDecompositionFireCyclePeriod->ForeColor = System::Drawing::Color::Black;

		tAverDecompositonPercElementalCarbon->Text = auxVegetationRemoval[12];
		tAverDecompositonPercElementalCarbon->ForeColor = System::Drawing::Color::Black;

		tAverLitterPercInstantaneous->Text = auxVegetationRemoval[13];
		tAverLitterPercInstantaneous->ForeColor = System::Drawing::Color::Black;

		tAverLitterPercDecomposition->Text = auxVegetationRemoval[14];
		tAverLitterPercDecomposition->ForeColor = System::Drawing::Color::Black;

		tAverDeadWoodPercInstantaneous->Text = auxVegetationRemoval[15];
		tAverDeadWoodPercInstantaneous->ForeColor = System::Drawing::Color::Black;

		tAverDeadWoodPercDecomposition->Text = auxVegetationRemoval[16];
		tAverDeadWoodPercDecomposition->ForeColor = System::Drawing::Color::Black;

		tAverDecayRateWoodProducts->Text = auxVegetationRemoval[17];
		tAverDecayRateWoodProducts->ForeColor = System::Drawing::Color::Black;

		tAverDecayRateElementalCarbon->Text = auxVegetationRemoval[18];
		tAverDecayRateElementalCarbon->ForeColor = System::Drawing::Color::Black;

		tAverDecayRateAGBDecomposition->Text = auxVegetationRemoval[19];
		tAverDecayRateAGBDecomposition->ForeColor = System::Drawing::Color::Black;

		tAverDecayRateBGBDecompositionAbove->Text = auxVegetationRemoval[20];
		tAverDecayRateBGBDecompositionAbove->ForeColor = System::Drawing::Color::Black;

		tAverDecayRateBGBDecompositionUnder->Text = auxVegetationRemoval[21];
		tAverDecayRateBGBDecompositionUnder->ForeColor = System::Drawing::Color::Black;

		tAverDecayRateLitterDecomposition->Text = auxVegetationRemoval[22];
		tAverDecayRateLitterDecomposition->ForeColor = System::Drawing::Color::Black;

		tAverDecayRateDeadWoodDecomposition->Text = auxVegetationRemoval[23];
		tAverDecayRateDeadWoodDecomposition->ForeColor = System::Drawing::Color::Black;
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

		lReturn->Return += tAverAGBPercAGB->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverAGBPercWoodProducts->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverAGBPercInstantaneous->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverAGBPercDecomposition->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercBGB->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercInstantaneous->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercDecompositionAbove->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercDecompositionUnder->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDecompositionFireCyclePeriod->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDecompositonPercElementalCarbon->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverLitterPercInstantaneous->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverLitterPercDecomposition->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDeadWoodPercInstantaneous->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDeadWoodPercDecomposition->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateWoodProducts->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateElementalCarbon->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateAGBDecomposition->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateBGBDecompositionAbove->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateBGBDecompositionUnder->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateLitterDecomposition->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDecayRateDeadWoodDecomposition->Text->Replace(",", ".");

		this->Close();
	}
}
