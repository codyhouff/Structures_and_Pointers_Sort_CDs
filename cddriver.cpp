#include "cds.h"
#include "cd.h"
#include "song.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void inpError_fileOpen(int argv,char *argc[]); // Checks to see if the file exists and checks arguments
void Help ();                                  // Function for help menu.

int main (int argv, char** argc)
{
	inpError_fileOpen(argv,argc);              // Passes command line arguments to inpError_fileOpen to see if the file
	string artist, rating;                     // creates a string for artist and rating
	
	CDs* c2 = createCDs(argc[1]);              // Sets a CD pointer c2 to the create cds function, passing it the 2nd command line argument
	cout <<" "<< endl;                         // Outputs a space to the console
	 
	
	
	cout << "Welcome to your CD database\n";  // Outputs welcome line to console.
	int choice = 0;                           // Creates an int for the choice in menu
	
	do                                        // Do while loop for the UI
	{
		
		cout << "Enter your selection below : \n"                     // Prompts user to enter selection
			 << "1. Find the CDs by an Artist \n"
			 << "2. Sort the CD listing \n"
			 << "3. Output Sorted CD listing to 'Collections.txt' \n"
			 << "4. Help \n"
			 << "5. Exit the program \n"
			 << "Enter choice: ";
		cin >> choice;
		
		if(choice > 5 || choice < 1)                                  // Input validation for menu selection
			cout << "Invalid choice, Please try again \n" << endl;
		switch (choice)
		{
			case 1:                                                   // Case for searching by artist.			 
			 cout << "Enter an artist to obtain their CDs in the collection: "<<endl; 
			 cin >> artist;                                           // Stores string in artist
			 findCDs (c2, artist);                                    // Passes array and artist string to the findCDs function and relies on function to print to console.
			break;
			 
			case 2: 		                                          // Case that sorts all cds and displays them in console.
			 sortCDs(c2);                                                 
			 displayCDs (c2);
			break;
			
			case 3:                                                   // Case that sorts all cds and outputs them to the file "collections.txt"
                cout << "Takes approx. 1-3 min on slower computers" << endl;
				sortCDs(c2);
				outputCDs(c2);
				
              
			break;
			
			case 4:                                                   // Case that calls help function.
				Help();
			break;
			
			case 5:  
			destroyCDs (c2);      // Calls destroyCDs function while passing it c2		
			                      // Case that exits program with exit code 1.
				exit(1);
			
			break;
			
			
				
		}
		
		
		
		
	cout << " " << endl;  // Outputs a space for formatting.	
	} while(choice !=6);  // Does loop while choice doesn't equal 6
	
	
	
	
	

return 0;	              // returns 0
}	

void inpError_fileOpen(int argv,char *argc[])     //void function for detecting argument & file errors
{
	
	
	ifstream infile; // Creates ifstream object named infile
	infile.open(argc[1]); // initial open for debugging function
		if (argv !=2) //Outputs error if there are not two arguments
		{
			cerr << "Invalid arguments, command structure must include: ";
			cerr << argc[0] << " <filename>.txt\n";
			cerr << "Please enter command and try again... \n";
		exit(0);
		
		}
		while (argv == 2 && !infile) //Outputs error for file access if there are two arguments and no access to the file
			{
				cerr << "Please input a file that exists\n";
				cin >> argc[1];
				infile.open(argc[1]); // tries to open file once again to pass both booleans. 
				}

			
		infile.close(); // closes file after debugger is finished	
	
	
}

void Help () //Help function for submenu accessed from main menu
{
	int val;
	do
	{
		cout << "Welcome to the help Menu, \n"
			 << "Please select an option below \n"
			 << "1. I want to find an artist \n"
			 << "2. About the Program \n"
			 << "3. Go Back to Main Menu \n"
			 << "Enter choice: ";
		cin	>> val;
		if(val > 3 || val < 1) // Input validation for menu
			cout << "Invalid choice, Please try again \n" << endl;
	
			switch (val)
			{
					case 1: //Outputs note on better performance
						cout << "For better performance select option 2, then option 1 in the main menu \n \n";
					break;
					
					case 2: // Easter Egg Output :)
						cout << "\n \nProgram is programmed by: \n" 
							 << "Brad Northern, Cody Houff, and Roy Fox \n"
							 << "All ideas for the program goes to Doc Brown. \n"
							 << "Also, Programmers are lazy! \n"
							 << "Global variables are EVIL and MUST be stopped! :) \n \n \n";
					break;
					
					case 3:	
						
					break;
			}
	
	
	
	
	
	
	}while (val != 3); // Goes through loop if val does not equal 3
	
	
	
	
}

