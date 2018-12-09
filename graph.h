//
// Created by student on 14.11.2018.
//

#ifndef PROJECT3_GRAPH_H
#define PROJECT3_GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <stack>
#include <iterator>

using namespace std;

class graph {
public:

    string input,output;
    int numberofvertix;
    int x,linenumber,edge;
    list<int>  * vertixlist;
    bool ** discovered;
    graph(string path,int,string);
    bool * notcracked;



};


#endif //PROJECT3_GRAPH_H
