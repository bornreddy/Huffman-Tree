This code is meant to emulate lossless text file compression via Huffman Encoding. 

The HuffmanEnc.cpp file, when compiled and executed, takes in a file of text as a command line paramter, analyzes its frequencies and creates a Huffman Tree for each character encountered. This is then used to construct a translated version of the file, as it appears as Huffman Codes in place of ASCII characters. (see normal1.txt). 

HuffmanDec.cpp, when compiled and executed, takes in a text file (as a command line paramter) in a specific format that lists the huffman codes for certain characters, recreates a Huffman Tree from this information, and then translates the coded message contained in the file into its ASCII representation. (See encoded1.txt). 