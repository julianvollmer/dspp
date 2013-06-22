#include "load_file.h"

int counter = 0;
int from = 0;
int to = 0;
int weight = 0;
int result;
string tmp_result;
int rownum = 0;
vector<int> weights;
ShortPath *spObject = new ShortPath;

void load_file(){
	ifstream Quelldatei;                          
	Quelldatei.open("in.txt", ios_base::in);      

	char c;                               
	string input;

	while (Quelldatei.get(c)) {           
		create_nodes_from_file_char(c);
	} 
}

ShortPath* getShortPathObject(){
	return spObject;
}

void validate_dataformat(){

}

void create_nodes_from_file_char(char c){
	if(c == ' ' || c == '\n'){
		weights.push_back(string_to_number(tmp_result));
		// cout << "aktueller Wert " << tmp_result << " wurde in graph eingeführt" <<endl;
		tmp_result = "";
		if (c == '\n'){
				counter = 0;
				
				tmp_result = "";
				weights.pop_back();
				add_row(weights);
				weights.clear();
			}
	}
	else{
		tmp_result += c;
	}
	
}

void add_row(vector<int> v){
	Dijkstra d ;
	d.set_distance_vector(v);
	spObject->add_row(d);
}




