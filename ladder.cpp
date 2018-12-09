//
// Created by student on 28.11.2018.
//

#include "ladder.h"


ladder::ladder(int **p, int r, int c,int q,int fx,int fy,int tx,int ty,bool ** visited,bool ** L,bool**R,bool**U,bool**D) {
    this->visited=visited;
    this->column=c;
    this->row=r;
    this->matrix=p;
    this->Q=q;
    this->fx=fx;
    this->fy=fy;
    this->tx=tx;
    this->ty=ty;
    this->solutionL=L;
    this->solutionR=R;
    this->solutionU=U;
    this->solutionD=D;
    this->dynamicD=new int * [r];
    this->dynamicU=new int * [r];
    this->dynamicL=new int * [r];
    this->dynamicR=new int * [r];

    for(int i=0;i<row;i++){
        this->dynamicD[i]=new int[c,0];
        this->dynamicU[i]=new int[c,0];
        this->dynamicL[i]=new int[c,0];
        this->dynamicR[i]=new int[c,0];
    }
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
bool ladder::createMinimumSpanning(int fx,int fy,int tx,int ty,int ladsize) { //call with zero initially

    if(fx==tx && fy==ty)  {
        this->laddersize=ladsize;
        // cout<<"  laddersize found-> "<<ladsize<<endl;
        return true;
    }      //target acquired!

    visited[fx][fy]=true;
//(matrix[fx+1][fy]-matrix[fx][fy])
    if(ladsize<(this->laddersize)){

        if(borders(fx,fy+1) && !visited[fx][fy+1] ) { //sağa
            if (!solutionR[fx][fy + 1]) {
               int  temp = max(ladsize, abs(matrix[fx][fy + 1] - matrix[fx][fy]));
                if (createMinimumSpanning(fx, fy + 1, tx, ty, temp)) {
                    dynamicR[fx][fy+1] = temp;
                    solutionR[fx][fy+1] = true;
                }
            } else {
                ladsize= min(dynamicR[fx][fy + 1], ladsize);
                return true;
            }
        }
        if(borders(fx+1,fy) && !visited[fx+1][fy] ){ // aşağı
            if (!solutionD[fx+1][fy]) {
           int  temp=max(ladsize,abs(matrix[fx+1][fy]-matrix[fx][fy]));
            //  cout<<"aşağı";
            if(createMinimumSpanning(fx+1,fy,tx,ty,temp)){
                dynamicD[fx+1][fy] = temp;
                solutionD[fx+1][fy] = true;
            }
            }else {
                ladsize = min(dynamicD[fx+1][fy], ladsize);
                return true;
            }
        }
        if(borders(fx-1,fy) && !visited[fx-1][fy] ) { // yukarı
            if (!solutionU[fx - 1][fy]) {
                int  temp=max(ladsize,abs(matrix[fx-1][fy]-matrix[fx][fy]));
                if (createMinimumSpanning(fx - 1, fy, tx, ty,temp)) {
                    dynamicU[fx-1][fy] = temp;
                    solutionU[fx-1][fy] = true;
                } else {
                    ladsize = min(dynamicU[fx - 1][fy], ladsize);
                    return true;
                }
            }
        }
        if(borders(fx,fy-1) && !visited[fx][fy-1] ){ //sola
            if (!solutionL[fx][fy-1]) {
                int  temp=max(ladsize,abs(matrix[fx][fy-1]-matrix[fx][fy]));
                if(createMinimumSpanning(fx,fy-1,tx,ty,temp)){
                    dynamicL[fx][fy-1] = temp;
                    solutionL[fx][fy-1] = true;
                } else {
                    ladsize = min(dynamicL[fx ][fy-1], ladsize);
                    return true;
                }
                }
            }
    }
    visited[fx][fy]=false;
}

ladder::~ladder() {
    for(int i=0;i<this->row;i++){
        delete visited[i],matrix[i];
        //delete dynamic[i];
    }
}