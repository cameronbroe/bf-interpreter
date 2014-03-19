/*	Implementation of machine.h functions.
	This is the bulk of the actual virtual machine,
	where all of the code executions will take place.
*/
#include <string>
#include <iostream>
#include <stdio.h> // We need this for a few C output functions
#include <string.h> // We need this for memset
#include "machine.h"
#include "parser.h"
// Private functions
int count(char code[]) {
	return std::string(code).length();
}

// Public - machine.h functions
void initialize_machine(bf_machine *machine) {
	machine->arr_ptr = machine->memory; // Initialize the pointer to be at the start of the array
	machine->ptr_pos = 0;
}

void shift_right(bf_machine *machine) {
	++machine->arr_ptr; // Move the pointer right by one in the array
	++machine->ptr_pos;
}

void shift_left(bf_machine *machine) {
	--machine->arr_ptr; // Move the pointer left by one in the array
	--machine->ptr_pos;
}

void increment(bf_machine *machine) {
	char *curr = machine->arr_ptr;
	++*curr; // Increment the value at arr_ptr by one
}

void decrement(bf_machine *machine) {
	char *curr = machine->arr_ptr;
	--*curr; // Decrement the value at arr_ptr by one
}

void output_ptr(bf_machine *machine) {
	char *curr = machine->arr_ptr;
	putchar(*curr); // Output the value at arr_ptr as ASCII
}

void output_debug(bf_machine *machine) {
	char *curr = machine->arr_ptr;
	int val = (int) *curr;
	std::cout << "Value at pointer " << machine->ptr_pos << " is " << val << std::endl;
}

void input_ptr(bf_machine *machine) {
	char ch = getchar(); // Get the input from the user
	*machine->arr_ptr = ch; // Put the value into the machine.
}

void loop_segment(bf_machine *machine, char code[], int startIndex, int endIndex, int *arr_pos, int *loopc) {
	char *ptr_copy = machine->arr_ptr; // Get a copy of the current pointer so we can test the value at the pointer of the array creation
	int currentIndex = startIndex;
	//(*loopc)++;
	//std::cout << "Entered loop " << *loopc << std::endl;
	while(*ptr_copy) {
		parse_char(code[currentIndex], machine, &currentIndex, code, loopc);
		currentIndex++;
		if(currentIndex >= endIndex) {
			currentIndex = startIndex; // Restart loop
		}
	}
	//std::cout << "Exited loop " << *loopc << std::endl;
	(*loopc)--;
	*arr_pos = endIndex;
}
