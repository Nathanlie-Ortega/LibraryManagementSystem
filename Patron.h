
/*

File:
Patron.h

*/

#ifndef PATRON_H
#define PATRON_H

#include <string>

using namespace std;

class Patron 
{
	
private:
    string name;
    int id;
    double fineBalance;
    int booksOut;

public:
	Patron();		//Default Constructor
	
    Patron(string name, int id, double fineBalance, int booksOut);	//Parametrized Constructor

    //Methods
    void addPatron();
    void editPatron();
    void deletePatron();
    void findPatron() const;
    void payFines();
    void printPatronDetails() const;
	double calculateFines() const;


    //Getters and setters
    string getName() const;
    int getId() const;
    double getFineBalance() const;
    int getBooksOut() const;

    void setName(string name);
    void setId(int id);
    void setFineBalance(double fineBalance);
    void setBooksOut(int booksOut);
};

#endif
