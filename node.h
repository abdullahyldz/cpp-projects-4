//
// Created by student on 11.12.2018.
//

#ifndef PROJECT4_NODE_H
#define PROJECT4_NODE_H
#include <iostream>
//#include "ladder.h"
#include <list>
#include <vector>
using namespace std;
class node {
public:
    node * pv;
    int rank;
    int height;
    int x,y;
    //bool onQueue;
    bool known;
    vector<node*> edgespv;
    vector<node*> query;
    node(int,int ,int);
    node();
    ~node();
};


#endif //PROJECT4_NODE_H
