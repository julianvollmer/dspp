#include "meine_math.h"

/**
 * Nimmt einen Wert hoch zu sich selber.
 * @param wert der hoch sich selber genommen werden soll
 * @return Wert der hoch sich selber genommen wurde (n^n).
 * 
**/
double mypow(double wert){
	return pow(wert,wert);
}

int ggt(int a, int b)
{
    int r;
    while (b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
