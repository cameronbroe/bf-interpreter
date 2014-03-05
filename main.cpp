#include <iostream>
#include "machine.h"

int main() {
	bf_machine instance;
	input_ptr(&instance);
	output_debug(&instance);
	return 0;
}

