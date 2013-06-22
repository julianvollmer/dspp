#include "write_file.h"


void write_graph_to_file(ShortPath *sp){
	ofstream myfile;
	
	string filename = "example";
	// if(is_file_aviable(filename)){
	  	myfile.open(filename.c_str());		
	  	 
	  	vector<Dijkstra> d = sp->get_elements();
	  	int length_d = d.size();
	  	cout <<"Size"<<length_d<<endl;
	  	
	  	for(int i = 0; i < length_d; i++){
	  		vector<int> weights = d.at(i).get_distances_to_other();
	  		int length_w = weights.size();
	  		cout << length_w<< "here it is"<< endl;

	  		for(int j = 0; j < length_w; j++){
	  			cout << weights.at(j) << "value" <<endl;
  				myfile << weights.at(j);	
				myfile << ' ';
				}
				myfile << '\n';
			  }


		// for (vector<Dijkstra>::iterator it = sp->get_elements().begin() ; it != sp->get_elements().end(); it++){
		// 	int length = it->distances.size();
		// 	cout << "length" <<length<<endl;
		// 	for(int i = 0; i < 10; i++){
		
  //   }

    

	  	
	myfile.close();
	// }
}


bool is_file_aviable(string filename){
	return true;
}
