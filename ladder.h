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
    ladder(int ** , int , int, int,int,int,int,int,bool**,bool**,bool**,bool**,bool** );
    int ** matrix;
    int row,column;
    bool ** visited;
    int ** dynamicR;
    int ** dynamicL;
    int ** dynamicU;
    int ** dynamicD;  //left to right
    int laddersize=INT_MAX;
    int Q,temp,temp1;
    //int laddersizesofar=INT_MAX;
    int fx,fy,tx,ty;
    void createDynamic();
    bool createMinimumSpanning(int,int,int,int,int);
    bool ** solutionR;
    bool ** solutionL;
    bool ** solutionU;
    bool ** solutionD;
    void printMatrix();
    bool borders(int ,int);
    bool isBetter(int);
    void spanCall();
};


#endif //PROJECT4_LADDER_H
