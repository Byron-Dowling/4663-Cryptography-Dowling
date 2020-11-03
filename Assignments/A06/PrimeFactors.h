/**
 * Class Name: PrimalityTesting
 * 
 * Description:
 *      This class implements a primality testing algorithm through various
 *		methods. Three Separate Vectors are used to handle the majority of the
 *		data including the number of test cases, the factors for each number and
 *		then which of those factors are prime. The results are written to a file.
 *		The class also has a Vector Size paramter for assistance in getting the 
 *		program running and a bool variable for control structure.
 * 
 * Public Methods:
 *      - PrimalityTesting() - default constructor
 *		- Push_TestCases(unsigned long long int num)
 *		- Push_PrimeFactors(unsigned long long int num)
 *		- SetTCVectSize()
 *		- StartTesting(ofstream& outfile)
 *		- void openFiles(ifstream& infile, ofstream& outfile)
 *		- bool Am_I_Prime(unsigned long long int n, ofstream& outfile)
 *		- void GetFactors(unsigned long long int n, ofstream& outfile)
 *		- bool Are_My_Factors_Prime(ofstream& outfile);
 *		- void Print_Results(ofstream& outfile);
 * 
 * Private Methods:
 *      - No Private or Protected methods
 * 
 * Usage: 
 * 
 *      - Read in the numbers of test cases and push to vector
 *		- Set the Test Case Vector size
 *		- Start Testing and call the method to run the various testing algorithms
 *		- After determining if a number is prime or composite, get the factors
 *		- Determine if the factors are prime or not
 *		- Print the results
 *      
 */

#pragma once
#include<iostream>
#include<vector>
using namespace std;

class PrimalityTesting
{
protected:
	vector<unsigned long long int> TestCases;
	vector<unsigned long long int> Factors;
	vector<unsigned long long int> PrimeFactors;
	double TC_Vector_Size;
	bool NumberisPrime;

public:
	PrimalityTesting()
	{
		TC_Vector_Size = 0;
		NumberisPrime = false;
	}

	void Push_TestCases(unsigned long long int num)	// As each value is read in, the method is called and the values
	{												// are pushed to the TestCases Vector to be used later
		TestCases.push_back(num);
	}

	void Push_PrimeFactors(unsigned long long int num)
	{
		Factors.push_back(num);
	}

	void SetTCVectSize()
	{
		TC_Vector_Size = TestCases.size();

	}

	void StartTesting(ofstream& outfile)
	{
		for (int i = 0; i < TC_Vector_Size; i++)	// After the Test Case Size is set, the Vector is looped through
		{											// and elements are sent one at a time to be tested and printed.
			Am_I_Prime(TestCases[i], outfile);
			Print_Results(outfile);
			NumberisPrime = false;					// Resets our Boolean control variable after each number is tested
		}
	}


	void openFiles(ifstream& infile, ofstream& outfile);
	bool Am_I_Prime(unsigned long long int n, ofstream& outfile);
	void GetFactors(unsigned long long int n, ofstream& outfile);
	bool Are_My_Factors_Prime(ofstream& outfile);
	void Print_Results(ofstream& outfile);
};