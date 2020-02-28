#pragma once
#include "Function.h"

namespace INPEEM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegrowRatesTableForm
	/// </summary>
	public ref class RegrowRatesTableForm : public System::Windows::Forms::Form
	{
	public:
		String^ gSYear = "";
		String^ gSCells = "";
		String^ gSCellsArea = "";
		String^ gSCellsHalfLife = "";
		String^ gSCellsDegrad = "";
		String^ gSCellsTitle = "";
		String^ gSDataMod = "";
		String^ gSExit = "";
		String^ gSCopyPasteTitle = "";
		String^ gSCopyPaste = "";
		String^ gSPasteTitle = "";
		String^ gSPaste = "";
		String^ gSValues = "";

		String^ emptyCellsMsg = "";
		String^ emptyCellsTitle = "";
		int numOfCells;

	private: System::Windows::Forms::ContextMenuStrip^  cmsHalfLife;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmCopyHalfLife;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmPasteHalfLife;
	private: System::Windows::Forms::ContextMenuStrip^  cmsArea;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmCopyArea;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmPasteArea;
	private: System::Windows::Forms::ContextMenuStrip^  cmsDegrad;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmCopyDegrad;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmPasteDegrad;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::DataGridView^  ratesDataGrid;
	private: System::Windows::Forms::Label^  ratesLabel;
	private: System::ComponentModel::IContainer^  components;

	public:
		RegrowRatesTableForm(System::String^ language, int numOfLines);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegrowRatesTableForm();

	protected:

	private:
		System::String^ language;
		int numOfLines;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->ratesDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->cmsArea = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tsmCopyArea = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmPasteArea = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ratesLabel = (gcnew System::Windows::Forms::Label());
			this->cmsHalfLife = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tsmCopyHalfLife = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmPasteHalfLife = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cmsDegrad = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tsmCopyDegrad = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmPasteDegrad = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ratesDataGrid))->BeginInit();
			this->cmsArea->SuspendLayout();
			this->cmsHalfLife->SuspendLayout();
			this->cmsDegrad->SuspendLayout();
			this->SuspendLayout();
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(88, 473);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 103;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &RegrowRatesTableForm::bSalvar_Click);
			// 
			// ratesDataGrid
			// 
			this->ratesDataGrid->AllowUserToAddRows = false;
			this->ratesDataGrid->AllowUserToDeleteRows = false;
			this->ratesDataGrid->AllowUserToResizeColumns = false;
			this->ratesDataGrid->AllowUserToResizeRows = false;
			this->ratesDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ratesDataGrid->ContextMenuStrip = this->cmsArea;
			this->ratesDataGrid->Location = System::Drawing::Point(12, 41);
			this->ratesDataGrid->Name = L"ratesDataGrid";
			this->ratesDataGrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->ratesDataGrid->Size = System::Drawing::Size(226, 426);
			this->ratesDataGrid->TabIndex = 100;
			this->ratesDataGrid->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RegrowRatesTableForm::dgAttr_KeyDown);
			// 
			// cmsArea
			// 
			this->cmsArea->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->tsmCopyArea, this->tsmPasteArea });
			this->cmsArea->Name = L"contextMenuStrip1";
			this->cmsArea->Size = System::Drawing::Size(103, 48);
			// 
			// tsmCopyArea
			// 
			this->tsmCopyArea->Name = L"tsmCopyArea";
			this->tsmCopyArea->Size = System::Drawing::Size(102, 22);
			this->tsmCopyArea->Text = L"Copy";
			this->tsmCopyArea->Click += gcnew System::EventHandler(this, &RegrowRatesTableForm::tsmCopyArea_Click);
			// 
			// tsmPasteArea
			// 
			this->tsmPasteArea->Name = L"tsmPasteArea";
			this->tsmPasteArea->Size = System::Drawing::Size(102, 22);
			this->tsmPasteArea->Text = L"Paste";
			this->tsmPasteArea->Click += gcnew System::EventHandler(this, &RegrowRatesTableForm::tsmPasteArea_Click);
			// 
			// ratesLabel
			// 
			this->ratesLabel->AutoSize = true;
			this->ratesLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ratesLabel->Location = System::Drawing::Point(24, 10);
			this->ratesLabel->Name = L"ratesLabel";
			this->ratesLabel->Size = System::Drawing::Size(200, 23);
			this->ratesLabel->TabIndex = 42;
			this->ratesLabel->Text = L"Taxas de Recrescimento";
			this->ratesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->ratesLabel->Click += gcnew System::EventHandler(this, &RegrowRatesTableForm::ratesLabel_Click);
			// 
			// cmsHalfLife
			// 
			this->cmsHalfLife->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tsmCopyHalfLife,
					this->tsmPasteHalfLife
			});
			this->cmsHalfLife->Name = L"contextMenuStrip1";
			this->cmsHalfLife->Size = System::Drawing::Size(68, 48);
			// 
			// tsmCopyHalfLife
			// 
			this->tsmCopyHalfLife->Name = L"tsmCopyHalfLife";
			this->tsmCopyHalfLife->Size = System::Drawing::Size(67, 22);
			// 
			// tsmPasteHalfLife
			// 
			this->tsmPasteHalfLife->Name = L"tsmPasteHalfLife";
			this->tsmPasteHalfLife->Size = System::Drawing::Size(67, 22);
			// 
			// cmsDegrad
			// 
			this->cmsDegrad->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->tsmCopyDegrad, this->tsmPasteDegrad });
			this->cmsDegrad->Name = L"contextMenuStrip1";
			this->cmsDegrad->Size = System::Drawing::Size(68, 48);
			// 
			// tsmCopyDegrad
			// 
			this->tsmCopyDegrad->Name = L"tsmCopyDegrad";
			this->tsmCopyDegrad->Size = System::Drawing::Size(67, 22);
			// 
			// tsmPasteDegrad
			// 
			this->tsmPasteDegrad->Name = L"tsmPasteDegrad";
			this->tsmPasteDegrad->Size = System::Drawing::Size(67, 22);
			// 
			// RegrowRatesTableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(251, 506);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->ratesDataGrid);
			this->Controls->Add(this->ratesLabel);
			this->Name = L"RegrowRatesTableForm";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Taxas de Recrescimento";
			this->Shown += gcnew System::EventHandler(this, &RegrowRatesTableForm::RegrowRatesTableForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ratesDataGrid))->EndInit();
			this->cmsArea->ResumeLayout(false);
			this->cmsHalfLife->ResumeLayout(false);
			this->cmsDegrad->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RegrowRatesTableForm_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgAttr);
	private: System::Void dgAttr_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void CopyToClipboard(DataGridView^ dgAttr);
	private: System::Void PasteClipboardValue(DataGridView^ dgAttr);
	private: System::Void tsmCopyArea_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tsmPasteArea_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ratesLabel_Click(System::Object^  sender, System::EventArgs^  e) {}
	};
}
