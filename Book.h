
/*

File:
Book.h

*/

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "LibraryItem.h"

using namespace std;

class Book : public LibraryItem 
{
private:
    string title;
	string author;
    string ISBN;
    string category;
    int libraryID;
    double cost;
    string status;

public:
    Book();  //Default Constructor
	
	//Destructor
	~Book();
	
	//Parametrized Constructor
    Book(string title, string author, string ISBN, string category, int libraryID, double cost, string status);

	//Overriding Methods from LibraryItem
    void addItem() override;
    void editItem() override;
    void deleteItem() override;
    void searchItem() const override;
    void printItemDetails() const override;

    //Getters and setters
	string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    string getCategory() const;
    virtual int getLibraryID() const; ;
    double getCost() const;
    string getStatus() const;

    void setAuthor(string author);
    void setTitle(string title);
    void setISBN(string ISBN);
    void setCategory(string category);
    void setLibraryID(int libraryID);
    void setCost(double cost);
    void setStatus(string status);
	
	//Overloaded operator to use with Book objects
    friend ostream& operator<<(ostream& os, const Book& book);
};

#endif

