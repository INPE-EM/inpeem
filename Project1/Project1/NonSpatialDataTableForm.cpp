#include "stdafx.h"
#include "NonSpatialDataTableForm.h"

Void INPEEM::NonSpatialDataTableForm::NonSpatialDataTableForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		this->Text = "Non Spatial Data Tables";
		lArea->Text = "Area";
		lHalfLife->Text = "Half Life";
		lDegrad->Text = "Degradation";
		bSalvar->Text = "Save";
		gSYear = "Years";
		gSCells = "All the cells must be fullfilled.";
		gSCellsTitle = "Error - Empty Cells";
		gSDataMod = "The data was modified, but not saved.\nThe data will be lost.\nDo you want to proceed?";
		gSExit = "Exit - Non Spatial Data Tables";
		gSCopyPasteTitle = "Copy/Paste";
		gSCopyPaste = "Copy/paste operation failed. ";
		gSPasteTitle = "Paste";
		gSPaste = "Please select a cell";
		gSValues = "Values";
	}
	else {
		this->Text = "Non Spatial Data Tables";
		lArea->Text = "Área";
		lHalfLife->Text = "Meia Vida";
		lDegrad->Text = "Degradação";
		bSalvar->Text = "Salvar";
		gSYear = "Anos";
		gSCells = "Todas as células devem ser preenchidas.";
		gSCellsTitle = "Erro - Células Vazias";
		gSDataMod = "Os dados foram modificados, mas não foram salvos.\nOs dados serão perdidos.\nDeseja continuar?";
		gSExit = "Sair - Non Spatial Data Tables";
		gSCopyPasteTitle = "Copiar/Colar";
		gSCopyPaste = "Operação de Copiar/Colar falhou. ";
		gSPasteTitle = "Colar";
		gSPaste = "Selecione uma célula";
		gSValues = "Valores";
	}

	dgArea->ColumnCount = 2;
	dgArea->Columns[0]->Name = gSYear;
	dgArea->Columns[0]->Width = dgArea->Columns[0]->Width / 2;
	dgArea->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;

	dgHalfLife->ColumnCount = 2;
	dgHalfLife->Columns[0]->Name = gSYear;
	dgHalfLife->Columns[0]->Width = dgHalfLife->Columns[0]->Width / 2;
	dgHalfLife->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;

	dgDegrad->ColumnCount = 2;
	dgDegrad->Columns[0]->Name = gSYear;
	dgDegrad->Columns[0]->Width = dgDegrad->Columns[0]->Width / 2;
	dgDegrad->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;

	int time = Convert::ToInt16(lReturn->StartTime);

	for (int i = 0; i < lReturn->YearsForSimulation; i++) {
		dgArea->Rows->Add(Convert::ToString(time));
		dgHalfLife->Rows->Add(Convert::ToString(time));
		dgDegrad->Rows->Add(Convert::ToString(time));
		time++;
	}

	dgArea->Columns[0]->ReadOnly = true;
	dgHalfLife->Columns[0]->ReadOnly = true;
	dgDegrad->Columns[0]->ReadOnly = true;

	dgArea->Columns[1]->Name = gSValues;
	dgHalfLife->Columns[1]->Name = gSValues;
	dgDegrad->Columns[1]->Name = gSValues;

}

Void INPEEM::NonSpatialDataTableForm::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	bool usingArea = false;
	bool usingHalfLife = false;
	bool usingDegrad = false;
	bool check = true;

	String^ tempArea = "";
	String^ tempHalfLife = "";
	String^ tempDegrad = "";


	for (int i = 0; i < dgArea->RowCount; i++) {
		if (usingArea && dgArea->Rows[i]->Cells[1]->Value == nullptr) {
			MessageBox::Show(gSCells, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
			tempArea = "";
			break;
		} else if (usingHalfLife && dgHalfLife->Rows[i]->Cells[1]->Value == nullptr) {
			MessageBox::Show(gSCells, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
			tempHalfLife = "";
			break;
		} else if (usingDegrad && dgDegrad->Rows[i]->Cells[1]->Value == nullptr) {
			MessageBox::Show(gSCells, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
			tempDegrad = "";
			break;
		}

		if (dgArea->Rows[i]->Cells[1]->Value != nullptr) {
			usingArea = true;
			tempArea += dgArea->Rows[i]->Cells[1]->Value;
			if (i + 1 < dgArea->RowCount) {
				tempArea += ",";
			}
		}
		
		if (dgHalfLife->Rows[i]->Cells[1]->Value != nullptr) {
			usingHalfLife = true;
			tempHalfLife += dgHalfLife->Rows[i]->Cells[1]->Value;
			if (i + 1 < dgHalfLife->RowCount) {
				tempHalfLife += ",";
			}
		}

		if (dgDegrad->Rows[i]->Cells[1]->Value != nullptr) {
			usingDegrad = true;
			tempDegrad += dgDegrad->Rows[i]->Cells[1]->Value;
			if (i + 1 < dgDegrad->RowCount) {
				tempDegrad += ",";
			}
		}
	}

	if (check) {
		lReturn->Return = tempArea;
		lReturn->Return += ";";
		lReturn->Return += tempHalfLife;
		lReturn->Return += ";";
		lReturn->Return += tempDegrad;
		lReturn->Return = lReturn->Return->Replace("\n", "");
		lReturn->Return = lReturn->Return->Replace("\r", "");
		this->Close();
	}
}