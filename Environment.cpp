#include "stdafx.h"
#include "Environment.h"
#include <fstream>


LibraryPool::LibraryPool(string filename){
	ifstream file(filename, std::ifstream::in);
	if(file.is_open())
		LibraryPool::load(&file);
	else {
		cout << "\nno File found";
	}
}

void LibraryPool::load(ifstream *file) {
	string temp;

	getline(*file, temp);
	if (temp != "<LibraryPool>")
		cout << "\nFalse Tag found in class LibraryPool";
	while (1) {
		getline(*file, temp);
		string tag = parseLineTag(temp);

		if (tag == "Library") {
			LibraryPool::addLibraryPool(new Library(file));
		}
		else if (tag == "Chairman") {
			leader = new Person(file);
			getline(*file, temp);
		}
		else if (tag == "Name") {
			name = parseLineContent(temp);
		}

		else if (tag == "Customer") {
			LibraryPool::addLibraryPool(new Person(file));
			getline(*file, temp);
		}
		else if (tag == "/LibraryPool") {
			break;
		}
		else {
			cout << "\nParsing Error LibraryPool";
		}
	}
}

//string LibraryPool::parseLine(string line) {
//	string tag;
//	size_t first = line.find_first_of("<") +1 ;
//	//Tag starts
//	size_t second = line.find_first_of(">")-1;
//	for (int i = 0; i < (second -first); i++){
//		tag.push_back(line.at(i));
//	}
//	return tag;
//}


/*
* reads first tag in XML @line
*/
string LibraryPool::parseLineTag(string line) {
	string tag;
	size_t first = line.find_first_of("<") + 1;
	//Tag starts
	//cout << line << endl;
	size_t second = line.find_first_of(">");
	for (int i = first; i < second; i++) {
		tag.push_back(line.at(i));
	}
	return tag;
}

/*
* reads content between XML Tag in @line
*/
string LibraryPool::parseLineContent(string line) {
	string end;
	for (int i = line.find_first_of(">")+1; i < line.length(); i++) {
		if (line.at(i) != '<')
			end.push_back(line.at(i));
		else {
			break;
		}
	}
	return end;
}