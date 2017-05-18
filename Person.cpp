#include "stdafx.h"
#include "structure.h"
#include <fstream>

using namespace std;

Person::Person(ifstream *file) {
	
	load(file);
	
}


void Person::load(ifstream *file) {
	string line;
	getline(*file, line);

	while (1) {
		getline(*file, line);
		string tag = parseLineTag(line);

		if (tag == "Name") {
			name = parseLineContent(line);
		}
		else if (tag == "Birthday") {
			birthday = Date(file);
			getline(*file, line);
		}
		else if (tag == "Address") {
			address=Address(file);
		}
		else if (tag == "/Person") {
			break;
		}
		else {
			cout << "\n Parsing Error in Person";
		}
	}
	
}



