# pragma once

#include<iostream>
#include<vector>
#include<fstream>


using namespace std;

/*
 $$$$$$\     $$$$$$\      $$$$$$\  
 \_$$  _|   $$  __$$\    $$  __$$\ 
   $$ |     $$ /  $$ |   $$ /  \__|
   $$ |     $$ |  $$ |   $$ |      
   $$ |     $$ |  $$ |   $$ |      
   $$ |     $$ |  $$ |   $$ |  $$\ 
 $$$$$$\ $$\ $$$$$$  |$$\\$$$$$$  |
 \______|\__|\______/ \__|\______/                               
 */                           
                                   
class Index_Of_Coincidence
{
protected:
	int IOC;
	int Size;
	int Sequence_Text_Length;
	string CipherText;
	string ShiftedText;
	vector<string> Sequences;

public:
	Index_Of_Coincidence()
	{
		Size = 16;
		IOC = 2;
		Sequence_Text_Length = 0;
	}

	friend class Counting;
	friend class Vigenere;
};



/*
 $$\    $$\ $$\
 $$ |   $$ |\__|
 $$ |   $$ |$$\  $$$$$$\   $$$$$$\  $$$$$$$\   $$$$$$\   $$$$$$\   $$$$$$\
 \$$\  $$  |$$ |$$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\
  \$$\$$  / $$ |$$ /  $$ |$$$$$$$$ |$$ |  $$ |$$$$$$$$ |$$ |  \__|$$$$$$$$ |
   \$$$  /  $$ |$$ |  $$ |$$   ____|$$ |  $$ |$$   ____|$$ |      $$   ____|
	\$  /   $$ |\$$$$$$$ |\$$$$$$$\ $$ |  $$ |\$$$$$$$\ $$ |      \$$$$$$$\
	 \_/    \__| \____$$ | \_______|\__|  \__| \_______|\__|       \_______|
				$$\   $$ |
				\$$$$$$  |
				 \______/
 */

class Vigenere
{
protected:
	string CipherText;
	string Plaintext;
	string Key;
	int Text_Length;
	int Key_Length;		// Between 2-16
	vector<Index_Of_Coincidence> Results;


public:
	friend class Counting;
	friend class Index_Of_Coincidence;
	void openFiles(ifstream& infile, ofstream& outfile);
	void GetCipherText(string CT);
	void Start_Crackalackin();
	void Calculate_IOC(Index_Of_Coincidence& C);
};



/*
  $$$$$$\                                 $$\     $$\                     
 $$  __$$\                                $$ |    \__|                    
 $$ /  \__| $$$$$$\  $$\   $$\ $$$$$$$\ $$$$$$\   $$\ $$$$$$$\   $$$$$$\  
 $$ |      $$  __$$\ $$ |  $$ |$$  __$$\\_$$  _|  $$ |$$  __$$\ $$  __$$\ 
 $$ |      $$ /  $$ |$$ |  $$ |$$ |  $$ | $$ |    $$ |$$ |  $$ |$$ /  $$ |
 $$ |  $$\ $$ |  $$ |$$ |  $$ |$$ |  $$ | $$ |$$\ $$ |$$ |  $$ |$$ |  $$ |
 \$$$$$$  |\$$$$$$  |\$$$$$$  |$$ |  $$ | \$$$$  |$$ |$$ |  $$ |\$$$$$$$ |
  \______/  \______/  \______/ \__|  \__|  \____/ \__|\__|  \__| \____$$ |
                                                                $$\   $$ |
                                                                \$$$$$$  |
                                                                 \______/ 
 */

class Counting
{
protected:
	string Alphabet;
	float Sigma;
	int BigN;
	int Stack_Size;
	int Frequency[26];

public:

	Counting()
	{
		Alphabet = "abcdefghijklmnopqrstuvwxyz";
		Sigma = 0;
		BigN = 0;
		Stack_Size = 0;
		
		for (int i = 0; i < 26; i++)	// Initializing to all Zeros since VS wouldn't accept an initialization list with 0
		{
			Frequency[i] = 0;
		}
	}


	friend class Vigenere;
	friend class Index_Of_Coincidence;

	~Counting()
	{
		cout << "Destructor Running!" << endl;
	}
};
