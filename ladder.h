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
using namespace std;
//struct link{
//    //link* pv;
//    int linkx,linky;
//    long long height;
//};
struct compareLink : public std::binary_function<node*, node*, bool>
{
    bool operator()(const node * low, const node * high) const
    {
        if((high->dv -low->dv)<0){
            return true;
        }
        return false;
    }
};

class ladder {

public:
    priority_queue< node*, std::vector<node*>,compareLink> treeQueue;
    void dfs(node*);
    void prims();
    void createEdge();
    ~ladder();
    ladder(int,int,string,string);
    string inputtext,outputtext;
    vector<vector<node *>> matrix;
    int row,column;
    bool ** visited;
    long long int final_ladder_height;
    void printMatrix();
    bool borders(int,int);
    int ** Q_values;
    int * solutions;
    int Q;
    void spanCall();
    void makeTree();
    void traverse(int,int,int,int);

    node * getRight(node *);
    node * getLeft(node *);
    node * getUp(node *);
    node * getDown(node *);

};


#endif //PROJECT4_LADDER_H
