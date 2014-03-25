#include <string>
#include <list>
/*
 * Syntax checker - Michael Irick
 * returns the index of the first error or -1 for no errors
 */
int	checkSyntax(std::string code)
{
	std::list<char> stack;
	for(int i = 0; i < (int) code.size(); i++)
	{
	    char letter = code[i];
		switch(letter)
		{
		    default: continue; //valid commands and other things are ignored
		    case '[': stack.push_back('['); break; //put the open bracket on the stack
		    case ']':
                if(stack.empty()) //if there are no brackets on the stack, error
                    return i;
                else
                    stack.pop_back(); //remove the bracket from the stack
                break;
		}
	}
	//if the stack is not, then we left a bracket open, error at the end of the code
	if(!stack.empty())
        return code.size();
    return -1; //if we got this far, we've encountered no errors, return -1
}
