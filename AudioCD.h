
/*

File:
AudioCD.h

*/

#ifndef AUDIOCD_H
#define AUDIOCD_H

#include "LibraryItem.h"
#include <string>

using namespace std;

class AudioCD : public LibraryItem 
{
private:
    string artist;
    string title;
    int numTracks;
    string releaseDate;
    string genre;

public:
    AudioCD();		//Default Constructor
	
	//Parametrized Constructor
    AudioCD(string artist, string title, int numTracks, string releaseDate, string genre, int libraryID, double cost, string status, int loanPeriod);
	
	//Overriding Methods from LibraryItem
    void addItem() override; 
    void editItem() override;
    void deleteItem() override;
    void searchItem() const override;
    void printItemDetails() const override;

    //Getter and Setter Methods
    string getArtist() const;
    string getTitle() const;
    int getNumTracks() const;
    string getReleaseDate() const;
    string getGenre() const;

    void setArtist(string artist);
    void setTitle(string title);
    void setNumTracks(int numTracks);
    void setReleaseDate(string releaseDate);
    void setGenre(string genre);
};

#endif
