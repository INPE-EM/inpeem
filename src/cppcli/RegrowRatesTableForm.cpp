#include "stdafx.h"
#include "RegrowRatesTableForm.h"
#include "RegrowRatesInfo.h"

using namespace System::Windows::Forms;

INPEEM::RegrowRatesTableForm::RegrowRatesTableForm(System::String ^ language, int numOfLines)
{
	InitializeComponent();
	this->language = language;
	this->numOfLines = numOfLines;
}

INPEEM::RegrowRatesTableForm::~RegrowRatesTableForm()
{
	if (components)
	{
		delete components;
	}
}

Void INPEEM::RegrowRatesTableForm::RegrowRatesTableForm_Shown(System::Object^  sender, System::EventArgs^  e)
{
	if (language == "en") {
		this->Text = "Regrow Rates";
		ratesLabel->Text = "Regrow Rates";
		bSalvar->Text = "Save";
		gSYear = "";
		gSCells = "At least one table must be used.";
		emptyCellsMsg = "All the cells must be fullfilled.";
		gSCellsHalfLife = "All the cells must be fullfilled in Half Life.";
		gSCellsDegrad = "All the cells must be fullfilled in Degradation.";
		emptyCellsTitle = "Error - Empty Cells";
		gSDataMod = "The data was modified, but not saved.\nThe data will be lost.\nDo you want to proceed?";
		gSExit = "Exit - Regrow Rates";
		gSCopyPasteTitle = "Copy/Paste";
		gSCopyPaste = "Copy/paste operation failed. ";
		gSPasteTitle = "Paste";
		gSPaste = "Please select a cell";
		gSValues = "Values";
	}
	else {
		this->Text = "Taxas de Recrescimento";
		ratesLabel->Text = "Taxas de Recrescimento";
		bSalvar->Text = "Salvar";
		gSYear = "";
		gSCells = "Pelo menos uma tabela deve ser usada.";
		emptyCellsMsg = "Todas as células devem ser preenchidas.";
		emptyCellsTitle = "Erro - Células Vazias";
		gSDataMod = "Os dados foram modificados, mas não foram salvos.\nOs dados serão perdidos.\nDeseja continuar?";
		gSExit = "Sair - Taxas de Recrescimento";
		gSCopyPasteTitle = "Copiar/Colar";
		gSCopyPaste = "Operação de Copiar/Colar falhou. ";
		gSPasteTitle = "Colar";
		gSPaste = "Selecione uma célula";
		gSValues = "Valores";
	}

	ratesDataGrid->ColumnCount = 2;
	ratesDataGrid->Columns[0]->Name = "";
	ratesDataGrid->Columns[0]->Width = ratesDataGrid->Columns[0]->Width / 2;
	ratesDataGrid->Columns[0]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGray;
	
	int time = 1;

	numOfCells = numOfLines;

	for (int i = 0; i < numOfLines; i++) {
		ratesDataGrid->Rows->Add(Convert::ToString(time));
		time++;
	}

	ratesDataGrid->Columns[0]->ReadOnly = true;
	ratesDataGrid->Columns[1]->Name = gSValues;
	ratesDataGrid->CurrentCell = ratesDataGrid->Rows[0]->Cells[1];

	if(RegrowRatesInfo::getInstance()->Count() != numOfLines)
	{
		if(RegrowRatesInfo::getInstance()->Count() > numOfLines)
		{
			RegrowRatesInfo::getInstance()->RemoveFrom(numOfLines);
		}
		else
			RegrowRatesInfo::getInstance()->Clear();
		
	}

	for (int i = 0; i < RegrowRatesInfo::getInstance()->Count(); i++) {
		ratesDataGrid->Rows[i]->Cells[1]->Value = RegrowRatesInfo::getInstance()->RateAt(i);
	}
}

Void INPEEM::RegrowRatesTableForm::bSalvar_Click(System::Object^  sender, System::EventArgs^  e)
{
	RegrowRatesInfo::getInstance()->Clear();

	for(int i = 0; i < ratesDataGrid->RowCount; i++) 
	{
		System::Object^ valueObj = ratesDataGrid->Rows[i]->Cells[1]->Value;

		if((valueObj == nullptr) || (valueObj == ""))
		{
			MessageBox::Show(emptyCellsMsg, emptyCellsTitle, MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;			
		} 

		RegrowRatesInfo::getInstance()->Add(valueObj->ToString());
	}

	this->Close();
}

/*
Locate the initial cell for copying or pasting
*/
System::Windows::Forms::DataGridViewCell ^ INPEEM::RegrowRatesTableForm::GetStartCell(System::Windows::Forms::DataGridView ^ dgAttr)
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
System::Void INPEEM::RegrowRatesTableForm::CopyToClipboard(DataGridView^ dgAttr)
{
	DataObject^ dataObj = dgAttr->GetClipboardContent();
	if (dataObj != nullptr) {
		Clipboard::SetDataObject(dataObj);
	}
}


/*
Paste the clipboard data
*/
System::Void INPEEM::RegrowRatesTableForm::PasteClipboardValue(DataGridView^ dgAttr)
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
		for (int i = 0; i < numOfCells; i++) {
			dgAttr->Rows[i]->Cells[1]->Value = lines[i]->Replace(",", ".");
		}
	}
}

/*
Capture the keys press
*/
System::Void INPEEM::RegrowRatesTableForm::dgAttr_KeyDown(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e)
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

System::Void INPEEM::RegrowRatesTableForm::tsmCopyArea_Click(System::Object^  sender, System::EventArgs^  e) {
	CopyToClipboard(ratesDataGrid);
}

System::Void INPEEM::RegrowRatesTableForm::tsmPasteArea_Click(System::Object^  sender, System::EventArgs^  e) {
	PasteClipboardValue(ratesDataGrid);
}



