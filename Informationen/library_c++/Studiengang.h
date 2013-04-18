/*
 * Studiengang.h
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#ifndef STUDIENGANG_H_
#define STUDIENGANG_H_
#include "mein_zufall.h"
#include "eingabe.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Studiengang{
	private:
		string name;
		int studiengangnr;
	public:
		Studiengang();
		virtual ~Studiengang();
		void zeige_studiengang();
		void erfasse_name();
		void erfasse_studiengangnr();
		void erfasse_studiengang();
		string get_studiengang();
};

#endif /* STUDIENGANG_H_ */
