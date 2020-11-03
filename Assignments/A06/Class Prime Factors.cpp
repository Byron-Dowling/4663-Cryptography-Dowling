#include "C:\\Users\byron\source\repos\Prime Number Algorithms\Prime Number Algorithms\PrimeFactors.h"
//#include "PrimeFactors.h"
#include<cmath>
#include<fstream>
#include<vector>

using namespace std;

/**
 * Public : Am_I_Prime
 *
 * Description:
 *      Determines whether a number is prime or composite by checking up
 *		to the Square Root of the number + 1 combinations of numbers. If
 *		the number is = to 0 Mod (x) then it is composite, otherwise the
 *		number is marked as prime. The function returns a bool but the
 *		actual data is pushed to the print function and the factors method
 *		is called. 
 *
 * Params:
 *      - unsigned long long int n
 *      - ofstream& outfile
 *
 * Returns:
 *      - bool
 */

bool PrimalityTesting::Am_I_Prime(unsigned long long int n, ofstream& outfile)
{
	unsigned long long int TempVal = 0;

	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 11 == 0 || n % 13 == 0)		// Capturing the common first few Primes
	{
		outfile << "The number " << n << " is Composite ";
		GetFactors(n, outfile);
		return false;
	}

	else
	{
		TempVal = (sqrt(n) + 1);	// intentional truncation

		if (n <= 1)
		{
			outfile << "The number " << n << " is neither Prime nor Composite.";
			return false;
		}

		for (int i = 2; i <= TempVal; i++)
		{
			if (n % i == 0)
			{
				outfile << "The number " << n << " is Composite ";
				GetFactors(n, outfile);
				return false;
			}

			if (i == TempVal)
			{
				outfile << "The number " << n << " is PRIME!" << endl;
				NumberisPrime = true;									// Setting this to true to assist the Print Method
				return true;
			}
		}
	}
}


/**
 * Public : GetFactors
 *
 * Description:
 *      Determines all of the factors for our test case number and then
 *		pushes them to the Factors Vector. This is achieved by starting the
 *		i increment at 2 and looping up to n and only pushing the result if it
 *		is equal to n mod 0. Not the most efficient way but the program runs
 *		fairly quickly even for large numbers.
 *
 * Params:
 *      - unsigned long long int n
 *      - ofstream& outfile
 *
 * Returns:
 *      - void
 */

void PrimalityTesting::GetFactors(unsigned long long int n, ofstream& outfile)
{
	for (int i = 2; i < n;)
	{
		if (n % i == 0)
		{
			Factors.push_back(i);			// Pushing the Factors into the Vector for further use
			i++;
		}
		else
			i++;
	}

	Are_My_Factors_Prime(outfile);
}

/**
 * Public : Are My Factors Prime
 *
 * Description:
 *      Works with the Vector of our previous calculated factors and
 *		applies similar primality testing that we did for our test case.
 *		If the factors are prime, they are pushed to the 3rd Vector called
 *		Prime Factors and are then printed to the file.
 *
 * Params:
 *      - ofstream& outfile
 *
 * Returns:
 *      - void
 */

bool PrimalityTesting::Are_My_Factors_Prime(ofstream& outfile)
{
	int Factorsize;
	int PrimeFactorsize;
	Factorsize = Factors.size();			// Size of the Factors Vector
	PrimeFactorsize = PrimeFactors.size();	// Size of the Prime Factors Vector
	bool found = false;						// Control Variable


	for (int i = 0; i < Factorsize; i++)
	{
		// Checking the common first few Primes
		if (Factors[i] == 2 || Factors[i] == 3 || Factors[i] == 5 ||
			Factors[i] == 7 || Factors[i] == 11 || Factors[i] == 13)
		{
			PrimeFactors.insert(PrimeFactors.end(), Factors[i]);
		}

		else
		{
			unsigned long long int Temp = Factors[i];
			unsigned long long int TempVal = 0;
			TempVal = (sqrt(Temp) + 2);

			for (int k = 2; k <= TempVal; k++)				// Looping through all options up to the Square Root of the factor 
			{												// + 2 and if all options aren't mod 0, then the number is Prime.

				if (Factors[i] % k == 0)					// If number if Composite
				{
					found = true;
				}

				if (k == TempVal && found == false)
				{
					PrimeFactors.push_back(Factors[i]);		// If number is prime, it's pushed to the PrimeFactors Vector
				}
			}
		}
	}

	return true;
}

/**
 * Public : Print Results
 *
 * Description:
 *      Method that is called to print the results to the outfile that
 *		was previously prompted and set by the user. A Boolean value is
 *		used to ensure that only the composite numbers are printing here
 *		as the Prime ones are directly read into the file from the Am I Prime
 *		Method.
 *
 * Params:
 *      - ofstream& outfile
 *
 * Returns:
 *      - void
 */

void PrimalityTesting::Print_Results(ofstream& outfile)
{
	if (NumberisPrime == false)							// Control Varible to Print the Composite numbers and their factors
	{
		outfile << " - Factors: ";
		for (int j = 0; j < PrimeFactors.size(); j++)
		{
			outfile << PrimeFactors[j] << " ";
		}
		outfile << endl;
	}
	Factors.clear();									// After a Print, both Vectors are cleared so they can be used again
	PrimeFactors.clear();
}

/**
 * Public : openFiles
 *
 * Description:
 *      Prompts the user to define the input and output files the program will use.
 *		I/O variables are passed by reference so their content can be edited here.
 *
 * Params:
 *      ifstream&    :  array of integers
 *      ofstream&    :  array size
 *
 * Returns:
 *      Void		 : Variables passed by reference, no return type
 */

void PrimalityTesting::openFiles(ifstream& infile, ofstream& outfile)
{
	char inFileName[40];
	char outFileName[40];

	cout << "Enter the input file name: ";
	cin >> inFileName;

	// open input file
	infile.open(inFileName);
	cout << "Enter the output file name: ";
	cin >> outFileName;

	// Open output file.
	outfile.open(outFileName);
}