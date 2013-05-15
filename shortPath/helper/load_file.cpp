#include "load_file.h"

int counter = 0;
int from = 0;
int to = 0;
int weight = 0;
int result;
string tmp_result;
	

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
				create_nodes_from_file_char(c);
				// if(c == ';'){
				// 	cout << input;
				// 	input = "";
				// }
				// else{
				// 	input += c;	
				// }
				// if(c == '\n'){
				// 	cout << " neue Zeile" << endl;
				// }

				// Zieldatei.put(c);                       // ... in die Zieldatei schreiben. 
			} 
		} 
	} 
}


void validate_dataformat(){

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