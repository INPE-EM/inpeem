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

public ref class cReturnNSDTF
{
public:
	String^ Return;
	int YearsForSimulation;
	bool Empty;
	bool ActiveComponent;
	String^ StartTime;
	String^ Language;
	cReturnNSDTF()
	{
		Return = "";
		YearsForSimulation = 0;
		Empty = true;
		ActiveComponent = true;
		StartTime = "";
		Language = "";
	}
};

