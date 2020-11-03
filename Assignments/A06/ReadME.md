## Assignment #6 -A06- Prime Factors
### Byron Dowling
### Description:

Given a somewhat large number, determine if it is prime or if it can be factored. If it can be factored print out the prime factors. Since this program was done in C++ there is a method to prompt the user to type in the input and output file destinations to run the program. ***Important*** within the Class Prime Factors program, the file would not run in Visual Studio without a full path to C so that is included and the include "PrimeFactors.h" will need to be uncommented out to run the program.

### Files

|   #   | File                    | Description                                        |
| :---: | ----------------------- | -------------------------------------------------- |
|   1   | Get Prime Factors.cpp   | Main driver of my project                          |
|   2   | PrimeFactors.h          | Header File with Class Definition                  |
|   2   | Class Prime Factors.cpp | Class Methods and Implementation                   |
|   3   | numbers.txt             | Input file that was used to test                   |
|   3   | output.txt              | Output file for the results                        |


### Instructions

- The program can be run from your machine's console or from this replit project: https://repl.it/@ByronDowling/Prime-Factors-C#main.cpp
- The program expects an input file and output file destination
- The program is broken up into three parts with main residing in "Get Prime Factors"
- The file "Prime Factors" is the class definition that drives the functionality of the program
- The file "Class Prime Factors" has the Class methods that implement the primality testing algorithms

Example Input
```
231697363
709
246641520131
72490732415291
```

Example Output
```
Name: Joe Sue

Number 1: 231697363 - Factors: 419 * 607 * 911
Number 2: 709 - Prime
Number 3: 246641520131 - ???
Number 4: 72490732415291 - Factors: 249089 * 147503 * 1973
```
