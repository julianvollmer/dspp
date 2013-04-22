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
    
    PathElement *p = new PathElement;
    p->setName("Julian");

    cout << p->getName() << endl;
 
 	PathVector *v = new PathVector;   
 	
 	v->initVector();
 	
 	v->addElement(*p);

 	v->printVector();

 	cout << liefere_ganze_zufallszahl(0,4) << endl;

    return 0;
}