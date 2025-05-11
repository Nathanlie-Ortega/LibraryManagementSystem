# Library Management System

**Author**: Nathanlie Ortega


**Email**: NathanlieOrtega.Dev@gmail.com

## Brief Description
A C++ console app for managing a library system. Supports books, CDs, DVDs, patrons, and loans. Features include item management, overdue tracking, and fine calculation. Uses OOP (inheritance, polymorphism), vectors, and a menu UI.

## Files and Structure
- `main.cpp`: Main logic and menu interface.
- `Patron.h`, `Patron.cpp`: Patron class and operations.
- `Book.h`, `Book.cpp`: Book class and operations.
- `AudioCD.h`, `AudioCD.cpp`: Audio CD class and operations.
- `DVD.h`, `DVD.cpp`: DVD class and operations.
- `Loan.h`, `Loan.cpp`: Loan class and operations.
- `LibraryItem.h`, `LibraryItem.cpp`: Base class for library items.
- `PatronsCollection.h`, `PatronsCollection.cpp`: Manages patron records.
- `BooksCollection.h`, `BooksCollection.cpp`: Manages books.
- `LoansCollection.h`, `LoansCollection.cpp`: Manages loans.
- `LibraryItemsCollection.h`, `LibraryItemsCollection.cpp`: Manages all library items.
- `Makefile`: Automates compilation.



## Compilation and Execution

1. Navigate to the project folder:

   cd LibraryManagementSystem

2. Compile:

    g++ AudioCD.cpp Book.cpp BooksCollection.cpp DVD.cpp LibraryItem.cpp LibraryItemsCollection.cpp Loan.cpp LoansCollection.cpp main.cpp Patron.cpp PatronsCollection.cpp

3. Run:

    ./a.exe


## Expected Output:
``````````````````````````````````````````````````````
+-------------------------------------------------+
|      Library Management System                  |
|      Author name: Nathanlie Ortega              |
|      NathanlieOrtega.Dev@gmail.com              |
+-------------------------------------------------+

The Menu:
1. Manage Patrons
2. Manage Library Items
3. Manage Loans
4. Reporting Functions
5. Exit Menu
Choose an option (1 to 5): 1

Patrons Management:        
1. Add Patron
2. Edit Patron
3. Delete Patron
4. Find Patron
5. Pay Fines
6. Print All Patrons       
7. Go Back
Choose an option (1 to 7): 1

Please enter the patron details
Enter Name: Edgar
Enter ID Number: 114466
Enter Fine Balance: 12
Enter Current Number of Books Out: 3
Patron has been added.

Patrons Management:
1. Add Patron
2. Edit Patron
3. Delete Patron
4. Find Patron
5. Pay Fines
6. Print All Patrons
7. Go Back
Choose an option (1 to 7): 6

(Continuation)......

````````````````````````````````````````````````````````