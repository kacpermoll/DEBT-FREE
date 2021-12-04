#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
//#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include "deklaracje.h"
using namespace std;

//wypisanie sumy pieniêdzy których brakuje
double write_rest(vector <entered_member> member, int size) {
	double cost_sum{}, gave_sum{}, rest{};
	for (int i = 0; i < size; i++) {
		cost_sum += member[i].order_cost;
		gave_sum += member[i].gave;
	}
	rest = cost_sum - gave_sum;
	
	return rest;
}

//wypisanie tabeli
void write(vector <entered_member> member, int number, int size) {
	cout << endl << endl << endl;
	cout.width(30);
	cout << " ";
	cout.width(15);
	cout << "Powinien zap" << char(0x88) << "aci" << char(0x86);
	cout.width(10);
	cout << "Zpa" << char(0x88) << "aci" << char(0x88);
	cout << endl << endl;
	for (int i = 0; i < size; i++) {
		if (member[i].nickname.empty()) {
			cout.width(30);
			cout<<right<< "Uczestnik " << i + 1;
		}
		else {
			cout.width(31);
			cout << right << member[i].nickname;
		}
		cout.width(11);
		cout << member[i].order_cost;

		cout.width(19);
		cout << member[i].gave;

		cout << endl << endl;
	}
	
}

//funckja pobiera nazwe uczestnika
string entered_member::nickname_(entered_member member, int number) {

	cout << "		    Wprowad" << char(0xAB) << " nazw" << char(0xA9) <<" uczestnika nr " << number << ": ";
	
	cin >> member.nickname;
	cin.ignore(24, '\n');
	
	return member.nickname;
}

//funkcja pobiera i zwraca wylozona kwote
double entered_member::gave_(entered_member member) {

	cout << "		" << member.nickname << ": ";
	cin >> member.gave;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(15, '\n');
		cout << "			       Niestety nie poda" << char(0x88) << "e" << char(0x98) << " liczby." << endl;
		cout << "			            Spr" << char(0xA2) << "buj ponownie!" << endl;
		cout << "		" << member.nickname << ": ";
		cin >> gave;
	}
	return member.gave;
}

//funkcja zlicza sumê ceny zamówienia i przypisuje ja argumentowi order_cost danego obiektu
double entered_member::order_cost_(entered_member member) {
	double cost{};
	string cost_string{};
	cout << "		" << member.nickname << ": ";
	cin >> cost;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(15, '\n');	
		cout << "			       Niestety nie poda" << char(0x88) << "e" << char(0x98) << " liczby." << endl;
		cout << "			            Spr" << char(0xA2) << "buj ponownie!" << endl;
		cout << "		" << member.nickname << ": ";
		cin >> cost;
	}
	return cost;
}

//predykat binarny potrzebny do sortowania
bool sort_debt(resolved_member& a, resolved_member& b) {
	return (a.debt > b.debt);
}
//predykat binarny potrzebny do wyeliminowania elementow wektora, ktore maja debt=0
bool check_if_zero(resolved_member& a) {
	return a.debt == 0;
}

//obliczenie kto komu powinien oddac
vector <resolved_member> algorithm(vector <resolved_member>& resolved_group) {

	//STWORZENIE WEKTORA, ABY KOPIOWAC USUWANY WEKTOR
	vector <resolved_member> substitute_vector;
	substitute_vector.reserve(resolved_group.size());
	while (!resolved_group.empty()) {


		if (resolved_group.front().debt <= -(resolved_group.back().debt)) {

			//splacenie dlugu
			resolved_group.back().debt += resolved_group.front().debt;

			//zapisanie w strukturze uczestnika informacji komu i ile ma zwrocic
			resolved_group.front().how_much.push_back(resolved_group.front().debt);
			resolved_group.front().whom.push_back(resolved_group.back().who);

			//kopia wektora
			substitute_vector.push_back(resolved_group.front());
			//usuniecie puerwszego elementu z wektora, poniewaz ma dlug splacony
			resolved_group.erase(resolved_group.begin());

			if (resolved_group.back().debt == 0)
				resolved_group.pop_back();
		}
		else
			while (resolved_group.front().debt > -(resolved_group.back().debt)) {

				resolved_group.front().how_much.push_back(-(resolved_group.back().debt));

				resolved_group.front().whom.push_back(resolved_group.back().who);
				resolved_group.front().debt += resolved_group.back().debt;

				resolved_group.pop_back();
			}

	}
	return substitute_vector;
}


//wypisanie danych koncowych
void print_person(vector <resolved_member> end_vector) {
	for (int i = 0; i < end_vector.size(); i++) {
		cout << "		" << end_vector[i].who << " powinien odda" << char(0x86) <<" ";
		for (int j = 0; j < end_vector[i].how_much.size(); j++) {
			cout <<  end_vector[i].how_much[j] << "z" << char(0x88) << " uczestnikowi " << end_vector[i].whom[j];
			if (j != end_vector[i].how_much.size() - 1)
				cout << endl << "		oraz ";
			else
				cout << ". " << endl;
		}
	}
}

//zapisanie danych koncowych do pliku
void save_to_file(vector <resolved_member> end_vector, string name) {
	
	ofstream file("Historia zrzutek.txt", ios::app);
	file  <<endl << "	    ----" << name << "----" << endl;
	for (int i = 0; i < end_vector.size(); i++) {
		file << end_vector[i].who << " powinien odda" << char(0x86) << " ";
		for (int j = 0; j < end_vector[i].how_much.size(); j++) {
			file << end_vector[i].how_much[j] << " uczestnikowi  " << end_vector[i].whom[j];
			if (j != end_vector[i].how_much.size() - 1)
				file << " i ";
			else
				file << ". " << endl;
		}
	}
	file.close();
}