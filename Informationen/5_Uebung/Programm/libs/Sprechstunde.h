/*
 * Sprechstunde.h
 *
 *  Created on: 20.06.2010
 *      Author: jule
 */

#ifndef SPRECHSTUNDE_H_
#define SPRECHSTUNDE_H_
#include "Wochentag.h"
#include "Uhrzeit.h"
class Sprechstunde{
	private:
		Wochentag tag;
		Uhrzeit zeit;
	public:
		Sprechstunde();
		~Sprechstunde();
		void zeige_sprechstunde();
		void erfasse_sprechstunde();
		string get_sprechstunde();
};

#endif /* SPRECHSTUNDE_H_ */
