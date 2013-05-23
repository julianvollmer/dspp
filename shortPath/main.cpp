//
//  main.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//
#include "main.h"
int main(int argc, char *argv[]){
	unsigned int (*matrix)[nodenum][nodenum] = 0;
	
int eingabe = 0;

	// if(parameter_ok(argc, argv)){
		Dijkstra *dk = new Dijkstra();	
		dk->get(matrix);
		dk->setMatrix(*matrix);
		dk->setSource(8);
		dk->calculate(true);
		do{
			loesche_bildschirm_mit_header();
			eingabe = menu();
			verarbeite_eingabe(eingabe, dk);
		}while(eingabe);

	// }

	// else
		anleitung();
	

    return 0;
}

void verarbeite_eingabe(int weiter, Dijkstra *dk){
	int auswahl = 0;
	
	switch (weiter)
    {
	    case 1:
	    	dk->setSource(8);
	    break;

	    case 2: 
	        dk->trace();
	    break;

	    case 3: 
	         dk->calculate(true);
	    break;

	    case 4: 
	        load_file();

	    break;

	    default:
	    	cout << "Vielen Dank für die Nutzung!" << endl;
    } 
}

/**
 * Zeigt das Menu und erfasst die Eingabe.
 */
int menu(){
	string menuepunkte[] = 
						{
							"Zufaellig neue Knoten erstellen",
							"Knoten ausgeben",
							"Berechne kuerzesten Weg",
							"Datei einlesen"
							
						};

	int anz_punkte = sizeof(menuepunkte) / sizeof(menuepunkte[0]);

	int weiter;
		for(int i = 0; i < anz_punkte; i++)
			cout <<"(" << i+1 << ")" << menuepunkte[i] << endl;
		cout << "Druecken Sie 0 zum Beeneden" << endl;
		weiter = erfasse_int( 0, anz_punkte, "Wie moechten Sie fortfahren");
	return weiter;
}

/**
 * Prueft, ob keiner, oder der eingegeben Parameter grosser als 0 ist.
 * @param argc Anzahl der eingegeben Parameter
 * @param argv Die eingegeben Parameter
 * @return true wenn die Parameter ok sind.
 */
bool parameter_ok(int argc, char *argv[]){
	return (argc == 2 && atoi(argv[1]) > 0);
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
