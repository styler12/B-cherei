#include "stdafx.h"
#include "Medien.h"



Medium::Medium(ifstream *file) {
	Medium::load(file);
}

Location::Location(ifstream *file) {
	Location::load( file);
}


void Location::load(ifstream * file) {
	string line;

	while (1) {
		getline(*file, line);
		string tag = parseLineTag(line);

		if (tag == "Section") {
			section = parseLineContent(line);
		}
		else if (tag == "Rack") {
			rack = parseLineContent(line);
		}
	
		else if (tag == "/Location") {
			break;
		}
		else {
			cout << "\nParsing Error in Location";
		}
	}

}
void Time::load(ifstream * file) {}

void Medium::setStatus(string status) {
	if (status == "0") {
		stat = ausgeliehen;
	}
	else if (status == "1") {
		stat = verfuegbar;
	}
	else if (status == "2") {
		stat = bestellt;
	}
	else if (status == "3") {
		stat = reserviert;
	}
	else {
		cout << "\nstatus error";
	}
}

void Medium::load(ifstream  *file) {
	string line;

	while (1) {
		getline(*file, line);
		string tag = parseLineTag(line);

		if (tag == "Title") {
			title = parseLineContent(line);
		}
		else if (tag == "Signatur") {
			id = parseLineContent(line);
		}
		else if (tag == "FSK") {
			fsk = stoi(parseLineContent(line));
		}
		else if (tag == "Status") {
			  setStatus(parseLineContent(line)); 
		
		}
		else if (tag == "Location") {
			location = Location(file); // string to enum??? evtl. neue Mehtode
		}
		else if (tag == "/Medium") {
			break;
		}
		else {
			cout << "\nParsing Error in Medium";
		}
	}
}

void DVD::load(ifstream * file) {}
void CD::load(ifstream * file) {}
void PrintedMedien::load(ifstream * file) {}
void Book::load(ifstream * file) {}
void Magazine::load(ifstream * file) {}
void AudioBook::load(ifstream * file) {}
