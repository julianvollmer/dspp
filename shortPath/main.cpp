//
//  main.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//
#include "main.h"
int main(int argc, char *argv[]){
	
	unsigned int test[nodenum][nodenum] = {
		{   0,  15, INF, INF, INF, INF, INF, INF, INF },
		{  15,   0, INF,  30,  10, INF,  25,  10,  30 },
		{ INF, INF,   0,  20, INF, INF,  15, INF, INF },
		{ INF,  30,  20,   0, INF, INF, INF, INF, INF },
		{ INF,  10, INF, INF,   0,  40,  10, INF, INF },
		{ INF, INF, INF, INF,  40,   0,  20, INF, INF },
		{ INF,  25,  15, INF,  10,  20,   0, INF, INF },
		{ INF,  10, INF, INF, INF, INF, INF,   0,  10 },
		{ INF,  30, INF, INF, INF, INF, INF,  10,   0 }
	};

    Dijkstra *blubb = new Dijkstra();

    //int matrix = blubb->generateMatrix();
    // Matrix setzen
    blubb->setMatrix(test);

    // Startknoten setzen
    blubb->setSource(8);

    // Algorithmus ausführen
    blubb->calculate(true);

    // Günstigste Wege aufzeigen
    blubb->trace();

	
 
    int (*matrix)[10][20] = 0;
    blubb->get(matrix);
 
        (*matrix)[2][3] = 25; /// ZUGRIFF

    system("Pause");

	
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
		//wait();
	}while(eingabe);
	
    return 0;
}

void verarbeite_eingabe(int weiter, PathVector *p){
	int auswahl = 0;
	
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
	        p->print_shortest_way();
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
