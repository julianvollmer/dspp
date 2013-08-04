#include "load_file.h"


/**
 * Why all these can't be in load_file.h ? 
 */
	int counter = 0;
	int from = 0;
	int to = 0;
	int weight = 0;
	int result;
	string tmp_result;
	int rownum = 0;
	vector<int> weights;
	ShortPath *spObject = new ShortPath;

	
/**
 * loads a file an writes it to the graph
 */
void load_file(){
	ifstream Quelldatei;                          
	Quelldatei.open("in.txt", ios_base::in);      

	char c;                               
	string input;

	while (Quelldatei.get(c)) {           
		create_nodes_from_file_char(c);
	} 
}

/**
 * Returns the ShortPath object
 * @return Returns the ShortPath object
 */

ShortPath* getShortPathObject(){
	return spObject;
}
/**
 * Check if the dataformat is correct
 * @return always :)
 */
bool validate_dataformat(){
	return true; // ;)
}
/**
 * Creates the nodes from the char of every file
 * @param c char from input file
 */
void create_nodes_from_file_char(char c){
	if(c == ' ' || c == '\n'){
		weights.push_back(string_to_number(tmp_result));
		
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
 /**
  * Adds a row to the vector
  * @param v vector to which the will be added
  */
void add_row(vector<int> v){
	Dijkstra d ;
	d.set_distance_vector(v);
	spObject->add_row(d);
}




