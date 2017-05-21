#pragma once
#ifndef ENVIRONMENT2
#define ENVIRONMENT2
#include <string>
#include "structure.h" 
#include "Medien.h"
#include <vector>
#include <fstream>


class Library {
	string name;
	Address address;
	Person *leader;
	vector<Medium*> mediumList;

public:
	Library::Library(ifstream *file);
	Library::Library(string name, Address address, Person* leader):address(address) {
		this->name = name;
		//this->address = address;
		this->leader = leader;
		this->name = name;
	}
	void Library::addMediumToLibrary(Medium * new_medium) {
		mediumList.push_back(new_medium);
	}

	void Library::printLibrary() {
		cout << "\nFilliale: " << name << endl;
		address.printAddress();
		cout << endl << "Leitung: " << leader->getName() << endl;
		leader->printPerson();
		cout << "\nEs bestehen " << mediumList.size() << " Werke \n" << endl;

		for (int i = 0; i < mediumList.size(); i++) {
			cout << "Medium NR. " << i+1 << endl;
			mediumList.at(i)->printMedium();
			cout << endl;
		}
	}
	virtual void Library::load(ifstream * file);
	Library::~Library() {
		for (int i = 0; i < mediumList.size(); i++) {
			mediumList.at(i)->~Medium();
		}
		leader->~Person();
	}
};

#endif