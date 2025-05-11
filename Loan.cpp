
/*

File:
Loan.cpp

*/

#include "Loan.h"
#include <iostream>
#include <ctime>


using namespace std;

//Default Constructor
Loan::Loan()
{
	int loanID = 0;
	int itemID = 0;
	int patronID = 0;
	string itemCategory = "Undefined";
	string dueDate = "Undefined";
	string loanDate = "Undefined";
	string status = "Normal";
}


//Parametized Constructor
Loan::Loan(int loanID, int itemID, int patronID, string itemCategory, string dueDate, string loanDate, string status)
{
	loanID = loanID;
	itemID = itemID;
	patronID = patronID;
	itemCategory = itemCategory;
	dueDate = dueDate;
	loanDate = loanDate;	
	status = status;
}


//stringToDate function to convert string date to struct time
tm stringToDate(const string& dateStr) {
    tm date = {};
    int month, day, year;
    
    //Date string in "MM-DD-YYYY" format
    if (sscanf(dateStr.c_str(), "%d-%d-%d", &month, &day, &year) != 3) {
        cerr << "Error: Invalid date format. Expected MM-DD-YYYY." << endl;
    } else {
        date.tm_mon = month - 1; //tm_mon is 0-based
        date.tm_mday = day;
        date.tm_year = year - 1900; //tm_year is years since 1900
    }

    return date;
}

//Check if the loan is overdue
bool Loan::isOverdue() const 
{
    time_t now = time(nullptr);  //Get current time
    tm dueDateTm = stringToDate(dueDate);  //Convert due date to struct tm

    if (difftime(mktime(&dueDateTm), now) < 0) //If current time is past the due date
	{
        return true;
    }
	
    return false;
}

int dateDifference(const string& date1, const string& date2) {
    tm dateTm1 = stringToDate(date1);
    tm dateTm2 = stringToDate(date2);
    
    time_t time1 = mktime(&dateTm1);
    time_t time2 = mktime(&dateTm2);

    double secondsDifference = difftime(time2, time1);
    int daysDifference = secondsDifference / (60 * 60 * 24);  //Convert seconds to days

    return daysDifference;
}


//Borrow a library item and create a loan
void Loan::borrowItem() 
{
	//Prompt user for Loan ID Number, Library Item ID Number. And Patron ID Number
    cout << "\nEnter Loan ID Number: ";
    cin >> loanID;
	
	cout << "Enter Library Item ID Number: ";
    cin >> itemID;

    cout << "Enter Patron ID Number: ";
    cin >> patronID;
	
	cout << "Select Library Item Category (Book, AudioCD, DVD): ";
    cin.ignore();
    getline(cin, itemCategory);

    cout << "Enter due date(MM-DD-YYYY): ";	//Prompt user for Date using (MM-DD-YYYY) format
    cin.ignore();
    getline(cin, dueDate);
	
	
	//Set loan date to the current date
	time_t now = time(0);
    tm *ltm = localtime(&now);
    loanDate = to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + "-" + to_string(1900 + ltm->tm_year);

    status = "Normal";  //Search for the Library Item by ID and check if it's available (Status = "Normal").

    cout << "Loan has been added." << endl;	//Add the Loan to the Loan collection
}

//Return a library item and update loan status
void Loan::returnItem() 
{
	//Prompted user for Loan ID Number
    cout << "Returning Library Item with Loan ID " << loanID << "...\n";
    status = "Returned";
    cout << "Library Item returned successfully.\n";	//Remove the Loan from the Loan collection
}

//List overdue loans
void Loan::listOverdue() const 
{
    if (status == "Overdue" || isOverdue()) 
	{
		//Print Loan details with Library Item and Patron number if Loan status is "Overdue"
        cout << "\nLoan Details(Overdue):" << endl;
        cout << "Loan ID Number: " << loanID << endl;
		cout << "Library Item ID Number: " << itemID << endl;
        cout << "Patron ID Number: " << patronID << endl;
		cout << "Library Item Category: " << itemCategory << endl;
		
		//Include the Due Date
        cout << "Due Date: " << dueDate << endl;
		
		
		//Calculate how long the loan has been active
		time_t now = time(nullptr);
        tm nowTm = *localtime(&now);
        string currentDate = to_string(nowTm.tm_mon + 1) + "-" + to_string(nowTm.tm_mday) + "-" + to_string(nowTm.tm_year + 1900);
		
		int overdueDays = dateDifference(dueDate, currentDate);
		
		//Include the Loan Active
		cout << "Loan Active for: " << overdueDays << " days" << endl;
		
    }
}

//Update the loan status based on the due date
void Loan::updateLoanStatus() 
{
    cout << "\nUpdating loan status for Loan ID " << loanID << endl;
	
	//Check the current date against the Due Date
	time_t now = time(nullptr);
    tm dueDateTm = stringToDate(dueDate);
	
	//If the current date exceeds the Due Date, update the current status to "Overdue."
    if (difftime(mktime(&dueDateTm), now) < 0)
	{
        status = "Overdue";
        cout << "Loan is overdue." << endl;
		
    } 
	
	else 
		
	{
        status = "Normal";
        cout << "Loan status is normal." << endl;
    }
}

//Extend the due date of a loan (recheck)
void Loan::recheckItem() 
{
	//Prompted user for Loan ID Number
    cout << "Extending loan for Loan ID Number: " << loanID << endl;
	
    cout << "Enter new due date(MM-DD-YYYY): ";	//Prompt user for Date using (MM-DD-YYYY) format
	cin.ignore();
    getline(cin, dueDate);
	
    cout << "Library Item has been rechecked." << endl;
}

//Edit an existing loan
void Loan::editLoan() 
{
	//Prompted user for Loan ID Number
    cout << "\nEnter the new details for loan with Loan ID Number: " << loanID << endl;

    cout << "Enter new due date(MM-DD-YYYY): ";	//Prompt user for Date using (MM-DD-YYYY) format
	cin.ignore();
    getline(cin, dueDate);

    cout << "Enter new status (Normal, Overdue, etc.): ";	//Prompt user for new status (Due Date, Status, etc.)
    getline(cin, status);

    cout << "Loan has been edited and rechecked." << endl;
}



//Report a library item as lost
void Loan::reportLost() 
{
    cout << "Reporting Library Item with Loan ID " << loanID << " as lost...\n";	//Search for the Loan by ID Number
    status = "Lost";		//If found, prompt the Library Item status as "Lost."
    cout << "Library Item reported lost successfully.\n";
}

//Getters and Setters
int Loan::getLoanID() const 
{
	return loanID; 
}

int Loan::getItemID() const 
{
	return itemID; 
}


int Loan::getPatronID() const 
{
	return patronID; 
}

string Loan::getItemCategory() const 
{
	return itemCategory; 
}


string Loan::getDueDate() const 
{
	return dueDate; 
}


string Loan::getStatus() const 
{
	return status;
}

void Loan::setLoanID(int loanID) 
{
	this->loanID = loanID; 
}

void Loan::setItemID(int itemID)
{
	this->itemID = itemID;
}


void Loan::setPatronID(int patronID)
{
	this->patronID = patronID;
}


void Loan::setDueDate(string dueDate)
{
	this->dueDate = dueDate;
}


void Loan::setStatus(string status)
{
	this->status = status;
}
