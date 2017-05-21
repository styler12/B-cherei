#include "stdafx.h"
#include "Library.h"


//string name;
//Address address;
//Person *leader;
//vector<Medium*> mediumList;

Library::Library(ifstream * file) {
	Library::load(file);
}
void Library::load(ifstream  *file) {
	string line;
	
	
	while (1) {
		getline(*file, line);
		string tag = parseLineTag(line);

		if (tag == "Name") {
			name = parseLineContent(line);
		}
		else if (tag == "Medium") {
			Library::addMediumToLibrary(new Medium(file));
		}
		else if (tag == "Address") {
			address = Address(file);
		}
		else if (tag == "Manager") {
			leader = new Person(file);
			getline(*file, line);
		}
		else if (tag == "/Library") {
			break;
		}
		else {
			cout << "\n Parsing Error in Library";
		}
	}
}

