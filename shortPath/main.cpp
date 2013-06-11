//
//  main.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.



#include "main.h"

/**
 * Last version with array, translate it to vector.
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, char *argv[]){
	
	
	int eingabe = 0;
	// initialisiere_zufallsgenerator();
	// if(parameter_ok(argc, argv)){
		// Dijkstra *dk = new Dijkstra();	
		ShortPath *sp = new ShortPath();
		sp->init_random();
		sp->calculate_distance();
		sp->print();
		
		sp->output();
		// do{
		// 	loesche_bildschirm_mit_header();
		// 	eingabe = menu();
		// 	verarbeite_eingabe(eingabe, dk);
		// }while(eingabe);

	// }

	// else
		anleitung();
	

    return 0;
}
/**
 * Verarbeitet die Eingabe
 * @param weiter Ausgewählte Menüpunkt
 * @param dk     Dijkstra Objekt mit dem gearbeitet werden soll
 */
// void verarbeite_eingabe(int weiter, Dijkstra *dk){
// 	int auswahl = 0;
	
// 	switch (weiter)
//     {
	    
// 	    case 1: 
// 	        load_file();

// 	    break;
// 	    case 2: 
// 	        test_new_dijkstra(dk);

// 	    break;

// 	    default:
// 	    	cout << "Vielen Dank für die Nutzung!" << endl;
//     } 
// }

/**
 * testet den Dijkstra Algo
 * @param dk Objekt mit dem gearbeitet werden soll
 */
// void test_new_dijkstra(Dijkstra *dk){
// 	dk->init_random();
//     dk->init_source();
//     dk->calculate_distance();
//     dk->output();

//     dk->print();
    
// }


/**
 * Zeigt das Menu und erfasst die Eingabe.
 */

void set_starting_point(Dijkstra *dk){
	int input = 0;
	input = erfasse_int(0, nodenum-1, "Bitte geben sie den Startpunkt ein.");
	// dk->setSource(input);
}
int menu(){
	string menuepunkte[] = 
						{
							"Datei einlesen",
							"test_new_dijkstra"
							
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
