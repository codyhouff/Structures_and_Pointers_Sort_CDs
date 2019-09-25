#include "song.h"
#include <iostream>


using namespace std;



Song* createSong (string name, string length) // Function that returns a song pointer and creates a song once passed the song name and length
{	

		Song* s = new Song;
		s->length = length;
		s->name = name;
		
		return s;
}

void displaySong (Song* s) // Void function that displays song from the s object
{
 cout  << s->name << " " << s->length <<endl;
}

void outputSong (Song* s) // Void function that outputs the song to a file
{
     ofstream outF;
    outF.open("collections.txt", ios::app);
    
    outF << s->name << " " << s->length <<endl;
    outF.close();
}

void destroySong (Song* s)  // Deletes song s
{
	delete s;
}
