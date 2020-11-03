///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Byron Dowling
// Email:            byrondowling7@gmail.com
// Label:            P01
// Title:            Prime Factors and Primality Testing
// Course:           4663
// Semester:         Fall 2020
//
// Description:
//       Test various numbers to determine if they are prime or composite.
//		 If the number is composite, list its prime factors.
//
// Usage:
//       Could be used to verify if a number if prime within the range of
//		 numbers that are within the limits of an unsigned long long int.
//
// Files:           
//       Get Prime Factors.cpp
//		 PrimeFactors.h
//		 Class Prime Factors.cpp
//       numbers.txt
//       output.txt
//
///////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include "PrimeFactors.h"
#include<fstream>

using namespace std;

int main()
{
	PrimalityTesting Run1;				// Declaring Class object to start the program

	ifstream in;
	ofstream out;
	Run1.openFiles(in, out);			// Calling function to set I/O files

	unsigned long long int TempVar = 0;	// Largest int value available


	if (!in)							// Error Control: If file isn't opened successfully
	{
		cout << "file not found" << endl;
		system("pause");
		exit(1);
	}


	while (!in.eof())					// Reading until the end of the file
	{
		in >> TempVar;					// Temp variable read from file
		Run1.Push_TestCases(TempVar);	// Pushing the temp variable to our TestCases Vector
	}

	Run1.SetTCVectSize();				// Setting the size of the vector after the reading is complete  

	Run1.StartTesting(out);				// Calls Method to begin Primality testing
										// Passes our outfile stream so results can be printed

	Run1.Print_Results(out);			// Calling Print function to print remaining results
	return 0;

}