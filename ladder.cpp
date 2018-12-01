//
// Created by student on 28.11.2018.
//

#include "ladder.h"


ladder::ladder(int **p, int r, int c,int q,int fx,int fy,int tx,int ty,bool ** visited) {
    this->visited=visited;
    this->column=c;
    this->row=r;
    this->matrix=p;
    this->Q=q;
    this->fx=fx;
    this->fy=fy;
    this->tx=tx;
    this->ty=ty;
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
    if(r>=0 && r<(this->row) && c>=0 && c<(this->column))
        return true;
    return false;
}

void ladder::spanCall() {
    createMinimumSpanning(this->fx,this->fy,this->tx,this->ty,0);
}
void ladder::createMinimumSpanning(int fx,int fy,int tx,int ty,int ladsize) { //call with zero initially

    if(fx==tx && fy==ty)  {
        this->laddersize=ladsize;
       // cout<<"  laddersize found-> "<<ladsize<<endl;
        return;
    }      //target acquired!

    visited[fx][fy]=true;
//(matrix[fx+1][fy]-matrix[fx][fy])
    if(ladsize<(this->laddersize)){
    if(borders(fx-1,fy) && !visited[fx-1][fy] ){
        //ladsize=;
       // cout<<"yukarı";
        createMinimumSpanning(fx-1,fy,tx,ty,max(ladsize,abs(matrix[fx-1][fy]-matrix[fx][fy])));
    }
    if(borders(fx+1,fy) && !visited[fx+1][fy] && (ladsize<(this->laddersize))){
        //ladsize=;
      //  cout<<"aşağı";
        createMinimumSpanning(fx+1,fy,tx,ty,max(ladsize,abs(matrix[fx+1][fy]-matrix[fx][fy])));
    }
    if(borders(fx,fy+1) && !visited[fx][fy+1] && (ladsize<(this->laddersize))){
       // ladsize=;
       // cout<<"sağa";
        createMinimumSpanning(fx,fy+1,tx,ty,max(ladsize,abs(matrix[fx][fy+1]-matrix[fx][fy])));
    }

    if(borders(fx,fy-1) && !visited[fx][fy-1] && (ladsize<(this->laddersize))){
        //ladsize=;
       // cout<<"sola";
        createMinimumSpanning(fx,fy-1,tx,ty,max(ladsize,abs(matrix[fx][fy-1]-matrix[fx][fy])));
    }}
    visited[fx][fy]=false;
}

ladder::~ladder() {
    for(int i=0;i<this->row;i++){
        delete visited[i],matrix[i];
                //delete dynamic[i];
    }
}