//
//  main.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//
#include "main.h"
int main(int argc, char *argv[]){
	
	int anzahl_nodes;
	PathVector *p = new PathVector();

	if(parameter_ok(argc, argv)){

		}

	else
		anleitung();
	int eingabe = 0;
	do{
			loesche_bildschirm_mit_header();
			eingabe = menu();
			verarbeite_eingabe(eingabe, p);

		// if(parameter_ok(argc, argv)){
		// 	if(argc == 1)
		// 		testing_purpose(liefere_ganze_zufallszahl(3,12));
		// 	else
		// 		testing_purpose(atoi(argv[1]));
		// }
		// else
		// 	anleitung();
		wait();
	}while(eingabe);
	
    return 0;
}

void verarbeite_eingabe(int weiter, PathVector *p){
	int auswahl = 0;
	
	switch (weiter)
    {
	    case 1:
	    	p->add_random_elements(4);
	    	cout << "Neue Knoten wurden erstellt!" << endl;
	    break;

	    case 2: 
	        p->print_vector();
	    break;

	    case 3: 
	        p->print_shortest_way();
	    break;

	    case 4: 
	        load_file();

	    case 5: 
	        test_boost();
	    break;

	    default:
	    	cout << "Vielen Dank für die Nutzung!" << endl;
    } 
}

/**
 * Zeigt das Menu und erfasst die Eingabe.
 */
int menu(){
	string menuepunkte[] = 
						{
							"Zufaellig neue Knoten erstellen",
							"Knoten ausgeben",
							"Berechne kuerzesten Weg",
							"Datei einlesen",
							"Boost testen"
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
	return (argc == 2 && atoi(argv[1]) > 0);
}



/**
 * Zeigt die Anleitung zu dem Programm
 */
void anleitung(){
	cout << ":::ANLEITUNG:::"<<endl<<endl;
	cout << "Das Programm berechnet den kuerzesten Weg mit hilfe von mehreren Prozessoren"<<endl;
	cout << "Es kann ohne Parameter oder mit einem Paramter aufgerufen werden"<<endl;
	cout << "Wird das Programm mit einem Parameter aufgerufen muss dieser eine Zahl sein"<<endl;
	cout << "Diese Zahl gibt an, wie viele Knoten zufaellig erzeugt werden"<<endl;
}

/**
 * [test_boost description] testet ob boost geht.
 */
void test_boost(){
 //create an -undirected- graph type, using vectors as the underlying containers
    //and an adjacency_list as the basic representation
    typedef adjacency_list<vecS, vecS, undirectedS> UndirectedGraph;

    //Our set of edges, which basically are just converted into ints (0-4)
    enum {A, B, C, D, E, N};
    const char *name = "ABCDE";

    //An edge is just a connection between two vertitices. Our verticies above
    //are an enum, and are just used as integers, so our edges just become
    //a std::pair<int, int>
    typedef std::pair<int, int> Edge;

    //Example uses an array, but we can easily use another container type
    //to hold our edges. 
    std::vector<Edge> edgeVec;
    edgeVec.push_back(Edge(A,B));
    edgeVec.push_back(Edge(A,D));
    edgeVec.push_back(Edge(C,A));
    edgeVec.push_back(Edge(D,C));
    edgeVec.push_back(Edge(C,E));
    edgeVec.push_back(Edge(B,D));
    edgeVec.push_back(Edge(D,E));

    //Now we can initialize our graph using iterators from our above vector
    UndirectedGraph g(edgeVec.begin(), edgeVec.end(), N);

    std::cout << num_edges(g) << "\n";

    //Ok, we want to see that all our edges are now contained in the graph
    typedef graph_traits<UndirectedGraph>::edge_iterator edge_iterator;

    //Tried to make this section more clear, instead of using tie, keeping all
    //the original types so it's more clear what is going on
    std::pair<edge_iterator, edge_iterator> ei = edges(g);
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        std::cout << "(" << source(*edge_iter, g) << ", " << target(*edge_iter, g) << ")\n";
    }

    std::cout << "\n";
    //Want to add another edge between (A,E)?
    add_edge(A, E, g);

    //Print out the edge list again to see that it has been added
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        std::cout << "(" << source(*edge_iter, g) << ", " << target(*edge_iter, g) << ")\n";
    }

    //Finally lets add a new vertex - remember the verticies are just of type int
    int F = add_vertex(g);
    std::cout << F << "\n";

    //Connect our new vertex with an edge to A...
    add_edge(A, F, g);

    //...and print out our edge set once more to see that it was added
    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        std::cout << "(" << source(*edge_iter, g) << ", " << target(*edge_iter, g) << ")\n";
    }
    
}




/*




int main(int argc, char *argv[])
{
   
}

 */



