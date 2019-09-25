#include "cds.h"
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

void resize_CDS_Array (CDs* cds) // resize_CDS_Array function, resizes the array of CDs 
{
	
	int max = cds->maxcds;
	max = max * 2; //multiplies cd array by 2
	
	int curr = cds->numcds;
	CD** newList = new CD*[max]; // creates new cd array in heap
		
		for(int q = 0; q < curr; q++)
		{
			newList[q] = cds->cds[q];
		}
		
	delete[] cds -> cds; //deletes the old array
	cds->cds = newList; //updates the size of the old array
	cds->maxcds = max;
	
} 

CDs* createCDs(const char* filename) //createCDs fuction, creates all the CDs and 
{
	ifstream infile;
	infile.open(filename);
	
	CDs* cd = new CDs;
	
	int maxcds = 3; //starting max value
	int numcds = 0; // num cds
	cd->numcds = numcds; 
	cd->maxcds = maxcds;
		
	string length, name, artist, title, extra;		
	int year, rate, numSongs;										

	cd-> cds = new CD*[maxcds];
	
	while(!infile.eof())
	{
	
		if((cd->numcds) == (cd->maxcds))
		{
			resize_CDS_Array(cd);
		} 
		
		getline(infile, artist);
		getline(infile, title);
		infile >> year;	
		infile >> rate;	
		infile >> numSongs;	
		getline(infile, extra);
		CD* c1 = createCD (artist, title, year, rate, numSongs);
	   
		int tmp2 = cd -> numcds;
		cd -> cds[tmp2] = c1;
	
			for (int i = 0; i < numSongs; i++)
			{	
			
			getline(infile, length, ',');  //reads in song_length until a "," is reached "needs to be tested -BN"
			
			getline(infile, name);         //ignores data until "," is reached.
			addSong (c1, name, length);    //calls the addSong fuction 
		
			}
		
		cd->numcds++; //increments the number of CDs, keeps track of the total number of CDs
	}
	infile.close();
 return cd;	
}	

 
void displayCDs (CDs* cds) //displayCDs function, displays all the CDs
{

	for (int i = 0; i < cds->numcds; i++)
	{		
	displayCD(cds->cds[i]); 
	}

}
void outputCDs(CDs* cds)
{
   ofstream outF;
   outF.open("collections.txt"); //deletes old file
   outF.close();
    for (int i = 0; i < cds->numcds; i++)
	{		
	outputCD(cds->cds[i]); 
	}

    
}

CDs* sortCDs (CDs* cds) //sorts CD array inside CDs struct
{
	
	int num = cds->numcds;
	CD** newList = new CD*[num];
	CD* holder;

	
	for(int q = 0; q < num; q++)
	{
		newList[q] = cds->cds[q]; //runs through every cds array element and makes a temp newList 
	}

	
	for (int j = 0; j < num - 1; j++) 
	{	
		for (int i = 0; i < num - j - 1; i++) 
		{	
			
			if (((cds->cds[i]->artist) > (cds->cds[i+1]->artist)))  // compares t
			{ 

				holder = newList[i]; 
				newList[i] = newList[i + 1]; 
				newList[i + 1] = holder; 
 
				cds->cds = newList;
			} 
	
		}
    } 
	
	
	
return cds;
}


void destroyCDs (CDs* cds) //destroyCDs fuction, destroys all the CDs
{
	
	for (int i = 0; i < cds->numcds; i++)
	{								
	destroyCD(cds->cds[i]);  //destroys CD array at each element. 
	}
	delete cds; //deletes cds struct component
	
}

CDs* findCDs(CDs* cds, string artist) //findCDs function, finds all the CDs by a particular artist  
{

	for (int i = 0; i < cds->numcds; i++)
	{
		if(artist == cds->cds[i]->artist ) //if artist that the user specifies is equal to the artist in cd array then display that cd.
		{                                  // keeps running until all CD's with that artist are found and displayed.
		displayCD(cds->cds[i]); 
		}
	} 
	
return cds;  
}




