
/*

File:
LibraryItemsCollection.cpp

*/

#include "LibraryItemsCollection.h"
#include "Book.h"
#include "AudioCD.h"
#include "DVD.h"
#include <algorithm>
#include <memory>

using namespace std;

LibraryItemsCollection::LibraryItemsCollection() {}

LibraryItemsCollection::~LibraryItemsCollection() {}

//Create a new LibraryItem
void LibraryItemsCollection::addLibraryItem(shared_ptr<LibraryItem> item) 
{
    items.push_back(item);	//Add the item to the collection (items.push_back(item))void editLibraryItem(int libraryID, int itemType)
}

shared_ptr<LibraryItem> LibraryItemsCollection::getLibraryItemByID(int libraryID) 
{
    for (auto& item : items) 
	{
        if (item->getLibraryID() == libraryID) 
		{
            return item;  //Return the item if the ID matches
        }
    }
	
    return nullptr;  // Return nullptr if no matching item is found
}


vector<shared_ptr<LibraryItem>> LibraryItemsCollection::getItemsByType(const string& type) const 
{
    vector<shared_ptr<LibraryItem>> filteredItems;
    
    for (const auto& item : items) 
	{
		//If item.getLibraryID() == Library ID || Artist Name || DVD Title
        if ((type == "Book" && dynamic_cast<Book*>(item.get())) || (type == "AudioCD" && dynamic_cast<AudioCD*>(item.get())) || (type == "DVD" && dynamic_cast<DVD*>(item.get()))) 
		{
            filteredItems.push_back(item);
        }
    }
    
    return filteredItems;
}



void LibraryItemsCollection::editLibraryItem(int libraryID, int itemType) 
{
    for (auto& item : items) 
	{
        if (item->getLibraryID() == libraryID) 
		{
            //Depending on the item type, call the respective edit function
            switch (itemType) 
			{
				//Prompt user for details to edit (library item details)
                case 1:
                    dynamic_pointer_cast<Book>(item)->editItem();  //Call editItem on Book
                    break;
                case 2:
                    dynamic_pointer_cast<AudioCD>(item)->editItem();	//Call editItem on AudioCD
                    break;
                case 3:
                    dynamic_pointer_cast<DVD>(item)->editItem();	//Call editItem on DVD
                    break;
                default:
                    cout << "Invalid item type." << endl;	//Wrong item type
                    return;
            }
            return;	//Return (Operation complete)
        }
    }
	//If not found, display "Library item not found
    cout << "Item with Library ID " << libraryID << " not found!" << endl;
}


bool LibraryItemsCollection::deleteLibraryItem(const string& identifier, int deleteItemType) 
{
    for (auto it = items.begin(); it != items.end(); ++it) 
    {
        //Check if the item matches the given identifier based on type
        if (deleteItemType == 1)  //Match by Library ID from Book
        {
            auto bookItem = dynamic_cast<Book*>(it->get());
            if (bookItem && to_string(bookItem->getLibraryID()) == identifier) 
            {
                items.erase(it);	//Clear all items from the collection (items.erase(it))
                return true;
            }
        } 
        else if (deleteItemType == 2)
        {
            auto audioCDItem = dynamic_cast<AudioCD*>(it->get());
            if (audioCDItem && audioCDItem->getArtist() == identifier) 
            {
                items.erase(it);	//Clear all items from the collection (items.erase(it))
                return true;
            }
        } 
        
		else if (deleteItemType == 3) 
        {
            auto dvdItem = dynamic_cast<DVD*>(it->get());
            if (dvdItem && dvdItem->getTitle() == identifier) 
            {
                items.erase(it);	//Clear all items from the collection (items.erase(it))
                return true;
            }
        }
    }

    return false;
}


void LibraryItemsCollection::searchLibraryItemByLibraryID(int libraryID) const
 {
    bool found = false;
    for (const auto& item : items) 
	{
        //Check if the item is of type Book and the libraryID matches
        if (auto book = dynamic_cast<Book*>(item.get()))
			{
				if (book->getLibraryID() == libraryID) //If item.getLibraryID() == Library ID:
				{
                book->printItemDetails();  //Print item details (item.printItemDetails())
                found = true;
                break;
				}
			}
			
			//Add cases for other item types like AudioCD, DVD if needed
	}
	
	if (!found)
		{
        cout << "No Library Item found with ID: " << libraryID << endl;	//If not found, display that the Library item with ID is not found.
		}
}


void LibraryItemsCollection::searchLibraryItemByArtist(const string& artist) const 
{
    bool found = false;
    for (const auto& item : items) 
	{
        if (auto audioCD = dynamic_cast<AudioCD*>(item.get())) 
		{
            if (audioCD->getArtist() == artist) 	//If item.getArtist() == Artist Name:
			{
                item->printItemDetails();  //Print item details (item.printItemDetails())
                found = true;	//Return (Found and printed details)
            }
        }
    }
    if (!found)
		{
        cout << "No AudioCD found with Artist: " << artist << endl;	//If not found, display that the Library item with Artist Name is not found
		}
}

void LibraryItemsCollection::searchLibraryItemByTitle(const string& title) const 
{
    bool found = false;
    for (const auto& item : items) 
	{
        if (auto dvd = dynamic_cast<DVD*>(item.get())) 
		{
            if (dvd->getTitle() == title) 	//If item.getTitle() == DVD Title:
			{ 
                item->printItemDetails();  //Print item details (item.printItemDetails())
                found = true;	//Return (Found and printed details)
            }
        }
    }
	
    if (!found) 
	{
        cout << "No DVD found with Title: " << title << endl;	//If not found, display that the library item with DVD Title is not found
    }
}

//Prints Item Details
void LibraryItemsCollection::printItemDetails() const
 {
    for (const auto& item : items) 
	{
        item->printItemDetails();
    }
}

vector<shared_ptr<LibraryItem>>& LibraryItemsCollection::getItems()
 {
    return items;
}
