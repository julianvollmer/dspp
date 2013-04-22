//
//  main.cpp
//  shortPath
//
//  Created by Julian Vollmer on 21.04.13.
//  Copyright (c) 2013 Julian Vollmer. All rights reserved.
//
#include "main.h"
int main(int argc, const char * argv[])
{

	loesche_bildschirm_mit_header();
    
    PathElement *p = new PathElement;
    p->setName("Julian");
 
 	PathVector *v = new PathVector;   
 	
 	
 	
 	v->addElement(*p);
 	v->addElement(*p);
 	v->addElement(*p);
 	v->addElement(*p);
 	v->addElement(*p);
 	v->addElement(*p);

 	v->printVector();
 	wait();	
    return 0;
}