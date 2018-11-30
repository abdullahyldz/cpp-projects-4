//
// Created by student on 28.11.2018.
//

#include "ladder.h"


ladder::ladder(int **p, int r, int c,int q,int x1,int y1,int x2,int y2,bool ** visited) {
    this->visited=visited;
    this->column=c;
    this->row=r;
    this->matrix=p;
    this->Q=q;
    this->fx=x1;
    this->fy=y1;
    this->tx=x2;
    this->ty=y2;
}
void ladder::printMatrix() {
    for(int i=0;i<row;i++){

        for(int j=0;j<column;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}
bool ladder::borders(int r, int c) {
    if(r>=0 && r<this->row && c>=0 && c<this->column)
        return true;
    return false;
}
void ladder::createMinimumSpanning(int fx,int fy) {

    if(fx==tx && fy==ty)        //target acquired!
        return;

    visited[fx][fy]=true;

    if(borders(fx+1,fy) && !visited[fx+1][fy]){
        createMinimumSpanning(fx+1,fy);
    }
    if(borders(fx-1,fy) && !visited[fx-1][fy]){
        createMinimumSpanning(fx-1,fy);
    }

    if(borders(fx,fy+1) && !visited[fx][fy+1]){
        createMinimumSpanning(fx,fy+1);
    }

    if(borders(fx,fy-1) && !visited[fx][fy-1]){
        createMinimumSpanning(fx,fy-1);
    }
    visited[fx][fy]=false;
}

ladder::~ladder() {
    for(int i=0;i<this->row;i++){
        delete visited[i],matrix[i],dynamic[i];
    }
}