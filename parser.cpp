/*	Implementation of Brainfuck parser
	Goes through the code and executes it
*/

// Includes
#include <iostream>
#include <string>
#include "parser.h"
#include "machine.h"

void parse_char(char op, bf_machine *machine, int *arr_pos, char code[], int *loopc) {
	switch(op) {
		case '+':
			increment(machine);
			break;
		case '-':
			decrement(machine);
			break;
		case '>':
			shift_right(machine);
			break;
		case '<':
			shift_left(machine);
			break;
		case '#':
			output_debug(machine);
			break;
		case '.':
			output_ptr(machine);
			break;
		case ',':
			input_ptr(machine);
			break;
		case '[':
			start_loop(machine, code, 0, 0, arr_pos, loopc);
			break;
		case ']':
			end_loop(machine, code, 0, *arr_pos, arr_pos, loopc); 
			break;
	}
}
