/*	Header file for the file reading portion of the interpreter
	This defines functions used for reading Brainfuck files
*/

#ifndef FILE_H_FOUND
#define FILE_H_FOUND

#include <string>
#include <fstream>
#include "file.h"

char* extract_code(std::string filename);

#endif
