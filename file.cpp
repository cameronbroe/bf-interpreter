/*	Implementation of file reader */

#include "file.h"
#include <string>
#include <fstream>


// Public functions
char* extract_code(std::string filename) {
	std::ifstream brainfuck_file;
	brainfuck_file.open(filename.c_str());
	char* code;
	if(brainfuck_file) {
		// Get the length of the file
		brainfuck_file.seekg(0, brainfuck_file.end); // Move pointer to end
		int length = brainfuck_file.tellg(); // Get positon
		brainfuck_file.seekg(0, brainfuck_file.beg); // Move pointer to beg
		
		code = new char[length]; // Initialize the array for our code
		brainfuck_file.read(code, length); // Read the code
		brainfuck_file.close(); // Close the file
	}
	return code; // Return the code
}
