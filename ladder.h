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
using namespace std;
struct link{
    int linkx;
    int linky;
    long long height;
};
class ladder {

public:
    link ** mylinks;
    ~ladder();
    ladder(int,int,string,string);
    string inputtext,outputtext;
    long long int ** matrix;

    int row,column;
    //bool ** visited;
    long long int final_ladder_height;
    void printMatrix();
    bool borders(int,int);
    bool isBetter(int);
    vector <int> * Q_values;
    int Q;
    void spanCall();
    void makeTree();
    void traverse(int,int,int,int);
};


#endif //PROJECT4_LADDER_H
