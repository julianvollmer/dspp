/*
 * professor.h
 *
 *  Created on: 12.06.2010
 *      Author: jule
 */

#ifndef PROFESSOR_H_
#define PROFESSOR_H_
#include "Sprechstunde.h"
#include "Fachbereich.h"
#include "Studiengang.h"
#include "Person.h"
class Professor : public Person{
private:
	Fachbereich fb;
	Studiengang stg;
	Sprechstunde spr;

public:
	Professor();
	virtual ~Professor();
	virtual void zeige_person();
	virtual void erfasse_person();
};

#endif /* PROFESSOR_H_ */
