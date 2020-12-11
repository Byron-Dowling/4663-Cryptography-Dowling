#include "Crypto5 Classes.h"
#include <iomanip>

using namespace std;


void Vigenere::Start_Crackalackin()
{
	Index_Of_Coincidence Cracking;
	Text_Length = CipherText.length();

	string TCT;							// TCT = Temp Cipher Text

	int KL = Cracking.IOC;				// KL = Key Length


	for (int i = 0; i < Text_Length; i++)
	{
		if (int(CipherText[i]) != 32)
		{
			TCT += CipherText[i];
		}
	}

	cout << endl << CipherText << endl;
	cout << TCT << endl;

	for (int j = 0; j < Cracking.IOC; j++)
	{
		int RT = j;						// Running Total
		string Temp = "";

		for (int k = 0; k < TCT.length(); k++)
		{
			if (RT < TCT.length())
			{
				Temp += TCT[RT];
			}

			RT = RT + KL;
		}

		cout << endl << "Temp crypto string is: " << Temp << endl;
		Cracking.Sequences.push_back(Temp);
	}

	Calculate_IOC(Cracking);
}



void Vigenere::GetCipherText(string CT)
{
	CipherText = CT;
}


void Vigenere::Calculate_IOC(Index_Of_Coincidence& C)
{
	Counting Summation;

	Summation.Stack_Size = C.Sequences.size();

	for (int i = 0; i < Summation.Stack_Size; i++)
	{
		string Temp = C.Sequences[i];

		Summation.BigN = Temp.length();

		for (int j = 0; j < Temp.length(); j++)
		{
			for (int k = 0; k < 26; k++)
			{
				if (Temp[j] == Summation.Alphabet[k])
				{
					Summation.Frequency[k] = (Summation.Frequency[k] + 1);
				}

			}
		}


		cout << endl << "Frequency distribution is as follows: ";

		for (int l = 0; l < 26; l++)
		{
			cout << Summation.Frequency[l] << " ";
		}
		cout << endl;

		float Temp_IOC = 0, small_n = 0, Num = 0, Denom = 0, Result = 0;


		for (int m = 0; m < 26; m++)
		{
			small_n = Summation.Frequency[m];

			Num = (small_n * (small_n - 1));
			Denom = (Summation.BigN * (Summation.BigN - 1));

			Temp_IOC = (Num / Denom);

			Result += Temp_IOC;
		}

		cout << "The I.O.C of the first string is " << setprecision(5) << Result << endl;

		for (int n = 0; n < 26; n++)
		{
			Summation.Frequency[n] = 0;
		}

	}
	//Summation.~Counting();	// Running Destructor once object has served its purpose
}



void Vigenere::openFiles(ifstream& infile, ofstream& outfile)
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