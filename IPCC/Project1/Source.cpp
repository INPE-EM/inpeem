#include "stdafx.h"
#include "MyForm.h"

using namespace System;
using namespace System::Reflection;

[assembly:AssemblyVersionAttribute("1.0.0.0")];

using namespace INPEEM;

[STAThreadAttribute]
int main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	INPEEM::MyForm^ myForm1 = gcnew INPEEM::MyForm();
	Application::Run(myForm1);
}