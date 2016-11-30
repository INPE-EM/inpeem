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
	/// Summary for ComponentBiomass
	/// </summary>
	public ref class ComponentBiomass : public System::Windows::Forms::Form
	{
	public:
		String^ gSDataMissing = "";
		String^ gSDataMissingTitle = "";

	public:
		cReturn^ lReturn;
		ComponentBiomass(cReturn^ pBiomass)
		{
			InitializeComponent();
			lReturn = pBiomass;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ComponentBiomass()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::TextBox^  tDescription;
	private: System::Windows::Forms::TextBox^  tAverBGBPercAGB;
	private: System::Windows::Forms::TextBox^  tAverAGB;
	private: System::Windows::Forms::TextBox^  tName;
	private: System::Windows::Forms::Label^  lAverBGBPercAGB;
	private: System::Windows::Forms::Label^  lDescription;
	private: System::Windows::Forms::Label^  lAverAGB;
	private: System::Windows::Forms::Label^  lName;
	private: System::Windows::Forms::Label^  lAverLitterPercAGB;
	private: System::Windows::Forms::TextBox^  tAverLitterPercAGB;
	private: System::Windows::Forms::Label^  lAverDeadWoodPercAGB;
	private: System::Windows::Forms::TextBox^  tAverDeadWoodPercAGB;
	private: System::Windows::Forms::TextBox^  tAverFactorB_CO2;
	private: System::Windows::Forms::Label^  lAverFactorB_CO2;
	private: System::Windows::Forms::TextBox^  tAverFactorB_C;
	private: System::Windows::Forms::Label^  lAverFactorB_C;
	private: System::Windows::Forms::TextBox^  tAverFactorB_CO2_fire;
	private: System::Windows::Forms::Label^  lAverFactorB_CO2_fire;
	private: System::Windows::Forms::TextBox^  tAverFactorB_CH4_fire;
	private: System::Windows::Forms::Label^  lAverFactorB_CH4_fire;
	private: System::Windows::Forms::TextBox^  tAverFactorB_N2O_fire;
	private: System::Windows::Forms::Label^  lAverFactorB_N2O_fire;
	private: System::Windows::Forms::TextBox^  tAverFactorB_NOx_fire;
	private: System::Windows::Forms::Label^  lAverFactorB_NOx_fire;
	private: System::Windows::Forms::TextBox^  tAverFactorB_CO_fire;
	private: System::Windows::Forms::Label^  lAverFactorB_CO_fire;
	private: System::Windows::Forms::Panel^  pSpace1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ComponentBiomass::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->tDescription = (gcnew System::Windows::Forms::TextBox());
			this->tAverBGBPercAGB = (gcnew System::Windows::Forms::TextBox());
			this->tAverAGB = (gcnew System::Windows::Forms::TextBox());
			this->tName = (gcnew System::Windows::Forms::TextBox());
			this->lAverBGBPercAGB = (gcnew System::Windows::Forms::Label());
			this->lDescription = (gcnew System::Windows::Forms::Label());
			this->lAverAGB = (gcnew System::Windows::Forms::Label());
			this->lName = (gcnew System::Windows::Forms::Label());
			this->lAverLitterPercAGB = (gcnew System::Windows::Forms::Label());
			this->tAverLitterPercAGB = (gcnew System::Windows::Forms::TextBox());
			this->lAverDeadWoodPercAGB = (gcnew System::Windows::Forms::Label());
			this->tAverDeadWoodPercAGB = (gcnew System::Windows::Forms::TextBox());
			this->tAverFactorB_CO2 = (gcnew System::Windows::Forms::TextBox());
			this->lAverFactorB_CO2 = (gcnew System::Windows::Forms::Label());
			this->tAverFactorB_C = (gcnew System::Windows::Forms::TextBox());
			this->lAverFactorB_C = (gcnew System::Windows::Forms::Label());
			this->tAverFactorB_CO2_fire = (gcnew System::Windows::Forms::TextBox());
			this->lAverFactorB_CO2_fire = (gcnew System::Windows::Forms::Label());
			this->tAverFactorB_CH4_fire = (gcnew System::Windows::Forms::TextBox());
			this->lAverFactorB_CH4_fire = (gcnew System::Windows::Forms::Label());
			this->tAverFactorB_N2O_fire = (gcnew System::Windows::Forms::TextBox());
			this->lAverFactorB_N2O_fire = (gcnew System::Windows::Forms::Label());
			this->tAverFactorB_NOx_fire = (gcnew System::Windows::Forms::TextBox());
			this->lAverFactorB_NOx_fire = (gcnew System::Windows::Forms::Label());
			this->tAverFactorB_CO_fire = (gcnew System::Windows::Forms::TextBox());
			this->lAverFactorB_CO_fire = (gcnew System::Windows::Forms::Label());
			this->pSpace1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(64, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 22;
			this->pbLogo1->TabStop = false;
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(212, 642);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 89;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &ComponentBiomass::bSalvar_Click);
			// 
			// tDescription
			// 
			this->tDescription->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tDescription->Location = System::Drawing::Point(155, 193);
			this->tDescription->Name = L"tDescription";
			this->tDescription->Size = System::Drawing::Size(264, 20);
			this->tDescription->TabIndex = 94;
			this->tDescription->Text = L"Descriçao do Componente";
			this->tDescription->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// tAverBGBPercAGB
			// 
			this->tAverBGBPercAGB->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverBGBPercAGB->Location = System::Drawing::Point(256, 273);
			this->tAverBGBPercAGB->Name = L"tAverBGBPercAGB";
			this->tAverBGBPercAGB->Size = System::Drawing::Size(89, 20);
			this->tAverBGBPercAGB->TabIndex = 95;
			this->tAverBGBPercAGB->Text = L"0.258";
			this->tAverBGBPercAGB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverBGBPercAGB->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// tAverAGB
			// 
			this->tAverAGB->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverAGB->Location = System::Drawing::Point(256, 238);
			this->tAverAGB->Name = L"tAverAGB";
			this->tAverAGB->Size = System::Drawing::Size(89, 20);
			this->tAverAGB->TabIndex = 96;
			this->tAverAGB->Text = L"240";
			this->tAverAGB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverAGB->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// tName
			// 
			this->tName->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->tName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tName->Location = System::Drawing::Point(155, 166);
			this->tName->MaxLength = 2;
			this->tName->Name = L"tName";
			this->tName->Size = System::Drawing::Size(53, 20);
			this->tName->TabIndex = 97;
			this->tName->Text = L"b";
			this->tName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tName->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// lAverBGBPercAGB
			// 
			this->lAverBGBPercAGB->AutoSize = true;
			this->lAverBGBPercAGB->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverBGBPercAGB->Location = System::Drawing::Point(101, 270);
			this->lAverBGBPercAGB->Name = L"lAverBGBPercAGB";
			this->lAverBGBPercAGB->Size = System::Drawing::Size(149, 23);
			this->lAverBGBPercAGB->TabIndex = 90;
			this->lAverBGBPercAGB->Text = L"averBGBPercAGB";
			this->lAverBGBPercAGB->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lDescription
			// 
			this->lDescription->AutoSize = true;
			this->lDescription->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDescription->Location = System::Drawing::Point(61, 193);
			this->lDescription->Name = L"lDescription";
			this->lDescription->Size = System::Drawing::Size(87, 23);
			this->lDescription->TabIndex = 91;
			this->lDescription->Text = L"Descrição";
			this->lDescription->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lAverAGB
			// 
			this->lAverAGB->AutoSize = true;
			this->lAverAGB->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverAGB->Location = System::Drawing::Point(170, 238);
			this->lAverAGB->Name = L"lAverAGB";
			this->lAverAGB->Size = System::Drawing::Size(80, 23);
			this->lAverAGB->TabIndex = 92;
			this->lAverAGB->Text = L"averAGB";
			this->lAverAGB->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lName->Location = System::Drawing::Point(90, 164);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(58, 23);
			this->lName->TabIndex = 93;
			this->lName->Text = L"Nome";
			this->lName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lAverLitterPercAGB
			// 
			this->lAverLitterPercAGB->AutoSize = true;
			this->lAverLitterPercAGB->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverLitterPercAGB->Location = System::Drawing::Point(93, 302);
			this->lAverLitterPercAGB->Name = L"lAverLitterPercAGB";
			this->lAverLitterPercAGB->Size = System::Drawing::Size(157, 23);
			this->lAverLitterPercAGB->TabIndex = 90;
			this->lAverLitterPercAGB->Text = L"averLitterPercAGB";
			this->lAverLitterPercAGB->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverLitterPercAGB
			// 
			this->tAverLitterPercAGB->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverLitterPercAGB->Location = System::Drawing::Point(256, 302);
			this->tAverLitterPercAGB->Name = L"tAverLitterPercAGB";
			this->tAverLitterPercAGB->Size = System::Drawing::Size(89, 20);
			this->tAverLitterPercAGB->TabIndex = 95;
			this->tAverLitterPercAGB->Text = L"0.049";
			this->tAverLitterPercAGB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverLitterPercAGB->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// lAverDeadWoodPercAGB
			// 
			this->lAverDeadWoodPercAGB->AutoSize = true;
			this->lAverDeadWoodPercAGB->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverDeadWoodPercAGB->Location = System::Drawing::Point(48, 334);
			this->lAverDeadWoodPercAGB->Name = L"lAverDeadWoodPercAGB";
			this->lAverDeadWoodPercAGB->Size = System::Drawing::Size(202, 23);
			this->lAverDeadWoodPercAGB->TabIndex = 90;
			this->lAverDeadWoodPercAGB->Text = L"averDeadWoodPercAGB";
			this->lAverDeadWoodPercAGB->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverDeadWoodPercAGB
			// 
			this->tAverDeadWoodPercAGB->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDeadWoodPercAGB->Location = System::Drawing::Point(256, 338);
			this->tAverDeadWoodPercAGB->Name = L"tAverDeadWoodPercAGB";
			this->tAverDeadWoodPercAGB->Size = System::Drawing::Size(89, 20);
			this->tAverDeadWoodPercAGB->TabIndex = 95;
			this->tAverDeadWoodPercAGB->Text = L"0.088";
			this->tAverDeadWoodPercAGB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDeadWoodPercAGB->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// tAverFactorB_CO2
			// 
			this->tAverFactorB_CO2->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverFactorB_CO2->Location = System::Drawing::Point(256, 436);
			this->tAverFactorB_CO2->Name = L"tAverFactorB_CO2";
			this->tAverFactorB_CO2->Size = System::Drawing::Size(89, 20);
			this->tAverFactorB_CO2->TabIndex = 99;
			this->tAverFactorB_CO2->Text = L"1.7249";
			this->tAverFactorB_CO2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverFactorB_CO2->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// lAverFactorB_CO2
			// 
			this->lAverFactorB_CO2->AutoSize = true;
			this->lAverFactorB_CO2->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverFactorB_CO2->Location = System::Drawing::Point(103, 434);
			this->lAverFactorB_CO2->Name = L"lAverFactorB_CO2";
			this->lAverFactorB_CO2->Size = System::Drawing::Size(147, 23);
			this->lAverFactorB_CO2->TabIndex = 98;
			this->lAverFactorB_CO2->Text = L"averFactorB_CO2";
			this->lAverFactorB_CO2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverFactorB_C
			// 
			this->tAverFactorB_C->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverFactorB_C->Location = System::Drawing::Point(256, 405);
			this->tAverFactorB_C->Name = L"tAverFactorB_C";
			this->tAverFactorB_C->Size = System::Drawing::Size(89, 20);
			this->tAverFactorB_C->TabIndex = 101;
			this->tAverFactorB_C->Text = L"0.47";
			this->tAverFactorB_C->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverFactorB_C->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// lAverFactorB_C
			// 
			this->lAverFactorB_C->AutoSize = true;
			this->lAverFactorB_C->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverFactorB_C->Location = System::Drawing::Point(124, 402);
			this->lAverFactorB_C->Name = L"lAverFactorB_C";
			this->lAverFactorB_C->Size = System::Drawing::Size(124, 23);
			this->lAverFactorB_C->TabIndex = 100;
			this->lAverFactorB_C->Text = L"averFactorB_C";
			this->lAverFactorB_C->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverFactorB_CO2_fire
			// 
			this->tAverFactorB_CO2_fire->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverFactorB_CO2_fire->Location = System::Drawing::Point(256, 468);
			this->tAverFactorB_CO2_fire->Name = L"tAverFactorB_CO2_fire";
			this->tAverFactorB_CO2_fire->Size = System::Drawing::Size(89, 20);
			this->tAverFactorB_CO2_fire->TabIndex = 103;
			this->tAverFactorB_CO2_fire->Text = L"1.601";
			this->tAverFactorB_CO2_fire->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverFactorB_CO2_fire->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// lAverFactorB_CO2_fire
			// 
			this->lAverFactorB_CO2_fire->AutoSize = true;
			this->lAverFactorB_CO2_fire->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverFactorB_CO2_fire->Location = System::Drawing::Point(66, 466);
			this->lAverFactorB_CO2_fire->Name = L"lAverFactorB_CO2_fire";
			this->lAverFactorB_CO2_fire->Size = System::Drawing::Size(184, 23);
			this->lAverFactorB_CO2_fire->TabIndex = 102;
			this->lAverFactorB_CO2_fire->Text = L"averFactorB_CO2_fire";
			this->lAverFactorB_CO2_fire->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverFactorB_CH4_fire
			// 
			this->tAverFactorB_CH4_fire->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverFactorB_CH4_fire->Location = System::Drawing::Point(256, 497);
			this->tAverFactorB_CH4_fire->Name = L"tAverFactorB_CH4_fire";
			this->tAverFactorB_CH4_fire->Size = System::Drawing::Size(89, 20);
			this->tAverFactorB_CH4_fire->TabIndex = 105;
			this->tAverFactorB_CH4_fire->Text = L"0.00625";
			this->tAverFactorB_CH4_fire->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverFactorB_CH4_fire->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// lAverFactorB_CH4_fire
			// 
			this->lAverFactorB_CH4_fire->AutoSize = true;
			this->lAverFactorB_CH4_fire->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverFactorB_CH4_fire->Location = System::Drawing::Point(67, 498);
			this->lAverFactorB_CH4_fire->Name = L"lAverFactorB_CH4_fire";
			this->lAverFactorB_CH4_fire->Size = System::Drawing::Size(183, 23);
			this->lAverFactorB_CH4_fire->TabIndex = 104;
			this->lAverFactorB_CH4_fire->Text = L"averFactorB_CH4_fire";
			this->lAverFactorB_CH4_fire->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverFactorB_N2O_fire
			// 
			this->tAverFactorB_N2O_fire->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverFactorB_N2O_fire->Location = System::Drawing::Point(256, 533);
			this->tAverFactorB_N2O_fire->Name = L"tAverFactorB_N2O_fire";
			this->tAverFactorB_N2O_fire->Size = System::Drawing::Size(89, 20);
			this->tAverFactorB_N2O_fire->TabIndex = 107;
			this->tAverFactorB_N2O_fire->Text = L"0.0002";
			this->tAverFactorB_N2O_fire->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverFactorB_N2O_fire->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// lAverFactorB_N2O_fire
			// 
			this->lAverFactorB_N2O_fire->AutoSize = true;
			this->lAverFactorB_N2O_fire->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverFactorB_N2O_fire->Location = System::Drawing::Point(63, 530);
			this->lAverFactorB_N2O_fire->Name = L"lAverFactorB_N2O_fire";
			this->lAverFactorB_N2O_fire->Size = System::Drawing::Size(187, 23);
			this->lAverFactorB_N2O_fire->TabIndex = 106;
			this->lAverFactorB_N2O_fire->Text = L"averFactorB_N2O_fire";
			this->lAverFactorB_N2O_fire->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverFactorB_NOx_fire
			// 
			this->tAverFactorB_NOx_fire->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverFactorB_NOx_fire->Location = System::Drawing::Point(256, 564);
			this->tAverFactorB_NOx_fire->Name = L"tAverFactorB_NOx_fire";
			this->tAverFactorB_NOx_fire->Size = System::Drawing::Size(89, 20);
			this->tAverFactorB_NOx_fire->TabIndex = 109;
			this->tAverFactorB_NOx_fire->Text = L"0.0017";
			this->tAverFactorB_NOx_fire->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverFactorB_NOx_fire->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// lAverFactorB_NOx_fire
			// 
			this->lAverFactorB_NOx_fire->AutoSize = true;
			this->lAverFactorB_NOx_fire->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverFactorB_NOx_fire->Location = System::Drawing::Point(64, 562);
			this->lAverFactorB_NOx_fire->Name = L"lAverFactorB_NOx_fire";
			this->lAverFactorB_NOx_fire->Size = System::Drawing::Size(186, 23);
			this->lAverFactorB_NOx_fire->TabIndex = 108;
			this->lAverFactorB_NOx_fire->Text = L"averFactorB_NOx_fire";
			this->lAverFactorB_NOx_fire->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverFactorB_CO_fire
			// 
			this->tAverFactorB_CO_fire->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverFactorB_CO_fire->Location = System::Drawing::Point(256, 596);
			this->tAverFactorB_CO_fire->Name = L"tAverFactorB_CO_fire";
			this->tAverFactorB_CO_fire->Size = System::Drawing::Size(89, 20);
			this->tAverFactorB_CO_fire->TabIndex = 111;
			this->tAverFactorB_CO_fire->Text = L"0.1078";
			this->tAverFactorB_CO_fire->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverFactorB_CO_fire->Enter += gcnew System::EventHandler(this, &ComponentBiomass::textBox_Enter);
			// 
			// lAverFactorB_CO_fire
			// 
			this->lAverFactorB_CO_fire->AutoSize = true;
			this->lAverFactorB_CO_fire->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverFactorB_CO_fire->Location = System::Drawing::Point(76, 594);
			this->lAverFactorB_CO_fire->Name = L"lAverFactorB_CO_fire";
			this->lAverFactorB_CO_fire->Size = System::Drawing::Size(174, 23);
			this->lAverFactorB_CO_fire->TabIndex = 110;
			this->lAverFactorB_CO_fire->Text = L"averFactorB_CO_fire";
			this->lAverFactorB_CO_fire->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// pSpace1
			// 
			this->pSpace1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pSpace1->Location = System::Drawing::Point(144, 379);
			this->pSpace1->Name = L"pSpace1";
			this->pSpace1->Size = System::Drawing::Size(216, 5);
			this->pSpace1->TabIndex = 140;
			// 
			// ComponentBiomass
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(495, 677);
			this->Controls->Add(this->pSpace1);
			this->Controls->Add(this->tAverFactorB_CO_fire);
			this->Controls->Add(this->lAverFactorB_CO_fire);
			this->Controls->Add(this->tAverFactorB_NOx_fire);
			this->Controls->Add(this->lAverFactorB_NOx_fire);
			this->Controls->Add(this->tAverFactorB_N2O_fire);
			this->Controls->Add(this->lAverFactorB_N2O_fire);
			this->Controls->Add(this->tAverFactorB_CH4_fire);
			this->Controls->Add(this->lAverFactorB_CH4_fire);
			this->Controls->Add(this->tAverFactorB_CO2_fire);
			this->Controls->Add(this->lAverFactorB_CO2_fire);
			this->Controls->Add(this->tAverFactorB_C);
			this->Controls->Add(this->lAverFactorB_C);
			this->Controls->Add(this->tAverFactorB_CO2);
			this->Controls->Add(this->lAverFactorB_CO2);
			this->Controls->Add(this->tDescription);
			this->Controls->Add(this->tAverDeadWoodPercAGB);
			this->Controls->Add(this->tAverLitterPercAGB);
			this->Controls->Add(this->tAverBGBPercAGB);
			this->Controls->Add(this->lAverDeadWoodPercAGB);
			this->Controls->Add(this->tAverAGB);
			this->Controls->Add(this->lAverLitterPercAGB);
			this->Controls->Add(this->tName);
			this->Controls->Add(this->lAverBGBPercAGB);
			this->Controls->Add(this->lDescription);
			this->Controls->Add(this->lAverAGB);
			this->Controls->Add(this->lName);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"ComponentBiomass";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ComponentBiomass";
			this->Shown += gcnew System::EventHandler(this, &ComponentBiomass::ComponentBiomass_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ComponentBiomass_Shown(System::Object^  sender, System::EventArgs^  e);
};
}
