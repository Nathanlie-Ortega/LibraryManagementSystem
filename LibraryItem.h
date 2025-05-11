
/*

File:
LibraryItem.h

*/

#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>

using namespace std;

class LibraryItem 
{
protected:
    int libraryID;
    double cost;
    string status;
    int loanPeriod;

public:
    LibraryItem();  //Default Constructor
    LibraryItem(int libraryID, double cost, string status, int loanPeriod);	//Parametrized Constructor

    //Virtual Destructor
	virtual ~LibraryItem() {}	

    //Getter and Setter Methods
    virtual int getLibraryID() const;
    double getCost() const;
    string getStatus() const;
    int getLoanPeriod() const;

    void setLibraryID(int libraryID);
    void setCost(double cost);
    void setStatus(string status);
    void setLoanPeriod(int loanPeriod);
	
	//Virtual Methods for Overriding
    virtual void addItem() = 0; 	 				//This shows the method generic for all add items
    virtual void editItem() = 0;  					//This shows the method generic for all edit items
    virtual void deleteItem() = 0; 					//This shows the method generic for all delete items
    virtual void searchItem() const = 0;  			//This shows the method generic for all search items
    virtual void printItemDetails() const = 0;  	//This shows the method generic for all printItemDetails or view items
	
	
	
};

#endif
