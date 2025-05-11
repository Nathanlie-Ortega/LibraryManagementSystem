
/*

File:
BooksCollection.h

*/

#ifndef BOOKSCOLLECTION_H
#define BOOKSCOLLECTION_H

#include <vector>
#include "Book.h"
#include "LibraryItemsCollection.h"
using namespace std;

class BooksCollection 
{
private:
    vector<Book> books;
	LibraryItemsCollection libraryItemsCollection;

//Mutators
public:
    void addBooksCollection();
    void editBooksCollection();
    void deleteBooksCollection();
    void findBooksCollection() const;
    void printAllBooksCollection() const;
    void printSingleBook(int libraryID) const;
};

#endif
