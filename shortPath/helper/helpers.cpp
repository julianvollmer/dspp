#include "helpers.h"

	int string_to_number(string str){

	int Result;//number which will contain the result

	stringstream convert(str);
	if ( !(convert >> Result) )//give the value to Result using the characters in the string
    	Result = 0;
 return Result;
}
