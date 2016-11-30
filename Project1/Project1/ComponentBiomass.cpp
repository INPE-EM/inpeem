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

	ComponentBiomass::Update();
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
		lReturn->Return += tAverAGB->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverBGBPercAGB->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverLitterPercAGB->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverDeadWoodPercAGB->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_C->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_CO2->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_CO2_fire->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_CH4_fire->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_N2O_fire->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_NOx_fire->Text;
		lReturn->Return += ";";
		lReturn->Return += tAverFactorB_CO_fire->Text;

		this->Close();
	}
}

