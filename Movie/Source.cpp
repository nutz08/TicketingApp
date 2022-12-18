#include "Bilet.h"
#include "Eveniment.h"
#include "Client.h"



int main()
{
	const int g_kArraySize = 8;
	Eveniment obiecte_events[g_kArraySize];

	Bilete* p_BileteCinema = new Bilete("Salut", "Bine te-am gasit!");
	p_BileteCinema->Init(obiecte_events, g_kArraySize);
	p_BileteCinema->Run();

	delete p_BileteCinema;
	return 0;
}