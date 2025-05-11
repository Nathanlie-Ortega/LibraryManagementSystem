
/*

File:
LoansCollection.cpp

*/

#include "LoansCollection.h"
#include <iostream>

using namespace std;

//Add a loan to the collection
void LoansCollection::addLoan() 
{
    Loan newLoan;		//Call the Loan’s method to input details
    newLoan.borrowItem();
    loans.push_back(newLoan);	//Add the new Loan to the vector by pushing the new Loan into the Loan’s vector
}



//Edit a loan by searching its ID
void LoansCollection::editLoan() 
{
    int loanID;
    cout << "\nEnter Loan ID Number to edit: ";		//Prompt user for Loan ID Number to edit
    cin >> loanID;

    for (auto &loan : loans) 
	{
        if (loan.getLoanID() == loanID) //Search by Loan ID Number by using getLoanID to find the Loan by ID
		{
            loan.editLoan();
            return;		//Update Loan’s details.
        }
    }
    
    cout << "Loan ID Number does not exist." << endl;	//If the Loan ID Number does not match, it does not exist
}



//Delete a loan from the collection
void LoansCollection::deleteLoan() 
{
    int loanID;
    cout << "\nEnter Loan ID Number to delete: ";	//Prompt user for Loan ID Number to delete
    cin >> loanID;

    for (auto it = loans.begin(); it != loans.end(); ++it) 	//Search by Loan ID Number by using getLoanID to find the patron by ID
	{
        if (it->getLoanID() == loanID) 
		{
            loans.erase(it);		//Call the Loan’s delete method
            cout << "\nLoan with ID Number " << loanID << " has been deleted." << endl;	//Remove the Loan from the collection and the object
            return;
        }
    }
    
    cout << "Loan ID Number does not exist." << endl;	//If the Loan ID Number does not match, it does not exist
}



//Find and display a loan by ID
void LoansCollection::findLoan() const 
{
    int loanID;
    cout << "\nEnter Loan ID Number to Search or Find: ";	//Prompt user for Loan ID Number to search
    cin >> loanID;

    for (const auto &loan : loans) 
    {
        if (loan.getLoanID() == loanID) // Search by Loan ID
        {
            if (loan.getStatus() == "Overdue") // Check if the loan is overdue
            {
                loan.listOverdue(); // Display overdue-specific details
            }
            else
            {
                // Display regular loan details
                cout << "\nLoan Details:" << endl;
                cout << "Loan ID Number: " << loan.getLoanID() << endl;
                cout << "Patron ID Number: " << loan.getPatronID() << endl;
                cout << "Library Item ID Number: " << loan.getItemID() << endl;
                cout << "Library Item Category: " << loan.getItemCategory() << endl;
                cout << "Due Date: " << loan.getDueDate() << endl;
                cout << "Current Status: " << loan.getStatus() << endl;
            }
            return; // Exit after finding and displaying the loan
        }
	}
    
    cout << "Loan ID Number does not exist." << endl;	//If the Loan ID Number does not match, it does not exist
}


//Prompt user for Loan ID Number to print All Overdue Loan’s collection.
void LoansCollection::printAllOverdueLoans() 
{
    bool foundOverdue = false;

    for (auto &loan : loans) 
	{
		loan.updateLoanStatus();  //Checks and updates status
		
        if (loan.getStatus() == "Overdue" || loan.isOverdue()) 
		{
            loan.listOverdue();
            foundOverdue = true;
        }
    }

    if (!foundOverdue) 
	{
        cout << "No overdue loans found." << endl;
    }
}


//Prompt user for Loan ID Number to print all Loan collection
void LoansCollection::printAllLoans() const 
{
    if (loans.empty()) 
	{
        cout << "No loans found.\n";
        return;
    }

    for (const auto &loan : loans) 
	{
		//Output the relevant details
        cout << "\nLoan Details:" << endl;
        cout << "Loan ID Number: " << loan.getLoanID() << endl;
        cout << "Patron ID Number: " << loan.getPatronID() << endl;
        cout << "Library Item ID Number: " << loan.getItemID() << endl;
		cout << "Library Item Category: " << loan.getItemCategory() << endl;
        cout << "Due Date: " << loan.getDueDate() << endl;
        cout << "Current Status: " << loan.getStatus() << endl;
    }
}
