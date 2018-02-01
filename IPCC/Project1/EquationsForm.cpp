#include "stdafx.h"
#include "EquationsForm.h"

/*
Count a number of a caracter on a String
*/
System::Int16 INPEEM::EquationsForm::countCaracter(String^ source, char caracter)
{
	int count = 0;
	for (int i = 0; i < source->Length; i++) {
		if (source[i] == caracter) {
			count++;
		}
	}

	return count;
}

System::Void INPEEM::EquationsForm::EquationsForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		gSFormula = "Equation";
		bSalvar->Text = "Save";

	}
	else {
		gSFormula = "Equação";
		bSalvar->Text = "Salvar";
	}

	tEquation->Visible = false;
	lvEquations->View = View::Details;
	lvEquations->GridLines = true;
	lvEquations->Columns->Add(gSFormula, lvEquations->Width - 52, HorizontalAlignment::Left);

	for (int i = 0; i < gEquations->Length; i++) {
		if (gEquations[i] != nullptr) {
			lvEquations->Items->Add(gEquations[i]);
			if (gEquationsOut[i] != nullptr) {
				lvEquations->Items[i]->SubItems->Add("OK");
			}
		}
		else {
			break;
		}
	}

	lvEquations->Columns->Add("Status", 47, HorizontalAlignment::Left);
}

System::Void INPEEM::EquationsForm::lvEquations_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 0; i < lvEquations->Items->Count; i++) {
		if (lvEquations->Items[i]->Selected == true) {
			tEquation->Text = lvEquations->Items[i]->Text;
			tEquation->Visible = true;
			bAdd->Visible = true;
			bSalvar->Visible = false;
			lvEquations->Visible = false;

			int countSpatialVariables = 0;
			String^ aux = gEquations[i];
			Label^ lFormulaVarTitle = gcnew Label();
			lFormulaVarTitle->Name = "lFormulaVarTitle";
			if (lReturn->Language == "br") {
				lFormulaVarTitle->Text = "Nome na Equação";
			}
			else {
				lFormulaVarTitle->Text = "Name in Equation";
			}
				
			lFormulaVarTitle->Font = gcnew System::Drawing::Font(L"Calibri", 14.25F, FontStyle::Bold);
			lFormulaVarTitle->Location = Point(213, 167);
			lFormulaVarTitle->AutoSize = true;
			Controls->Add(lFormulaVarTitle);

			Label^ lSpatialVarTitle = gcnew Label();
			lSpatialVarTitle->Name = "lSpatialVarTitle";
			if (lReturn->Language == "br") {
				lSpatialVarTitle->Text = "Nome no Shape";
			}
			else {
				lSpatialVarTitle->Text = "Name in Shape";
			}

			lSpatialVarTitle->Font = gcnew System::Drawing::Font(L"Calibri", 14.25F, FontStyle::Bold);
			lSpatialVarTitle->Location = Point(220 + lFormulaVarTitle->Width, 167);
			lSpatialVarTitle->AutoSize = true;
			Controls->Add(lSpatialVarTitle);

			countSpatialVariables = countCaracter(aux, '$');
				
			for (int j = 0; j < countSpatialVariables; j++) {
				aux = aux->Substring(aux->IndexOf("$"));
				int  k = 1;
				String^ varName = "";
					
				while (k < aux->Length && aux[k] != ' ' && aux[k] != '*' && aux[k] != '/' && aux[k] != '-' && aux[k] != '+' && aux[k] != '(' && aux[k] != ')') {
					varName += aux[k];
					k++;
				}

				aux = aux->Substring(k);

				Label^ lSpatialVar = gcnew Label();
				lSpatialVar->Name = "lSpatialVar" + j;
				lSpatialVar->Text = varName;
				lSpatialVar->Font = gcnew System::Drawing::Font(L"Calibri", 14.25F, FontStyle::Bold);
				lSpatialVar->Location = Point(213, 197 + (j * 30));
				lSpatialVar->AutoSize = true;
				Controls->Add(lSpatialVar);

				TextBox^ tSpatialVar = gcnew TextBox();
				tSpatialVar->Name = "tSpatialVar" + j;
				tSpatialVar->Location = Point(223 + lFormulaVarTitle->Width, 197 + (j * 30));
				tSpatialVar->Width = 150;
				
				if (gEquationsOut[i] != nullptr) {
					array<String^>^dataToFill = gEquationsOut[i]->Split('_');
					int k = 0;
					
					while (k < dataToFill[j+1]->Length && dataToFill[j+1][k] != ' ' && dataToFill[j + 1][k] != '*' && dataToFill[j + 1][k] != '/' && dataToFill[j + 1][k] != '-' && dataToFill[j + 1][k] != '+' && dataToFill[j + 1][k] != '(' && dataToFill[j + 1][k] != ')') {
						tSpatialVar->Text += dataToFill[j + 1][k];
						k++;
					}
				}

				Controls->Add(tSpatialVar);
			}
		}
	}
}

System::Void INPEEM::EquationsForm::bAdd_Click(System::Object^  sender, System::EventArgs^  e)
{
	for (int i = 0; i < lvEquations->Items->Count; i++) {
		if (lvEquations->Items[i]->Selected == true) {
			int countSpatialVariables = countCaracter(gEquations[i], '$');
			array<String^>^ formula = gEquations[i]->Split('$');

			for (int j = 0; j < countSpatialVariables; j++) {
				Label^ auxFormula = safe_cast<System::Windows::Forms::Label^>(Controls->Find("lSpatialVar" + j, true)[0]);
				TextBox^ auxSpatial = safe_cast<System::Windows::Forms::TextBox^>(Controls->Find("tSpatialVar" + j, true)[0]);
				
				for (int k = 0; k < formula->Length; k++) {
					if (formula[k]->Contains(auxFormula->Text)) {
						formula[k] = formula[k]->Replace(auxFormula->Text, "f0" + (i+1) + "_" + auxSpatial->Text);
						break;
					}
				}

				Controls->Remove(Controls->Find("lSpatialVar" + j, true)[0]);
				Controls->Remove(Controls->Find("tSpatialVar" + j, true)[0]);
			}

			Controls->Remove(Controls->Find("lFormulaVarTitle", true)[0]);
			Controls->Remove(Controls->Find("lSpatialVarTitle", true)[0]);

			gEquationsOut[i] = "";

			for (int j = 0; j < formula->Length; j++) {
				gEquationsOut[i] += formula[j];
			}
			
			lvEquations->Items[i]->SubItems->Add("OK");
			break;
		}
	}

	for (int i = 0; i < lvEquations->Items->Count; i++) {
		lvEquations->Items[i]->Selected = false;
	}

	bAdd->Visible = false;
	tEquation->Visible = false;
	bSalvar->Visible = true;
	lvEquations->Visible = true;
}

System::Void INPEEM::EquationsForm::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Close();
}
