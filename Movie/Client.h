#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
#pragma once

class client {
	
	private:
		char* nume_client;
		string adresa_client;
		string numar_telefon;
		bool activ;
	public:
		client();
		client(char* my_name, string my_address, string my_phone_number, bool activ);
		client(const client& my_client);
		~client();
		client& operator=(const client& my_client);
		char* get_nume_client();
		string get_adresa_client();
		string get_numar_telefon();
		void set_nume_client(char* my_name);
		void set_adresa_client(string my_address);
		void set_numar_telefon(string my_phone_number);
		void Display();

		//operator<< and operator>>
		friend ostream& operator<<(ostream& out, client& my_client);
		friend istream& operator>>(istream& in, client& my_client);
		
		//operator!
		bool operator!();

		//operator<=
		client& operator<=(int new_nume_client);

};

