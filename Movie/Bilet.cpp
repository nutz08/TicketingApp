#include "Bilet.h"

const int g_kArraySize = 8;

Bilete::Bilete():id_bilet((int)this)
{
	nume_events = "";
	locatie_events = "";
	p_EventsList = NULL;
}

Bilete::Bilete(string my_nume_eveniment, string my_locatie_eveniment) :id_bilet((int)this)
{
	nume_events = my_nume_eveniment;
	locatie_events = my_locatie_eveniment;
	p_EventsList = NULL;
}

Bilete::Bilete(const Bilete& my_bilete) :id_bilet(my_bilete.id_bilet)
{
	nume_events = my_bilete.nume_events;
	locatie_events = my_bilete.locatie_events;
	p_EventsList = new Eveniment[g_kArraySize];
	for (int i = 0; i < g_kArraySize; i++)
	{
		p_EventsList[i] = my_bilete.p_EventsList[i];
	}
}


Bilete::~Bilete()
{
	cout << "Bilete Evenimente: " << "Multumim pentru ca ati folosit aplicatia noastra! " << endl;
}

Bilete& Bilete::operator=(const Bilete& my_bilete)
{
	if (this != &my_bilete)
	{
		nume_events = my_bilete.nume_events;
		locatie_events = my_bilete.locatie_events;
		p_EventsList = new Eveniment[g_kArraySize];
		for (int i = 0; i < g_kArraySize; i++)
		{
			p_EventsList[i] = my_bilete.p_EventsList[i];
		}
	}
	return *this;
}



void Bilete::Init(Eveniment* p_my_lista_evenimente, int array_size)
{
	string nume_event[g_kArraySize] = { "Fotbal",
		"Teatru",
		"Cinema",
		"Volei",
		"Tenis",
		"Tedx",
		"Concert",
	};

	int bilete_event[g_kArraySize] = { 85,75,90,90,75,100,65 };

	double pret_event[g_kArraySize] = { 15.5,30,28.5,15,5,13.5,50 };

	Eveniment* p = p_my_lista_evenimente;

	for (int i = 0; i <= g_kArraySize - 1; i++) {
		p->set_nume_eveniment(nume_event[i]);
		p->set_bilete_disponibile(bilete_event[i]);
		p->set_pret_bilet(pret_event[i]);
		p++;
	}

	p_EventsList = p_my_lista_evenimente;

}



void Bilete::Run()
{
	int option;

	do {

		DisplayMenu();

		cout << endl << "\t\t\t\tAlege o optiune: ";

		cin >> option;

		switch (option)
		{

		case 1:
			ViewEvents();
			system("PAUSE");
			system("CLS");
			break;

		case 2:

			SearchEvents();
			system("PAUSE");
			system("CLS");
			break;

		case 3:

			PurchaseTicket();
			break;

		case 4:

			cout << "\nMultumim!\n" << endl;
			break;

		default:

			cout << "Te rog alege o varianta corecta:" << endl
				<< "=============================" << endl;
			cin.ignore();

		}
	} while (option != 4);
}



void Bilete::DisplayMenu()
{

	cout << "\t\t\t\tEvenimente: " << nume_events << ", Natalia! " << locatie_events << endl
		<< endl << "\t\t\t\t  ***********************  " << endl
		<< "\t\t\t\t===========================" << endl
		<< "\t\t\t\t  Rezervari Bilete Online" << endl
		<< "\t\t\t\t===========================" << endl
		<< "\t\t\t\t\tMeniu Principal: " << endl
		<< "\t\t\t\t1=> Vezi toate evenimentele" << endl
		<< "\t\t\t\t2=> Cauta un eveniment" << endl
		<< "\t\t\t\t3=> Cumpara bilet" << endl
		<< "\t\t\t\t4=> Paraseste aplicatia" << endl;

}



void Bilete::ViewEvents()
{

	Eveniment* p_view_events = p_EventsList;
	system("CLS");
	cout << endl
		<< "Lista noastra de evenimente: " << endl
		<< "=========================" << endl << endl;

	for (int i = 0; i < g_kArraySize; i++) {
		cout << "Eveniment " << i + 1 << ": " << endl;
		p_view_events->Display();
		++p_view_events;
	}
}


Eveniment* Bilete::SearchEvents()
{
	string search_event_name;

	cout << "\n\t\t\t\tVa rugam sa introduceti un nume de eveniment ";
	cin.sync();
	cin >> search_event_name;

	Eveniment* p = FindEvents(search_event_name);

	if (p != NULL) {
		p->Display();
	}
	else {
		cout << endl << "\n\t\t\t\tEroare: Evenimentul respectiv nu face parte din lista noastra" << endl << endl;
		return NULL;
	}
	return p;
}


Eveniment* Bilete::FindEvents(string find_event_name)
{

	Eveniment* p_find_event = p_EventsList;
	for (int i = 0; i < 8; i++) {
		if (p_find_event->get_nume_eveniment() == find_event_name) {
			cout << endl << "\n\t\t\t\tEvenimentul a fost gasit" << endl;
			return p_find_event;
		}
		else {
			p_find_event++;
		}
	}
	return NULL;
}


void Bilete::PurchaseTicket()
{
	string purchase_event_name;
	string numele_tau;
	string rande;
	string loc;
	int total_tickets;
	srand((unsigned)time(NULL));
	int random = rand();
	system("CLS");
	cout << "\n\n\t\t\t\tVa rugam sa evenimentul la care doriti sa participati ";
	cin.sync();
	cin >> purchase_event_name;

	cout << "\n\t\t\t\tVa rugam sa introduceti numarul total de bilete pe care doriti sa le cumparati: ";
	cin >> total_tickets;
	cout << "\n\t\t\t\tVa rugam sa va introduceti numele: ";
	cin >> numele_tau;
	cout << "\n\t\t\t\tVa rugam sa introduceti randul: ";
	cin >> rande;
	cout << "\n\t\t\t\tVa rugam sa introduceti locul pe care doriti sa-l ocupati: ";
	cin >> loc;




	Eveniment* p = FindEvents(purchase_event_name);

	if (p != NULL) {
		double total_cost = p->CumparaBilet(total_tickets);
		if (total_cost == -1) {
			cout << "\n\t\t\t\tNu mai exista bilete disponibile pentru acest eveniment" << endl
				<< "\n\t\t\t\tnu sunt suficiente bilete disponibile conform cererii dumneavoastră" << endl << endl;
		}
		else {
			system("CLS");
			cout << "\n\t\t\t\tIti multumim, " << numele_tau << ", pentru ca ati apelat la serviciile noastre " << endl;
			cout << "\n\t\t\t\t" << "Numarul biletului dvs este: " << random << ". Va rugam sa-l prezentati la intrare" << endl;
			cout << "\n\t\t\t\t" << "Veti ocupa locul: " << loc << " de pe randul " << rande << endl;
			cout << "\n\t\t\t\tAveti un total de plata de: " << total_cost << " Lei" << endl;

		}
		cout << "\n\n\n\n\t\t\t\t";

		system("PAUSE");
		system("CLS");
	}
	else {
		cout << "Nu a fost găsit niciun eveniment" << endl;
	}

}

Eveniment& Bilete::operator[](int index)
{
	if (index < 0 || index >= g_kArraySize) {
		cout << "Evenimentul nu exista" << endl;
		return;
	}
	return p_EventsList[index];

}

Bilete& operator>= (double my_pret_bilet, Bilete& my_bilete)
{
	{
		int i;
		for (i = 0; i < 8; i++)
		{
			if (my_bilete[i].get_pret_bilet() >= my_pret_bilet)
			{
				my_bilete[i].Display();
			}
		}
		return my_bilete;
	}
}

ostream& operator<<(ostream& out, Bilete& my_bilete)
{
	out << "Nume eveniment: " << my_bilete.nume_events << endl;
	out << "Locatie eveniment: " << my_bilete.locatie_events << endl;
	out << "Evenimente disponibile: " << endl;
	for (int i = 0; i < g_kArraySize; i++)
	{
		out << my_bilete.p_EventsList[i] << endl;
	}
	
	return out;
}

istream& operator>>(istream& in, Bilete& my_bilete)
{
	string buffer;
	cout << "Nume eveniment: ";
	in >> buffer;
	while (in.fail() || buffer.empty())
	{
		cout << "Reintroduceti numele evenimentului: ";
		in >> buffer;
	}
	cout << "Locatie eveniment: ";
	in >> buffer;
	while (in.fail() || buffer.empty())
	{
		cout << "Reintroduceti locatia evenimentului: ";
		in >> buffer;
	}
	return in;
}

