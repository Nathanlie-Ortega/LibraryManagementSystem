
/*

File:
Loan.h

*/

#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <ctime>

using namespace std;

class Loan 
{
private:
    int loanID;
    int itemID;
    int patronID;
	string itemCategory;	//Category of the LibraryItem (Book, AudioCD, DVD)
    string dueDate;  //Time utilization using "YYYY-MM-DD"
	string loanDate;  // New attribute to store the loan start date
    string status;   //Status such as: (Overdue, Normal, Lost, Returned)

public:
    Loan();		//Default Constructor
    Loan(int loanID, int itemID, int patronID, string itemCategory, string dueDate, string status, string loanDate);	//Parameterized constructor

    //Loan Methods
    void borrowItem();
    void returnItem();
    void listOverdue() const;
    void updateLoanStatus();
    void recheckItem();
    void editLoan();
    void reportLost();

    //Getter for isOverdue function
    bool isOverdue() const;

    //Getters and Setters
    int getLoanID() const;
    int getItemID() const;
    int getPatronID() const;
	string getItemCategory() const;
    string getDueDate() const;
	string getLoanDate() const;
    string getStatus() const;

    void setLoanID(int loanID);
    void setItemID(int itemID);
    void setPatronID(int patronID);
	void setItemCategory(string itemCategory);
    void setDueDate(string dueDate);
	void setLoanDate(string loanDate);
    void setStatus(string status);
};

#endif
