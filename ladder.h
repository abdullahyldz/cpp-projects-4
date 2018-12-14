//
// Created by student on 28.11.2018.
//

#ifndef PROJECT4_LADDER_H
#define PROJECT4_LADDER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include<bits/stdc++.h>
#include <algorithm>
#include "limits.h"
#include "node.h"
#include <list>

using namespace std;

//struct compareLink : public std::binary_function<node*, node*, bool>
//{
//    bool operator()(const node * low, const node * high) const
//    {
//        if((high->dv -low->dv)<0){
//            return true;
//        }
//        return false;
//    }
//};

class ladder {

public:

    ~ladder();
    ladder(int,int,string,string);
    string inputtext,outputtext;
    vector<vector<node *>> matrix;
    int row,column;
    //bool ** visited;
    long long int final_ladder_height;
    void printMatrix();
    bool borders(int,int);
    vector<node*> Q_source;
    vector<node*> Q_target;
    int * solutions;
    int Q;
    list<node*> findEdge(node*);
    void dfs(node*,int);
    void union_sets(node * v,node * u);
    node* find_set(node *v);
    node * getRight(node *);
    node * getLeft(node *);
    node * getUp(node *);
    node * getDown(node *);

};


#endif //PROJECT4_LADDER_H
