#include "helpers.h"

/**
 * Converts a string to integer
 * @param  str string to convert
 * @return     convertet string as integer
 */
int string_to_number(string str){
	int Result;
	stringstream convert(str);
	if ( !(convert >> Result) )
    	Result = 0;
 return Result;
}

/**
 * Converters a integer to a string
 * @param  number number to be converted
 * @return        number as string
 */
string konvertiere_int(int number)
{
	ostringstream convert;
	convert << number;

	return convert.str();
}

/**
 * concat a string with an int
 * @param  str string
 * @param  i   integer to concat
 * @return     string plus integer as string
 */
string concat_string_and_int(string str, int i){
	std::stringstream sstm;
	sstm << str << i;
	return sstm.str();
}

/**
 * Show up the menu and fetches the user input.
 */
int menu(){
	string menuepunkte[] = 
						{
							"Datei einlesen",
							"Kuerzte Wege (ohne Threads)",
							"Kuerzte Wege (mit Threads)",
							"Setze Anzahl der zu berechnenden Knoten",	
							"Anzahl der Threads fuer Multicore",
							"Schreibe Adjazenzmatrix auf Terminal",
							"Schreibe Wegberechnung auf Terminal",
							"Speichere Adjazenzmatrix",
							"Zeige Vergleichstest",
							"Hilfe"
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
 * Shows the description of the programm
 */
void help(){
	cout << ":::ANLEITUNG:::"<<endl<<endl;
	cout << "Das Programm berechnet den kuerzesten Weg mit hilfe von mehreren Prozessoren."<<endl;
	cout << "Es kann ohne Parameter oder mit einem Paramter aufgerufen werden."<<endl;
	cout << "Wird das Programm mit einem Parameter aufgerufen muss dieser eine Zahl sein."<<endl;
	cout << "Diese Zahl gibt an, wie viele Knoten zufaellig erzeugt werden sollen."<<endl;
	cout << "Viel Freude bei der Benutzung."<<endl;
	erfasse_enter();
}

/**
 * Loads the graph from a file
 */
void load_graph_from_file(){
	sp->clear();
	load_file();
	sp = getShortPathObject();
}

/**
 * Prints the footer of the matrix.
 * @param number_of_seperator number of seperators needed.
 */
void print_footer(int number_of_seperator){
	for (int i = 0; i < number_of_seperator; i++){
		cout << '-';
	}	
	cout << endl;
}

/**
 * Prints the header of the matrix.
 * @param number_of_seperator number of seperators needed.
 */
void print_header(int number_of_seperator){
	for (int i = 0; i < number_of_seperator; i++){
		cout << '-';
	}
	cout << endl;
	cout << "| Anzahl Knoten" << "\t| " << "Single" << "\t| " << "Multi(2)" << "\t| " << "Multi(4)" << "\t| "<<endl;
	for (int i = 0; i < number_of_seperator; i++){
		cout << '-';
	}
	cout << endl;
}

