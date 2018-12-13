//
// Created by student on 11.12.2018.
//

#ifndef PROJECT4_NODE_H
#define PROJECT4_NODE_H
#include <iostream>
#include "ladder.h"
using namespace std;
#include <list>
#include "pair.h"
class node {
public:
    node * pv;
    int dv;
    int height;
    int x,y;
    bool onQueue;
    bool known;
    list<pair*> edges;
    node(int,int ,int);
    node();
   // ~node();
};


#endif //PROJECT4_NODE_H
