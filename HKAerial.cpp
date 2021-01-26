/*
	Bryan Jeremy
	24JAN2021
	Assignment - Skynet::HK-Aerial
	CSC215 - Intro to C/C++ programming

	Program requirements:
		* 8x8 grid formation consisting of 64 blocks
		* program keeps track of each turn (to be displayed)
		* program should use binary search pattern (unpredictable)
		* program should loop until enemy location is found
		* display enemy found location
		* display how many tries to get there before finding enemy
		* display grid location of enemy
		* display the size of search grid
*/
// preprocessor directives
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
// global directives
using std::cout;
using std::endl;
using std::cin;
using std::string;
// the one and only mandatory function in C++ programs
int main()
{
	// random seed generator
	// seed random number generator
	srand(static_cast<unsigned int>(time(0)));
	// initializing and declaring random number between 1 and 64
	int randomNumber = (rand() % 64) + 1;
	// initializing and declaring variable to count number of attempts used by program to find target location
	int gridCount = 0;
	// initializing and declaring an array variable of 64 int to represent an 8 x 8 grid
	int gridArray[64] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64 };
	// initializing and declaring an array variable of 64 strings to be used as grid location names
	string gridMatch[64] =
	{
		"1A", "1B", "1C", "1D", "1E", "1F", "1G", "1H",
		"2A", "2B", "2C", "2D", "2E", "2F", "2G", "2H",
		"3A", "3B", "3C", "3D", "3E", "3F", "3G", "3H",
		"4A", "4B", "4C", "4D", "4E", "4F", "4G", "4H",
		"5A", "5B", "5C", "5D", "5E", "5F", "5G", "5H",
		"6A", "6B", "6C", "6D", "6E", "6F", "6G", "6H",
		"7A", "7B", "7C", "7D", "7E", "7F", "7G", "7H",
		"8A", "8B", "8C", "8D", "8E", "8F", "8G", "8H"
	};

	// initializing and declaring an int variable for binary search low number
	int searchGridLowNumber = 0;
	// initializing and declaring an int variable for binary search high number
	int searchGridHighNumber = sizeof(gridArray) / sizeof(gridArray[0]);
	// initializing and declaring an int variable for binary search potential target location 
	int targetLocationPrediction = 0;
	// initializing and declaring a char variable for replay option
	char playAgain = 'Y';

	// INTRODUCTION TO SKYNET HK-AERIAL
	cout << "Initializing Skynet HK-Aerial program... " << endl;
	cout << "Displaying 8 x 8 Targeting Grid... \n" << endl;

	
	// DISPLAY AN 8 X 8 GRID to make it easier to code data for location array
	// initializing and declaring a char array for 8x8 grid display
	char rows[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	// initializing and declaring an int array for 8x8 grid display
	int columns[8] = { 1,2,3,4,5,6,7,8 };
	// nested for loops that create an 8x8 grid
	// we want 8 columns, start from (index 0) 1, up to (index 7) 8
	for (int i = 0; i < 8; i++)
	{
		// we want 8 rows, start from (index 0) 1, up to (index 7) 8
		for (int j = 0; j < 8; j++)
		{
			cout << columns[i] << rows[j] << " ";
		}
		// after outputting 8 columns, continue on next line
		cout << endl;
	}
	cout << "\n";
	


	// MATCH RANDOM NUMBER TO A GRID LOCATION
	// initializing and declaring an int variable with the value of the seeded random number
	int secretGridLocationTemp = randomNumber;
	// initializing and declaring a string variable with the value of the array index that could be a potential target
	string gridLocation = gridMatch[secretGridLocationTemp];

	// TARGET LOCATION/ATTEMPT COUNT
	// binary search algorithm: cuts array in half
	targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
	// if statement used to determine how close to target
	// if the initial prediction is the target...
	if (targetLocationPrediction == randomNumber)
	{
		// ... add to the number of attempts at finding a target (this would be the first and only attempt, if correct)
		gridCount++;
		cout << "The A.I. application took " << gridCount << " attempt to locate the rebel forces.\n" << endl;
		cout << "\nThe rebel forces were located at grid location " << randomNumber << "\n" << endl;
	}
	else
	{
		// increment the count of attempts to acquire target
		gridCount++;
		// if the initial prediction is incorrect, do this as long as the target location remains unacquired (while loop)
		while (targetLocationPrediction != randomNumber)
		{
			// ...and the prediction is greater than the actual target location do this...
			if (targetLocationPrediction > randomNumber)
			{
				// init and decl a string variable equivalent to the value of the results of attempted target acquisition
				string currentPredictionLocation = gridMatch[targetLocationPrediction];
				// increment the attempts at target acquisition
				gridCount++;
				cout << "The HK_Aerial Targeting algorithm determined grid location " << targetLocationPrediction << "/" << currentPredictionLocation << " as high probability.\n\t[No target acquired.]" << endl;
				// change the value of the binary search HIGH number to the value of the target location prediction number
				searchGridHighNumber = targetLocationPrediction;
				// run the binary search with new high number
				targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
			}
			else
			{
				// change the value of string variable to the value of the results of attempted target acquisition
				string currentPredictionLocation = gridMatch[targetLocationPrediction];
				// increment the attempts at target acquisition
				gridCount++;
				cout << "The HK_Aerial Targeting algorithm determined grid location " << targetLocationPrediction << "/" << currentPredictionLocation << " as high probability.\n\t[No target acquired.]" << endl;
				// change the value of the binary search LOW number to the value of the target location prediction number
				searchGridLowNumber = targetLocationPrediction;
				// run the binary search with new LOW number
				targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
			}
		}
	}

	cout << "\n";
	cout << "The Skynet HK-Aerial application took " << gridCount << " attempts to locate enemy forces." << endl;
	cout << "The current enemy grid location is: " << secretGridLocationTemp << "/" << gridLocation << "\n";
	cout << "Dispatching forces to grid location " << secretGridLocationTemp << "/" << gridLocation << "\n" << endl;

	// change values of gridMatch[] to ##s, except for gridLocation number, for the purpose of easier viewing
	// go thru a values of the 8x8 grid, change every value that is not the target location to ##
	for (int i = 0; i < 64; i++)
	{
		if (gridMatch[i] != gridLocation)
		{
			gridMatch[i] = "##";
		}
		else
		{
			// keep target location value as value
			string temp = gridMatch[i];
		}
	}
	
	// VISUAL GRID DISPLAY FORMATTING
	// initialize and declare a size_t array for columns
	size_t i{};
	// while the size of the grid is smaller than the size of the array...
	while (i < sizeof(gridMatch) / sizeof(gridMatch[0]))
	{
		// initialize and declare a size_t array for rows
		size_t j{};
		// keep row length to 8
		while (j < 8)
		{
			// as long as the row length is less than 8, print value of index to console
			cout << gridMatch[i] << " ";
			// increment column count
			++i;
			// increment row count
			++j;
		}
		cout << "\n";
	}

	cout << "\nWould you like to target the next enemy force location?  Y or N: \n" << endl;
	cin >> playAgain;
	// ask player if he/she wishes to play again
	// if user input does not equal the value of variable 'playAgain' exit the program
	if (playAgain != 'Y')
	{
		exit(0);
	}
	// if user inputs an uppercase 'Y', reacquire a new target
	else
	{
		cout << "\n" << endl;
		main();
	}
	// the main function expects an integer
	return 0;
}