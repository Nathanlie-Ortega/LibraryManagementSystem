
/*

File:
Patron.cpp

*/

#include "Patron.h"
#include <iostream>

using namespace std;

//Default Constructor
Patron::Patron()
{
	string name = "Undefined";		//Default name
	int id = 0; 					//Default id
	double fineBalance = 0.0; 		//Default fine balance
	int booksOut = 0;				//Default books out count
}

//Parametrized Constructor
Patron::Patron(string name, int id, double fineBalance, int booksOut)
{
	name = name;		//Set name using the provided argument
	id = id; 			//Set id using the provided argument
	fineBalance = fineBalance;	//Set fine balance using the provided argument
	booksOut = booksOut; 		//Set books out count using the provided argument
}

//Getter method to return the patron's ID	
int Patron::getId() const 
{
    return id;
}

//Method to add a new patron with user input
void Patron::addPatron() 
{
	//Prompt user for Name, ID Number, Fine Balance, and Current number of books out
    cout << "\nPlease enter the patron details" << endl;
	
    cout << "Enter Name: ";
	cin.ignore();
	getline(cin, name);
	
    cout << "Enter ID Number: ";
	cin >> id;
	
	fineBalance = 0.0;
    booksOut = 0;
	
	cout << "Enter Fine Balance: ";
	cin >> fineBalance;
	
	cout << "Enter Current Number of Books Out: ";
	cin >> booksOut;
	
    cout << "Patron has been added." << endl;	//Add the Patron to the Patron collection
}

//Method to edit an existing patron's details
void Patron::editPatron() 
{
	//Prompt user for Patron ID Number
    cout << "\nEdit the new details for patron with ID Number: " << id << endl;		//Search for the Patron in the Patron collection by ID Number
	
	cout << "Enter New Name: ";		 //Input for the new name
	cin.ignore();
	getline(cin, name);
	
	//If found, prompt for new values of Name, Fine Balance, and Books Out
    cout << "Enter New Fine Balance: ";		//Input for the updated fine balance
	cin >> fineBalance;
	
    cout << "Enter New Number of Books Out: ";		//Input for the updated books out count
	cin >> booksOut;
	
    cout << "Patron has been edited." << endl;		//Update the attributes with the new values
}


//Method to delete a patron by resetting the ID
void Patron::deletePatron() 
{
	cout << "\nPatron with ID Number: " << id << " has been deleted." << endl;	//Prompt user for Patron ID Number
    id = 0;  		//Reset the ID to indicate deletion
   
}

//Method to find and display the patron's details
void Patron::findPatron() const 
{
	//Prompt user for Patron ID Number.
    cout << "\nSearching for patron with ID Number: " << id << endl;	//Search for the Patron in the Patron collection by ID Number
    printPatronDetails();	//If found, return the Patron details
}


//Method to allow the patron to pay fines and reduce their balance
void Patron::payFines()
{
	//If found, Prompt user to enter payment amount
    double payment;
    cout << "Enter payment amount: ";		//Input for the payment amount
	cin >> payment;
	
    fineBalance -= payment;		//Deduct the Payment Amount from the Patron’s Fine Balance
	
	//If Fine Balance is now zero, reset overdue status
    if (fineBalance < 0) 
	{
		fineBalance = 0;
	}
	
    cout << "Payment Successful." << endl; 
	cout << "New Fine Balance: $" << fineBalance << endl;	//Return the updated Fine Balance
}


//Method to print the patron's details
void Patron::printPatronDetails() const 
{
	//If found, print all Patron details (Name, ID, Fine Balance, Books Out)
	cout << "\nPatron Details:" << endl;
    cout << "Name: " << name << endl;
	cout << "ID Number: " << id << endl; 	//Search for the Patron by ID Number
    cout << "Fine Balance: $" << fineBalance << endl;
    cout << "Current Number of Books Out: " << booksOut << endl;
}

//Show Fines Owed by Patrons in Reporting Functions Menu
double Patron::calculateFines() const 
{

    return fineBalance; 
}
