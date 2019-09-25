#if !defined CD_H
#define CD_H


#include <string>
#include "song.h"

using namespace std;

struct CD
{
	string artist; // A string for the artist
	string title; // A string for the title of the CD
	int year; // An integer containing the year the CD was released
	int rate; // An integer indicating the rating the CD has earned
	int numSongs; // An integer indicating the number of individual Song on the CD
	int sSize;	// An integer indicating the current number of individual Song on the CD				
	Song** songs;   
};

/*
	Description: Creates a CD
	Pre: Null
	Post: outputs a CD
	
*/
CD* createCD (string artist, string title, int year, int rate, int numSongs);//createCD prototype

/*
	Description: Displays a CD
	Pre: CD has been initilized and defined
	Post: NULL
*/
void displayCD (CD* c); //displayCD prototype
/*
    Description: outputs a CD to "collections.txt"
    Pre: CD has been initialized and defined
    Post: NULL
*/
void outputCD (CD* c); //outputCD prototype
/*
	Description: Destroys a CD from memory
	Pre: CD has been initialized and defined
	Post: NULL
*/
void destroyCD (CD* c); //destroyCD prototype
/*
		Description: " create a new Song and add that song to the songArray inside CD" - Doc Brown
		Pre: CD has been initialized and defined, two variables of type 'string' is passed.
		Post: NULL
*/
void addSong (CD* c, string name, string length); //addSong prototype


#endif