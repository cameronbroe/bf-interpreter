/*	Implementation of Brainfuck parser
	Goes through the code and executes it
*/

// Includes
#include <iostream>
#include <string>
#include "parser.h"
#include "machine.h"

void parse_char(char op, bf_machine *machine, int *arr_pos, char code[], int *loopc) {
	//std::cout << "Processing: " << op << std::endl;
	//std::cin.ignore();
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
			//std::cout << "Loop start: " << *arr_pos << std::endl;
			parse_loop(machine, code, arr_pos, loopc);
			break;
		case ']':
			//int start = get_loop_start(code, *arr_pos, *loopc);
			//std::cout << "Loop start: " << start << std::endl;
			//std::cout << "Loop end: " << *arr_pos << std::endl;
			end_loop(machine, code, 0, *arr_pos, arr_pos, loopc); 
			break;
	}
	//std::cout << op << std::endl;
}

void parse_loop(bf_machine *machine, char code[], int *arr_pos, int *loopc) {
	int start_pos = *arr_pos + 1;
	//std::cout << code[start_pos] << std::endl;
	//std::cout << *arr_pos << std::endl;
	std::string code_str = std::string (code);
	int loop_end_index = code_str.find_last_of(']');
	int temp = *loopc;
	for(int i = 0; i < temp - 1; i++) {
		loop_end_index = code_str.find_last_of(']', loop_end_index - 1);
	}
//	std::cout << loop_end_index << std::endl;
	//std::cout << loop_end_index << std::endl;
	start_loop(machine, code, start_pos, loop_end_index, arr_pos, loopc);
}

int get_loop_start(char code[], int currentPosition, int loopc) {
	std::string code_str = std::string (code);
	int loop_start_index = currentPosition;
	for(int i = 0; i < loopc; i++) {
		loop_start_index = code_str.find_last_of('[', loop_start_index);
	}
	if(loopc == 0) {
		loop_start_index = code_str.find_first_of('[');
	}
	return loop_start_index;
}
