//precompiled header mora ici na pocetku; on u biti nije include; ako imamo neke druge ispred, 
//a njega nakon, ignorirat ce sve ispred
//namjena je da u njemu drzimo headere koji se nece mijenjati


#include "pch.h"
#include <iostream>
#include "../lib/public.h";
#include "../dll2/public.h";
#include <windows.h> 

int main()
{
	typedef double (CALLBACK* FuncAdress) (int);

   //from static lib:
	std::cout << static_lib::get_value(5) << std::endl;

	//from dynamic s impl
	std::cout << get_value(5) << std::endl;

	//from dynamic_library
	HINSTANCE handle = LoadLibraryA("C:\\day1\\exercise\\01\\dll1\\x64\\Debug\\dynamic_library.dll");
	if (handle == NULL)
		return -1;
	FuncAdress fAddress = (FuncAdress) GetProcAddress(handle, "get_value");
	if (fAddress == NULL)
		return -2;
	double value = fAddress(5);
	std::cout << value << std::endl;
	FreeLibrary(handle);
	return 0;
}

