#include "Client.h"


client::client()
{
	nume_client = nullptr;
	adresa_client = "";
	numar_telefon = "";
	activ = false;
}

client::client(char* my_name, string my_address, string my_phone_number, bool activ)
{
	nume_client = new char[strlen(my_name) + 1];
	strcpy_s(nume_client, strlen(my_name) + 1, my_name);
	adresa_client = my_address;
	numar_telefon = my_phone_number;
	this->activ = activ;
}

client::client(const client& my_client)
{
	nume_client = new char[strlen(my_client.nume_client) + 1];
	strcpy_s(nume_client, strlen(my_client.nume_client) + 1, my_client.nume_client);
	adresa_client = my_client.adresa_client;
	numar_telefon = my_client.numar_telefon;
	activ = my_client.activ;
}

client::~client()
{
	if (nume_client != nullptr)
	{
		delete[] nume_client;
		nume_client = nullptr;
	}
}

client& client::operator=(const client& my_client)
{
	if (this != &my_client) {
		nume_client = new char[strlen(my_client.nume_client) + 1];
		strcpy_s(nume_client, strlen(my_client.nume_client) + 1, my_client.nume_client);
		adresa_client = my_client.adresa_client;
		numar_telefon = my_client.numar_telefon;
		activ = my_client.activ;
	}
	return *this;
}

char* client::get_nume_client()
{
	char* temp = new char[strlen(nume_client) + 1];
	strcpy_s(temp, strlen(nume_client) + 1, nume_client);
	return temp;
}

string client::get_adresa_client()
{
	return adresa_client;
}

string client::get_numar_telefon()
{
	return numar_telefon;
}

void client::set_nume_client(char* my_name)
{
	if (nume_client != nullptr)
	{
		delete[] nume_client;
	}
	nume_client = new char[strlen(my_name) + 1];
	strcpy_s(nume_client, strlen(my_name) + 1, my_name);
}

void client::set_adresa_client(string my_address)
{
	adresa_client = my_address;
}

void client::set_numar_telefon(string my_phone_number)
{
	numar_telefon = my_phone_number;
}

void client::Display()
{
	cout << " ";


}

//dezactivare client
bool client::operator!()
{
	activ = !activ;
}
;


client& client::operator<=(int new_nume_client)
{
	if (strlen(nume_client) <= 3)
	{
		nume_client = new char[strlen(nume_client) + 1];
		strcpy_s(nume_client, strlen(nume_client) + 1, nume_client);
	}
};
		
		

ostream& operator<<(ostream& out, client& my_client)
{
	out << "Nume client: " << my_client.nume_client << endl;
	out << "Adresa client: " << my_client.adresa_client << endl;
	out << "Numar telefon: " << my_client.numar_telefon << endl;
	out << "Activ: " << my_client.activ << endl;
	return out;
}

istream& operator>>(istream& in, client& my_client)
{
	//in with validations buffer as strings
	string buffer;
	cout << "Nume client: ";
	getline(in, buffer);
	while (buffer.empty()) {
		//error message
		cout << "Numele clientului nu trebuie sa fie vid. Reintroduceti numele: ";
		getline(in, buffer);
	}
	my_client.nume_client = new char[buffer.length() + 1];
	strcpy_s(my_client.nume_client, buffer.length() + 1, buffer.c_str());
	cout << "Adresa client: ";
	getline(in, buffer);
	while (buffer.length() > 50 || buffer.length() < 5 || buffer.empty())
	{
		cout << "Adresa trebuie sa aiba intre 5 si 50 de caractere. Introduceti din nou adresa: ";
		getline(in, buffer);
	}
	cout << "Numar telefon: ";
	in >> buffer;
	while (buffer.length() != 10)
	{
		cout << "Numarul de telefon trebuie sa aiba 10 cifre" << endl;
		my_client.numar_telefon = buffer;
		cout << "Numar telefon: ";
		in >> buffer;
	}
	bool buffer_bool;
	cout << "Activ: (1/0)";
	in >> buffer_bool;
	if (buffer_bool == 1)
	{
		my_client.activ = true;
	}
	if (buffer_bool == 0)
	{
		my_client.activ = false;
	}
	else {
		cout << "Invalid input";
	}
	return in;
}
