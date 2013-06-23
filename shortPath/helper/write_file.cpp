#include "write_file.h"

/**
 * Writes a graph to a file
 * @param sp graph 
 */
void write_graph_to_file(ShortPath *sp){
	ofstream myfile;
	
	string filename = "out.txt";

	  	myfile.open(filename.c_str());		
	  	 
	  	vector<Dijkstra> d = sp->get_elements();
	  	int length_d = d.size();
	  	
	  	for(int i = 0; i < length_d; i++){
	  		vector<int> weights = d.at(i).get_distances_to_other();
	  		int length_w = weights.size();
	  		for(int j = 0; j < length_w; j++){
	  			// cout << weights.at(j) << "value" <<endl;
  				myfile << weights.at(j);	
				myfile << ' ';
				}
				myfile << '\n';
			  }
  	
	myfile.close();

}

/**
 * Check if the file is avaiable
 * @param  filename Filename to check
 * @return          always true
 */
bool is_file_aviable(string filename){
	return true;
}
