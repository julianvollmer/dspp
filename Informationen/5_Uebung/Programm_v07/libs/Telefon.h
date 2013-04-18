/*
 * Telefon.h
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#ifndef TELEFON_H_
#define TELEFON_H_
#include <iostream>
using namespace std;
class Telefon{
	private:
		string vorwahl;
		string anschluss;
	public:
		Telefon();
		void erfasse_vorwahl();
		void erfasse_anschluss();
		void erfasse_telefon();
		string get_telefon();

};

#endif /* TELEFON_H_ */
