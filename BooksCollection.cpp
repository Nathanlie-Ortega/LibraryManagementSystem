
/*

File:
BooksCollection.cpp

*/

#include "BooksCollection.h"
#include <iostream>

using namespace std;

//Adds a new book to the collection by calling the addBook() method from the Book class 
void BooksCollection::addBooksCollection() 
{
    Book newBook;		//Call the Book’s method to input details
    newBook.addItem();
    books.push_back(newBook);  //Add the new patron to the vector by pushing the new book into the book’s vector
	
	// Calls LibraryItemsCollectionItemsCollection
    shared_ptr<LibraryItem> item = make_shared<Book>(newBook);
    libraryItemsCollection.addLibraryItem(item);  //Add to LibraryItemsCollection
	cout << "Book added successfully." << endl;
}



//Edits an existing book in the collection
void BooksCollection::editBooksCollection() 
{
    int id;  
    cout << "\nEnter Library ID Number of book to edit: ";  // Prompt user for Book ID
    cin >> id;
    
    //Search for the book in the LibraryItemsCollection using its ID
    shared_ptr<LibraryItem> item = libraryItemsCollection.getLibraryItemByID(id);

	//If item is found, cast it to Book and edit
    if (item) 
	{
        dynamic_pointer_cast<Book>(item)->editItem();
        cout << "Book has been updated." << endl;
    } 
	
	else 
	{
        cout << "Item not found!" << endl;
    }
}


//Deletes a book from the collection by its Library ID.  
void BooksCollection::deleteBooksCollection() 
{
    int id;
    cout << "Enter Library ID Number of book to delete: ";  // Prompt user for Book ID
    cin >> id;
	
    string idStr = to_string(id);
    
    //Search and delete in the LibraryItemsCollection
    shared_ptr<LibraryItem> item = libraryItemsCollection.getLibraryItemByID(id);
    
    if (item)  //If item is found, delete it
	{
        dynamic_pointer_cast<Book>(item)->deleteItem();
        libraryItemsCollection.deleteLibraryItem(idStr, 1);  //Remove from LibraryItemsCollection
    } 
	
	else 
	{
        cout << "Item not found!" << endl;
    }
}



//Searches for a book by its Library ID
void BooksCollection::findBooksCollection() const 
{
    int id;
    cout << "Enter Library ID Number of book to Search or Find: ";	//Prompt user for Book ID Number to search
    cin >> id;
    
	//Search by Book ID and use getLibraryID to find the Book by ID Number
    for (const auto &book : books) 
	{
        if (book.getLibraryID() == id) 
		{
            book.printItemDetails();  	//If found, the book's details are printed using printBookDetails(); 
            return;
        }
    }
    
    cout << "Library ID Number does not exist." << endl;  //If the Book ID Number does not match, it does not exist
}



//Prompt user for Book ID Number to print all Book collection
void BooksCollection::printAllBooksCollection() const 
{
    if (books.empty()) 
	{
        cout << "No books found." << endl;
        return;
    }

    for (const auto &book : books) {  //Loops through all the books in the collection and prints the details of each book by calling printBookDetails() for each book in the 'books' vector.
        book.printItemDetails();	//Output the relevant details
    }
}


//Prompt user for Book ID Number to print single Book’s collection
void BooksCollection::printSingleBook(int libraryID) const 
{
    if (books.empty()) 
	{
        cout << "No books found." << endl;
        return;
    }

    for (const auto &book : books) {  //Loops through all the books in the collection and prints the details of each book by calling printBookDetails() for each book in the 'books' vector.
        book.printItemDetails();
    }
}
