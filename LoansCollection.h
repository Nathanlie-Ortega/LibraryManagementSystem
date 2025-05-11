
/*

File:
LoansCollection.h

*/

#ifndef LOANSCOLLECTION_H
#define LOANSCOLLECTION_H

#include <vector>
#include "Loan.h"

using namespace std;

class LoansCollection 
{
private:
    vector<Loan> loans;

public:

	//LoansCollection Methods
    void addLoan();
    void editLoan();
    void deleteLoan();
    void findLoan() const;
	void printAllOverdueLoans();
    void printAllLoans() const;
    void printSingleLoan(int loanID) const;
};

#endif
