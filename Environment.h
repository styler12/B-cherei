#ifndef ENVIRONMENT
#define ENVIRONMENT
#include <string>
#include "structure.h" 
#include "Medien.h"
#include <vector>
#include "Library.h"

using namespace std;

class LibraryPool {
	string name;
	Person *leader;

	vector<Library*> libraryList;
	vector<Library*> libraryList2;
	vector<Person*> customerlist;
public:
	LibraryPool() {}
	LibraryPool(string filename); 
	LibraryPool(string name, Person * leader) {
		this->leader = leader;
		this->name = name;
	}
	void LibraryPool::addLibraryPool(Library * new_library) {
		libraryList.push_back(new_library);
	}
	void LibraryPool::addLibraryPool(Person * new_customer) {
		customerlist.push_back(new_customer);
	}
	void LibraryPool::printContent() {
		cout << name << endl;
		leader->printPerson();
			cout << endl;
		for (int i = 0; i < libraryList.size(); i++) {
			libraryList.at(i)->printLibrary();
		}
	}
	virtual void LibraryPool::load(ifstream  *file);
protected:
	string LibraryPool::parseLineTag(string line);
	string LibraryPool::parseLineContent(string line);
};



/*class Library {
	string name;
	Address address;
	Person *leader;
	vector<Medium*> mediumList;

public:
	Library::Library() {}

	Library::Library(string name, Address address, Person* leader) {
		this->name = name;
		this->address = address;
		this->leader = leader;
		this->name = name;
	}
	void Library::addMediumToLibrary(Medium * new_medium) {
		mediumList.push_back(new_medium);
	}

	void Library::printLibrary() {
		cout << name << endl << "Leitung: ";
		leader->printPerson();
		address.printAddress();

		for (int i = 0; i < mediumList.size(); i++) {
			mediumList.at(i)->printMedium();

		}
	}
};

*/
#endif