#ifndef CDS_H
#define CDS_H

#include "cd.h"

using namespace std;

struct CDs
{
	CD** cds;        // An array of CD struct.
	int numcds;	     // Number of cds.
	int maxcds;      // Max number of cds.
};

/*
Description: Creates CDs based on the passed filename.
Pre: Filename is a constant character array that contains the name of the text file holding the cd list.
Post: Returns a CDs datatype to int main.
*/ 
CDs* createCDs(const char* filename);

/*
Description: Destroys the cds that are passed to it, freeing up memory.
Pre: The var cds is of CDs datatype and contains cds.
Post: NULL
*/
void destroyCDs(CDs* cds);

/*
Description: Displays cds to the console.
Pre: The var cds is of CDs datatype and contains cds.
Post: NULL
*/
void displayCDs(CDs* cds);
/*
Description: Outputs cds to a file named "Collections.txt".
Pre: The var cds is of CDs datatype and contains cds.
Post: NULL
*/

void outputCDs(CDs* cds);
/*
Description: Sorts CDs alphabetically.
Pre: The var cds is of CDs datatype and contains cds.
Post: NULL
*/
CDs* sortCDs (CDs* cds);
/*
Description: Finds cds based on user input validation.
Pre: The var cds is of CDs datatype and contains cds.
Post: NULL

*/
CDs* findCDs(CDs* cds, string artist);


#endif