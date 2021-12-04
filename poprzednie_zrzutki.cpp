#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "deklaracje.h"

using namespace std;
//odczyt z pliku
void podglad_poprzednich_zrzutek() {

	ifstream file("Historia zrzutek.txt");
	string line{};
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			cout <<"     "<< line << endl;
		}
	}
	else
		cout << "              Historia zrzutek jest pusta!" << endl;
	Sleep(1000);
	cout << "     Wci" << char(0x98) << "nij ENTER aby wr" << char(0xA2) << "ci" << char(0x86) << " do menu g" << char(0x88) << char(0xA2) << "wnego..." << endl;
	cin.get();
	file.close();
}