#include "stdafx.h"
#include "LanguageForm.h"

System::Void INPEEM::LanguageForm::LanguageForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		this->Text = "Language Selection";
		bSelectLanguage->Text = "Select";
		rLEn->Checked = true;
	}
	else {
		this->Text = "Seleção de Idioma";
		bSelectLanguage->Text = "Selecionar";
		rLBr->Checked = true;
	}
}

System::Void INPEEM::LanguageForm::bSelectLanguage_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (rLEn->Checked == true) {
		lLanguage = "en";
	}
	else {
		lLanguage = "br";
	}

	String^ fileName = "language.dat";
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(fileName);
	sw->WriteLine(lLanguage);
	sw->Close();

	this->Close();
}

