#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include "Crypto5 Classes.h"

using namespace std;


int main()
{
	ifstream in;
	ofstream out;

	Vigenere Decoder;

	Decoder.openFiles(in, out);

	string Temp;

	getline(in, Temp);
	Decoder.GetCipherText(Temp);


	Decoder.Start_Crackalackin();

	return 0;
}