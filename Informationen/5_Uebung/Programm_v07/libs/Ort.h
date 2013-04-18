/*
 * Ort.h
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef ORT_H_
#define ORT_H_
#include <iostream>
using namespace std;
#include "mein_zufall.h"
class Ort{
	private:
		string ortsname;
		string plz;
		//string bundesland;
		string land;
	public:
		Ort();
		string get_ort();
		string get_plz();
		string get_land();
		void erfasse_ortsname();
		void erfasse_plz();
		void erfasse_land();
		void erfasse_ort();
};

#endif /* ORT_H_ */
