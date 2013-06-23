#include "helpers.h"

/**
 * Converts a string to integer
 * @param  str string to convert
 * @return     convertet string as integer
 */
int string_to_number(string str){
	int Result;
	stringstream convert(str);
	if ( !(convert >> Result) )
    	Result = 0;
 return Result;
}


/**
 * concat a string with an int
 * @param  str string
 * @param  i   integer to concat
 * @return     string plus integer as string
 */
string concat_string_and_int(string str, int i){
	std::stringstream sstm;
	sstm << str << i;
	return sstm.str();
}