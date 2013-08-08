//
//  main.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
#include <iostream>
#include "lib/Dijkstra.h"
#include "lib/ShortPath.h"
#include "helper/random.h"
#include "helper/ausgabe.h"
#include "helper/eingabe.h"
#include "helper/load_file.h"
#include "time.h"
#include "main.h"

/**
 * This Programm shows different implementation of solving the shortest Path Problem with Dijkstra. 
 * The different solutions realized with different Framework, mainly for multiprocessor operations.
 * @param  argc Number of Arguments
 * @param  argv Arguments given
 * @return      Zero for Ok
 */
int main(int argc, char *argv[]){
	int eingabe = 0;
	number_of_graphs = 2000;
    
   if(parameter_ok(argc, argv)){
		if(argc == 2){
			number_of_graphs = atoi(argv[1]);
		}

		sp->init_random(number_of_graphs);
		 do{
		 	loesche_bildschirm_mit_header();
		 	eingabe = menu();
		 	verarbeite_eingabe(eingabe, sp);
		 }while(eingabe);
	}
	else{
		help();
	}
	
    return 0;
}
/**
 * Handles the Input
 * @param weiter Choosen menupoint
 * @param dk     Dijkstra Objekt to work with
 */
void verarbeite_eingabe(int weiter, ShortPath *sp){
	int auswahl = 0;
	
	switch (weiter)
    {
	    
	    case 1: 
	        load_graph_from_file();
	    break;

	     case 2: 
	        do_shortpath_calculation(sp);
	    break;
	    
	    case 3: 
	        do_shortpath_calculation_mulitproc(sp);
	    break;
	    
	    case 4: 
	        set_number_of_graphs(sp);
	    break;
	    
	    case 5: 
	        set_num_of_threads(sp);
	    break;
	    
	    case 6: 
	        sp->print();
	    break;
	    
	    case 7: 
	        sp->output();
	    break;

	     case 8: 
	        write_graph_to_file(sp);
	    break;

	     case 9: 
	        show_performance_test(sp);
	    break;

	     case 10: 
	        help();
	    break;

	    default:
	    	cout << "Vielen Dank für die Nutzung!" << endl;
    } 
}


/**
 * Does the short path algorithm on the given object
 * @param sp object for short path algorithm
 */
void do_shortpath_calculation(ShortPath *sp){
    start = omp_get_wtime();
	sp->calculate_distance();
    stop = omp_get_wtime();
    t = (double) (stop-start);
    print_number_from_matrix_double(t);
		
}

/**
 * Overrides the short path object with the number of graphs which init randomly.
 * @param sp short path to override
 */
void set_number_of_graphs(ShortPath *sp){
	number_of_graphs = erfasse_int(1, 20000, "Bitte geben sie die Anzahl der zu erfassenden Knoten ein");
	sp->init_random(number_of_graphs);
}
/**
 * Set the number of threads to calculate
 * @param sp numerb of threads for calculation.
 */
void set_num_of_threads(ShortPath *sp){
	number_of_threads = erfasse_int(1, 16, "Bitte geben sie die Anzahl der zu erfassenden Knoten ein");
	sp->set_number_of_threads(number_of_graphs);
}
/**
 * Calculates the short path algorithm with multiprocessors
 * @param sp [description]
 */
void do_shortpath_calculation_mulitproc(ShortPath *sp){
    start = omp_get_wtime();
	sp->calculate_distance_multiproc();
    stop = omp_get_wtime();
    t = (double) (stop-start);
    print_number_from_matrix_double(t);
}


/**
 * Shows up the test
 * @param sp Graph to search
 */
void show_performance_test(ShortPath *sp){
	loesche_bildschirm();
	print_header(65);
	int adder =  sp->get_num_of_vertices();
	for(int i = 0; i < 10; i++){
		sp->init_random(adder);
		print_run(sp);	
		adder+=2000;
	}
	print_footer(65);
	erfasse_enter();
}
/**
 * Prints the output in the terminal.
 * @param sp Graph to print.
 */
void print_run(ShortPath *sp){
	print_number_from_matrix_int(sp->get_num_of_vertices());
	do_one_run(sp);	
	cout << "|" << endl;
}

/**
 * Does a search to the graph.
 * @param sp Graph to search.
 */
void do_one_run(ShortPath *sp){
	
	do_shortpath_calculation(sp);

	sp->set_number_of_threads(2);
	do_shortpath_calculation_mulitproc(sp);
	
	sp->set_number_of_threads(4);
	do_shortpath_calculation_mulitproc(sp);
}
/**
 * Make a full path search without multithreads.
 * @param sp graph to search
 */
void full_path_search(ShortPath *sp){
	int length = sp->get_num_of_vertices();
    start = clock();
	for (int i = 0; i < length; ++i)
	{
		sp->set_source(i);
		sp->calculate_distance();
	}
	stop = clock();
    t = (double) (stop-start)/CLOCKS_PER_SEC;
    cout<<t;
    erfasse_enter();
    loesche_bildschirm();
}

/**
 * Make a full path search with multithreads
 * @param sp graph to search
 */
void full_path_search_multi(ShortPath *sp){
	int length = sp->get_num_of_vertices();
	
    start = clock();
   	
   	#pragma omp for schedule(static)
	for (int i = 0; i < length; ++i)
	{
		sp->set_source(i);
		sp->calculate_distance_multiproc();
	}
	   stop = clock();
    t = (double) (stop-start)/CLOCKS_PER_SEC;
    cout << t;
    erfasse_enter();
    loesche_bildschirm();
}

