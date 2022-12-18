#include "Eveniment.h"

#pragma once
class Bilete
{
private:
	const int id_bilet;
	Eveniment* p_EventsList;
	string nume_events;
	string locatie_events;
public:
	Bilete();
	Bilete(string my_nume_eveniemnt, string my_locatie_eveniment);
	Bilete(const Bilete& my_bilete);
	~Bilete();
	Bilete& operator=(const Bilete& my_bilete);
	void Init(Eveniment* p_my_evenimente, int array_size);
	void Run();
	void DisplayMenu();
	void ViewEvents();
	Eveniment* SearchEvents();
	Eveniment* FindEvents(string cauta_eveniment);
	void PurchaseTicket();

	//operator<< and operator>>
	friend ostream& operator<<(ostream& out, Bilete& my_bilete);
	friend istream& operator>>(istream& in, Bilete& my_bilete);
	
	//operator[]
	Eveniment& operator[](int index);

	
	//operator>=
	Bilete& operator>=(double my_pret_bilet);
	
	
};