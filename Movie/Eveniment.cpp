#include "Eveniment.h"

unsigned Eveniment::nr_evenimente = 1;

Eveniment::Eveniment():id_eveniment(nr_evenimente)
{
	nume_eveniment = "";
	bilete_disponibile = 0;
	pret_bilet = 0.0;
	nr_evenimente++;
}


Eveniment::Eveniment(string my_event_name, int my_tickets_available, double my_ticket_price) :id_eveniment(nr_evenimente)
{
	nume_eveniment = my_event_name;
	bilete_disponibile = my_tickets_available;
	pret_bilet = my_ticket_price;
	nr_evenimente++;
}

Eveniment::Eveniment(const Eveniment& my_eveniment):id_eveniment(my_eveniment.id_eveniment)
{
	nume_eveniment = my_eveniment.nume_eveniment;
	bilete_disponibile = my_eveniment.bilete_disponibile;
	pret_bilet = my_eveniment.pret_bilet;
}


Eveniment::~Eveniment()
{

}

Eveniment& Eveniment::operator=(const Eveniment& my_eveniment)
{
	if (this != &my_eveniment)
	{
		nume_eveniment = my_eveniment.nume_eveniment;
		bilete_disponibile = my_eveniment.bilete_disponibile;
		pret_bilet = my_eveniment.pret_bilet;
	}
	return *this;
}


string Eveniment::get_nume_eveniment()
{
	return nume_eveniment;
}


int Eveniment::get_bilete_disponibile()
{
	return bilete_disponibile;
}


double Eveniment::get_pret_bilet()
{
	return pret_bilet;
}


void Eveniment::set_nume_eveniment(string new_event_name)
{
	nume_eveniment = new_event_name;
}


void Eveniment::set_bilete_disponibile(int new_tickets_available)
{
	bilete_disponibile = new_tickets_available;
}


void Eveniment::set_pret_bilet(double new_ticket_price)
{
	pret_bilet = new_ticket_price;
}

unsigned Eveniment::get_nr_evenimente()
{
	return nr_evenimente;
}

void Eveniment::set_nr_evenimente(unsigned new_nr_evenimente)
{
	nr_evenimente = new_nr_evenimente;
}

double Eveniment::CumparaBilet(int purchase_tickets_available)
{
	double total_price;

	if (purchase_tickets_available <= bilete_disponibile) {
		total_price = purchase_tickets_available * pret_bilet;
		bilete_disponibile = bilete_disponibile - purchase_tickets_available;
		return total_price;

	}
	else {
		return -1;
	}
}

void Eveniment::Display()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << endl << "\t\t\t\tNume eveniment: " << nume_eveniment << endl
		<< "\n\t\t\t\tBilete disponibile: " << bilete_disponibile << endl
		<< "\n\t\t\t\tPretul unui bilet: " << pret_bilet << endl << endl
		<< "\n\t\t\t\tEvenimentul are loc in Bucuresti" << endl;

}

Eveniment& Eveniment::operator+(int new_bilete_disponibile)
{
	bilete_disponibile = bilete_disponibile + new_bilete_disponibile;
	return *this;
}

Eveniment::operator double()
{
	return pret_bilet;
}

ostream& operator<<(ostream& out, Eveniment& my_eveniment)
{
	out << "Nume Eveniment: " << my_eveniment.nume_eveniment << endl
		<< "Bilete disponibile: " << my_eveniment.bilete_disponibile << endl
		<< "Pretul unui bilet: " << my_eveniment.pret_bilet << endl;	
	return out;
}

istream& operator>>(istream& in, Eveniment& my_eveniment)
{
	string buffer;
	int buffer_int;
	double buffer_double;
	
	cout << "Nume eveniment: ";
	in >> buffer;
	while (in.fail() || buffer.empty()) {
		cout << "Nume eveniment invalid: ";
		in.clear();
		in.ignore(256, '\n');
		in >> buffer;
	}
	cout << "Bilete disponibile: ";
	in >> buffer_int;
	while (in.fail() || buffer_int < 0) {
		cout << "Bilete disponibile invalid: ";
		in.clear();
		in.ignore(256, '\n');
		in >> buffer_int;
	}
	cout << "Pretul unui bilet: ";
	in >> buffer_double;
	while (in.fail() || buffer_double < 0) {
		cout << "Pretul unui bilet invalid: ";
		in.clear();
		in.ignore(256, '\n');
		in >> buffer_double;
	}
	my_eveniment.nume_eveniment = buffer;
	my_eveniment.bilete_disponibile = buffer_int;

	my_eveniment.pret_bilet = buffer_double;	return in;
}
