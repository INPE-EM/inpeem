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
	/// Summary for NonSpatialDataTableForm
	/// </summary>
	public ref class NonSpatialDataTableForm : public System::Windows::Forms::Form
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

	private: System::Windows::Forms::ContextMenuStrip^  cmsHalfLife;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmCopyHalfLife;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmPasteHalfLife;
	private: System::Windows::Forms::ContextMenuStrip^  cmsArea;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmCopyArea;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmPasteArea;
	private: System::Windows::Forms::ContextMenuStrip^  cmsDegrad;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmCopyDegrad;
	private: System::Windows::Forms::ToolStripMenuItem^  tsmPasteDegrad;
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::DataGridView^  dgArea;
	private: System::Windows::Forms::Label^  lArea;
	private: System::Windows::Forms::Label^  lHalfLife;
	private: System::Windows::Forms::DataGridView^  dgHalfLife;
	private: System::Windows::Forms::Label^  lDegrad;
	private: System::Windows::Forms::DataGridView^  dgDegrad;
	private: System::ComponentModel::IContainer^  components;

	public:
		cReturnNSDTF^ lReturn;
		NonSpatialDataTableForm(cReturnNSDTF^ pTables)
		{
			InitializeComponent();
			lReturn = pTables;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NonSpatialDataTableForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NonSpatialDataTableForm::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->dgArea = (gcnew System::Windows::Forms::DataGridView());
			this->cmsArea = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tsmCopyArea = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmPasteArea = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lArea = (gcnew System::Windows::Forms::Label());
			this->lHalfLife = (gcnew System::Windows::Forms::Label());
			this->dgHalfLife = (gcnew System::Windows::Forms::DataGridView());
			this->cmsHalfLife = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tsmCopyHalfLife = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmPasteHalfLife = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lDegrad = (gcnew System::Windows::Forms::Label());
			this->dgDegrad = (gcnew System::Windows::Forms::DataGridView());
			this->cmsDegrad = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->tsmCopyDegrad = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tsmPasteDegrad = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgArea))->BeginInit();
			this->cmsArea->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgHalfLife))->BeginInit();
			this->cmsHalfLife->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDegrad))->BeginInit();
			this->cmsDegrad->SuspendLayout();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(189, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 23;
			this->pbLogo1->TabStop = false;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(335, 642);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 103;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &NonSpatialDataTableForm::bSalvar_Click);
			// 
			// dgArea
			// 
			this->dgArea->AllowUserToAddRows = false;
			this->dgArea->AllowUserToDeleteRows = false;
			this->dgArea->AllowUserToResizeColumns = false;
			this->dgArea->AllowUserToResizeRows = false;
			this->dgArea->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgArea->ContextMenuStrip = this->cmsArea;
			this->dgArea->Location = System::Drawing::Point(16, 196);
			this->dgArea->Name = L"dgArea";
			this->dgArea->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgArea->Size = System::Drawing::Size(226, 426);
			this->dgArea->TabIndex = 100;
			this->dgArea->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NonSpatialDataTableForm::dgAttr_KeyDown);
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
			this->tsmCopyArea->Click += gcnew System::EventHandler(this, &NonSpatialDataTableForm::tsmCopyArea_Click);
			// 
			// tsmPasteArea
			// 
			this->tsmPasteArea->Name = L"tsmPasteArea";
			this->tsmPasteArea->Size = System::Drawing::Size(102, 22);
			this->tsmPasteArea->Text = L"Paste";
			this->tsmPasteArea->Click += gcnew System::EventHandler(this, &NonSpatialDataTableForm::tsmPasteArea_Click);
			// 
			// lArea
			// 
			this->lArea->AutoSize = true;
			this->lArea->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lArea->Location = System::Drawing::Point(65, 170);
			this->lArea->Name = L"lArea";
			this->lArea->Size = System::Drawing::Size(132, 23);
			this->lArea->TabIndex = 42;
			this->lArea->Text = L"Desmatamento";
			this->lArea->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lHalfLife
			// 
			this->lHalfLife->AutoSize = true;
			this->lHalfLife->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lHalfLife->Location = System::Drawing::Point(329, 170);
			this->lHalfLife->Name = L"lHalfLife";
			this->lHalfLife->Size = System::Drawing::Size(90, 23);
			this->lHalfLife->TabIndex = 42;
			this->lHalfLife->Text = L"Meia Vida";
			this->lHalfLife->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dgHalfLife
			// 
			this->dgHalfLife->AllowUserToAddRows = false;
			this->dgHalfLife->AllowUserToDeleteRows = false;
			this->dgHalfLife->AllowUserToResizeColumns = false;
			this->dgHalfLife->AllowUserToResizeRows = false;
			this->dgHalfLife->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgHalfLife->ContextMenuStrip = this->cmsHalfLife;
			this->dgHalfLife->Location = System::Drawing::Point(259, 196);
			this->dgHalfLife->Name = L"dgHalfLife";
			this->dgHalfLife->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgHalfLife->Size = System::Drawing::Size(226, 426);
			this->dgHalfLife->TabIndex = 101;
			this->dgHalfLife->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NonSpatialDataTableForm::dgAttr_KeyDown);
			// 
			// cmsHalfLife
			// 
			this->cmsHalfLife->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tsmCopyHalfLife,
					this->tsmPasteHalfLife
			});
			this->cmsHalfLife->Name = L"contextMenuStrip1";
			this->cmsHalfLife->Size = System::Drawing::Size(103, 48);
			// 
			// tsmCopyHalfLife
			// 
			this->tsmCopyHalfLife->Name = L"tsmCopyHalfLife";
			this->tsmCopyHalfLife->Size = System::Drawing::Size(102, 22);
			this->tsmCopyHalfLife->Text = L"Copy";
			this->tsmCopyHalfLife->Click += gcnew System::EventHandler(this, &NonSpatialDataTableForm::tsmCopyHalfLife_Click);
			// 
			// tsmPasteHalfLife
			// 
			this->tsmPasteHalfLife->Name = L"tsmPasteHalfLife";
			this->tsmPasteHalfLife->Size = System::Drawing::Size(102, 22);
			this->tsmPasteHalfLife->Text = L"Paste";
			this->tsmPasteHalfLife->Click += gcnew System::EventHandler(this, &NonSpatialDataTableForm::tsmPasteHalfLife_Click);
			// 
			// lDegrad
			// 
			this->lDegrad->AutoSize = true;
			this->lDegrad->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDegrad->Location = System::Drawing::Point(568, 170);
			this->lDegrad->Name = L"lDegrad";
			this->lDegrad->Size = System::Drawing::Size(103, 23);
			this->lDegrad->TabIndex = 42;
			this->lDegrad->Text = L"Degradação";
			this->lDegrad->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// dgDegrad
			// 
			this->dgDegrad->AllowUserToAddRows = false;
			this->dgDegrad->AllowUserToDeleteRows = false;
			this->dgDegrad->AllowUserToResizeColumns = false;
			this->dgDegrad->AllowUserToResizeRows = false;
			this->dgDegrad->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgDegrad->ContextMenuStrip = this->cmsDegrad;
			this->dgDegrad->Location = System::Drawing::Point(501, 196);
			this->dgDegrad->Name = L"dgDegrad";
			this->dgDegrad->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgDegrad->Size = System::Drawing::Size(226, 426);
			this->dgDegrad->TabIndex = 102;
			this->dgDegrad->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &NonSpatialDataTableForm::dgAttr_KeyDown);
			// 
			// cmsDegrad
			// 
			this->cmsDegrad->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->tsmCopyDegrad, this->tsmPasteDegrad });
			this->cmsDegrad->Name = L"contextMenuStrip1";
			this->cmsDegrad->Size = System::Drawing::Size(103, 48);
			// 
			// tsmCopyDegrad
			// 
			this->tsmCopyDegrad->Name = L"tsmCopyDegrad";
			this->tsmCopyDegrad->Size = System::Drawing::Size(102, 22);
			this->tsmCopyDegrad->Text = L"Copy";
			this->tsmCopyDegrad->Click += gcnew System::EventHandler(this, &NonSpatialDataTableForm::tsmCopyDegrad_Click);
			// 
			// tsmPasteDegrad
			// 
			this->tsmPasteDegrad->Name = L"tsmPasteDegrad";
			this->tsmPasteDegrad->Size = System::Drawing::Size(102, 22);
			this->tsmPasteDegrad->Text = L"Paste";
			this->tsmPasteDegrad->Click += gcnew System::EventHandler(this, &NonSpatialDataTableForm::tsmPasteDegrad_Click);
			// 
			// NonSpatialDataTableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(745, 677);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->dgDegrad);
			this->Controls->Add(this->lDegrad);
			this->Controls->Add(this->dgHalfLife);
			this->Controls->Add(this->lHalfLife);
			this->Controls->Add(this->dgArea);
			this->Controls->Add(this->lArea);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"NonSpatialDataTableForm";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Non Spatial - Data Tables";
			this->Shown += gcnew System::EventHandler(this, &NonSpatialDataTableForm::NonSpatialDataTableForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgArea))->EndInit();
			this->cmsArea->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgHalfLife))->EndInit();
			this->cmsHalfLife->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDegrad))->EndInit();
			this->cmsDegrad->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void NonSpatialDataTableForm_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Windows::Forms::DataGridViewCell^ GetStartCell(System::Windows::Forms::DataGridView^ dgAttr);
	private: System::Void dgAttr_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
	private: System::Void CopyToClipboard(DataGridView^ dgAttr);
	private: System::Void PasteClipboardValue(DataGridView^ dgAttr);
	private: System::Void tsmCopyArea_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tsmPasteArea_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tsmCopyHalfLife_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tsmPasteHalfLife_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tsmCopyDegrad_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tsmPasteDegrad_Click(System::Object^  sender, System::EventArgs^  e);
};
}
