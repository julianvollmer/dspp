//
//  main.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//
#include "main.h"
int main(int argc, char *argv[]){
	
	int anzahl_nodes;
	PathVector *p = new PathVector();

	if(parameter_ok(argc, argv)){

		}

	else
		anleitung();
	int eingabe = 0;
	do{
			loesche_bildschirm_mit_header();
			eingabe = menu();
			verarbeite_eingabe(eingabe, p);

		// if(parameter_ok(argc, argv)){
		// 	if(argc == 1)
		// 		testing_purpose(liefere_ganze_zufallszahl(3,12));
		// 	else
		// 		testing_purpose(atoi(argv[1]));
		// }
		// else
		// 	anleitung();
		wait();
	}while(eingabe);

    return 0;
}

void verarbeite_eingabe(int weiter, PathVector *p){
	int auswahl = 0;
	
	// if(weiter == 1){
	// 	// p->add_random_elements(liefere_ganze_zufallszahl(2,3));
	// 	p->add_random_elements(2);
	// 	cout << "Neue Knoten wurden erstellt" << endl;
	// }
	// else if(weiter == 2){
	// 	p->print_vector();
	// }
	// else if()
	// else
	// 	cout << "Vielen Dank fuer die Nutzung!";

	switch (weiter)
    {
    case 1:
    	p->add_random_elements(4);
    	cout << "Neue Knoten wurden erstellt!" << endl;
    break;

    case 2: 
        p->print_vector();
    break;

    case 3: 
        p->fill();
    break;

    case 4: 
        p->print_shortest_way();
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
							"Fuelle Matrix(Fix it !!!)",
							"Berechne kuerzesten Weg",
							"irgendwas anderes"
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

