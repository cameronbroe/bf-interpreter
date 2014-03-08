#include <iostream>
#include <string>
#include "machine.h"
#include "parser.h"

int code_count(char code[]) {
	return std::string(code).length();
}

int main() {
	bf_machine instance;
	initialize_machine(&instance);
	char code[] = "++[>+<-]#>#";
	for(int i = 0; i < code_count(code); i++) {
		//std::cout << i << std::endl;
		parse_char(code[i], &instance, &i, code);
	}
	return 0;
}

