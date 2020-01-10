#include "stdafx.h"
#include "ComponentBiomass.h"
#include "Function.h"

System::Void INPEEM::ComponentBiomass::ComponentBiomass_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		lName->Text = "Name";
		lDescription->Text = "Description";
		lDescription->Location = System::Drawing::Point(46, 193);
		bSalvar->Text = "Save";
		gSDataMissingTitle = "Error - Data missing";
		gSDataMissing = "All the parameters must be fulfilled.";
		
	}
	else {
		lName->Text = "Nome";
		lDescription->Text = "Descrição";
		lDescription->Location = System::Drawing::Point(61, 193);
		bSalvar->Text = "Salvar";
		gSDataMissingTitle = "Erro - Dados não preenchidos";
		gSDataMissing = "Todos os parâmetros devem ser preenchidos.";
	}

	if (lReturn->Return != "") {
		array<String^>^ auxBiomass = lReturn->Return->Split(';');

		tName->Text = auxBiomass[0];
		tName->ForeColor = System::Drawing::Color::Black;
		
		tDescription->Text = auxBiomass[1];
		tDescription->ForeColor = System::Drawing::Color::Black;

		tAverAGB->Text = auxBiomass[2];
		tAverAGB->ForeColor = System::Drawing::Color::Black;
		
		tAverBGBPercAGB->Text = auxBiomass[3];
		tAverBGBPercAGB->ForeColor = System::Drawing::Color::Black;

		tAverLitterPercAGB->Text = auxBiomass[4];
		tAverLitterPercAGB->ForeColor = System::Drawing::Color::Black;

		tAverDeadWoodPercAGB->Text = auxBiomass[5];
		tAverDeadWoodPercAGB->ForeColor = System::Drawing::Color::Black;

		tAverFactorB_C->Text = auxBiomass[6];
		tAverFactorB_C->ForeColor = System::Drawing::Color::Black;

		tAverFactorB_CO2->Text = auxBiomass[7];
		tAverFactorB_CO2->ForeColor = System::Drawing::Color::Black;

		tAverFactorB_CO2_fire->Text = auxBiomass[8];
		tAverFactorB_CO2_fire->ForeColor = System::Drawing::Color::Black;

		tAverFactorB_CH4_fire->Text = auxBiomass[9];
		tAverFactorB_CH4_fire->ForeColor = System::Drawing::Color::Black;

		tAverFactorB_N2O_fire->Text = auxBiomass[10];
		tAverFactorB_N2O_fire->ForeColor = System::Drawing::Color::Black;

		tAverFactorB_NOx_fire->Text = auxBiomass[11];
		tAverFactorB_NOx_fire->ForeColor = System::Drawing::Color::Black;

		tAverFactorB_CO_fire->Text = auxBiomass[12];
		tAverFactorB_CO_fire->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::ComponentBiomass::textBox_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	//Create the efect of a edited TextBox (must select this function on focus->enter property of a TextBox)
	System::Windows::Forms::TextBox^ thisTextBox = safe_cast<System::Windows::Forms::TextBox^>(sender);
	if (thisTextBox->ForeColor != System::Drawing::Color::Black) {
		thisTextBox->Text = "";
		thisTextBox->ForeColor = System::Drawing::Color::Black;
	}
}

System::Void INPEEM::ComponentBiomass::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool check = true;

	if (tName->Text == "" || tAverAGB->Text == "" || tAverBGBPercAGB->Text == "" || tAverDeadWoodPercAGB->Text == "" || tAverFactorB_C->Text == "" || 
		tAverFactorB_CH4_fire->Text == "" || tAverFactorB_CO2->Text == "" || tAverFactorB_CO2_fire->Text == "" || tAverFactorB_CO_fire->Text == "" || 
		tAverFactorB_N2O_fire->Text == "" || tAverFactorB_NOx_fire->Text == "" || tAverLitterPercAGB->Text == "") {
			MessageBox::Show(gSDataMissing, gSDataMissingTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
			check = false;
	}

	if (check) {
		lReturn->Return = "";
		lReturn->Return += tName->Text;
		lReturn->Return += ";";
		lReturn->Return += tDescription->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverAGB->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercAGB->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverLitterPercAGB->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverDeadWoodPercAGB->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_C->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_CO2->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_CO2_fire->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_CH4_fire->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_N2O_fire->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_NOx_fire->Text->Replace(",", ".");
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_CO_fire->Text->Replace(",", ".");

		this->Close();
	}
}

