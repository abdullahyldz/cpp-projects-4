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
using namespace std;
class ladder {

public:
    ~ladder();
    ladder(int ** , int , int, int,int,int,int,int,bool** );
    int ** matrix;
    int row,column;
    bool ** visited;
    //int ** dynamic;  //left to right
    int laddersize=INT_MAX;
    int Q;
    //int laddersizesofar=INT_MAX;
    int fx,fy,tx,ty;
    void createDynamic();
    void createMinimumSpanning(int,int,int,int,int);
    void printMatrix();
    bool borders(int ,int);
    bool isBetter(int);
    void spanCall();
};


#endif //PROJECT4_LADDER_H
