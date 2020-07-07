#include <time.h>
#include "stdafx.h"
#include "AboutForm.h"
#include "INPEEMVersion.h"

System::Void INPEEM::AboutForm::AboutForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	int year = timePtr->tm_year + 1900;

	if (lLanguage == "en") {
		this->Text = "About";
		lProgram->Text = "INPE-EM Model Manager";
		lVersion->Text = "Version " + INPEEM_VERSION;
		lCopyright->Text = "Copyright © " + year + ". All rigths reserved.";
	}
	else {
		this->Text = "Sobre";
		lProgram->Text = "Gerenciador de Modelos INPE-EM";
		lVersion->Text = "Versão " + INPEEM_VERSION;
		lCopyright->Text = "Copyright © " + year + ". Todos os direitos reservados.";
	}
}

System::Void INPEEM::AboutForm::linkLabel1_LinkClicked(System::Object ^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e)
{
	linkLabel1->LinkVisited = true;
	System::Diagnostics::Process::Start("http://inpe-em.ccst.inpe.br/");
}
