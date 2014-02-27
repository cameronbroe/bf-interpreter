#include <iostream>
#include "machine.h"

int main() {
	bf_machine instance;
	for(int i = 0; i < 32; i++) {
		increment(&instance);
	}
	output_debug(&instance);
	return 0;
}

