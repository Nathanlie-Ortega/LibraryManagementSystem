
/*

File:
DVD.h

*/

#ifndef DVD_H
#define DVD_H

#include "LibraryItem.h"
#include <string>

using namespace std;

class DVD : public LibraryItem 
{
private:
    string title;
    string category;
    int runtime;
    string studio;
    string releaseDate;

public:
    DVD();	//Default Constructor
	
	//Parametrized Constructor
    DVD(string title, string category, int runtime, string studio, string releaseDate, int libraryID, double cost, string status, int loanPeriod);

 //Overriding Methods from LibraryItem
    void addItem() override;
    void editItem() override;
    void deleteItem() override;
    void searchItem() const override;
    void printItemDetails() const override;

    //Getter and Setter Methods
    string getTitle() const;
    string getCategory() const;
    int getRuntime() const;
    string getStudio() const;
    string getReleaseDate() const;

    void setTitle(string title);
    void setCategory(string category);
    void setRuntime(int runtime);
    void setStudio(string studio);
    void setReleaseDate(string releaseDate);
};

#endif
