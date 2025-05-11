
/*

File:
AudioCD.cpp

*/

#include "AudioCD.h"
#include <iostream>

using namespace std;

//Default Constructor that initializes all member variables to default value
AudioCD::AudioCD() : LibraryItem() 
{
    artist = "Undefined";
    title = "Undefined";
    numTracks = 0;
    releaseDate = "Undefined";
    genre = "Undefined";
}

//Parametrized Constructor
AudioCD::AudioCD(string artist, string title, int numTracks, string releaseDate, string genre, int libraryID, double cost, string status, int loanPeriod)
    : LibraryItem(libraryID, cost, status, loanPeriod), artist(artist), title(title), numTracks(numTracks), releaseDate(releaseDate), genre(genre) {}

//Prompts the user to input details for a AudioCD and updates the member variables
void AudioCD::addItem() 
{
	//Prompts user for Atist Name, Title, Number of Tracks, Release Date, and Genre
	cout << "\nEnter Audio CD Details: " << endl;
	
    cout << "Enter Artist Name: ";
	cin.ignore();
    getline(cin, artist);
	
    cout << "Enter Title: ";
    getline(cin, title);
	
    cout << "Enter Number of Tracks: ";
    cin >> numTracks;
	
    cout << "Enter Release Date: ";
	cin.ignore();
    getline(cin, releaseDate);
	
    cout << "Enter Genre (Pop, Classic Rock, Classical, Christian, Jazz, New age, etc): ";
    getline(cin, genre);
	
	cout << "AudioCD has been added." << endl;
	
}

//Prompts users to modify details of an existing AudioCD
void AudioCD::editItem() 
{
	cout << "\nEnter Audio CD Details to Edit: " << endl;
	
	//If found, prompt for new values of Atist Name, Title, Number of Tracks, Release Date, and Genre
    cout << "Enter New Artist Name: ";
    getline(cin, artist);
	
    cout << "Enter New Title: ";
    getline(cin, title);
	
    cout << "Enter New Number of Tracks: ";
    cin >> numTracks;
	
    cout << "Enter New Release Date: ";
	cin.ignore();
    getline(cin, releaseDate);
	
    cout << "Enter New Genre (Pop, Classic Rock, Classical, Christian, Jazz, New age, etc): ";
    getline(cin, genre);
	
	cout << "AudioCD has been edited." << endl;
	
}

//Prompted users to delete AudioCD
void AudioCD::deleteItem() 
{
    cout << "Audio CD " << artist << " has been deleted." << endl;
}

//Prompts users to search for a AudioCD by its Title and prints its details
void AudioCD::searchItem() const 
{
    cout << "Searching for Audio CD: " << artist << endl;
}

//Output the relevant DVD details
void AudioCD::printItemDetails() const
 {
	cout << "\nAudioCD Details: " << endl;
    cout << "Artist: " << artist << endl;
    cout << "Title: " << title << endl;
    cout << "Number of Tracks: " << numTracks << endl;
    cout << "Release Date: " << releaseDate << endl;
    cout << "Genre: " << genre << endl;
}

//Get the Artist
string AudioCD::getArtist() const 
{
    return artist;  //Return the artist's name
}