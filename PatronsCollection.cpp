
/*

File:
PatronsCollection.cpp

*/

#include "PatronsCollection.h"
#include <iostream>

using namespace std;

//Add a new patron to the collection
void PatronsCollection::addPatronsCollection() 
{
    Patron newPatron;
    newPatron.addPatron();  //Call the Patron's method to input details
    patrons.push_back(newPatron);  //Add the new patron to the vector
}

//Edit an existing patron based on ID
void PatronsCollection::editPatronsCollection() 
{
    int id;
	
	//Prompt user for Patron ID Number to edit
    cout << "\nEnter Patron ID Number to edit: ";
	cin >> id;		//Search by Patron ID Number
	
    for (auto &patron : patrons) 
	{
        if (patron.getId() == id) 	//Use getId to find the patron by ID
		{ 
            patron.editPatron();  //Call the Patron's edit method
            return;
        }
    }
	
    cout << "Patron ID Number does not exist." << endl;	//If Patron ID Number does not match, it does not exist
}

//Delete a patron based on ID
void PatronsCollection::deletePatronsCollection() 
{
    int id;
	
	//Prompt user for Patron ID Number to delete
    cout << "\nEnter Patron ID Number to delete: ";
	cin >> id;
	
    for (auto it = patrons.begin(); it != patrons.end(); ++it) 
	{
        if (it->getId() == id) 	//Search by Patron ID Number by using getId to find the patron by ID
		{  
            it->deletePatron();  //Call the Patron's delete method
            patrons.erase(it);  //Remove the patron from the collection
            return;
        }
    }
	
    cout << "Patron ID Number does not exist." << endl;		//If Patron ID Number does not match, it does not exist
}

//Find a patron by ID and print their details
void PatronsCollection::findPatronsCollection() const 
{
    int id;
	
	//Prompt user for Patron ID Number to search
    cout << "\nEnter Patron ID Number to find: ";
	cin >> id;
	
    for (const auto &patron : patrons) 
	{
        if (patron.getId() == id) 		//Search by Patron ID and use getID to find the patron by ID Number
		{
            patron.printPatronDetails();  //Print the details if found
            return;
        }
    }
    
	cout << "Patron ID Number does not exist." << endl;		//If Patron ID Number does not match, it does not exist
}


//Payfines for patrons
void PatronsCollection::payFinesCollection() 
{
    int id;
	
	//Prompt user for Patron ID Number to pay fines
    cout << "\nEnter Patron ID Number to pay fines: ";
    cin >> id;
	
    for (auto &patron : patrons) 	//Search by ID and use getID to find the patron by ID Number
    {
        if (patron.getId() == id) 
        {
            patron.payFines();  //Call the Patron's payFines method
            return;
        }
    }
	
    cout << "Patron ID Number does not exist." << endl;	//If Patron ID Number does not match, it does not exist
}

//Prompt user for Patron ID Number to print all Patrons collection
void PatronsCollection::printAllPatronsCollection() const 
{
    for (const auto &patron : patrons) 
	{
        patron.printPatronDetails();  //Print details of each patron or Output the relevant details
    }
}


//Prompt user for Patron ID Number to print single patron’s collection
void PatronsCollection::printSinglePatron(int id) const 
{
    for (const auto &patron : patrons) 
	{
        patron.printPatronDetails();  //Print details of each patron
    }
}



vector<Patron> PatronsCollection::getPatrons() const 
{
    return patrons; 	//Return the vector of patrons
}
