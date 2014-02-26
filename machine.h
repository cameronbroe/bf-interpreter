/* 	Header file for machine instructions
	This has the declarations for all relevant functions
	to implement the Brainfuck virtual machine

	The virtual machine is implemented with a simple struct
	that holds an array for the memory, a reference to a pointer
	that shows what memory address we're at, and functions
	that affect the values of these variables
*/

#define MEMORY_SIZE 30000 // Classic Brainfuck implementation has the memory array size set to 30k

typedef struct {
	char memory[MEMORY_SIZE]; // Array of characters simulating machine memory
	char *arr_ptr; // This is the "pointer" that holds the address we are currently working with
} bf_machine;

/*	These functions emulate the processor commands for the
	Brainfuck virtual machine.
*/

void shift_right(struct bf_machine *machine); // Shift the pointer to the right

void shift_left(struct bf_machine *machine); // Shift the pointer to the left

void increment_ptr(struct bf_machine *machine); // Increment the value at the pointer

void decrement_ptr(struct bf_machine *machine); // Decrement the value at the pointer

void output_ptr(struct bf_machine *machine); // Output the value at the pointer as ASCII

void input_ptr(struct bf_machine *machine); // Take a byte as input to put at pointer

void loop_segment(struct bf_machine *machine, char[] segment); // Loops a given segment of code.

void output_debug(struct bf_machine *machine); // Outputs the current pointer and value at pointer for debugging
