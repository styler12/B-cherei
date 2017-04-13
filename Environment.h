#ifndef ENVIRONMENT
#define ENVIRONMENT
#include <string>
#include "structure.h" 
#include "Medien.h"

class LibraryPool {
	string name;
	Library librarylist[];
	Person * customerlist[];
};

class Library {
	string name;
	Address address;
	Medium * mediumlist[];
};

#endif