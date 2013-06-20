//
//  main.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.


#include <iostream>
#include "lib/Dijkstra.h"
#include "lib/ShortPath.h"
#include "helper/random.h"
#include "helper/ausgabe.h"
#include "helper/eingabe.h"
#include "helper/load_file.h"
#include "time.h"
#include "main.h"

/**
 * Last version with array, translate it to vector.
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, char *argv[]){
	
	
	int eingabe = 0;
	number_of_graphs = 2001;
    
   if(parameter_ok(argc, argv)){
		if(argc == 2){
			number_of_graphs = atoi(argv[1]);
		}
			
		else{
			number_of_graphs = 1000;
		}
			
		
		sp->init_random(number_of_graphs);


		// sp->print();
		
		// sp->output();
		// sp->show_dk();
		 do{
		 	loesche_bildschirm_mit_header();
		 	eingabe = menu();
		 	verarbeite_eingabe(eingabe, sp);
		 }while(eingabe);


	}
	else
		anleitung();

    return 0;
}
/**
 * Verarbeitet die Eingabe
 * @param weiter Ausgewählte Menüpunkt
 * @param dk     Dijkstra Objekt mit dem gearbeitet werden soll
 */
void verarbeite_eingabe(int weiter, ShortPath *sp){
	int auswahl = 0;
	
	switch (weiter)
    {
	    
	    case 1: 
	        load_graph_from_file();
	    break;

	     case 2: 
	        do_shortpath_calculation(sp);
	    break;
	    
	    case 3: 
	        do_shortpath_calculation_mulitproc(sp);
	    break;
	    
	    case 4: 
	        set_number_of_graphs(sp);
	    break;
	    
	    case 5: 
	        set_number_of_cores(sp);
	    break;
	    
	    case 6: 
	        sp->print();
	    break;
	    
	    case 7: 
	        sp->output();
	    break;

	     case 8: 
	        write_graph_to_file(sp);
	    break;

	  


	    default:
	    	cout << "Vielen Dank für die Nutzung!" << endl;
    } 
}

void load_graph_from_file(){
	load_file();

	 sp = getShortPathObject();
}

void do_shortpath_calculation(ShortPath *sp){
	 cout << "Naive" << endl;
    start = clock();
		sp->calculate_distance();
    stop = clock();
    t = (double) (stop-start)/CLOCKS_PER_SEC;
    cout << "Run time: " << t << endl;
		
    
}

void set_number_of_graphs(ShortPath *sp){
	number_of_graphs = erfasse_int(1, 20000, "Bitte geben sie die Anzahl der zu erfassenden Graphen ein");
	sp->init_random(number_of_graphs);
}

void set_number_of_cores(ShortPath *sp){
	number_of_cores = erfasse_int(1, 16, "Bitte geben sie die Anzahl der zu erfassenden Graphen ein");
	sp->init_random(number_of_graphs);
}

void do_shortpath_calculation_mulitproc(ShortPath *sp){
	cout << "Multicore" << endl;
    start = clock();
		sp->calculate_distance_multiproc();
    stop = clock();
    t = (double) (stop-start)/CLOCKS_PER_SEC;
    cout << "Run time: " << t << endl;
}


/**
 * Zeigt das Menu und erfasst die Eingabe.
 */


int menu(){
	string menuepunkte[] = 
						{
							"Datei einlesen",
							"Kuerzte Wege (ohne Threads)",
							"Kuerzte Wege (mit Threads)",
							"Setze Anzahl der zu berechnenden Graphen",	
							"Anzahl der Threads fuer Multicore",
							"Schreibe Adjazenzmatrix auf Terminal",
							"Schreibe Wegberechnung auf Terminal",
							"Speichere Adjazenzmatrix"
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
	return (
			(argc == 2 && atoi(argv[1]) > 0 && atoi(argv[1]) < 20000) || 
			(argc == 1)
		);
}

/**
 * Zeigt die Anleitung zu dem Programm
 */
void anleitung(){
	cout << ":::ANLEITUNG:::"<<endl<<endl;
	cout << "Das Programm berechnet den kuerzesten Weg mit hilfe von mehreren Prozessoren"<<endl;
	cout << "Es kann ohne Parameter oder mit einem Paramter aufgerufen werden"<<endl;
	cout << "Wird das Programm mit einem Parameter aufgerufen muss dieser eine Zahl sein"<<endl;
	std::cout << "Diese Zahl gibt an, wie viele Knoten zufaellig erzeugt werden"<<endl;
}
