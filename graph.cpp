//
// Created by student on 14.11.2018.
//

#include "graph.h"

using namespace std;

graph::graph(string path,int num,string output) {
    //ios_base::sync_with_stdio(false);
    string line;
    ifstream myfile(path);
    if (!myfile.is_open()) {
        cout << "file not opened properly!" << endl;
        return ;
    }
    this->input=path;
    this->output=output;

    this->numberofvertix = num;

    this->linenumber=1;

    this->vertixlist=new list<int>[num+1];

    this->onStack=new bool[num+1];

    this->discovered=new bool[num+1];

    this->index=new int[num+1];

    this->lowlink=new int[num+1];

    this->notcracked=new bool[num+1];

    this->backW=new int[num+1];

    for(int i=1;i<numberofvertix+1;i++){
        // this->stage[i]=-1;
        this->discovered[i]=false;
        this->notcracked[i]=false;
    }
    this->stage=new int[num+1];



    this->ind=1;

    getline(myfile, line);
    for(int p=0;p<num;p++) {

        getline(myfile, line);
        stringstream s(line);
        s >> this->x;

        for (int i = 0; i < this->x; i++) {
            s>>this->edge;
            vertixlist[this->linenumber].push_back(this->edge);
        }
        linenumber++;
    }

    myfile.close();
};






