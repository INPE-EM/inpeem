#pragma once

public ref class RegrowRatesInfo
{
public:
	static RegrowRatesInfo^ getInstance();
	~RegrowRatesInfo() {}

	void Add(System::String^ value);
	System::String^ RateAt(unsigned int i);
	void Clear();
	bool IsEmpty();
	int Count();
	void RemoveFrom(unsigned int fromIdx);

private:
	RegrowRatesInfo();
	static RegrowRatesInfo^ instance;
	System::Collections::Generic::List<System::String^>^ rates;
};