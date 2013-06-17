#include "load_file.h"

int counter = 0;
int from = 0;
int to = 0;
int weight = 0;
int result;
string tmp_result;
int rownum = 0;
vector<int> weights;
ShortPath sp;

void load_file(){
	ifstream Quelldatei;                          // neuen Lese-Stream erzeugen 
	Quelldatei.open("in.txt", ios_base::in);      // Datei_1.txt öffnen 

	if (!Quelldatei)                              // Fehler beim Öffnen? 
		cerr << "Eingabe-Datei kann nicht geöffnet werden\n"; 
	else {                                        // falls es geklappt hat ... 
		ofstream Zieldatei("out.txt");              // ja, richtig. Mit Dateinamen im Konstruktor wird die Datei implizit geöffnet 
		if (!Zieldatei)                             // Fehler beim Öffnen? 
			cerr << "Ausgabe-Datei kann nicht geöffnet werden\n"; 	
		else {                                      // falls es funktioniert hat 
			char c;                                   // und jetzt, jedes Zeichen ... 
			string input;
			while (Quelldatei.get(c)) {               // ... einzeln ... 
				// create_nodes_from_file_char(c);
				create_nodes_from_file_char_2(c);
			} 
		} 
	} 
	show_vector();
}


void show_vector(){
	cout << "my size is " << sp.size()<<endl;
}



void validate_dataformat(){

}

void create_nodes_from_file_char_2(char c){

	if(c == ' ' || c == '\n'){
		weights.push_back(string_to_number(tmp_result));
		cout << "aktueller Wert " << tmp_result << " wurde in graph eingeführt" <<endl;
		tmp_result = "";
		if (c == '\n'){
				counter = 0;
				cout <<endl<<endl<<endl<< "reihe " << rownum++ << " abgearbeitet"<< endl;
				tmp_result = "";
				add_row(weights);
				
			}
	}
	else{
		tmp_result += c;
	}
	
}

void add_row(vector<int> v){
	Dijkstra d ;
	d.set_distance_vector(v);
	sp.add_row(d);
}




void create_nodes_from_file_char(char c){
	tmp_result += c;
	if(c == ';'){
		counter++;
		switch (counter)
		    {
			    case 1:
				   from = string_to_number(tmp_result);
				   tmp_result = "";
			    break;

			    case 2:
			    	to = string_to_number(tmp_result);
			    	tmp_result = "";
			    break;
			    
			    case 3:
			    	weight = string_to_number(tmp_result);
			    	tmp_result = "";
			    break;
			    default:
			    	 cout << "Verkackt!" << endl;
		    }

		
	}
	
	if (c == '\n'){
		counter = 0;
		cout << "from " << from << " to " << to << " weight " << weight << endl;
	}
}