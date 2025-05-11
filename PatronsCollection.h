
/*

File:
PatronsCollection.h

*/

#ifndef PATRONSCOLLECTION_H
#define PATRONSCOLLECTION_H

#include <vector>
#include "Patron.h"

using namespace std;

class PatronsCollection 
{
private:
    vector<Patron> patrons;	//Private member to store a collection of patrons using vector

public:
	//Methods
    void addPatronsCollection();
    void editPatronsCollection();
    void deletePatronsCollection();
    void findPatronsCollection() const;
	void payFinesCollection();
    void printAllPatronsCollection() const;
    void printSinglePatron(int id) const;
	vector<Patron> getPatrons() const;
};

#endif
