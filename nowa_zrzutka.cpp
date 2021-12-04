#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
//#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include "deklaracje.h"
using namespace std;


void nowa_zrzutka() {
	int zmienna{};
	
	cout << endl << endl << endl;
	cout << "			Ile os" << char(0xA2) << "b uczestniczy w zbi" << char(0xA2) << "rce? ";
	cin >> zmienna;

	//zabezpieczenie przed wprowadzeniem literki
	while (cin.fail()) {
		cin.clear();
		cin.ignore(15,'\n');
		cout << endl << endl;
		cout << "			    Niestety nie poda" << char(0x88) <<"e" << char(0x98) <<" liczby."<< endl;
		cout << "			         Spr" << char(0xA2) << "buj ponownie!" << endl;
		Sleep(1000);
		system("cls");
		cout << endl << endl << endl;
		cout << "			Ile os" << char(0xA2) << "b uczestniczy w zbi" << char(0xA2) << "rce? ";
		cin >> zmienna;
	}
	system("cls");

	//stworzenie wetorów struktur
	vector <entered_member> entered_group(zmienna);
	vector <resolved_member> resolved_group(zmienna);
	vector <resolved_member> end_vector;

	//wprowadzanie danych wejsciowych - NAZWA
	for (int i = 0; i < entered_group.size(); i++) {
		write(entered_group, i, entered_group.size());
		entered_group[i].nickname = entered_group[i].nickname_(entered_group[i], i + 1);
		system("cls");
	}
	//wprowadzanie danych wejsciowych - ILE POWIENIEN ZAP£ACIÆ
	for (int i = 0; i < entered_group.size(); i++) {
		write(entered_group, i, entered_group.size());
		cout << endl;
		cout << "		Wprowad" << char(0xAB) << " kwot" << char(0xA9) << ", kt" << char(0xA2) << "r" << char(0xA5);
		cout << " powinien zap" << char(0x88) << "aci" << char(0x86) << " dany uczestnik zbi" << char(0xA2) << "rki: " << endl << endl;
		entered_group[i].order_cost = entered_group[i].order_cost_(entered_group[i]);
		system("cls");
	}
	//wprowadzanie danych wejsciowych - ILE ZAP£ACI£
	//pêtla aby program siê nie wysypa³
	//w rzypadku wprowadzenia za ma³o lub za du¿o pieniêdzy
	do {
		
		for (int i = 0; i < entered_group.size(); i++) {
			entered_group[i].gave = 0;
		}
		for (int i = 0; i < entered_group.size(); i++) {
			system("cls");
			write(entered_group, i, entered_group.size());
			cout << endl << "						         Brakuje: " << write_rest(entered_group, entered_group.size()) << endl << endl;
			cout << "		Wprowad" << char(0xAB) << " kwot" << char(0xA9) << ", kt" << char(0xA2) << "r" << char(0xA5);
			cout << " wy" << char(0x88) << "o" << char(0xBE) << "y" << char(0x88) << " dany uczestnik zbi" << char(0xA2) << "rki: " << endl << endl;
			entered_group[i].gave = entered_group[i].gave_(entered_group[i]);
			system("cls");
		}
		if (write_rest(entered_group, entered_group.size()) > 0) {
			cout << endl << endl << endl << endl << endl << endl;
			cout << "				  Brakuje pare z" << char(0x88) << "ociszy... " << endl;
			cout << "				     Spr" << char(0xA2) << "buj ponownie!" << endl;
			Sleep(1500);
			system("cls");
		}
		else if (write_rest(entered_group, entered_group.size()) < 0) {
			cout << endl << endl << endl << endl << endl << endl;
			cout << "			     Nie da" << char(0x88) << " kto" << char(0x98) << " czasem za du" << char(0xBE) << "o?" << endl;
			cout << "			         Spr" << char(0xA2) << "buj ponownie!" << endl;
			Sleep(1500);
			system("cls");
		}
	}while(write_rest(entered_group, entered_group.size()) != 0);

	//wypisanie tabeli
	write(entered_group, entered_group.size() - 1, entered_group.size());

	//przypisanie do nowej struktury nazwy i dlugu
	for (int i = 0; i < resolved_group.size(); i++) {
		resolved_group[i].who = entered_group[i].nickname;
		//do zmiennej debt zapisuje sie kwota jaka nalezy dostac/oddac, jezeli jest na minusie, oznacza to ze tyle powinien dostac, jezeli na plusie to tyle powinien oddac
		resolved_group[i].debt = -(entered_group[i].gave - entered_group[i].order_cost);
	}

	//wyeliminowanie osób z d³ugiem równym zeru
	resolved_group.erase(std::remove_if(resolved_group.begin(), resolved_group.end(), check_if_zero), resolved_group.end());

	//sortowanie wed³ug d³ugu od najwiêkszego d³ugu do najwiêkszego kredytu
	std::sort(resolved_group.begin(), resolved_group.end(), sort_debt);

	//Njawazniejsza operacja
	end_vector = algorithm(resolved_group);

	//wypisanie informacji koncowej
	print_person(end_vector);

	char wybor{};
	do
	{
		cout << endl;
		cout << "		Zapisac ta zrzutke?" << endl;
		cout << "		1. Zapisz" << endl;
		cout << "		2. Nie zapisuj" << endl << endl;

		wybor = _getch();
		switch (wybor)
		{
			case '1': {
				cout << "		Podaj nazwe tej zrzutki: ";
				string nazwa{};
				cin >> nazwa;
				cin.ignore(24, '\n');
				//zapisanie zrzutki
				save_to_file(end_vector, nazwa);
				cout << "		Zapisano pomyslenie!" << endl;
				Sleep(1500);
				break;
			}

			case '2': {
				system("cls");
				write(entered_group, entered_group.size() - 1, entered_group.size());
				cout << "		Twoja zrzutka nie zostanie zapisana, na pewno nie chcesz jej zapisac?" << endl;
				cout << "		1. Zapisz" << endl;
				cout << "		2. Powroc do menu bez zapisu" << endl;
				do {
					wybor = _getch();
					if (wybor == '1') {
						cout << "		Podaj nazwe tej zrzutki: ";
						string nazwa{};
						cin >> nazwa;
						cin.ignore(24, '\n');
						//zapisanie zrzutki
						save_to_file(end_vector, nazwa);
						cout << "		Zapisano pomyslenie!" << endl;
						Sleep(1500);
						break;
					}
					else if (wybor == '2')
						break;
				} while (wybor != '1' && wybor != '2');
			}

		}
	} while (wybor != '1' && wybor != '2');

}