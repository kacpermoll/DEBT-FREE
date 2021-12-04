#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//----OPCJE-MENU-----
void nowa_zrzutka();
void kalkulator();
void podglad_poprzednich_zrzutek();
void informacje_o_programie();

//---NOWA-ZRZUTKA----
struct entered_member {
	string nickname{};
	double order_cost{};
	double gave{};
	string nickname_(entered_member memeber, int number);
	double order_cost_(entered_member member);
	double gave_(entered_member member);
};

struct resolved_member {
	string who{};
	double debt{};
	//wielkosc tablic zale¿na od iloœci uczestników
	vector <string> whom{};
	vector <double> how_much{};
};

double write_rest(vector <entered_member> member, int size);
void write(vector <entered_member> member, int number, int size);
bool sort_debt(resolved_member& a, resolved_member& b);
vector <resolved_member> algorithm(vector <resolved_member>& resolved_group);
void print_person(vector <resolved_member> end_vector);
void save_to_file(vector <resolved_member> end_vector, string name);
bool check_if_zero(resolved_member& a);