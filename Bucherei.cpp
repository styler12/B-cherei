// Bucherei.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Structure.h"
#include "Medien.h"

using namespace std;

int main()
{
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
    return 0;
}

