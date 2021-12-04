#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "deklaracje.h"

using namespace std;
//funkcja kalkulatora
void kalkulator() {
	char wybor{};
	double a{}, b{};
	do {
		cout << endl << endl << endl << endl << endl;
	cout << "				  1. Dodawanie " << endl;
	cout << "				  2. Odejmowanie " << endl;
	cout << "				  3. Dzielenie" << endl;
	cout << "				  4. Mno"<< char(0xBE) << "enie" << endl;
	cout << "				  5. Powr" << char(0xA2) <<"t do menu" << endl << endl;
	
	cout << "				  Wybierz: ";
	
	
		wybor = _getch();
		system("cls");
		cout << endl << endl << endl << endl << endl;
		switch (wybor)
		{
		case '1': {
			cout << "				  Pierwsza liczba: ";
			cin >> a;
			cout << "				  Druga liczba: ";
			cin >> b;
			cout << "				  Suma: " << a << " + " << b << " = " << a + b << endl << endl;
			cout << "			Wci" << char(0x98) << "nij enter aby zako" << char(0xE4) << "czy" << char(0x86) << " operacj" << char(0xA9) << "!";
			cin.get(); cin.get();
			system("cls");
		}
				break;
		case '2': {
			cout << "				  Pierwsza liczba: ";
			cin >> a;
			cout << "				  Druga liczba: ";
			cin >> b;
			cout << "				  R" << char(0xA2) << char(0xBE) << "nica: " << a << " - " << b << " = " << a - b << endl << endl;
			cout << "			Wci" << char(0x98) << "nij enter aby zako" << char(0xE4) << "czy" << char(0x86) << " operacj" << char(0xA9) << "!";
			cin.get(); cin.get();
			system("cls");
		}
				break;
		case '3': {
			cout << "				  Pierwsza liczba: ";
			cin >> a;
			do {
				cout << "				  Druga liczba: ";
				cin >> b;
				if (b == 0)
					cout << "			   Dzielnik musi by" << char(0x86) << " r" << char(0xA2) << char(0xBE) << "ny od zera!" << endl;
			} while (b == 0);
			cout << "				  Iloraz: " << a << " / " << b << " = " << a / b << endl << endl;
			cout << "			Wci" << char(0x98) << "nij enter aby zako" << char(0xE4) << "czy" << char(0x86) << " operacj" << char(0xA9) << "!";
			cin.get(); cin.get();
			system("cls");
		}
				break;
		case '4': {
			cout << "				  Pierwsza liczba: ";
			cin >> a;
			cout << "				  Druga liczba: ";
			cin >> b;
			cout << "				  Iloczyn: " << a << " * " << b << " = " << a * b << endl << endl;
			cout << "			Wci" << char(0x98) << "nij enter aby zako" << char(0xE4) << "czy" << char(0x86) << " operacj" << char(0xA9) << "!";
			cin.get(); cin.get();
			system("cls");
		}
				break;
		case '5': /*cout << "			Wci" << char(0x98) << "nij enter aby wr" << char(0xA2) << "ci" << char(0x86) << " do menu!";*/
			break;

		default: {
			cout << "			Kalkulator nie znalaz" << char(0x88) << " takiej opcji!" << endl;
			Sleep(1500);
			system("cls");
		}
		}
	} while (wybor != '5');
	
}