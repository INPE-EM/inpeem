#include "RegrowRatesInfo.h"

RegrowRatesInfo::RegrowRatesInfo()
{
	rates = gcnew System::Collections::Generic::List<System::String^>();
}

RegrowRatesInfo^ RegrowRatesInfo::getInstance()
{
	if (!instance)
	{
		instance = gcnew RegrowRatesInfo();
	}

	return instance;
}

void RegrowRatesInfo::Add(System::String ^ value)
{
	rates->Add(value);
}

System::String ^ RegrowRatesInfo::RateAt(unsigned int i)
{
	return rates[i];
}

void RegrowRatesInfo::Clear()
{
	rates->Clear();
}

bool RegrowRatesInfo::IsEmpty()
{
	return rates->Count == 0;
}

int RegrowRatesInfo::Count()
{
	return rates->Count;
}

void RegrowRatesInfo::RemoveFrom(unsigned int fromIdx)
{
	rates->RemoveRange(fromIdx, rates->Count - fromIdx);
}
