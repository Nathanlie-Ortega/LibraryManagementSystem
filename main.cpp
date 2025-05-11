
/*

File:
main.cpp

*/

#include <iostream>
#include <limits>
#include "Patron.h"
#include "Book.h"
#include "AudioCD.h"
#include "DVD.h"
#include "Loan.h"
#include "PatronsCollection.h"
#include "LibraryItemsCollection.h"
#include "LoansCollection.h"

using namespace std;

//Declare collections for patrons, library items, and loans
PatronsCollection patronsCollection;
LibraryItemsCollection libraryItemsCollection;  //Collections that handles books, audio CDs, and DVDs
LoansCollection loansCollection;

//A function to display the main menu
void displayMenu() 
{
    cout << "\nThe Menu:" << endl;
    cout << "1. Manage Patrons" << endl;
    cout << "2. Manage Library Items" << endl;
    cout << "3. Manage Loans" << endl;
    cout << "4. Reporting Functions" << endl;
    cout << "5. Exit Menu" << endl;
    cout << "Choose an option (1 to 5): ";
}

//A function to display the patrons management menu and user input
void patronsMenu() 
{
    int choice;

    do 
	{
        cout << "\nPatrons Management:" << endl;
        cout << "1. Add Patron" << endl;
        cout << "2. Edit Patron" << endl;
        cout << "3. Delete Patron" << endl;
        cout << "4. Find Patron" << endl;
        cout << "5. Pay Fines" << endl;
        cout << "6. Print All Patrons" << endl;
        cout << "7. Go Back" << endl;

        cout << "Choose an option (1 to 7): ";
        cin >> choice;

        //Handle user input based on the choice
        switch (choice) 
        {
            case 1:
                patronsCollection.addPatronsCollection();
                break;

            case 2:
                patronsCollection.editPatronsCollection();
                break;

            case 3:
                patronsCollection.deletePatronsCollection();
                break;

            case 4:
                patronsCollection.findPatronsCollection();
                break;

            case 5:
                patronsCollection.payFinesCollection();
                break;

            case 6:
                patronsCollection.printAllPatronsCollection();
                break;

            case 7:
                cout << "Back to the Menu" << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } 
	
	while (choice != 7);  //Loop until the user chooses to go back
}


//A function to display the library items management menu and user input
void libraryItemsMenu(LibraryItemsCollection& libraryItemsCollection)
 {
    int option;
    do 
	{
        cout << "\nLibrary Items Menu:" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Edit Item" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Search Item" << endl;
        cout << "5. View All Items" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option (1 to 6): ";
        cin >> option;
		
		//Handle user input based on the choice
        switch (option) 
		{
			//Add Item Optimization
            case 1: 
			{
                int itemType;
                cout << "\nChoose item type: " << endl;
                cout << "1. Book" << endl;
                cout << "2. AudioCD" << endl;
                cout << "3. DVD" << endl;
                cout << "Choose an option (1 to 3): ";
                cin >> itemType;

                shared_ptr<LibraryItem> newItem = nullptr;
                switch (itemType) {
                    case 1: newItem = make_shared<Book>(); break;
                    case 2: newItem = make_shared<AudioCD>(); break;
                    case 3: newItem = make_shared<DVD>(); break;
                    default:
                        cout << "Invalid item type." << endl;
                        continue;
                }
				
				newItem->addItem();  //Call addItem for the chosen type
                libraryItemsCollection.addLibraryItem(newItem);  //Add the item to collection
                break;
            }
			
			
			//Edit Item Optimization
            case 2: 
			{
                int editItemType;
                cout << "\nChoose item type to edit:" << endl;
                cout << "1. Book" << endl;
                cout << "2. AudioCD" << endl;
                cout << "3. DVD" << endl;
                cout << "Choose an option (1 to 3): ";
                cin >> editItemType;

                vector<shared_ptr<LibraryItem>> itemsToEdit;
				
                switch (editItemType) 
				{
                    case 1: itemsToEdit = libraryItemsCollection.getItemsByType("Book"); 
					break;
					
                    case 2: itemsToEdit = libraryItemsCollection.getItemsByType("AudioCD"); 
					break;
					
                    case 3: itemsToEdit = libraryItemsCollection.getItemsByType("DVD"); 
					break;
					
                    default:
                        cout << "Invalid item type." << endl;
                        continue;
                }

                if (itemsToEdit.empty()) 
				{
                    cout << "No items of the selected type found." << endl;
                    break;
                }
				
				
				
				//Handle case for editing AudioCD by artist
				string artistNameToEdit;
				if (editItemType == 2)
				{
					cout << "\nEnter Audio CD Artist to edit: ";
					cin.ignore();
					getline(cin, artistNameToEdit);
					
					//Find the AudioCD item to edit by artist name
					shared_ptr<AudioCD> audioCDToEdit = nullptr;
					for (auto& item : itemsToEdit) 
					{
						auto audioCDItem = dynamic_pointer_cast<AudioCD>(item);
						if (audioCDItem && audioCDItem->getArtist() == artistNameToEdit) 
						{
							audioCDToEdit = audioCDItem;
							break;
						}
					}

					if (audioCDToEdit == nullptr) 
					{
						cout << "AudioCD with Artist Name " << artistNameToEdit << " not found." << endl;
						break;
					}

					//Display item details before editing
					audioCDToEdit->editItem();
				}
				else if (editItemType == 3)  //For DVD, edit by title
				{
					string dvdTitleToEdit;
					cout << "\nEnter DVD title to edit: ";
					cin.ignore();  //To clear the newline character from the buffer
					getline(cin, dvdTitleToEdit);

					//Find the DVD item to edit
					shared_ptr<DVD> dvdToEdit = nullptr;
					for (auto& item : itemsToEdit) 
					{
						auto dvdItem = dynamic_pointer_cast<DVD>(item);
						if (dvdItem && dvdItem->getTitle() == dvdTitleToEdit) 
						{
							dvdToEdit = dvdItem;
							break;
						}
					}

					if (dvdToEdit == nullptr) 
					{
						cout << "DVD with Title \"" << dvdTitleToEdit << "\" not found." << endl;
						break;
					}

					//Display item details before editing
					dvdToEdit->editItem();
				}
				else
				{
					//Handle the case for Book, by Library ID (as before)
					int libraryIDToEdit;
					cout << "\nEnter the Library ID number of the item to edit: ";
					cin >> libraryIDToEdit;

					shared_ptr<LibraryItem> itemToEdit = nullptr;
					for (auto& item : itemsToEdit) 
					{
						if (item->getLibraryID() == libraryIDToEdit) 
						{
							itemToEdit = item;
							break;
						}
					}

					if (itemToEdit == nullptr) 
					{
						cout << "Item with Library ID " << libraryIDToEdit << " not found." << endl;
						break;
					}

					//Display item details before editing
					itemToEdit->editItem();
				}
				
				break;
			}
			
			
			
			//Delete Item Optimization
            case 3:
			{
				int deleteItemType;
				cout << "\nChoose item type to delete:" << endl;
				cout << "1. Book" << endl;
				cout << "2. AudioCD" << endl;
				cout << "3. DVD" << endl;
				cout << "Choose an option (1 to 3): ";
				cin >> deleteItemType;

				vector<shared_ptr<LibraryItem>> itemsToDelete;
				string identifier;  
				
				//Holds the Library ID, artist name, or title based on type
				switch (deleteItemType) 
				{
					case 1:  
						//Book deletion
						itemsToDelete = libraryItemsCollection.getItemsByType("Book");
						if (itemsToDelete.empty()) 
						{
							cout << "No Book items found." << endl;
							break;
						}
						cout << "\nEnter the Library ID number of the Book to delete: ";
						cin >> identifier;
						break;

					case 2:  
						//AudioCD deletion
						itemsToDelete = libraryItemsCollection.getItemsByType("AudioCD");
						if (itemsToDelete.empty()) 
						{
							cout << "No AudioCD items found." << endl;
							break;
						}
						cout << "\nEnter the Artist Name of the AudioCD to delete: ";
						cin.ignore();
						getline(cin, identifier);
						break;

					case 3: 
						//DVD deletion
						itemsToDelete = libraryItemsCollection.getItemsByType("DVD");
						if (itemsToDelete.empty()) 
						{
							cout << "No DVD items found." << endl;
							break;
						}
						cout << "\nEnter the Title of the DVD to delete: ";
						cin.ignore();
						getline(cin, identifier);
						break;

					default:
						cout << "Invalid item type.\n";
						continue;
				}

				//Delete the item based on identifier and type
				bool deleted = libraryItemsCollection.deleteLibraryItem(identifier, deleteItemType);
				if (deleted) 
				{
					cout << "The specified item has been deleted." << endl;
				} 
				else 
				{
					cout << "Item is incorrect and not found." << endl;
				}
				
				break;
			}


			
			//Search Item Optimization
			case 4: 
			{
				int itemType;
				cout << "\nChoose item type to search:" << endl;
				cout << "1. Book" << endl;
				cout << "2. AudioCD" << endl;
				cout << "3. DVD" << endl;
				cout << "Choose an option (1 to 3): ";
				cin >> itemType;

				string searchTerm;
				int libraryID; 
				
				switch (itemType) 
				{
					
					case 1: 
						//Search by Title for Book
						cout << "\nEnter the Library ID number for Book: ";
						cin >> libraryID;
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						libraryItemsCollection.searchLibraryItemByLibraryID(libraryID);
						break;	
						
						
					case 2: 
						//Search by Artist for AudioCD
						cout << "Enter the Artist name: ";
						cin.ignore();
						getline(cin, searchTerm);
						libraryItemsCollection.searchLibraryItemByArtist(searchTerm);
						break;
						
						
						
					case 3: 
						//Search by Title for DVD
						cout << "Enter the DVD Title: ";
						cin.ignore();
						getline(cin, searchTerm); 
						libraryItemsCollection.searchLibraryItemByTitle(searchTerm);
						break;
						
						
					default:
						cout << "Invalid option." << endl;
						break;
						
				}
				
				break;
			}
			
			//Print the Item Optimization	
            case 5:
                libraryItemsCollection.printItemDetails();
                break;
				
			//Exit Menu Optimization	
            case 6:
                cout << "Exiting menu." << endl;
                break;
				
			//If the Optimization is incorrect	
            default:
                cout << "Invalid option. Please try again." << endl;
				
				
        }
    } 
	
	while (option != 6);
}


//A function to display the loans management menu and handle user input
void loansMenu() 
{
    int choice;

    do 
	{
        cout << "\nLoans Management:" << endl;
        cout << "1. Add Loan" << endl;
        cout << "2. Edit Loan" << endl;
        cout << "3. Delete Loan" << endl;
        cout << "4. Search/Find Loan" << endl;
        cout << "5. Print All Overdue Loans" << endl;
        cout << "6. Print Loan Details" << endl;
        cout << "7. Go Back" << endl;

        cout << "Choose an option (1 to 7): ";
        cin >> choice;

        //Handle user input based on the choice
        switch (choice) 
        {
            case 1:
                loansCollection.addLoan();
                break;

            case 2:
                loansCollection.editLoan();
                break;

            case 3:
                loansCollection.deleteLoan();
                break;

            case 4:
                loansCollection.findLoan();
                break;

            case 5:
                loansCollection.printAllOverdueLoans();
                break;

            case 6:
                loansCollection.printAllLoans();
                break;

            case 7:
                cout << "Back to the Menu" << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } 
	
	while (choice != 7);  //Loop until the user chooses to go back
}

//Function to display the reporting menu
void reportingMenu() 
{
    int choice;
    do 
	{
        cout << "\nReporting Menu:" << endl;
        cout << "1. List All Patrons\n";
        cout << "2. List All Library Items\n";
        cout << "3. List All Loans\n";
        cout << "4. List Overdue Loans\n";
        cout << "5. Show Fines Owed by Patrons\n";
        cout << "6. Go Back\n";
        cout << "Choose an option (1 to 6): ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                patronsCollection.printAllPatronsCollection();
                break;

            case 2:
                libraryItemsCollection.printItemDetails();
                break;

            case 3:
                loansCollection.printAllLoans();
                break;

            case 4:
                loansCollection.printAllOverdueLoans();
                break;

            case 5:
                for (const auto& patron : patronsCollection.getPatrons()) 
                {
                    cout << "Patron ID: " << patron.getId() 
                         << ", Fines Owed: $" << patron.calculateFines() << endl;
                }
                break;

            case 6:
                cout << "Back to the Menu" << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } 
	
	while (choice != 6);
}

int main() 
{
	//A display of the title, my name, and e-mail address
    cout << "+-------------------------------------------------+" << endl;
    cout << "|      Library Management System		  |" << endl;
    cout << "|      Author name: Nathanlie Ortega              |" << endl;
    cout << "|      NathanlieOrtega.Dev@gmail.com              |" << endl;
    cout << "+-------------------------------------------------+\n" << endl;

    int choice;

    //Loop to display the main menu until the user chooses to exit
    do 
	{
        displayMenu();
        cin >> choice;

        //Handle user input based on the choice
        switch (choice) 
        {
            case 1:
                patronsMenu();
                break;

            case 2:
                libraryItemsMenu(libraryItemsCollection);  //Updated to manage LibraryItems
                break;

            case 3:
                loansMenu();
                break;

            case 4:
                reportingMenu();
                break;

            case 5:
                cout << "Exit Complete" << endl;
                break;

            default:
                cout << "Invalid option, please try again." << endl;
        }

    } 
	
	while (choice != 5);  //Loop until the user chooses to exit

    return 0;
}
