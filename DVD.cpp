
/*

File:
DVD.cpp

*/

#include "DVD.h"
#include <iostream>

using namespace std;

//Default Constructor that initializes all member variables to default value
DVD::DVD() : LibraryItem() 
{
    title = "Undefined";
    category = "Undefined";
    runtime = 0;
    studio = "Undefined";
    releaseDate = "Undefined";
}

//Parametrized Constructor
DVD::DVD(string title, string category, int runtime, string studio, string releaseDate, int libraryID, double cost, string status, int loanPeriod)
    : LibraryItem(libraryID, cost, status, loanPeriod), title(title), category(category), runtime(runtime), studio(studio), releaseDate(releaseDate) {}

//Prompts the user to input details for a DVD and updates the member variables
void DVD::addItem()
{
	//Prompts user for Title, Category, Runtime, Studio, and Release Date
	cout << "\nEnter DVD Details: " << endl;
	
    cout << "Enter Title: ";
	cin.ignore();
    getline(cin, title);
	
    cout << "Enter Category (Action, SciFi, Drama, etc.): ";
    getline(cin, category);
	
    cout << "Enter Runtime (In Minutes): ";
    cin >> runtime;
	
    cout << "Enter Studio (Marvel, Pixar, Disney, etc.): ";
	cin.ignore();
    getline(cin, studio);
	
    cout << "Enter Release Date: ";
    getline(cin, releaseDate);
	
	cout << "DVD has been added." << endl;
}

//Prompts users to modify details of an existing DVD
void DVD::editItem() 
{
	cout << "\nEnter DVD Details to Edit: " << endl;
	
	//If found, prompt for new values of Title, Category, Runtime, Studio, and Release Date
    cout << "Enter New Title: ";
    getline(cin, title);
	
    cout << "Enter New Category (Action, SciFi, Drama, etc.): ";
    getline(cin, category);
	
    cout << "Enter New Runtime (In Minutes): ";
    cin >> runtime;
	
    cout << "Enter New Studio (Marvel, Pixar, Disney, etc.): ";
    cin.ignore();
    getline(cin, studio);
	
    cout << "Enter New Release Date: ";
    getline(cin, releaseDate);
	
	cout << "DVD has been edited." << endl;
}

//Prompted users to delete DVD
void DVD::deleteItem() 
{
    cout << "DVD " << title << " has been deleted." << endl;
}

//Prompts users to search for a DVD by its Title and prints its details
void DVD::searchItem() const 
{
    cout << "Searching for DVD: " << title << endl;
}

//Output the relevant DVD details
void DVD::printItemDetails() const 
{
	cout << "\nDVD Details: " << endl;
    cout << "Title: " << title << endl;
    cout << "Category: " << category << endl;
    cout << "Runtime: " << runtime << " Minutes" << endl;
    cout << "Studio: " << studio << endl;
    cout << "Release Date: " << releaseDate << endl;
}

//Get the Title
string DVD::getTitle() const 
{
    return title;  //Return the title of the DVD
}