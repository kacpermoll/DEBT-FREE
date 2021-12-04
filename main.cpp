#include <iostream>
#include <string>
#include <cstdlib>
//#include <stdio.h>
#include <conio.h>
//#include<ctime>
#include<windows.h>
#include<iomanip>
#include "deklaracje.h"
using namespace std;

//wyœwietlanie okna pocz¹tkowego oraz opcja zmiany motywu
int main() {
	system("Color 70");
	while (true) {
		cout << endl;
		cout << "		  ##   #### ###  #######      ##### ###  #### ####" << endl;
		cout << "		  # #  #    #  #    #         #     #  # #    #" << endl;
		cout << "		  #  # ###  ###     #    $$   ###   ###  ###  ###" << endl;
		cout << "		  # #  #    #  #    #         #     # #  #    #" << endl;
		cout << "		  ##   #### ####    #         #     #  # #### ####" << endl;
		cout << endl;
		cout << "				    MENU G"<<char(0x9D) <<char(0xE0)<<"WNE" << endl;
		cout << "			 ----------------------------------" << endl;
		cout << "			 $ 1. Nowa zrzutka                $" << endl;
		cout << "			 $ 2. Kalkulator                  $" << endl;
		cout << "			 $ 3. Podgl"<<char(0xA5) <<"d poprzednich zrzutek $" << endl;
		cout << "			 $ 4. Informacje o programie      $" << endl;
		cout << "			 $ 5. Zmiana motywu               $" << endl;
		cout << "			 $ 6. Wyjd" << char(0xAB) << " z programu            $" << endl;
		cout << "			 ----------------------------------" << endl << endl;

		cout << "			   Wybierz: ";
		char wybor{};
		char wybor1{};
		wybor = _getch();
		system("cls");
		switch (wybor)
		{
		case '1': 
			nowa_zrzutka();
			break;
		case '2': 
			kalkulator();
			break;
		case '3':
			podglad_poprzednich_zrzutek();
			break;
		case '4':
			informacje_o_programie();
			break;
		case '5': {
			do {
				cout << endl << endl << endl;
				cout << "	      Tutaj mo" << char(0xBE) << "esz zmieni" << char(0x86) << " motyw, wybierz jeden z ni" << char(0xBE) << "ej wymienionych" << endl << endl << endl;
				cout << "			 1. Czarne t" << char(0x88) << "o, bia" << char(0x88) << "e napisy" << endl;
				cout << "			 2. Brudno-bia" << char(0x88) << "e t" << char(0x88) << "o, zielone napisy" << endl;
				cout << "			 3. Brudno-bia" << char(0x88) << "e t" << char(0x88) << "o, czarne napisy napisy" << endl;
				cout << "			 4. Niebieskie t" << char(0x88) << "o, r" << char(0xA2) << char(0xBE) <<"owe"<< " napisy" << endl;
				cout << "			 5. Powr" << char(0xA2) << "t do menu" << endl;
				wybor1 = _getch();
				switch (wybor1)
				{
				case '1':
					system("Color 0F"); system("cls");
					break;
				case '2':
					system("Color 72"); system("cls");
					break;
				case '3':
					system("Color 70"); system("cls");
					break;
				case '4':
					system("Color BD"); system("cls");
					break;
				case '5':
					break;
				default:
					cout << "			Nie znalaz" << char(0x88) << "em takiej opcji!" << endl;
					Sleep(1500);
					system("cls");
					break;
				}
			} while (wybor1 != '5');
		}
			
			break;
		case '6':
			exit(0);
			break;
		default: cout << endl << endl << endl << endl << "			  Nie ma takiej opcji w menu!"; Sleep(1000);
		}
		system("cls");
	}
	system("pause");
	return 0;
}