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
	/// Summary for ComponentVegetationRemoval
	/// </summary>
	public ref class ComponentVegetationRemoval : public System::Windows::Forms::Form
	{
	public:
		String^ gSDataMissing = "";
		String^ gSDataMissingTitle = "";

	public:
		cReturn^ lReturn;
		ComponentVegetationRemoval(cReturn^ pVegetationRemoval)
		{
			InitializeComponent();
			lReturn = pVegetationRemoval;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ComponentVegetationRemoval()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pbLogo1;
	private: System::Windows::Forms::TextBox^  tAverDecompositonPercElementalCarbon;
	private: System::Windows::Forms::Label^  lAverDecompositonPercElementalCarbon;
	private: System::Windows::Forms::TextBox^  tAverDecompositionFireCyclePeriod;
	private: System::Windows::Forms::Label^  lAverDecompositionFireCyclePeriod;
	private: System::Windows::Forms::TextBox^  tAverBGBPercDecompositionUnder;
	private: System::Windows::Forms::Label^  lAverBGBPercDecompositionUnder;
	private: System::Windows::Forms::TextBox^  tAverBGBPercDecompositionAbove;

	private: System::Windows::Forms::Label^  lAverBGBPercDecompositionAbove;
	private: System::Windows::Forms::TextBox^  tAverBGBPercInstantaneous;
	private: System::Windows::Forms::Label^  lAverBGBPercInstantaneous;
	private: System::Windows::Forms::TextBox^  tAverAGBPercDecomposition;
	private: System::Windows::Forms::Label^  lAverAGBPercDecomposition;
	private: System::Windows::Forms::TextBox^  tAverBGBPercBGB;
	private: System::Windows::Forms::Label^  lAverBGBPercBGB;
	private: System::Windows::Forms::TextBox^  tDescription;
	private: System::Windows::Forms::TextBox^  tAverAGBPercInstantaneous;
	private: System::Windows::Forms::TextBox^  tAverAGBPercWoodProducts;
	private: System::Windows::Forms::Label^  lAverAGBPercInstantaneous;
	private: System::Windows::Forms::TextBox^  tAverAGBPercAGB;
	private: System::Windows::Forms::TextBox^  tName;
	private: System::Windows::Forms::Label^  lAverAGBPercWoodProducts;
	private: System::Windows::Forms::Label^  lDescription;
	private: System::Windows::Forms::Label^  lAverAGBPercAGB;
	private: System::Windows::Forms::Label^  lName;
	private: System::Windows::Forms::Label^  lAverLitterPercInstantaneous;
	private: System::Windows::Forms::Label^  lAverLitterPercDecomposition;
	private: System::Windows::Forms::Label^  lAverDeadWoodPercInstantaneous;
	private: System::Windows::Forms::TextBox^  tAverLitterPercInstantaneous;
	private: System::Windows::Forms::Label^  lAverDeadWoodPercDecomposition;
	private: System::Windows::Forms::TextBox^  tAverLitterPercDecomposition;
	private: System::Windows::Forms::TextBox^  tAverDeadWoodPercInstantaneous;
	private: System::Windows::Forms::TextBox^  tAverDeadWoodPercDecomposition;
	private: System::Windows::Forms::Label^  lAverDecayRateElementalCarbon;
	private: System::Windows::Forms::TextBox^  tAverDecayRateElementalCarbon;
	private: System::Windows::Forms::Label^  lAverDecayRateWoodProducts;
	private: System::Windows::Forms::TextBox^  tAverDecayRateWoodProducts;
	private: System::Windows::Forms::Label^  lAverDecayRateAGBDecomposition;
	private: System::Windows::Forms::TextBox^  tAverDecayRateAGBDecomposition;
	private: System::Windows::Forms::Label^  lAverDecayRateBGBDecompositionAbove;
	private: System::Windows::Forms::TextBox^  tAverDecayRateBGBDecompositionAbove;
	private: System::Windows::Forms::Label^  lAverDecayRateBGBDecompositionUnder;
	private: System::Windows::Forms::TextBox^  tAverDecayRateBGBDecompositionUnder;
	private: System::Windows::Forms::Label^  lAverDecayRateLitterDecomposition;
	private: System::Windows::Forms::TextBox^  tAverDecayRateLitterDecomposition;
	private: System::Windows::Forms::Label^  lAverDecayRateDeadWoodDecomposition;
	private: System::Windows::Forms::TextBox^  tAverDecayRateDeadWoodDecomposition;
	private: System::Windows::Forms::Button^  bSalvar;
	private: System::Windows::Forms::Panel^  pSpace1;
	private: System::Windows::Forms::Panel^  pSpace2;
	private: System::Windows::Forms::Panel^  pSpace3;
	private: System::Windows::Forms::CheckBox^  cbSave;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ComponentVegetationRemoval::typeid));
			this->pbLogo1 = (gcnew System::Windows::Forms::PictureBox());
			this->tAverDecompositonPercElementalCarbon = (gcnew System::Windows::Forms::TextBox());
			this->lAverDecompositonPercElementalCarbon = (gcnew System::Windows::Forms::Label());
			this->tAverDecompositionFireCyclePeriod = (gcnew System::Windows::Forms::TextBox());
			this->lAverDecompositionFireCyclePeriod = (gcnew System::Windows::Forms::Label());
			this->tAverBGBPercDecompositionUnder = (gcnew System::Windows::Forms::TextBox());
			this->lAverBGBPercDecompositionUnder = (gcnew System::Windows::Forms::Label());
			this->tAverBGBPercDecompositionAbove = (gcnew System::Windows::Forms::TextBox());
			this->lAverBGBPercDecompositionAbove = (gcnew System::Windows::Forms::Label());
			this->tAverBGBPercInstantaneous = (gcnew System::Windows::Forms::TextBox());
			this->lAverBGBPercInstantaneous = (gcnew System::Windows::Forms::Label());
			this->tAverAGBPercDecomposition = (gcnew System::Windows::Forms::TextBox());
			this->lAverAGBPercDecomposition = (gcnew System::Windows::Forms::Label());
			this->tAverBGBPercBGB = (gcnew System::Windows::Forms::TextBox());
			this->lAverBGBPercBGB = (gcnew System::Windows::Forms::Label());
			this->tDescription = (gcnew System::Windows::Forms::TextBox());
			this->tAverAGBPercInstantaneous = (gcnew System::Windows::Forms::TextBox());
			this->tAverAGBPercWoodProducts = (gcnew System::Windows::Forms::TextBox());
			this->lAverAGBPercInstantaneous = (gcnew System::Windows::Forms::Label());
			this->tAverAGBPercAGB = (gcnew System::Windows::Forms::TextBox());
			this->tName = (gcnew System::Windows::Forms::TextBox());
			this->lAverAGBPercWoodProducts = (gcnew System::Windows::Forms::Label());
			this->lDescription = (gcnew System::Windows::Forms::Label());
			this->lAverAGBPercAGB = (gcnew System::Windows::Forms::Label());
			this->lName = (gcnew System::Windows::Forms::Label());
			this->lAverLitterPercInstantaneous = (gcnew System::Windows::Forms::Label());
			this->lAverLitterPercDecomposition = (gcnew System::Windows::Forms::Label());
			this->lAverDeadWoodPercInstantaneous = (gcnew System::Windows::Forms::Label());
			this->tAverLitterPercInstantaneous = (gcnew System::Windows::Forms::TextBox());
			this->lAverDeadWoodPercDecomposition = (gcnew System::Windows::Forms::Label());
			this->tAverLitterPercDecomposition = (gcnew System::Windows::Forms::TextBox());
			this->tAverDeadWoodPercInstantaneous = (gcnew System::Windows::Forms::TextBox());
			this->tAverDeadWoodPercDecomposition = (gcnew System::Windows::Forms::TextBox());
			this->lAverDecayRateElementalCarbon = (gcnew System::Windows::Forms::Label());
			this->tAverDecayRateElementalCarbon = (gcnew System::Windows::Forms::TextBox());
			this->lAverDecayRateWoodProducts = (gcnew System::Windows::Forms::Label());
			this->tAverDecayRateWoodProducts = (gcnew System::Windows::Forms::TextBox());
			this->lAverDecayRateAGBDecomposition = (gcnew System::Windows::Forms::Label());
			this->tAverDecayRateAGBDecomposition = (gcnew System::Windows::Forms::TextBox());
			this->lAverDecayRateBGBDecompositionAbove = (gcnew System::Windows::Forms::Label());
			this->tAverDecayRateBGBDecompositionAbove = (gcnew System::Windows::Forms::TextBox());
			this->lAverDecayRateBGBDecompositionUnder = (gcnew System::Windows::Forms::Label());
			this->tAverDecayRateBGBDecompositionUnder = (gcnew System::Windows::Forms::TextBox());
			this->lAverDecayRateLitterDecomposition = (gcnew System::Windows::Forms::Label());
			this->tAverDecayRateLitterDecomposition = (gcnew System::Windows::Forms::TextBox());
			this->lAverDecayRateDeadWoodDecomposition = (gcnew System::Windows::Forms::Label());
			this->tAverDecayRateDeadWoodDecomposition = (gcnew System::Windows::Forms::TextBox());
			this->bSalvar = (gcnew System::Windows::Forms::Button());
			this->pSpace1 = (gcnew System::Windows::Forms::Panel());
			this->pSpace2 = (gcnew System::Windows::Forms::Panel());
			this->pSpace3 = (gcnew System::Windows::Forms::Panel());
			this->cbSave = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->BeginInit();
			this->SuspendLayout();
			// 
			// pbLogo1
			// 
			this->pbLogo1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo1.Image")));
			this->pbLogo1->Location = System::Drawing::Point(320, 12);
			this->pbLogo1->Name = L"pbLogo1";
			this->pbLogo1->Size = System::Drawing::Size(367, 134);
			this->pbLogo1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbLogo1->TabIndex = 23;
			this->pbLogo1->TabStop = false;
			// 
			// tAverDecompositonPercElementalCarbon
			// 
			this->tAverDecompositonPercElementalCarbon->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDecompositonPercElementalCarbon->Location = System::Drawing::Point(355, 581);
			this->tAverDecompositonPercElementalCarbon->Name = L"tAverDecompositonPercElementalCarbon";
			this->tAverDecompositonPercElementalCarbon->Size = System::Drawing::Size(89, 20);
			this->tAverDecompositonPercElementalCarbon->TabIndex = 134;
			this->tAverDecompositonPercElementalCarbon->Text = L"0.02";
			this->tAverDecompositonPercElementalCarbon->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDecompositonPercElementalCarbon->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDecompositonPercElementalCarbon
			// 
			this->lAverDecompositonPercElementalCarbon->AutoSize = true;
			this->lAverDecompositonPercElementalCarbon->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lAverDecompositonPercElementalCarbon->Location = System::Drawing::Point(16, 581);
			this->lAverDecompositonPercElementalCarbon->Name = L"lAverDecompositonPercElementalCarbon";
			this->lAverDecompositonPercElementalCarbon->Size = System::Drawing::Size(331, 23);
			this->lAverDecompositonPercElementalCarbon->TabIndex = 136;
			this->lAverDecompositonPercElementalCarbon->Text = L"averDecompositonPercElementalCarbon";
			this->lAverDecompositonPercElementalCarbon->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverDecompositionFireCyclePeriod
			// 
			this->tAverDecompositionFireCyclePeriod->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDecompositionFireCyclePeriod->Location = System::Drawing::Point(355, 547);
			this->tAverDecompositionFireCyclePeriod->Name = L"tAverDecompositionFireCyclePeriod";
			this->tAverDecompositionFireCyclePeriod->Size = System::Drawing::Size(89, 20);
			this->tAverDecompositionFireCyclePeriod->TabIndex = 133;
			this->tAverDecompositionFireCyclePeriod->Text = L"3";
			this->tAverDecompositionFireCyclePeriod->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDecompositionFireCyclePeriod->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDecompositionFireCyclePeriod
			// 
			this->lAverDecompositionFireCyclePeriod->AutoSize = true;
			this->lAverDecompositionFireCyclePeriod->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lAverDecompositionFireCyclePeriod->Location = System::Drawing::Point(58, 544);
			this->lAverDecompositionFireCyclePeriod->Name = L"lAverDecompositionFireCyclePeriod";
			this->lAverDecompositionFireCyclePeriod->Size = System::Drawing::Size(289, 23);
			this->lAverDecompositionFireCyclePeriod->TabIndex = 134;
			this->lAverDecompositionFireCyclePeriod->Text = L"averDecompositionFireCyclePeriod";
			this->lAverDecompositionFireCyclePeriod->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverBGBPercDecompositionUnder
			// 
			this->tAverBGBPercDecompositionUnder->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverBGBPercDecompositionUnder->Location = System::Drawing::Point(355, 494);
			this->tAverBGBPercDecompositionUnder->Name = L"tAverBGBPercDecompositionUnder";
			this->tAverBGBPercDecompositionUnder->Size = System::Drawing::Size(89, 20);
			this->tAverBGBPercDecompositionUnder->TabIndex = 132;
			this->tAverBGBPercDecompositionUnder->Text = L"1";
			this->tAverBGBPercDecompositionUnder->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverBGBPercDecompositionUnder->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverBGBPercDecompositionUnder
			// 
			this->lAverBGBPercDecompositionUnder->AutoSize = true;
			this->lAverBGBPercDecompositionUnder->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverBGBPercDecompositionUnder->Location = System::Drawing::Point(66, 493);
			this->lAverBGBPercDecompositionUnder->Name = L"lAverBGBPercDecompositionUnder";
			this->lAverBGBPercDecompositionUnder->Size = System::Drawing::Size(282, 23);
			this->lAverBGBPercDecompositionUnder->TabIndex = 132;
			this->lAverBGBPercDecompositionUnder->Text = L"averBGBPercDecompositionUnder";
			this->lAverBGBPercDecompositionUnder->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverBGBPercDecompositionAbove
			// 
			this->tAverBGBPercDecompositionAbove->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverBGBPercDecompositionAbove->Location = System::Drawing::Point(355, 460);
			this->tAverBGBPercDecompositionAbove->Name = L"tAverBGBPercDecompositionAbove";
			this->tAverBGBPercDecompositionAbove->Size = System::Drawing::Size(89, 20);
			this->tAverBGBPercDecompositionAbove->TabIndex = 131;
			this->tAverBGBPercDecompositionAbove->Text = L"0";
			this->tAverBGBPercDecompositionAbove->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverBGBPercDecompositionAbove->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverBGBPercDecompositionAbove
			// 
			this->lAverBGBPercDecompositionAbove->AutoSize = true;
			this->lAverBGBPercDecompositionAbove->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverBGBPercDecompositionAbove->Location = System::Drawing::Point(64, 459);
			this->lAverBGBPercDecompositionAbove->Name = L"lAverBGBPercDecompositionAbove";
			this->lAverBGBPercDecompositionAbove->Size = System::Drawing::Size(284, 23);
			this->lAverBGBPercDecompositionAbove->TabIndex = 130;
			this->lAverBGBPercDecompositionAbove->Text = L"averBGBPercDecompositionAbove";
			this->lAverBGBPercDecompositionAbove->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverBGBPercInstantaneous
			// 
			this->tAverBGBPercInstantaneous->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverBGBPercInstantaneous->Location = System::Drawing::Point(355, 426);
			this->tAverBGBPercInstantaneous->Name = L"tAverBGBPercInstantaneous";
			this->tAverBGBPercInstantaneous->Size = System::Drawing::Size(89, 20);
			this->tAverBGBPercInstantaneous->TabIndex = 130;
			this->tAverBGBPercInstantaneous->Text = L"0";
			this->tAverBGBPercInstantaneous->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverBGBPercInstantaneous->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverBGBPercInstantaneous
			// 
			this->lAverBGBPercInstantaneous->AutoSize = true;
			this->lAverBGBPercInstantaneous->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverBGBPercInstantaneous->Location = System::Drawing::Point(121, 425);
			this->lAverBGBPercInstantaneous->Name = L"lAverBGBPercInstantaneous";
			this->lAverBGBPercInstantaneous->Size = System::Drawing::Size(227, 23);
			this->lAverBGBPercInstantaneous->TabIndex = 128;
			this->lAverBGBPercInstantaneous->Text = L"averBGBPercInstantaneous";
			this->lAverBGBPercInstantaneous->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverAGBPercDecomposition
			// 
			this->tAverAGBPercDecomposition->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverAGBPercDecomposition->Location = System::Drawing::Point(355, 339);
			this->tAverAGBPercDecomposition->Name = L"tAverAGBPercDecomposition";
			this->tAverAGBPercDecomposition->Size = System::Drawing::Size(89, 20);
			this->tAverAGBPercDecomposition->TabIndex = 128;
			this->tAverAGBPercDecomposition->Text = L"0.425";
			this->tAverAGBPercDecomposition->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverAGBPercDecomposition->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverAGBPercDecomposition
			// 
			this->lAverAGBPercDecomposition->AutoSize = true;
			this->lAverAGBPercDecomposition->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverAGBPercDecomposition->Location = System::Drawing::Point(113, 333);
			this->lAverAGBPercDecomposition->Name = L"lAverAGBPercDecomposition";
			this->lAverAGBPercDecomposition->Size = System::Drawing::Size(234, 23);
			this->lAverAGBPercDecomposition->TabIndex = 126;
			this->lAverAGBPercDecomposition->Text = L"averAGBPercDecomposition";
			this->lAverAGBPercDecomposition->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverBGBPercBGB
			// 
			this->tAverBGBPercBGB->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverBGBPercBGB->Location = System::Drawing::Point(355, 392);
			this->tAverBGBPercBGB->Name = L"tAverBGBPercBGB";
			this->tAverBGBPercBGB->Size = System::Drawing::Size(89, 20);
			this->tAverBGBPercBGB->TabIndex = 129;
			this->tAverBGBPercBGB->Text = L"0";
			this->tAverBGBPercBGB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverBGBPercBGB->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverBGBPercBGB
			// 
			this->lAverBGBPercBGB->AutoSize = true;
			this->lAverBGBPercBGB->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverBGBPercBGB->Location = System::Drawing::Point(201, 391);
			this->lAverBGBPercBGB->Name = L"lAverBGBPercBGB";
			this->lAverBGBPercBGB->Size = System::Drawing::Size(148, 23);
			this->lAverBGBPercBGB->TabIndex = 124;
			this->lAverBGBPercBGB->Text = L"averBGBPercBGB";
			this->lAverBGBPercBGB->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tDescription
			// 
			this->tDescription->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tDescription->Location = System::Drawing::Point(166, 189);
			this->tDescription->Name = L"tDescription";
			this->tDescription->Size = System::Drawing::Size(278, 20);
			this->tDescription->TabIndex = 124;
			this->tDescription->Text = L"Descriçao do Componente";
			this->tDescription->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// tAverAGBPercInstantaneous
			// 
			this->tAverAGBPercInstantaneous->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverAGBPercInstantaneous->Location = System::Drawing::Point(355, 305);
			this->tAverAGBPercInstantaneous->Name = L"tAverAGBPercInstantaneous";
			this->tAverAGBPercInstantaneous->Size = System::Drawing::Size(89, 20);
			this->tAverAGBPercInstantaneous->TabIndex = 127;
			this->tAverAGBPercInstantaneous->Text = L"0.425";
			this->tAverAGBPercInstantaneous->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverAGBPercInstantaneous->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// tAverAGBPercWoodProducts
			// 
			this->tAverAGBPercWoodProducts->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverAGBPercWoodProducts->Location = System::Drawing::Point(355, 271);
			this->tAverAGBPercWoodProducts->Name = L"tAverAGBPercWoodProducts";
			this->tAverAGBPercWoodProducts->Size = System::Drawing::Size(89, 20);
			this->tAverAGBPercWoodProducts->TabIndex = 126;
			this->tAverAGBPercWoodProducts->Text = L"0.15";
			this->tAverAGBPercWoodProducts->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverAGBPercWoodProducts->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverAGBPercInstantaneous
			// 
			this->lAverAGBPercInstantaneous->AutoSize = true;
			this->lAverAGBPercInstantaneous->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverAGBPercInstantaneous->Location = System::Drawing::Point(119, 301);
			this->lAverAGBPercInstantaneous->Name = L"lAverAGBPercInstantaneous";
			this->lAverAGBPercInstantaneous->Size = System::Drawing::Size(228, 23);
			this->lAverAGBPercInstantaneous->TabIndex = 114;
			this->lAverAGBPercInstantaneous->Text = L"averAGBPercInstantaneous";
			this->lAverAGBPercInstantaneous->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverAGBPercAGB
			// 
			this->tAverAGBPercAGB->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverAGBPercAGB->Location = System::Drawing::Point(355, 237);
			this->tAverAGBPercAGB->Name = L"tAverAGBPercAGB";
			this->tAverAGBPercAGB->Size = System::Drawing::Size(89, 20);
			this->tAverAGBPercAGB->TabIndex = 125;
			this->tAverAGBPercAGB->Text = L"0";
			this->tAverAGBPercAGB->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverAGBPercAGB->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// tName
			// 
			this->tName->CharacterCasing = System::Windows::Forms::CharacterCasing::Lower;
			this->tName->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tName->Location = System::Drawing::Point(166, 163);
			this->tName->MaxLength = 2;
			this->tName->Name = L"tName";
			this->tName->Size = System::Drawing::Size(53, 20);
			this->tName->TabIndex = 123;
			this->tName->Text = L"vr";
			this->tName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tName->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverAGBPercWoodProducts
			// 
			this->lAverAGBPercWoodProducts->AutoSize = true;
			this->lAverAGBPercWoodProducts->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverAGBPercWoodProducts->Location = System::Drawing::Point(117, 269);
			this->lAverAGBPercWoodProducts->Name = L"lAverAGBPercWoodProducts";
			this->lAverAGBPercWoodProducts->Size = System::Drawing::Size(231, 23);
			this->lAverAGBPercWoodProducts->TabIndex = 112;
			this->lAverAGBPercWoodProducts->Text = L"averAGBPercWoodProducts";
			this->lAverAGBPercWoodProducts->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lDescription
			// 
			this->lDescription->AutoSize = true;
			this->lDescription->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lDescription->Location = System::Drawing::Point(76, 186);
			this->lDescription->Name = L"lDescription";
			this->lDescription->Size = System::Drawing::Size(87, 23);
			this->lDescription->TabIndex = 115;
			this->lDescription->Text = L"Descrição";
			this->lDescription->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lAverAGBPercAGB
			// 
			this->lAverAGBPercAGB->AutoSize = true;
			this->lAverAGBPercAGB->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverAGBPercAGB->Location = System::Drawing::Point(198, 237);
			this->lAverAGBPercAGB->Name = L"lAverAGBPercAGB";
			this->lAverAGBPercAGB->Size = System::Drawing::Size(150, 23);
			this->lAverAGBPercAGB->TabIndex = 116;
			this->lAverAGBPercAGB->Text = L"averAGBPercAGB";
			this->lAverAGBPercAGB->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lName
			// 
			this->lName->AutoSize = true;
			this->lName->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lName->Location = System::Drawing::Point(105, 160);
			this->lName->Name = L"lName";
			this->lName->Size = System::Drawing::Size(58, 23);
			this->lName->TabIndex = 117;
			this->lName->Text = L"Nome";
			this->lName->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lAverLitterPercInstantaneous
			// 
			this->lAverLitterPercInstantaneous->AutoSize = true;
			this->lAverLitterPercInstantaneous->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverLitterPercInstantaneous->Location = System::Drawing::Point(574, 240);
			this->lAverLitterPercInstantaneous->Name = L"lAverLitterPercInstantaneous";
			this->lAverLitterPercInstantaneous->Size = System::Drawing::Size(235, 23);
			this->lAverLitterPercInstantaneous->TabIndex = 116;
			this->lAverLitterPercInstantaneous->Text = L"averLitterPercInstantaneous";
			this->lAverLitterPercInstantaneous->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lAverLitterPercDecomposition
			// 
			this->lAverLitterPercDecomposition->AutoSize = true;
			this->lAverLitterPercDecomposition->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverLitterPercDecomposition->Location = System::Drawing::Point(568, 273);
			this->lAverLitterPercDecomposition->Name = L"lAverLitterPercDecomposition";
			this->lAverLitterPercDecomposition->Size = System::Drawing::Size(241, 23);
			this->lAverLitterPercDecomposition->TabIndex = 112;
			this->lAverLitterPercDecomposition->Text = L"averLitterPercDecomposition";
			this->lAverLitterPercDecomposition->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// lAverDeadWoodPercInstantaneous
			// 
			this->lAverDeadWoodPercInstantaneous->AutoSize = true;
			this->lAverDeadWoodPercInstantaneous->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverDeadWoodPercInstantaneous->Location = System::Drawing::Point(529, 306);
			this->lAverDeadWoodPercInstantaneous->Name = L"lAverDeadWoodPercInstantaneous";
			this->lAverDeadWoodPercInstantaneous->Size = System::Drawing::Size(280, 23);
			this->lAverDeadWoodPercInstantaneous->TabIndex = 113;
			this->lAverDeadWoodPercInstantaneous->Text = L"averDeadWoodPercInstantaneous";
			this->lAverDeadWoodPercInstantaneous->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverLitterPercInstantaneous
			// 
			this->tAverLitterPercInstantaneous->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverLitterPercInstantaneous->Location = System::Drawing::Point(812, 243);
			this->tAverLitterPercInstantaneous->Name = L"tAverLitterPercInstantaneous";
			this->tAverLitterPercInstantaneous->Size = System::Drawing::Size(89, 20);
			this->tAverLitterPercInstantaneous->TabIndex = 135;
			this->tAverLitterPercInstantaneous->Text = L"1";
			this->tAverLitterPercInstantaneous->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverLitterPercInstantaneous->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDeadWoodPercDecomposition
			// 
			this->lAverDeadWoodPercDecomposition->AutoSize = true;
			this->lAverDeadWoodPercDecomposition->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverDeadWoodPercDecomposition->Location = System::Drawing::Point(523, 338);
			this->lAverDeadWoodPercDecomposition->Name = L"lAverDeadWoodPercDecomposition";
			this->lAverDeadWoodPercDecomposition->Size = System::Drawing::Size(286, 23);
			this->lAverDeadWoodPercDecomposition->TabIndex = 114;
			this->lAverDeadWoodPercDecomposition->Text = L"averDeadWoodPercDecomposition";
			this->lAverDeadWoodPercDecomposition->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverLitterPercDecomposition
			// 
			this->tAverLitterPercDecomposition->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverLitterPercDecomposition->Location = System::Drawing::Point(812, 275);
			this->tAverLitterPercDecomposition->Name = L"tAverLitterPercDecomposition";
			this->tAverLitterPercDecomposition->Size = System::Drawing::Size(89, 20);
			this->tAverLitterPercDecomposition->TabIndex = 136;
			this->tAverLitterPercDecomposition->Text = L"0";
			this->tAverLitterPercDecomposition->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverLitterPercDecomposition->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// tAverDeadWoodPercInstantaneous
			// 
			this->tAverDeadWoodPercInstantaneous->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDeadWoodPercInstantaneous->Location = System::Drawing::Point(812, 307);
			this->tAverDeadWoodPercInstantaneous->Name = L"tAverDeadWoodPercInstantaneous";
			this->tAverDeadWoodPercInstantaneous->Size = System::Drawing::Size(89, 20);
			this->tAverDeadWoodPercInstantaneous->TabIndex = 137;
			this->tAverDeadWoodPercInstantaneous->Text = L"0.5";
			this->tAverDeadWoodPercInstantaneous->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDeadWoodPercInstantaneous->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// tAverDeadWoodPercDecomposition
			// 
			this->tAverDeadWoodPercDecomposition->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDeadWoodPercDecomposition->Location = System::Drawing::Point(812, 339);
			this->tAverDeadWoodPercDecomposition->Name = L"tAverDeadWoodPercDecomposition";
			this->tAverDeadWoodPercDecomposition->Size = System::Drawing::Size(89, 20);
			this->tAverDeadWoodPercDecomposition->TabIndex = 138;
			this->tAverDeadWoodPercDecomposition->Text = L"0.5";
			this->tAverDeadWoodPercDecomposition->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDeadWoodPercDecomposition->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDecayRateElementalCarbon
			// 
			this->lAverDecayRateElementalCarbon->AutoSize = true;
			this->lAverDecayRateElementalCarbon->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverDecayRateElementalCarbon->Location = System::Drawing::Point(543, 420);
			this->lAverDecayRateElementalCarbon->Name = L"lAverDecayRateElementalCarbon";
			this->lAverDecayRateElementalCarbon->Size = System::Drawing::Size(266, 23);
			this->lAverDecayRateElementalCarbon->TabIndex = 124;
			this->lAverDecayRateElementalCarbon->Text = L"averDecayRateElementalCarbon";
			this->lAverDecayRateElementalCarbon->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverDecayRateElementalCarbon
			// 
			this->tAverDecayRateElementalCarbon->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDecayRateElementalCarbon->Location = System::Drawing::Point(812, 420);
			this->tAverDecayRateElementalCarbon->Name = L"tAverDecayRateElementalCarbon";
			this->tAverDecayRateElementalCarbon->Size = System::Drawing::Size(89, 20);
			this->tAverDecayRateElementalCarbon->TabIndex = 140;
			this->tAverDecayRateElementalCarbon->Text = L"0.001";
			this->tAverDecayRateElementalCarbon->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDecayRateElementalCarbon->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDecayRateWoodProducts
			// 
			this->lAverDecayRateWoodProducts->AutoSize = true;
			this->lAverDecayRateWoodProducts->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverDecayRateWoodProducts->Location = System::Drawing::Point(563, 386);
			this->lAverDecayRateWoodProducts->Name = L"lAverDecayRateWoodProducts";
			this->lAverDecayRateWoodProducts->Size = System::Drawing::Size(246, 23);
			this->lAverDecayRateWoodProducts->TabIndex = 126;
			this->lAverDecayRateWoodProducts->Text = L"averDecayRateWoodProducts";
			this->lAverDecayRateWoodProducts->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverDecayRateWoodProducts
			// 
			this->tAverDecayRateWoodProducts->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDecayRateWoodProducts->Location = System::Drawing::Point(812, 388);
			this->tAverDecayRateWoodProducts->Name = L"tAverDecayRateWoodProducts";
			this->tAverDecayRateWoodProducts->Size = System::Drawing::Size(89, 20);
			this->tAverDecayRateWoodProducts->TabIndex = 139;
			this->tAverDecayRateWoodProducts->Text = L"0.1";
			this->tAverDecayRateWoodProducts->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDecayRateWoodProducts->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDecayRateAGBDecomposition
			// 
			this->lAverDecayRateAGBDecomposition->AutoSize = true;
			this->lAverDecayRateAGBDecomposition->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lAverDecayRateAGBDecomposition->Location = System::Drawing::Point(525, 451);
			this->lAverDecayRateAGBDecomposition->Name = L"lAverDecayRateAGBDecomposition";
			this->lAverDecayRateAGBDecomposition->Size = System::Drawing::Size(284, 23);
			this->lAverDecayRateAGBDecomposition->TabIndex = 128;
			this->lAverDecayRateAGBDecomposition->Text = L"averDecayRateAGBDecomposition";
			this->lAverDecayRateAGBDecomposition->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverDecayRateAGBDecomposition
			// 
			this->tAverDecayRateAGBDecomposition->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDecayRateAGBDecomposition->Location = System::Drawing::Point(812, 452);
			this->tAverDecayRateAGBDecomposition->Name = L"tAverDecayRateAGBDecomposition";
			this->tAverDecayRateAGBDecomposition->Size = System::Drawing::Size(89, 20);
			this->tAverDecayRateAGBDecomposition->TabIndex = 141;
			this->tAverDecayRateAGBDecomposition->Text = L"0.4";
			this->tAverDecayRateAGBDecomposition->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDecayRateAGBDecomposition->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDecayRateBGBDecompositionAbove
			// 
			this->lAverDecayRateBGBDecompositionAbove->AutoSize = true;
			this->lAverDecayRateBGBDecompositionAbove->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lAverDecayRateBGBDecompositionAbove->Location = System::Drawing::Point(475, 483);
			this->lAverDecayRateBGBDecompositionAbove->Name = L"lAverDecayRateBGBDecompositionAbove";
			this->lAverDecayRateBGBDecompositionAbove->Size = System::Drawing::Size(334, 23);
			this->lAverDecayRateBGBDecompositionAbove->TabIndex = 130;
			this->lAverDecayRateBGBDecompositionAbove->Text = L"averDecayRateBGBDecompositionAbove";
			this->lAverDecayRateBGBDecompositionAbove->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverDecayRateBGBDecompositionAbove
			// 
			this->tAverDecayRateBGBDecompositionAbove->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDecayRateBGBDecompositionAbove->Location = System::Drawing::Point(812, 484);
			this->tAverDecayRateBGBDecompositionAbove->Name = L"tAverDecayRateBGBDecompositionAbove";
			this->tAverDecayRateBGBDecompositionAbove->Size = System::Drawing::Size(89, 20);
			this->tAverDecayRateBGBDecompositionAbove->TabIndex = 142;
			this->tAverDecayRateBGBDecompositionAbove->Text = L"0.4";
			this->tAverDecayRateBGBDecompositionAbove->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDecayRateBGBDecompositionAbove->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDecayRateBGBDecompositionUnder
			// 
			this->lAverDecayRateBGBDecompositionUnder->AutoSize = true;
			this->lAverDecayRateBGBDecompositionUnder->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lAverDecayRateBGBDecompositionUnder->Location = System::Drawing::Point(477, 515);
			this->lAverDecayRateBGBDecompositionUnder->Name = L"lAverDecayRateBGBDecompositionUnder";
			this->lAverDecayRateBGBDecompositionUnder->Size = System::Drawing::Size(332, 23);
			this->lAverDecayRateBGBDecompositionUnder->TabIndex = 132;
			this->lAverDecayRateBGBDecompositionUnder->Text = L"averDecayRateBGBDecompositionUnder";
			this->lAverDecayRateBGBDecompositionUnder->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverDecayRateBGBDecompositionUnder
			// 
			this->tAverDecayRateBGBDecompositionUnder->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDecayRateBGBDecompositionUnder->Location = System::Drawing::Point(812, 516);
			this->tAverDecayRateBGBDecompositionUnder->Name = L"tAverDecayRateBGBDecompositionUnder";
			this->tAverDecayRateBGBDecompositionUnder->Size = System::Drawing::Size(89, 20);
			this->tAverDecayRateBGBDecompositionUnder->TabIndex = 143;
			this->tAverDecayRateBGBDecompositionUnder->Text = L"0.7";
			this->tAverDecayRateBGBDecompositionUnder->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDecayRateBGBDecompositionUnder->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDecayRateLitterDecomposition
			// 
			this->lAverDecayRateLitterDecomposition->AutoSize = true;
			this->lAverDecayRateLitterDecomposition->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lAverDecayRateLitterDecomposition->Location = System::Drawing::Point(518, 547);
			this->lAverDecayRateLitterDecomposition->Name = L"lAverDecayRateLitterDecomposition";
			this->lAverDecayRateLitterDecomposition->Size = System::Drawing::Size(291, 23);
			this->lAverDecayRateLitterDecomposition->TabIndex = 134;
			this->lAverDecayRateLitterDecomposition->Text = L"averDecayRateLitterDecomposition";
			this->lAverDecayRateLitterDecomposition->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverDecayRateLitterDecomposition
			// 
			this->tAverDecayRateLitterDecomposition->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDecayRateLitterDecomposition->Location = System::Drawing::Point(812, 548);
			this->tAverDecayRateLitterDecomposition->Name = L"tAverDecayRateLitterDecomposition";
			this->tAverDecayRateLitterDecomposition->Size = System::Drawing::Size(89, 20);
			this->tAverDecayRateLitterDecomposition->TabIndex = 144;
			this->tAverDecayRateLitterDecomposition->Text = L"0.4";
			this->tAverDecayRateLitterDecomposition->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDecayRateLitterDecomposition->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// lAverDecayRateDeadWoodDecomposition
			// 
			this->lAverDecayRateDeadWoodDecomposition->AutoSize = true;
			this->lAverDecayRateDeadWoodDecomposition->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lAverDecayRateDeadWoodDecomposition->Location = System::Drawing::Point(473, 579);
			this->lAverDecayRateDeadWoodDecomposition->Name = L"lAverDecayRateDeadWoodDecomposition";
			this->lAverDecayRateDeadWoodDecomposition->Size = System::Drawing::Size(336, 23);
			this->lAverDecayRateDeadWoodDecomposition->TabIndex = 136;
			this->lAverDecayRateDeadWoodDecomposition->Text = L"averDecayRateDeadWoodDecomposition";
			this->lAverDecayRateDeadWoodDecomposition->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// tAverDecayRateDeadWoodDecomposition
			// 
			this->tAverDecayRateDeadWoodDecomposition->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->tAverDecayRateDeadWoodDecomposition->Location = System::Drawing::Point(812, 580);
			this->tAverDecayRateDeadWoodDecomposition->Name = L"tAverDecayRateDeadWoodDecomposition";
			this->tAverDecayRateDeadWoodDecomposition->Size = System::Drawing::Size(89, 20);
			this->tAverDecayRateDeadWoodDecomposition->TabIndex = 145;
			this->tAverDecayRateDeadWoodDecomposition->Text = L"0.4";
			this->tAverDecayRateDeadWoodDecomposition->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tAverDecayRateDeadWoodDecomposition->Enter += gcnew System::EventHandler(this, &ComponentVegetationRemoval::textBox_Enter);
			// 
			// bSalvar
			// 
			this->bSalvar->Location = System::Drawing::Point(466, 642);
			this->bSalvar->Name = L"bSalvar";
			this->bSalvar->Size = System::Drawing::Size(75, 23);
			this->bSalvar->TabIndex = 122;
			this->bSalvar->Text = L"Salvar";
			this->bSalvar->UseVisualStyleBackColor = true;
			this->bSalvar->Click += gcnew System::EventHandler(this, &ComponentVegetationRemoval::bSalvar_Click);
			// 
			// pSpace1
			// 
			this->pSpace1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pSpace1->Location = System::Drawing::Point(228, 373);
			this->pSpace1->Name = L"pSpace1";
			this->pSpace1->Size = System::Drawing::Size(216, 5);
			this->pSpace1->TabIndex = 139;
			// 
			// pSpace2
			// 
			this->pSpace2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pSpace2->Location = System::Drawing::Point(228, 528);
			this->pSpace2->Name = L"pSpace2";
			this->pSpace2->Size = System::Drawing::Size(216, 5);
			this->pSpace2->TabIndex = 140;
			// 
			// pSpace3
			// 
			this->pSpace3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pSpace3->Location = System::Drawing::Point(685, 371);
			this->pSpace3->Name = L"pSpace3";
			this->pSpace3->Size = System::Drawing::Size(216, 5);
			this->pSpace3->TabIndex = 141;
			// 
			// cbSave
			// 
			this->cbSave->AutoSize = true;
			this->cbSave->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold));
			this->cbSave->Location = System::Drawing::Point(736, 172);
			this->cbSave->Name = L"cbSave";
			this->cbSave->Size = System::Drawing::Size(170, 27);
			this->cbSave->TabIndex = 146;
			this->cbSave->Text = L"Salvar em arquivo";
			this->cbSave->UseVisualStyleBackColor = true;
			// 
			// ComponentVegetationRemoval
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1006, 677);
			this->Controls->Add(this->cbSave);
			this->Controls->Add(this->pSpace3);
			this->Controls->Add(this->pSpace2);
			this->Controls->Add(this->pSpace1);
			this->Controls->Add(this->bSalvar);
			this->Controls->Add(this->tAverDecayRateDeadWoodDecomposition);
			this->Controls->Add(this->tAverDecompositonPercElementalCarbon);
			this->Controls->Add(this->lAverDecayRateDeadWoodDecomposition);
			this->Controls->Add(this->lAverDecompositonPercElementalCarbon);
			this->Controls->Add(this->tAverDecayRateLitterDecomposition);
			this->Controls->Add(this->tAverDecompositionFireCyclePeriod);
			this->Controls->Add(this->lAverDecayRateLitterDecomposition);
			this->Controls->Add(this->lAverDecompositionFireCyclePeriod);
			this->Controls->Add(this->tAverDecayRateBGBDecompositionUnder);
			this->Controls->Add(this->tAverBGBPercDecompositionUnder);
			this->Controls->Add(this->lAverDecayRateBGBDecompositionUnder);
			this->Controls->Add(this->lAverBGBPercDecompositionUnder);
			this->Controls->Add(this->tAverDecayRateBGBDecompositionAbove);
			this->Controls->Add(this->tAverBGBPercDecompositionAbove);
			this->Controls->Add(this->lAverDecayRateBGBDecompositionAbove);
			this->Controls->Add(this->lAverBGBPercDecompositionAbove);
			this->Controls->Add(this->tAverDecayRateAGBDecomposition);
			this->Controls->Add(this->tAverBGBPercInstantaneous);
			this->Controls->Add(this->lAverDecayRateAGBDecomposition);
			this->Controls->Add(this->lAverBGBPercInstantaneous);
			this->Controls->Add(this->tAverDecayRateWoodProducts);
			this->Controls->Add(this->tAverAGBPercDecomposition);
			this->Controls->Add(this->lAverDecayRateWoodProducts);
			this->Controls->Add(this->lAverAGBPercDecomposition);
			this->Controls->Add(this->tAverDecayRateElementalCarbon);
			this->Controls->Add(this->tAverBGBPercBGB);
			this->Controls->Add(this->lAverDecayRateElementalCarbon);
			this->Controls->Add(this->lAverBGBPercBGB);
			this->Controls->Add(this->tDescription);
			this->Controls->Add(this->tAverDeadWoodPercDecomposition);
			this->Controls->Add(this->tAverAGBPercInstantaneous);
			this->Controls->Add(this->tAverDeadWoodPercInstantaneous);
			this->Controls->Add(this->tAverLitterPercDecomposition);
			this->Controls->Add(this->tAverAGBPercWoodProducts);
			this->Controls->Add(this->lAverDeadWoodPercDecomposition);
			this->Controls->Add(this->lAverAGBPercInstantaneous);
			this->Controls->Add(this->tAverLitterPercInstantaneous);
			this->Controls->Add(this->lAverDeadWoodPercInstantaneous);
			this->Controls->Add(this->tAverAGBPercAGB);
			this->Controls->Add(this->lAverLitterPercDecomposition);
			this->Controls->Add(this->tName);
			this->Controls->Add(this->lAverAGBPercWoodProducts);
			this->Controls->Add(this->lAverLitterPercInstantaneous);
			this->Controls->Add(this->lDescription);
			this->Controls->Add(this->lAverAGBPercAGB);
			this->Controls->Add(this->lName);
			this->Controls->Add(this->pbLogo1);
			this->Name = L"ComponentVegetationRemoval";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Componente - Vegetação Primária";
			this->Shown += gcnew System::EventHandler(this, &ComponentVegetationRemoval::ComponentVegetationRemoval_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox_Enter(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ComponentVegetationRemoval_Shown(System::Object^  sender, System::EventArgs^  e);
	private: System::Void bSalvar_Click(System::Object^  sender, System::EventArgs^  e);
};
}
