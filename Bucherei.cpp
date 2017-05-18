// Bucherei.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Structure.h"
#include "Medien.h"
#include "Environment.h"

using namespace std;


void aufgabe1und2() {
	Date D1, D2(1, 5, 2017);
	Time T1, T2(6, 32, 27), T3(17, 45);
	cout << "\nKlasse TDate:" << endl;
	cout << "Standardkonstruktor Heutiges Datum (D1):     ";   D1.printDate();   cout << endl;
	cout << "Konstruktor         Tag der Arbeit (D2):     ";   D2.printDate();   cout << endl;
	cout << "\nKlasse TTime:" << endl;
	cout << "Standardkonstruktor Aktuelle Uhrzeit (T1):   ";   T1.printTime();   cout << endl;
	cout << "Konstruktor         Zeit zum Aufstehen (T2): ";   T2.printTime();   cout << endl;
	cout << "Konstruktor         Uebungsbeginn (T3):      ";   T3.printTime();   cout << endl;


	Location L1, L2("Technik", "Computer"); // Technik-Abteilung im Computer-Regal
	Date Geburtstag(17, 11, 1984);
	Address A1("Luxemburger Str.", "10", "D-13351", "Berlin");
	Address Adresse("Berliner Str.", "21-23", "10876", "Berlin");
	Person Egon("Egon Mustermann", Adresse, Geburtstag);
	cout << "Klasse TLocation:" << endl;
	cout << "Standardkonstruktor fuer neue Buecher:    ";     L1.printLocation();   cout << endl;
	cout << "Konstruktor Technik-Abt., Computer-Regal: ";     L2.printLocation();   cout << endl;
	cout << "\nKlasse TAddress:" << endl;
	cout << "Konstruktor Adresse der Beuth Hochschule:\n";    A1.printAddress();   cout << endl;
	cout << "\nKlasse TPerson:" << endl;
	cout << "Konstruktor Egon Mustermann:\n";                 Egon.printPerson(); cout << endl;
}

void aufgabe3() {
	Date D1(17, 11, 1963);
	Location L1("Technik", "Computer");
	Location L2("Romane", "Krimi");
	Location L3("Kinder", "Comics");
	Location L4("DVDs", "Horror");
	Address A1("Buchallee", "15a", "13315", "Berlin");
	Address A2("Schlossstr.", "117", "12077", "Berlin");
	Address A3("Muellerstr.", "39", "13309", "Berlin");
	Person Leitung("Egon Mustermann", A2, D1);
	Person FL1("Peter Mueller", A3, D1);
	Person FL2("Erika Mueller", A3, D1);
	Person K1("Marion Schulz", A1, D1);
	Person K2("Stefan Meier", A2, D1);
	Medium M1("Programmieren in C", "PC99", L1, 0, Medium::ausgeliehen);
	Medium M2("Der Hexer", "He83", L2, 12, Medium::verfuegbar);
	Medium M3("Asterix und Obelix", "KC17", L3, 0, Medium::verfuegbar);
	Medium M4("Der Werwolf", "WW175", L4, 16, Medium::ausgeliehen);
	Library LWedding("Wedding", A1, &FL1);
	Library LSteglitz("Steglitz", A2, &FL2);
	LibraryPool LP("Buechereiverband Berlin", &Leitung);
	LWedding.addMediumToLibrary(&M1);
	LWedding.addMediumToLibrary(&M2);
	LSteglitz.addMediumToLibrary(&M3);
	LSteglitz.addMediumToLibrary(&M4);
	LP.addLibraryPool(&LWedding);
	LP.addLibraryPool(&LSteglitz);
	LP.addLibraryPool(&K1);
	LP.addLibraryPool(&K2);
	LP.printContent();
	cout << endl;
}

void aufgabe4() {
	LibraryPool LP("data.xml");
	LP.printContent();
	cout << endl;
}
int main()
{
	
	//aufgabe3();
	aufgabe4();

	cout << "Beliebige Taste drücken zum beenden" << endl;
	int l;
	cin >> l;
	exit(1);
    return 0;
}

