/* 	Header file for machine instructions
	This has the declarations for all relevant functions
	to implement the Brainfuck virtual machine

	The virtual machine is implemented with a simple struct
	that holds an array for the memory, a reference to a pointer
	that shows what memory address we're at, and functions
	that affect the values of these variables
*/

// Once-only Header
#ifndef FILE_MACHINE_FOUND
#define FILE_MACHINE_FOUND
#define MEMORY_SIZE 30000 // Classic Brainfuck implementation has the memory array size set to 30k

typedef struct {
	unsigned char memory[MEMORY_SIZE]; // Array of characters simulating machine memory
	unsigned char *arr_ptr; // This is the "pointer" that holds the address we are currently working with
	int ptr_pos; // This is the numerical value for the pointer we are at
} bf_machine;

/*	These functions emulate the processor commands for the
	Brainfuck virtual machine.
*/

void initialize_machine(bf_machine *machine); // Initialize the machine to have 0 in all the array

void shift_right(bf_machine *machine); // Shift the pointer to the right

void shift_left(bf_machine *machine); // Shift the pointer to the left

void increment(bf_machine *machine); // Increment the value at the pointer

void decrement(bf_machine *machine); // Decrement the value at the pointer

void output_ptr(bf_machine *machine); // Output the value at the pointer as ASCII

void input_ptr(bf_machine *machine); // Take a byte as input to put at pointer

void start_loop(bf_machine *machine , char code[], int startIndex, int endIndex, int *arr_pos, int *loopc); // Starts a loop

void end_loop(bf_machine *machine, char code[], int startIndex, int endIndex, int *arr_pos, int *loopc); // Checks to see if loop should end

void output_debug(bf_machine *machine); // Outputs the current pointer and value at pointer for debugging

#endif
