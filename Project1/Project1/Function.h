#pragma once
using namespace System;
using namespace System::Collections::Generic;

public ref class cReturn
{
public:
	String^ Return;
	String^ Language;
	cReturn()
	{
		Return = "";
		Language = "";
	}
};

public ref class cReturnPCVINPE
{
public:
	String^ Return;
	int YearsForSimulation;
	bool Empty;
	bool ActiveComponent;
	String^ StartTime;
	String^ LUT;
	String^ Language;
	cReturnPCVINPE()
	{
		Return = "";
		YearsForSimulation = 0;
		Empty = true;
		ActiveComponent = true;
		StartTime = "";
		LUT = "";
		Language = "";
	}
};

public ref class cReturnCITwoMP
{
public:
	String^ Return;
	int FinalYear;
	bool Empty;
	bool ActiveComponent;
	String^ LUT;
	String^ Language;
	cReturnCITwoMP()
	{
		Return = "";
		FinalYear = 0;
		Empty = true;
		ActiveComponent = true;
		LUT = "";
		Language = "";
	}
};

public ref class cReturnCIThreeMP
{
public:
	String^ Return;
	int MiddleYear;
	int FinalYear;
	bool Empty;
	bool ActiveComponent;
	String^ LUT;
	String^ Language;
	cReturnCIThreeMP()
	{
		Return = "";
		FinalYear = 0;
		MiddleYear = 0;
		Empty = true;
		ActiveComponent = true;
		LUT = "";
		Language = "";
	}
};

public ref class cReturnPotential
{
public:
	String^ Return;
	String^ LUT;
	int Component;
	String^ Language;
	cReturnPotential()
	{
		Return = "";
		LUT = "";
		Component = 0;
		Language = "";
	}
};

public ref class cReturnAllocation
{
public:
	String^ Return;
	String^ LUT;
	int Component;
	String^ Language;
	cReturnAllocation()
	{
		Return = "";
		LUT = "";
		Component = 0;
		Language = "";
	}
};
