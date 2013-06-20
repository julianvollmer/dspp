#include "write_file.h"


void write_graph_to_file(ShortPath *sp){
	ofstream myfile;
	
	string filename = "example";
	// if(is_file_aviable(filename)){
	  	myfile.open(filename.c_str());		
	  	 
		for (vector<Dijkstra>::iterator it = sp->get_elements().begin() ; it != sp->get_elements().end(); ++it){
			int length = it->get_length();
			for(int i = 0; i < length; i++){
			 
			myfile << it->get_distance_from_specific(i); 
			myfile << ' ';
			}
			myfile << '\n';
    }

    

	  	
	myfile.close();
	// }
}


bool is_file_aviable(string filename){
	return true;
}
