#include "stdafx.h"
#include "AboutForm.h"

System::Void INPEEM::AboutForm::AboutForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lLanguage == "en") {
		this->Text = "About";
		lProgram->Text = "INPE-EM IPCC Model Manager";
		lCompatible->Text = "Compatible with INPE-EM IPCC 1.0";
		lVersion->Text = "Version 1.0";
		lCopyright->Text = "Copyright © 2018. All rigths reserved.";
	}
	else {
		this->Text = "Sobre";
		lProgram->Text = "Gerenciador de Modelos INPE-EM IPCC";
		lCompatible->Text = "Compatível com INPE-EM IPCC 1.0";
		lVersion->Text = "Versão 1.0";
		lCopyright->Text = "Copyright © 2018. Todos os direitos reservados.";
	}
}

System::Void INPEEM::AboutForm::linkLabel1_LinkClicked(System::Object ^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e)
{
	linkLabel1->LinkVisited = true;
	System::Diagnostics::Process::Start("http://inpe-em.ccst.inpe.br/");
}
