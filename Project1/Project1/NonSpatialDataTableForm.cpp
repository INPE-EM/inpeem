#include "stdafx.h"
#include "NonSpatialDataTableForm.h"

using namespace System::Windows::Forms;

Void INPEEM::NonSpatialDataTableForm::NonSpatialDataTableForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (lReturn->Language == "en") {
		this->Text = "Non Spatial Data Tables";
		lArea->Text = "Deforest";
		lHalfLife->Text = "Half Life";
		lDegrad->Text = "Degradation";
		bSalvar->Text = "Save";
		gSYear = "Years";
		gSCells = "At least one table must be used.";
		gSCellsArea = "All the cells must be fullfilled in Areas.";
		gSCellsHalfLife = "All the cells must be fullfilled in Half Life.";
		gSCellsDegrad = "All the cells must be fullfilled in Degradation.";
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
		this->Text = "Tabela de Dados Não Espaciais";
		lArea->Text = "Desmatamento";
		lHalfLife->Text = "Meia Vida";
		lDegrad->Text = "Degradação";
		bSalvar->Text = "Salvar";
		gSYear = "Anos";
		gSCells = "Pelo menos uma tabela deve ser usada.";
		gSCellsArea = "Todas as células devem ser preenchidas em Áreas.";
		gSCellsHalfLife = "Todas as células devem ser preenchidas em Meia Vida.";
		gSCellsDegrad = "Todas as células devem ser preenchidas em Degradação.";
		gSCellsTitle = "Erro - Células Vazias";
		gSDataMod = "Os dados foram modificados, mas não foram salvos.\nOs dados serão perdidos.\nDeseja continuar?";
		gSExit = "Sair - Non Spatial Data Tables";
		gSCopyPasteTitle = "Copiar/Colar";
		gSCopyPaste = "Operação de Copiar/Colar falhou. ";
		gSPasteTitle = "Colar";
		gSPaste = "Selecione uma célula";
		gSValues = "Valores";
	}

	dgArea->ColumnCount = 0;
	dgArea->ColumnCount = 2;
	dgArea->Columns[0]->Name = gSYear;
	dgArea->Columns[0]->Width = dgArea->Columns[0]->Width / 2;
	dgArea->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;

	dgHalfLife->ColumnCount = 0;
	dgHalfLife->ColumnCount = 2;
	dgHalfLife->Columns[0]->Name = gSYear;
	dgHalfLife->Columns[0]->Width = dgHalfLife->Columns[0]->Width / 2;
	dgHalfLife->Columns[0]->DefaultCellStyle->ForeColor = System::Drawing::Color::Gray;

	dgDegrad->ColumnCount = 0;
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

	if (lReturn->Return != "") {
		array<String^>^ auxNonSpationData = lReturn->Return->Split(';');
		array<String^>^ auxAreaData = auxNonSpationData[0]->Split(',');
		array<String^>^ auxHalfLifeData = auxNonSpationData[1]->Split(',');
		array<String^>^ auxDegradData = auxNonSpationData[2]->Split(',');

		int sizeDgArea = dgArea->Rows->Count;
		if (sizeDgArea > auxAreaData->Length) {
			sizeDgArea = auxAreaData->Length;
		}

		for (int i = 0; i < sizeDgArea; i++) {
			dgArea->Rows[i]->Cells[1]->Value = auxAreaData[i];
		}

		int sizeDgHalfLife = dgHalfLife->Rows->Count;
		if (sizeDgHalfLife > auxHalfLifeData->Length) {
			sizeDgHalfLife = auxHalfLifeData->Length;
		}

		for (int i = 0; i < sizeDgHalfLife; i++) {
			dgHalfLife->Rows[i]->Cells[1]->Value = auxHalfLifeData[i];
		}

		int sizeDgDegrad = dgDegrad->Rows->Count;
		if (sizeDgDegrad > auxDegradData->Length) {
			sizeDgDegrad = auxDegradData->Length;
		}

		for (int i = 0; i < sizeDgDegrad; i++) {
			dgDegrad->Rows[i]->Cells[1]->Value = auxDegradData[i];
		}
	}
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
		if (dgArea->Rows[i]->Cells[1]->Value != nullptr && dgArea->Rows[i]->Cells[1]->Value != "") {
			usingArea = true;
			tempArea += dgArea->Rows[i]->Cells[1]->Value;
			if (i + 1 < dgArea->RowCount) {
				tempArea += ",";
			}
		}

		if (dgHalfLife->Rows[i]->Cells[1]->Value != nullptr && dgHalfLife->Rows[i]->Cells[1]->Value != "") {
			usingHalfLife = true;
			tempHalfLife += dgHalfLife->Rows[i]->Cells[1]->Value;
			if (i + 1 < dgHalfLife->RowCount) {
				tempHalfLife += ",";
			}
		}

		if (dgDegrad->Rows[i]->Cells[1]->Value != nullptr && dgDegrad->Rows[i]->Cells[1]->Value != "") {
			usingDegrad = true;
			tempDegrad += dgDegrad->Rows[i]->Cells[1]->Value;
			if (i + 1 < dgDegrad->RowCount) {
				tempDegrad += ",";
			}
		}

		if (usingArea && dgArea->Rows[i]->Cells[1]->Value == nullptr) {
			MessageBox::Show(gSCellsArea, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
			tempArea = "";
			break;
		} else if (usingHalfLife && dgHalfLife->Rows[i]->Cells[1]->Value == nullptr) {
			MessageBox::Show(gSCellsHalfLife, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
			tempHalfLife = "";
			break;
		} else if (usingDegrad && dgDegrad->Rows[i]->Cells[1]->Value == nullptr) {
			MessageBox::Show(gSCellsDegrad, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			check = false;
			tempDegrad = "";
			break;
		}
	}

	if (check && (usingArea || usingHalfLife || usingDegrad)) {
		lReturn->Return = "";
		lReturn->Return += tempArea;
		lReturn->Return += ";";
		lReturn->Return += tempHalfLife;
		lReturn->Return += ";";
		lReturn->Return += tempDegrad;
		lReturn->Return = lReturn->Return->Replace("\n", "");
		lReturn->Return = lReturn->Return->Replace("\r", "");
		this->Close();
	}
	else {
		MessageBox::Show(gSCells, gSCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

/*
Locate the initial cell for copying or pasting
*/
System::Windows::Forms::DataGridViewCell ^ INPEEM::NonSpatialDataTableForm::GetStartCell(System::Windows::Forms::DataGridView ^ dgAttr)
{
	//get the smallest row,column index
	if (dgAttr->SelectedCells->Count == NONE)
		return nullptr;

	int rowIndex = dgAttr->Rows->Count - 1;
	int colIndex = dgAttr->Columns->Count - 1;

	for each(DataGridViewCell^ dgvCell in dgAttr->SelectedCells)
	{
		if (dgvCell->RowIndex < rowIndex)
			rowIndex = dgvCell->RowIndex;
		if (dgvCell->ColumnIndex < colIndex)
			colIndex = dgvCell->ColumnIndex;
	}

	return dgAttr[colIndex, rowIndex];
}

/*
Copy the clipboard data
*/
System::Void INPEEM::NonSpatialDataTableForm::CopyToClipboard(DataGridView^ dgAttr)
{
	DataObject^ dataObj = dgAttr->GetClipboardContent();
	if (dataObj != nullptr) {
		Clipboard::SetDataObject(dataObj);
	}
}


/*
Paste the clipboard data
*/
System::Void INPEEM::NonSpatialDataTableForm::PasteClipboardValue(DataGridView^ dgAttr)
{
	//Show Error if no cell is selected
	if (dgAttr->SelectedCells->Count == NONE)
	{
		MessageBox::Show(gSPaste, gSPasteTitle, MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	//Get the satring Cell
	DataGridViewCell^ startCell = GetStartCell(dgAttr);

	//Get the clipboard value in a dictionary
	String^ aux = Clipboard::GetText();

	if (aux != "") {
		array<String^>^ lines = aux->Split('\n');

		if (dgAttr->RowCount < lines->Length - 1) {
			while (dgAttr->RowCount < lines->Length) {
				dgAttr->Rows->Add();
			}
		}


		for (int i = 0; i < lines->Length - 1; i++) {
			dgAttr->Rows[i]->Cells[1]->Value = lines[i];
		}
	}
}

/*
Capture the keys press
*/
System::Void INPEEM::NonSpatialDataTableForm::dgAttr_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
{
	DataGridView^ dgAttr = (DataGridView^)sender;
	try
	{
		if (e->Modifiers == Keys::Control)
		{
			switch (e->KeyCode)
			{
			case Keys::C:
				CopyToClipboard(dgAttr);
				break;

			case Keys::V:
				PasteClipboardValue(dgAttr);
				break;
			}
		}
		else {
			switch (e->KeyCode)
			{
			case Keys::Delete:
				if (dgAttr->SelectedCells->Count != NONE)
				{
					DataGridViewCell^ startCell = GetStartCell(dgAttr);
					int row = startCell->RowIndex;

					for (int i = row; i < dgAttr->RowCount; i++) {
						if (dgAttr->Rows[i]->Cells[1]->Selected) {
							dgAttr->Rows[i]->Cells[1]->Value = "";
						}
					}
				}
			}
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(gSCopyPaste + ex->Message, gSCopyPasteTitle, MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void INPEEM::NonSpatialDataTableForm::tsmCopyArea_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard(dgArea);
}

System::Void INPEEM::NonSpatialDataTableForm::tsmPasteArea_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue(dgArea);
}

System::Void INPEEM::NonSpatialDataTableForm::tsmCopyHalfLife_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard(dgHalfLife);
}

System::Void INPEEM::NonSpatialDataTableForm::tsmPasteHalfLife_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue(dgHalfLife);
}

System::Void INPEEM::NonSpatialDataTableForm::tsmCopyDegrad_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard(dgDegrad);
}

System::Void INPEEM::NonSpatialDataTableForm::tsmPasteDegrad_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue(dgDegrad);
}
