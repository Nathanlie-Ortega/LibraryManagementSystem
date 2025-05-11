
/*

File:
Book.cpp

*/

#include "Book.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//Default Constructor that initializes all member variables to default value
Book::Book() : LibraryItem()  //This Call the default constructor of LibraryItem
{
	title = "Undefined";
    author = "Undefined";
    ISBN = "Undefined";
    category = "Undefined";
    libraryID = 0;
    cost = 0.0;
    status = "In, Out, Repair, Lost";
}


//Destructor
Book::~Book() 
{

}

//Parameterized Constructor that initializes member variables with user-defined values
Book::Book(string title, string author, string ISBN, string category, int libraryID, double cost, string status)

    : LibraryItem(libraryID, cost, status, 0)  //Initializes base class (LibraryItem)
	
{
    this->title = title;
	this->author = author;
    this->ISBN = ISBN;
    this->category = category;
    this->libraryID = libraryID;
    this->cost = cost;
    this->status = status;
}



//Prompts the user to input details for a book and updates the member variables
void Book::addItem() 
{
	//Prompt for Library ID Number
    cout << "Enter Library ID Number: ";
    cin >> libraryID;
	
	//Prompt user for Title, Author, ISBN Number, Category, Cost, and Status (In, Out, Repair, Lost)
    cout << "\nPlease enter book details" << endl;
    cout << "Enter Title: ";
    cin.ignore();
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter ISBN Number: ";
    getline(cin, ISBN);

    cout << "Enter Category (Biography, Fiction, SciFi, History, etc.): ";
    getline(cin, category);

    cout << "Enter Cost: ";
    cin >> cost;

    cout << "Enter Status (In, Out, Repair, Lost): ";
    cin.ignore();
    getline(cin, status);
	
	
 //Prompt for Loan Period Due Date
    string dueDateInput;
    cout << "Enter Due Date for Loan Period (MM-DD-YYYY): ";
    cin >> dueDateInput;

    //Manually extract the month, day, and year from the dueDateInput
    int dueMonth = 0, dueDay = 0, dueYear = 0;
    char dash1, dash2;

    if (sscanf(dueDateInput.c_str(), "%d%c%d%c%d", &dueMonth, &dash1, &dueDay, &dash2, &dueYear) == 5 && dash1 == '-' && dash2 == '-') 
	{
        //Calculate the loan period
        time_t now = time(0);
        tm dueDate = {};
        dueDate.tm_mday = dueDay;
        dueDate.tm_mon = dueMonth - 1;  // Adjust month to 0-based
        dueDate.tm_year = dueYear - 1900;  // Adjust year to start from 1900

        //Convert dueDate to time_t
        time_t due = mktime(&dueDate);

        if (due != -1) 
		{ 
            int loanPeriod = difftime(due, now) / (60 * 60 * 24); //Calculate in days
            setLoanPeriod(loanPeriod > 0 ? loanPeriod : 0); 	//Set loan period to 0 if overdue
        } 
		
		else 
		{
            setLoanPeriod(0);  //Default to 0 if date conversion fails
        }
    } 
	
	else 
	{
        cout << "Invalid date format. Setting loan period to 0 days." << endl;
        setLoanPeriod(0);
    }

    cout << "Book has been added with a loan period of " << getLoanPeriod() << " days." << endl;
}

//Prompts users to modify details of an existing book based on its Library ID
void Book::editItem() 
{
   //Prompted user for Library ID Number
    cout << "\nEnter the New details for " << libraryID << endl;	//Search for the Book in the Book collection by Library ID Number
	
	//If found, prompt for new values of Author, Title, ISBN Number, Cost, and Current Status
	cout << "Enter New Title: ";
	cin.ignore();
    getline(cin, title);
	
    cout << "Enter New Author: ";
    getline(cin, author);

    cout << "Enter New ISBN Number: ";
    getline(cin, ISBN);
	
	cout << "Enter New Category (Biography, Fiction, SciFi, History, etc.): ";
    getline(cin, category);

    cout << "Enter New Cost: ";
    cin >> cost;

    cout << "Enter New Status (In, Out, Repair, Lost): ";
    cin.ignore();
    getline(cin, status);

    //Prompt for due date
    string dueDateInput;
    cout << "Enter New Due Date for Loan Period(MM-DD-YYYY): ";
    cin >> dueDateInput;

    //Extract the month, day, and year from the dueDateInput
    int dueMonth = 0, dueDay = 0, dueYear = 0;
    char dash1, dash2;

    if (sscanf(dueDateInput.c_str(), "%d%c%d%c%d", &dueMonth, &dash1, &dueDay, &dash2, &dueYear) == 5 && dash1 == '-' && dash2 == '-')
		{
        //Calculate the loan period
        time_t now = time(0);
        tm dueDate = {};
        dueDate.tm_mday = dueDay;
        dueDate.tm_mon = dueMonth - 1;  // Adjust month to 0-based
        dueDate.tm_year = dueYear - 1900;  // Adjust year to start from 1900

        // Convert dueDate to time_t
        time_t due = mktime(&dueDate);

        if (due != -1) 
		{
            int loanPeriod = difftime(due, now) / (60 * 60 * 24); 	//Calculate in days
            setLoanPeriod(loanPeriod > 0 ? loanPeriod : 0); 		//Set loan period to 0 if overdue
        } 
		
		else 
		{
            setLoanPeriod(0);  //Default to 0 if date conversion fails
        }
    } 
	
	else 
	{
        cout << "Invalid date format. Setting loan period to 0 days." << endl;
        setLoanPeriod(0);
    }

    cout << "Book has been edited with a new loan period of " << getLoanPeriod() << " days." << endl;
}

//Prompts users to delete by resetting its Library ID to 0
void Book::deleteItem() 
{
//Prompted user for Library ID Number
    cout << "\nBook with Library ID Number: " << libraryID << " has been deleted." << endl;		//If found, remove the Book from the collection
    libraryID = 0;  //Reset the ID to indicate deletion
}

//Prompts users to search for a book by its Library ID and prints its details
void Book::searchItem() const 
{
	//Prompted user for Library ID Number
    cout << "\nSearching for book with Library ID Number: " << libraryID << endl;	//If found, return the Book details
    printItemDetails();
}

void Book::printItemDetails() const 
{
	//Output the LibraryItem details (overloaded << operator)
    cout << *this;
    cout << "\nBook Details for Library ID Number " << libraryID << " is: " << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN Number: " << ISBN << endl;
    cout << "Category: " << category << endl;
}

ostream& operator<<(ostream& os, const Book& book) 
{
    os << "\nLibrary ID Number: " << book.getLibraryID() << endl
       << "Cost: $" << book.getCost() << endl
       << "Status: " << book.getStatus() << endl
       << "Loan Period: " << book.getLoanPeriod() << " days" << endl;
    return os;
}

//Getter and Setter methods
string Book::getAuthor() const 
{
	return author; 
}

string Book::getTitle() const 
{
	return title;
}

string Book::getISBN() const 
{
	return ISBN;
}

string Book::getCategory() const 
{
	return category;
}

int Book::getLibraryID() const
{
	return libraryID;
}

double Book::getCost() const
{
	return cost;
}

string Book::getStatus() const
{
	return status;
}


void Book::setAuthor(string author)
{
	this->author = author;
}

void Book::setTitle(string title)
{
	this->title = title;
}

void Book::setISBN(string ISBN)
{
	this->ISBN = ISBN;
}

void Book::setCategory(string category)
{
	this->category = category;
}

void Book::setLibraryID(int libraryID)
{
	this->libraryID = libraryID;
}

void Book::setCost(double cost)
{
	this->cost = cost;
}

void Book::setStatus(string status)
{
	this->status = status;
}