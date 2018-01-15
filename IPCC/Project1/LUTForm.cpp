#include "stdafx.h"
#include "LUTForm.h"
#include "NovoModelo.h"

System::Void INPEEM::LUTForm::bAddLUT_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (tLUT->Text != "") {
		this->lvLUT->Items->Add(tLUT->Text);
		tLUT->Text = "";
		bUpLUT->Visible = false;
		bDownLUT->Visible = false;
		bRemLUT->Visible = false;
		tLUT->TabIndex = 1;
		this->Update();
	}
}

System::Void INPEEM::LUTForm::tLUT_Enter(System::Object ^ sender, System::EventArgs ^ e)
{
	if (tLUT->ForeColor != System::Drawing::Color::Black) {
		tLUT->Text = "";
		tLUT->ForeColor = System::Drawing::Color::Black;
		bUpLUT->Visible = false;
		bDownLUT->Visible = false;
		bRemLUT->Visible = false;
		bAddLUT->TabIndex = 1;
		this->Update();
	}
}

System::Void INPEEM::LUTForm::LUTForm_Shown(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lReturn->Language == "en") {
		this->Text = "Land Use Types Management";
		lLUT->Text = "Land Use";
		bAddLUT->Text = "Add";
		bRemLUT->Text = "Delete";
		bSalvar->Text = "Save";
		gSLUT = "Land Use Types";
		gSLUTMod = "The data was modified, but not saved.\nThe data will be lost.\nDo you want to proceed?";
		gSExit = "Exit - Land Use Types";
	}
	else {
		this->Text = "Gerenciar Usos da Terra";
		lLUT->Text = "Uso da Terra";
		bAddLUT->Text = "Adicionar";
		bRemLUT->Text = "Remover";
		bSalvar->Text = "Salvar";
		gSLUT = "Tipos de Uso da Terra";
		gSLUTMod = "Os dados foram modificados, mas não foram salvos.\nOs dados serão perdidos.\nDeseja continuar?";
		gSExit = "Sair - Tipos de Uso da Terra ";
	}

	this->lvLUT->View = View::Details;
	this->lvLUT->GridLines = true;
	this->lvLUT->Columns->Add(gSLUT, lvLUT->Width - 5, HorizontalAlignment::Left);
	if (this->lReturn->Return->Length > 0) {
		String^ aux = "";
		for (int i = 0; i < this->lReturn->Return->Length; i++) {
			if (this->lReturn->Return[i] != '\"') {
				if (this->lReturn->Return[i] == ',') {
					this->lvLUT->Items->Add(aux);
					aux = "";
				}
				else if (this->lReturn->Return[i] != ',')
				{
					aux += this->lReturn->Return[i];
				}
			}
		}
		if (aux != "") {
			this->lvLUT->Items->Add(aux);
			aux = "";
		}
	}
}

System::Void INPEEM::LUTForm::LUTForm_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
{
	if (!close) {
		this->lReturn->Return = "";
		for (int i = 0; i < lvLUT->Items->Count; i++) {
			this->lReturn->Return += "\"";
			this->lReturn->Return += lvLUT->Items[i]->Text;
			if (i == lvLUT->Items->Count - 1) {
				this->lReturn->Return += "\"";
			}
			else {
				this->lReturn->Return += "\",";
			}
		}
		if (aux != this->lReturn->Return) {
			if (MessageBox::Show(gSLUTMod, gSExit, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == INPEEM::DialogResult::No) {
				e->Cancel = true;
			}
			else {
				this->lReturn->Return = aux;
			}
		}
	}
}

System::Void INPEEM::LUTForm::lvLUT_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	bUpLUT->Visible = false;
	bDownLUT->Visible = false;
	bRemLUT->Visible = false;
	this->Update();
	Boolean checked = false;
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected) {
			checked = true;
		}
	}
	if (checked) {
		if (!lvLUT->Items[0]->Selected) {
			bUpLUT->Visible = true;
		}
		if (!lvLUT->Items[lvLUT->Items->Count - 1]->Selected) {
			bDownLUT->Visible = true;
		}
		bRemLUT->Visible = true;
	}
	this->Update();
}

System::Void INPEEM::LUTForm::bRemLUT_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected) {
			lvLUT->Items->RemoveAt(i);
		}
	}
}

System::Void INPEEM::LUTForm::bUpLUT_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	String^ aux = gcnew String("");
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected) {
			aux = lvLUT->Items[i - 1]->Text;
			lvLUT->Items[i - 1]->Text = lvLUT->Items[i]->Text;
			lvLUT->Items[i]->Text = aux;
			lvLUT->Items[i - 1]->Selected = true;
		}
	}
}

System::Void INPEEM::LUTForm::bDownLUT_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	String^ aux = gcnew String("");
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		if (lvLUT->Items[i]->Selected) {
			aux = lvLUT->Items[i + 1]->Text;
			lvLUT->Items[i + 1]->Text = lvLUT->Items[i]->Text;
			lvLUT->Items[i]->Text = aux;
			lvLUT->Items[i + 1]->Selected = true;
			lvLUT->Update();
			break;
		}
	}
}

System::Void INPEEM::LUTForm::LUTForm_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		lvLUT->Items[i]->Selected = false;
	}
	bUpLUT->Visible = false;
	bDownLUT->Visible = false;
	bRemLUT->Visible = false;
	this->Update();
}

System::Void INPEEM::LUTForm::bSalvar_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->lReturn->Return = "";
	for (int i = 0; i < lvLUT->Items->Count; i++) {
		this->lReturn->Return += "\"";
		this->lReturn->Return += lvLUT->Items[i]->Text;
		if (i == lvLUT->Items->Count - 1) {
			this->lReturn->Return += "\"";
		}
		else {
			this->lReturn->Return += "\",";
		}
	}
	close = true;
	INPEEM::Form::Close();
}

System::Void INPEEM::LUTForm::tLUT_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
	switch (e->KeyCode)
	{
	case Keys::Enter:
		if (tLUT->Text != "") {
			bAddLUT_Click(sender, e);
		}
		break;
	default:
		break;
	}

}