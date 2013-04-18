/*
 * bruchrechner.cpp
 *
 *  Created on: 02.05.2010
 *      Author: Veronika
 */

#include "bruchrechner.h"

void bruchrechner(Bruch a, Bruch b, string op){
	Bruch erg;

	zeige_bruch(a);
	cout << " " << op << " ";
	zeige_bruch(b);


	if (op == "-v"){
		if( a < b)
			cout << "a < b";
		if (a == b)
			cout <<"gleich";
		if (a > b)
			cout << "a > b";
	}

	else if(op == "+"){
		erg = a + b;
	}
	else if(op == "-"){
		erg = a - b;
	}


	else
		cout << endl << "dumm gelaufen" << endl;
	//zeige_bruch(a);

	erg.kuerzen();
	cout << " = ";
	zeige_bruch(erg);

}
