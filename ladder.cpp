//
// Created by student on 28.11.2018.
//

#include "ladder.h"


ladder::ladder(int row, int column , string inp, string out) {

    this->row=row;
    this->column=column;
    this->inputtext=inp;
    this->outputtext=out;

    int x,y;
    ifstream myfile(this->inputtext);
    if(!myfile.is_open()){
        cout<<"couldn't open it!!"<<endl;
        return ;
    }
    myfile>>x>>y;
    matrix=new long long int* [row];
   // visited=new bool *[row];
    mylinks=new link*[row];
    for(int i=0;i<row;i++){
        matrix[i]=new long long int [column];
        //visited[i]=new bool [column,false];
        mylinks[i]=new link[column];

    }


    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            myfile>>matrix[i][j];
            mylinks[i][j].height=LONG_LONG_MAX;
        }
    }
    myfile>>this->Q;
    Q_values=new vector<int>[this->Q];

    for(int i=0;i<this->Q;i++)
        myfile>>Q_values[i][0]>>Q_values[i][1]>>Q_values[i][2]>>Q_values[i][3];

    this->final_ladder_height=LONG_LONG_MAX;
}

void ladder::makeTree() {

    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->column; j++) {


            if (borders(i + 1, j)) { //down
                if (abs(matrix[i][j] - matrix[i + 1][j]) < mylinks[i][j].height) {
                    mylinks[i][j].linkx = i + 1;
                    mylinks[i][j].linky = j;
                    mylinks[i][j].height=abs(matrix[i][j] - matrix[i + 1][j]);
                }//update link
                //border if
            }
            if (borders(i - 1, j)) { //up
                if (abs(matrix[i][j] - matrix[i - 1][j]) < mylinks[i][j].height) {
                    mylinks[i][j].linkx = i - 1;
                    mylinks[i][j].linky = j;
                    mylinks[i][j].height=abs(matrix[i][j] - matrix[i - 1][j]);
                }//update link
                //border if
            }
            if (borders(i, j + 1)) { //right
                if (abs(matrix[i][j] - matrix[i ][j+ 1]) < mylinks[i][j].height) {
                    mylinks[i][j].linkx = i ;
                    mylinks[i][j].linky = j+ 1;
                    mylinks[i][j].height=abs(matrix[i][j] - matrix[i][j + 1]);
                }//update link
                //border if
            }
            if(borders(i,j-1)){ //left
                if(abs(matrix[i][j]-matrix[i][j-1])<mylinks[i][j].height){
                    mylinks[i][j].linkx=i;
                    mylinks[i][j].linky=j-1;
                    mylinks[i][j].height=abs(matrix[i][j] - matrix[i][j-1]);
                }//update link
                //border if
            }
        }
}
void ladder::printMatrix() {
    cout<<"row-column: "<<this->row<<" "<<this->column<<endl;
    for(int i=0;i<row;i++){

        for(int j=0;j<column;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl<<"Q values";
    for(int i=0;i<this->Q;i++){
        cout<<Q_values[i][0]<<Q_values[i][1]<<Q_values[i][2]<<Q_values[i][3]<<endl;
    }

}
bool ladder::borders(int r, int c) {
    if(r>=0 && r<(this->row) && c>=0 && c<(this->column))
        return true;
    return false;
}
void ladder::traverse(int fx, int fy, int tx, int ty) {
    if(fx==tx && fy==ty){
        cout<<"found!";
        return;
    }else
    traverse(mylinks[fx][fy].linkx,mylinks[fx][fy].linky,tx,ty);
}
void ladder::spanCall() {
    for(int i=0;i<this->Q;i++){
        traverse(Q_values[i][0],Q_values[i][1],Q_values[i][2],Q_values[i][3]);
    }
}


ladder::~ladder() {
    for(int i=0;i<this->row;i++){
//        delete matrix[i];
//        delete mylinks[i];
         }
//    for(int i=0;i<this->Q;i++){
//        delete Q_values[i];
//    }
}