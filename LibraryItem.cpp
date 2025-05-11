
/*

File:
LibraryItem.cpp

*/

#include "LibraryItem.h"
using namespace std;

//Default Constructor
LibraryItem::LibraryItem() : libraryID(0), cost(0.0), status("In"), loanPeriod(0) {}

//Parametrized Constructor
LibraryItem::LibraryItem(int libraryID, double cost, string status, int loanPeriod)
    : libraryID(libraryID), cost(cost), status(status), loanPeriod(loanPeriod) {}

//Getter Methods
int LibraryItem::getLibraryID() const 
{
	return libraryID;
}

double LibraryItem::getCost() const 
{
	return cost;
}

string LibraryItem::getStatus() const
{
	return status;
}
int LibraryItem::getLoanPeriod() const
{
	return loanPeriod;
}

//Setter Methods
void LibraryItem::setLibraryID(int libraryID)
{
	this->libraryID = libraryID;
}

void LibraryItem::setCost(double cost)
{
	this->cost = cost;
}

void LibraryItem::setStatus(string status)
{
	this->status = status;
}

void LibraryItem::setLoanPeriod(int loanPeriod)
{
	this->loanPeriod = loanPeriod;
}
