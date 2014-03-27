#include <iostream>
#include <string>
#include <unistd.h> // For getopt()
#include "machine.h"
#include "parser.h"
#include "file.h"
#include "syntax.h"

int code_count(char code[]) {
	return std::string(code).length();
}

int main(int argc, char* argv[]) {
	bf_machine instance;
	initialize_machine(&instance);
	int loop_count = 0;
	int *loopc = &loop_count;
	char* code;
	int c;
	bool syntax_check_only = false;
	/*if(argc > 0) {
		char* arg_val = argv[1];
		std::string file = arg_val;
		code = extract_code(file);
	}*/
	while((c = getopt(argc, argv, "c")) != -1) {
		switch(c) {
			case 'c':
				syntax_check_only = true;
				break;
		}
	}

	if(optind <= argc) {
		code = extract_code(argv[optind]);
	}
	std::string code_str = code;
	if(check_syntax(code_str) == -1) {
		if(syntax_check_only) {
			std::cout << "Syntax OK" << std::endl;
		} else {
			for(int i = 0; i < code_count(code); i++) {
				//std::cout << i << std:endl;
				parse_char(code[i], &instance, &i, code, loopc);
			}
		}
	} else {
		std::cout << "Syntax error, you have mismatched braces." << std::endl;
	}
	return 0;
}
