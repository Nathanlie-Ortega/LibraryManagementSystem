
/*

File:
LibraryItemsCollection.h

*/

#ifndef LIBRARYITEMSCOLLECTION_H
#define LIBRARYITEMSCOLLECTION_H

#include "LibraryItem.h"
#include <vector>
#include <memory>
using namespace std;

class LibraryItemsCollection 
{
private:
    vector<shared_ptr<LibraryItem>> items;
	
//Mutators
public:
    LibraryItemsCollection();
    ~LibraryItemsCollection();

    void addLibraryItem(shared_ptr<LibraryItem> item);
    void editLibraryItem(int libraryID, int itemType);
	bool deleteLibraryItem(const string& identifier, int deleteItemType);
	void searchLibraryItemByLibraryID(int libraryID) const;
    void searchLibraryItemByArtist(const string& artist) const;
    void searchLibraryItemByTitle(const string& title) const;
	void printItemDetails() const;
	
	shared_ptr<LibraryItem> getLibraryItemByID(int libraryID);
	
	vector<shared_ptr<LibraryItem>> getItemsByType(const string& type) const;


    vector<shared_ptr<LibraryItem>>& getItems();
};

#endif
