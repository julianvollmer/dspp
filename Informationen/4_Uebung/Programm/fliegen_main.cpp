/*
 * fliegen_main.cpp
 *
 *  Created on: 28.05.2010
 *      Author: julian
 */

#include "fliegen_main.h"


/**
 * Dies Programm dient der Simulation von einem Flugtag.
 * Es erzeugt hierfür einmal Flughaefen mit Flugzeugen und
 * simmuliert anhand dessen einen Flugtag.
 * Dafuer wechseln die Flugzeuge ihre Flughaefen und werden
 * anhand eines Zufalls mit Passagieren gefuellt.
 * Danach wird der Flugtag analysiert.
 */
int main(int argc, char *argv[]){
	if(parameter_ok(argc, argv)){
		Flugtag flgtg(atoi(argv[1]));
		flgtg.simuliere_fluege();

	}
	else
		anleitung();
	return 1;

}

/**
 * Prueft, ob der eingegeben Parameter grosser als 1 und kleiner als 30 ist.
 * @param argc Anzahl der eingegeben Parameter
 * @param argv Die eingegeben Parameter
 * @return true wenn die Parameter ok sind.
 */
bool parameter_ok(int argc, char *argv[]){

	return (atoi(argv[1]) && atoi(argv[1]) > 1 && atoi(argv[1]) <  30 && argc == 2 ) ;
	//return false;
}

/**
 * Zeigt die Anleitung zu dem Programm
 */
void anleitung(){

	cout << ":::ANLEITUNG:::"<<endl<<endl;
	cout << "Das Program muss mit einem numerischen Parameter aufgerufen werden"<<endl;
	cout << "Der Parameter gibt an wie viele Flughaefen initialisiert werden."<<endl;
	cout << "Er muss groesser als 1 und kleiner als 30 sein" <<endl;
	cout << "Beispiel: fliegen 14"<<endl;
}

