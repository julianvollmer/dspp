#include "helpers.h"

/**
 * Konvertiert einen string in einen int Wert.
 * @param  str string der zurück gegeben werden soll.
 * @return     Der konvertierte string als int Wert.
 */
int string_to_number(string str){
	int Result;
	stringstream convert(str);
	if ( !(convert >> Result) )
    	Result = 0;
 return Result;
}
