/*	Implementation of machine.h functions.
	This is the bulk of the actual virtual machine,
	where all of the code executions will take place.
*/
#include <string>
#include <iostream>
#include <stdio.h> // We need this for a few C output functions
#include "machine.h"
// Private functions


// Public - machine.h functions
void shift_right(bf_machine *machine) {
	++machine->arr_ptr; // Move the pointer right by one in the array
}

void shift_left(bf_machine *machine) {
	--machine->arr_ptr; // Move the pointer left by one in the array
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
	std::cout << "Value at current pointer " << val << std::endl;
}

void input_ptr(bf_machine *machine) {
	char ch = getchar(); // Get the input from the user
	*machine->arr_ptr = ch; // Put the value into the machine.
}

void loop_segment(bf_machine *machine, char segment[]) {

}
