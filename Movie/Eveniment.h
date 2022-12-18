#include <iostream>
#include <string>
#include <cstdlib>
using namespace std; 
#pragma once
class Eveniment
{
private:
	const unsigned id_eveniment;
	static unsigned nr_evenimente;
	string nume_eveniment;
	int bilete_disponibile;
	double pret_bilet;

public:
	Eveniment();
	Eveniment(string nume_eveniment, int bilete_mele, double pret_biletelor);
	Eveniment(const Eveniment& my_eveniment);
	~Eveniment();
	Eveniment& operator=(const Eveniment& my_eveniment);

	string get_nume_eveniment();
	int get_bilete_disponibile();
	double get_pret_bilet();
	void set_nume_eveniment(string new_nume_eveniment);
	void set_bilete_disponibile(int new_bilete_disponibile);
	void set_pret_bilet(double new_pret_bilete);
	static unsigned get_nr_evenimente();
	static void set_nr_evenimente(unsigned new_nr_evenimente);


	double CumparaBilet(int new_bilete_disponi);
	void Display();

	//operator<< and operator>>
	friend ostream& operator<<(ostream& out, Eveniment& my_eveniment);
	friend istream& operator>>(istream& in, Eveniment& my_eveniment);
	
	//operator+
	Eveniment& operator+(int new_bilete_disponibile);
	//explicit cast to double
	explicit operator double();
	
	
};
