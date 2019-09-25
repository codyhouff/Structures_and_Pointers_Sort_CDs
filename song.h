#if !defined SONG_H
#define SONG_H

#include <string>
#include <fstream>
using namespace std;
 
struct Song
{
	string length; // length of song, xx:xx, stored as a string
	string name; // the title of a song
};


/*
	Description: Creates a song
	Pre: NULL
	Post: initializes struct Song
*/
Song* createSong (string name, string length);

/*
	Description: Displays a song to the user
	Pre: song has been defined
	Post: NULL
*/
void displaySong (Song* s);

/*
    Description: outputs a song to "Collections.txt"
    Pre: song has been defined
    Post: NULL
*/
void outputSong (Song* s);

/*
	Description: Destroys the song in memory
	Pre: song has been initialized and defined
	Post: NULL
*/
void destroySong (Song* s);

#endif