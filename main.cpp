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
	char* eval_code;
	int c;
	bool syntax_check_only = false, evaluate_code = false, no_file_flag = false;
	/*if(argc > 0) {
		char* arg_val = argv[1];
		std::string file = arg_val;
		code = extract_code(file);
	}*/
	if(argc < 2) {
		no_file_flag = true;
	}
	while((c = getopt(argc, argv, "ce:")) != -1) {
		switch(c) {
			case 'c':
				syntax_check_only = true;
				break;
			case 'e':
				evaluate_code = true;
				eval_code = optarg;
				break;
			case '?':
				if(optopt == 'e') {
					std::cout << "Option -e requires an argument to evaluate." << std::endl;
				}
				return 1;
			default:
				return 0;
		}
	}
	if((optind == argc) && !evaluate_code) {
		no_file_flag = true;
	}
	if(!no_file_flag) {
		if((optind <= argc) && !evaluate_code) {
			code = extract_code(argv[optind]);
		}
		if(evaluate_code) {
			code = eval_code;
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
	} else {
		std::cout << "You didn't give me anything to interpret! ]=" << std::endl;
		return 1;
	}
	return 0;
}
