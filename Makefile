# Makefile executable (Homework4):
sum: main.o Patron.o Book.o Loan.o PatronsCollection.o BooksCollection.o LoansCollection.o LibraryItem.o AudioCD.o DVD.o LibraryItemsCollection.o
	g++ -o sum main.o Patron.o Book.o Loan.o PatronsCollection.o BooksCollection.o LoansCollection.o LibraryItem.o AudioCD.o DVD.o LibraryItemsCollection.o

# Compiling main.cpp into main.o
main.o: main.cpp Patron.h Book.h Loan.h PatronsCollection.h BooksCollection.h LoansCollection.h LibraryItem.h AudioCD.h DVD.h LibraryItemsCollection.h
	g++ -c main.cpp

# Compiling Patron.cpp into Patron.o
Patron.o: Patron.cpp Patron.h
	g++ -c Patron.cpp

# Compiling Book.cpp into Book.o
Book.o: Book.cpp Book.h LibraryItem.h
	g++ -c Book.cpp

# Compiling Loan.cpp into Loan.o
Loan.o: Loan.cpp Loan.h
	g++ -c Loan.cpp

# Compiling PatronsCollection.cpp into PatronsCollection.o
PatronsCollection.o: PatronsCollection.cpp PatronsCollection.h
	g++ -c PatronsCollection.cpp

# Compiling BooksCollection.cpp into BooksCollection.o
BooksCollection.o: BooksCollection.cpp BooksCollection.h
	g++ -c BooksCollection.cpp

# Compiling LoansCollection.cpp into LoansCollection.o
LoansCollection.o: LoansCollection.cpp LoansCollection.h
	g++ -c LoansCollection.cpp

# Compiling LibraryItem.cpp into LibraryItem.o
LibraryItem.o: LibraryItem.cpp LibraryItem.h
	g++ -c LibraryItem.cpp

# Compiling AudioCD.cpp into AudioCD.o
AudioCD.o: AudioCD.cpp AudioCD.h LibraryItem.h
	g++ -c AudioCD.cpp

# Compiling DVD.cpp into DVD.o
DVD.o: DVD.cpp DVD.h LibraryItem.h
	g++ -c DVD.cpp

# Compiling LibraryItemsCollection.cpp into LibraryItemsCollection.o
LibraryItemsCollection.o: LibraryItemsCollection.cpp LibraryItemsCollection.h
	g++ -c LibraryItemsCollection.cpp

# Clean command to remove object files and the executable:
clean:
	rm -f *.o sum
