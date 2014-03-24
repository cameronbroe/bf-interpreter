/*	Header file for parsing Brainfuck code
	This file takes Brainfuck code as a string or
	character array and parses the code on the virtual
	machine. This file is also used for the syntax checker
*/

// Once-only Header
#ifndef FILE_PARSER_FOUND
#define FILE_PARSER_FOUND

// Includes
#include "machine.h" // We need the VM code so we can execute each "statement"

void parse_char(char op, bf_machine *machine, int *arr_pos, char code[], int *loopc);

void parse_loop(bf_machine *machine, char code[], int *arr_pos, int *loopc);

int get_loop_start(char code[], int currentPosition, int loopc);

#endif
