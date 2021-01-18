# Algorithms---Huffman-Encoding-and-Decoding
The program contains several subprograms that can be used independently or together. 

1. Subprogram1 reads a .txt text file and generates a character frequency table in a .txt file. 

2. Subprogram2 reads the frequency table from the output of subprogram1 and builds a Huffman tree to output the code table for each character in a .txt file. 

3. Subprogram3A is an “experimental program” that compresses the text in string level. It reads both the text file and the code table, and replaces each character with its code, then writes the encoded file in strings of code. Clearly, the size of the compressed file is larger than the original text file.

4. Subprogram3B is also an “experimental program” that decompresses the encoded file from subprogram3A. It reads the code table and the encoded file, and uses the code table to rebuild the Huffman tree to decode the encoded file.

5. Subprogram4A is the real Huffman encoding. It reads the text file and the code table, encodes each character as its code, and writes the output file in binary level. 

6. Subprogram4B is the real Huffman decoding. It reads the encoded file from subprogram4A and the code table, uses the code table to rebuild the Huffman tree, and decodes the file.
