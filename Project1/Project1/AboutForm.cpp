#include "stdafx.h"
#include "AboutForm.h"

System::Void INPEEM::AboutForm::AboutForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		this->Text = "About";
		lProgram->Text = "INPE-EM Model Manager";
		lCompatible->Text = "Compatible with INPE-EM 3.1";
		lVersion->Text = "Version 2.2";
		lCopyright->Text = "Copyright © 2017. All rigths reserved.";
	}
	else {
		this->Text = "Sobre";
		lProgram->Text = "Gerenciador de Modelos INPE-EM";
		lCompatible->Text = "Compatível com INPE-EM 3.1";
		lVersion->Text = "Versão 2.2";
		lCopyright->Text = "Copyright © 2017. Todos os direitos reservados.";
	}
}

System::Void INPEEM::AboutForm::linkLabel1_LinkClicked(System::Object ^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e)
{
	linkLabel1->LinkVisited = true;
	System::Diagnostics::Process::Start("http://inpe-em.ccst.inpe.br/");
}
