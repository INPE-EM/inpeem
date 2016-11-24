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
		cReturn^ lReturn;
		NonSpatialDataTableForm(cReturn^ pTables)
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
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::DataGridView^  dgArea;
	private: System::Windows::Forms::Label^  lArea;
	private: System::Windows::Forms::Label^  lHalfLife;
	private: System::Windows::Forms::DataGridView^  dgHalfLife;
	private: System::Windows::Forms::Label^  lDegrad;
	private: System::Windows::Forms::DataGridView^  dgDegrad;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NonSpatialDataTableForm::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->dgArea = (gcnew System::Windows::Forms::DataGridView());
			this->lArea = (gcnew System::Windows::Forms::Label());
			this->lHalfLife = (gcnew System::Windows::Forms::Label());
			this->dgHalfLife = (gcnew System::Windows::Forms::DataGridView());
			this->lDegrad = (gcnew System::Windows::Forms::Label());
			this->dgDegrad = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgArea))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgHalfLife))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDegrad))->BeginInit();
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
			this->bSalvar->TabIndex = 44;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			// 
			// dgArea
			// 
			this->dgArea->AllowUserToAddRows = false;
			this->dgArea->AllowUserToDeleteRows = false;
			this->dgArea->AllowUserToResizeColumns = false;
			this->dgArea->AllowUserToResizeRows = false;
			this->dgArea->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgArea->Location = System::Drawing::Point(16, 196);
			this->dgArea->Name = L"dgArea";
			this->dgArea->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgArea->Size = System::Drawing::Size(226, 426);
			this->dgArea->TabIndex = 43;
			// 
			// lArea
			// 
			this->lArea->AutoSize = true;
			this->lArea->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lArea->Location = System::Drawing::Point(104, 170);
			this->lArea->Name = L"lArea";
			this->lArea->Size = System::Drawing::Size(48, 23);
			this->lArea->TabIndex = 42;
			this->lArea->Text = L"Área";
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
			this->dgHalfLife->Location = System::Drawing::Point(259, 196);
			this->dgHalfLife->Name = L"dgHalfLife";
			this->dgHalfLife->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgHalfLife->Size = System::Drawing::Size(226, 426);
			this->dgHalfLife->TabIndex = 43;
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
			this->dgDegrad->Location = System::Drawing::Point(501, 196);
			this->dgDegrad->Name = L"dgDegrad";
			this->dgDegrad->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dgDegrad->Size = System::Drawing::Size(226, 426);
			this->dgDegrad->TabIndex = 43;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgArea))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgHalfLife))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDegrad))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
