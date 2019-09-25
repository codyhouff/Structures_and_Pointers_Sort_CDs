#include <iostream>
#include "cd.h"


using namespace std;

CD* createCD (string artist, string title, int year, int rate, int numSongs) //Create CD function that returns a CD pointer
{
	CD* c = new CD;                     
	c->artist = artist; //stores the artist in the CD struct
	c->title = title;  //stores the title in the CD struct
	c->year = year;     //stores the year in the CD struct
	c->rate = rate;      //stores the rate in the CD struct
	c->numSongs = numSongs;  //stores the total of songs in the CD struct
	c->sSize = 0;			 //stores the current number of songs in the CD struct												
	c -> songs = new Song*[numSongs];   
	return c;
}
 
 
 void addSong (CD* c, string name, string length)  //addSong fuction that adds songs to the song struct
{			
	Song* temp = createSong (name,length);  //calls the create song fuction

	int tmp = c->sSize;
	c->songs[tmp] = temp;	//creates the songs array						
	c->sSize++;	            //increments current number of songs in the CD struct
} 

void displayCD (CD* c)  // display CD fuction, displays a CD 
{
	cout<<" "<<endl;
	cout << "Artist: " << c->artist << endl;
	cout << "Title: " << c->title << endl;
	cout << "Year: " << c->year << endl;
	cout << "Rating: " << c->rate<<endl;
	
 		
		for (int i = 0; i < c->numSongs; i++)   
		{
		
		cout<< i+1<<" ";
		
		displaySong(c->songs[i]);  //calls the display song fuction
			
		
		}
	 
}

void outputCD (CD* c)   //outputCD fuction, outputs the all the CDs to a txt file
{
    ofstream outF;
    outF.open("collections.txt", ios::app);
    
    outF <<" "<<endl;
	outF << "Artist: " << c->artist << endl;
	outF << "Title: " << c->title << endl;
	outF << "Year: " << c->year << endl;
	outF << "Rating: " << c->rate<<endl;
	
 		
		for (int i = 0; i < c->numSongs; i++)
		{
        ofstream outF;
        outF.open("collections.txt", ios::app); 
		outF<< i+1<<" ";
        outF.close();
		outputSong(c->songs[i]); 
			
		
		}
    
    
    
}

void destroyCD (CD* c) // destroyCD fuction, destroys the CD array and everything in it
{
	int songNum = c->numSongs;
    
    Song** cdSongs = c->songs;
                
    for ( int i = 0; i < songNum; i++)
    {
    destroySong (cdSongs[i]);    // calls the destroy song function
    }
	
	delete c;
}