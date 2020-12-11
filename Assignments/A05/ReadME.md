## Assignment 5 - Vigenere Cracking
### Byron Dowling
### Description:

Assignment is not currently complete according to the decsription but in C++ I have written a program that will calculate the Index of Coincidence of different keylengths to determine what is most likely the length of the key. At this point minus the dictionary attack portion, we could brute force all different shift combinations to determine which is most likely. However this is likely too advanced for my current C++ abilities. Will continue to work on it until it is complete.

### Files

|   #   | File                    | Description                                        |
| :---: | ----------------------- | -------------------------------------------------- |
|   1   | Crypto5.cpp             | Main driver of my project                          |
|   2   | Crypto5 Classes.h       | Header File with Class Definition                  |
|   3   | Crypto5 Methods.cpp     | Class Methods and Implementation                   |
|   4   | VCT1.txt                | Input file that was used to test                   |
|   5   | VCT1_Results.txt        | Output file for the results                        |



### Original Assignment Details:
<sup>Good Source: http://practicalcryptography.com/cryptanalysis/stochastic-searching/cryptanalysis-vigenere-cipher/</sup>

You will be given 1 or more encrypted files. You know the files were encrypted using the Vigenère method. You also know that the key used is an english dictionary word with a length 2-16 inclusive.

Write a python program that will 1) discover the size of that dictionary word (keylength) and then determine which word was used to encrypt your file(s).

To find the keylength you can use the `Index of Coincidence (I.C.)` described breifly below, but more thoroughly at the link provided.

### Incidence of Coincidence
<sup>Source: http://practicalcryptography.com/cryptanalysis/text-characterisation/index-coincidence/</sup>

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/ic.png" width="200">

- Where ***c=26***, 
- ***n***<sub>***i***</sub> is the frequency of each letter, 
- and ***N*** is the length of the text.

### Dictionary Attack

Using the dictionary provided [here](../../Resources/dictionary.json) and your newly discovered keylength, find all words in the dictionary of same length and proceed to brute force your way into decrypting the ciphertext. How will you know when you have achieved your decryption? Maybe this will help: https://www.python-course.eu/naive_bayes_classifier_introduction.php. You don't 
have to use the bayes classifier but it will make life easier. You could simply write your own probability function that assigns a value between 0,1 based on how many words you find in the dictionary .... expensive!

### Requirements

- You will be given one or more file(s) with an encrypted message in the file. 
- Process each file and:
  - print the key-length first
  - print the keyword when found
  - print the first 50 words of the message after decryption
- You must run your program like the following:


