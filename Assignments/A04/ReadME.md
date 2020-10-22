## Assignment #4 -A04- ADFGX Cipher
### Byron Dowling
### Description:

The intent of this program is to implement an ADFGX cipher that will both encrypt a plaintext message using the cipher and decrypt cipher text that was encrypted using the ADFGX cipher. The ADFGX cipher was a field cipher used by the German Army during World War I. It is closely related to the ADFGVX cipher. ADFGX is a fractionating transposition cipher which combined a modified Polybius square with a single columnar transposition. The cipher is named after the five possible letters used in the ciphertext: A, D, F, G and X. These letters were chosen deliberately because they sound very different from each other when transmitted via morse code. The intention was to reduce the possibility of operator error. To properly implement an ADFGX cipher, one will need two keys with non-repeating characters as well as preferred plaintext or previously encrypted cipher text.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | adfgx.py        | Main driver of my project                          |
|   2   | polybius.py     | Helper class that building the polybius square     |
|   3   | .replit         | To run the program in repl.it                      |
|   4   | encrypted.txt   | Output file for final encrypted text               |
|   5   | plaintext.txt   | Input file for beginning the encryption process    |
|   6   | cipher.txt      | Input file for beginning the decryption process    |
|   7   | decrypted.txt   | Output file for final decrypted text               |

### Instructions

- The program can be run from your machine's console or from this replit project: https://repl.it/@ByronDowling/ADFGX-Cipher-Program#adfgx.py
- The program expects an input file and output file destination, a command, either Encrypt or Decrypt, and a keyword 1 and keyword 2 with non-repeating characters

- Example Parameters:
    - `language = "python3"`
    - `run = "python3 adfgx.py input_file=encrypted.txt output_file=decrypted.txt operation=Decrypt keyword1=turing keyword2=enigma"`