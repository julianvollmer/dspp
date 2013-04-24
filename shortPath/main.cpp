//
//  main.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//
#include "main.h"
int main(int argc, char *argv[])
{
	loesche_bildschirm_mit_header();

	if(parameter_ok(argc, argv)){
		if(argc == 1)
			testing_purpose(liefere_ganze_zufallszahl(3,12));
		else
			testing_purpose(atoi(argv[1]));
		wait();
	}
	else
		anleitung();

    return 0;
}

void testing_purpose(int counter){
 PathElement *p = new PathElement;
    p->setName("Julian");
 
 	PathVector *v = new PathVector;   
 	
 	for (int i = 0; i < counter; ++i)
 	{
 		v->addElement(*p);
 	}


 	v->printVector();
}

/**
 * Prueft, ob der eingegeben Parameter grosser als 1 und kleiner als 30 ist.
 * @param argc Anzahl der eingegeben Parameter
 * @param argv Die eingegeben Parameter
 * @return true wenn die Parameter ok sind.
 */
bool parameter_ok(int argc, char *argv[]){

	return (argc == 1 || (atoi(argv[1]) && argc == 2)) ;
	//return false;
}

/**
 * Zeigt die Anleitung zu dem Programm
 */
void anleitung(){

	
	cout << ":::ANLEITUNG:::"<<endl<<endl;
	cout << "Das Programm berechnet den kuerzesten Weg mit hilfe von mehreren Prozessoren"<<endl;
	cout << "Es kann ohne Parameter oder mit einem Paramter aufgerufen werden"<<endl;
	cout << "Wird das Programm mit einem Parameter aufgerufen muss dieser eine Zahl sein"<<endl;
	cout << "Diese Zahl gibt an, wie viele Knoten zufaellig erzeugt werden"<<endl;
}

