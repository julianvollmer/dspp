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
 * @return      Zero for 0k
 */
int main(int argc, char *argv[]){
	
	
	int eingabe = 0;
	number_of_graphs = 2001;
    
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
		anleitung();
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
	        set_number_of_cores(sp);
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
	        show_test(sp);
	    break;

	    default:
	    	cout << "Vielen Dank für die Nutzung!" << endl;
    } 
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
 * Does the short path algorithm on the given object
 * @param sp object for short path algorithm
 */
void do_shortpath_calculation(ShortPath *sp){
	 cout << "Naive " ;
    start = omp_get_wtime();
		sp->calculate_distance();
    stop = omp_get_wtime();
    t = (double) (stop-start);
    cout << "Run time: " << t << endl;
		
}

/**
 * Overrides the short path object with the number of graphs which init randomly.
 * @param sp short path to override
 */
void set_number_of_graphs(ShortPath *sp){
	number_of_graphs = erfasse_int(1, 20000, "Bitte geben sie die Anzahl der zu erfassenden Graphen ein");
	sp->init_random(number_of_graphs);
}
/**
 * Set the number of cores to calculate
 * @param sp numerb of cores for calculation.
 */
void set_number_of_cores(ShortPath *sp){
	number_of_cores = erfasse_int(1, 16, "Bitte geben sie die Anzahl der zu erfassenden Graphen ein");
	sp->init_random(number_of_graphs);
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
    cout << t;
}

void print_show_test_header(){
	cout << "Anzahl Graphen" << '\t' << "Single" << '\t' << "Multi (2)" << '\t' << "Multi (4)" << endl;
	for (int i = 0; i < 0; i++){
		cout << '-';
	}
	cout << endl;
}

void show_test(ShortPath *sp){

	print_show_test_header();
	do_one_run(sp,1000,0);

	/*
	int first_run 	= 1000;
	int second_run 	= 3000;
	int third_run 	= 5000;
	int fourth_run  = 10000;
	int fifth_run   = 20000;

	

	sp->init_random(second_run);
	cout << second_run << " Graphen werden mit einem Core berechnet"<<endl;
	do_shortpath_calculation(sp);
	cout << second_run << " Graphen werden mit 4 Cores berechnet"<<endl;
	do_shortpath_calculation_mulitproc(sp);

	sp->init_random(third_run);
	cout << third_run << " Graphen werden mit einem Core berechnet"<<endl;
	do_shortpath_calculation(sp);
	cout << third_run << " Graphen werden mit 4 Cores berechnet"<<endl;
	do_shortpath_calculation_mulitproc(sp);

	sp->init_random(fourth_run);
	cout << fourth_run << " Graphen werden mit einem Core berechnet"<<endl;
	do_shortpath_calculation(sp);
	cout << fourth_run << " Graphen werden mit 4 Cores berechnet"<<endl;
	do_shortpath_calculation_mulitproc(sp);

	sp->init_random(fifth_run);
	cout << fifth_run << " Graphen werden mit einem Core berechnet"<<endl;
	do_shortpath_calculation(sp);
	cout << fifth_run << " Graphen werden mit 4 Cores berechnet"<<endl;
	do_shortpath_calculation_mulitproc(sp);



	sp->init_random(50);
	full_path_search(sp);
	full_path_search_multi(sp);*/
	erfasse_enter();
}

void do_one_run(ShortPath *sp, int num_of_graphs, int num_of_cores){
	if(num_of_cores == 0){
		sp->init_random(num_of_graphs);
		do_shortpath_calculation(sp);
	}
	else{
		do_shortpath_calculation_mulitproc(sp);
	}

}

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

}
void full_path_search_multi(ShortPath *sp){
	omp_set_num_threads(2);

	int length = sp->get_num_of_vertices();
	
	cout << "Multicore" << endl;
    start = clock();
   	
   	#pragma omp for schedule(static)
	for (int i = 0; i < length; ++i)
	{
		sp->set_source(i);
		sp->calculate_distance_multiproc();
	}
	   stop = clock();
    t = (double) (stop-start)/CLOCKS_PER_SEC;
    cout << "Run time: " << t << endl;

}

