#include "stdafx.h"
#include "NovoModelo.h"
#include "Function.h"
#include "LanguageForm.h"
#include "AboutForm.h"
#include "ComponentDeforest.h"
#include "ComponentBiomass.h"
#include "ComponentDegradation.h"
#include "ComponentSecondaryVegetation.h"
#include "ComponentVegetationRemoval.h"
#include "NonSpatialDataTableForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

Void INPEEM::NovoModelo::bDeforest_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lDeforest = gcnew cReturn();
	if (gDeforest != "") {
		lDeforest->Return = gDeforest;
	}
	
	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lDeforest);
	deforestForm->ShowDialog();

	if (lDeforest->Return != "") {
		gDeforest = lDeforest->Return;
	}
}

Void INPEEM::NovoModelo::bBiomass_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lBiomass = gcnew cReturn();
	if (gBiomass != "") {
		lBiomass->Return = gBiomass;
	}

	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lBiomass);
	deforestForm->ShowDialog();

	if (lBiomass->Return != "") {
		gBiomass = lBiomass->Return;
	}
}

Void INPEEM::NovoModelo::bVegetationRemoval_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lVegetationRemoval = gcnew cReturn();
	if (gVegetationRemoval != "") {
		lVegetationRemoval->Return = gVegetationRemoval;
	}

	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lVegetationRemoval);
	deforestForm->ShowDialog();

	if (lVegetationRemoval->Return != "") {
		gVegetationRemoval = lVegetationRemoval->Return;
	}
}

Void INPEEM::NovoModelo::bSecondVegetation_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lSecondaryVegetation = gcnew cReturn();
	if (gSecondaryVegetation != "") {
		lSecondaryVegetation->Return = gSecondaryVegetation;
	}

	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lSecondaryVegetation);
	deforestForm->ShowDialog();

	if (lSecondaryVegetation->Return != "") {
		gSecondaryVegetation = lSecondaryVegetation->Return;
	}
}

Void INPEEM::NovoModelo::bDegrad_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lDegradation = gcnew cReturn();
	if (gDegradation != "") {
		lDegradation->Return = gDegradation;
	}

	ComponentDeforest^ deforestForm = gcnew ComponentDeforest(lDegradation);
	deforestForm->ShowDialog();

	if (lDegradation->Return != "") {
		gDegradation = lDegradation->Return;
	}
}

Void INPEEM::NovoModelo::bTableData_Click(System::Object^  sender, System::EventArgs^  e)
{
	cReturn^ lNonSpatialTables = gcnew cReturn();
	if (gNonSpatialTables != "") {
		lNonSpatialTables->Return = gNonSpatialTables;
	}

	NonSpatialDataTableForm^ nonSpatialDataTableForm = gcnew NonSpatialDataTableForm(lNonSpatialTables);
	nonSpatialDataTableForm->ShowDialog();

	if (lNonSpatialTables->Return != "") {
		gNonSpatialTables = lNonSpatialTables->Return;
	}
}