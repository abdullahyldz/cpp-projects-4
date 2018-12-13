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
    visited=new bool *[this->row];

    matrix.assign(row,vector<node*>(column,nullptr));
    //printMatrix();
    int temp;
    for(int i=0;i<row;i++) {
        visited[i]=new bool[this->column];
        for (int j = 0; j < column; j++) {

            myfile >> temp;
            matrix[i][j] = new node(temp, i, j);

        }
    }

    //printMatrix();
    myfile>>this->Q;
    Q_values=new int*[this->Q];
    solutions=new int[this->Q];
    for(int i=0;i<this->Q;i++)
        Q_values[i]=new int[4];

    for(int i=0;i<this->Q;i++)
        myfile>>Q_values[i][0]>>Q_values[i][1]>>Q_values[i][2]>>Q_values[i][3];

    this->final_ladder_height=LONG_LONG_MAX;
}

void ladder::createEdge() {
    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->column;j++) {
            matrix[i][j]->edges.push_back(new pair(matrix[i][j]->pv,matrix[i][j]->dv));
            matrix[i][j]->pv->edges.push_back(new pair(matrix[i][j],matrix[i][j]->dv));
        }
    }
    std::list<pair*>::iterator it;
    for(it=matrix[0][0]->edges.begin();it!=matrix[0][0]->edges.end();){
        if((*it)->pv==matrix[0][0]){
            it=matrix[0][0]->edges.erase(it);
            continue;
        }
        it++;
    }
}
void ladder::printMatrix() {
std::list<pair*>::iterator it;
    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->column;j++){
            cout<<matrix[i][j]->height<<"->("<<matrix[i][j]->edges.size()<<")";
            for(it=matrix[i][j]->edges.begin();it!=matrix[i][j]->edges.end();++it){
                cout<<","<<(*it)->pv->height<<"pair"<<(*it)->dv;
            }
            cout<<"\t";
        }
        cout<<endl;
    }
//    cout<<endl<<"Q values "<<Q<<endl;
//    for(int i=0;i<this->Q;i++){
//        cout<<Q_values[i][0]<<Q_values[i][1]<<Q_values[i][2]<<Q_values[i][3]<<endl;
//    }
}
bool ladder::borders(int r, int c) {
    if(r>=0 && r<(this->row) && c>=0 && c<(this->column))
        return true;
    return false;
}

void ladder::spanCall() {
    for(int i=0;i<this->Q;i++){
        traverse(Q_values[i][0],Q_values[i][1],Q_values[i][2],Q_values[i][3]);
    }
}
//void ladder::traverse(int fx, int fy , int tx, int ty ) {
//    std::list<node*>::iterator it=matrix[fx][fy]->edges.begin();
//
//    for(;it!=matrix[fx][fy]->edges.end();++it){
//        if(!visited[(*it)->x][(*it)->y])
//            dfs(*it);
//    }
//}
//void ladder::dfs(node *n){
//    visited[n->x][n->y]=true;
//    std::list<node*>::iterator it=n->edges.begin();
//
//    for(;it!=n->edges.end();++it){
//        if(!visited[(*it)->x][(*it)->y])
//            dfs(*it);
//    }
//};
node* ladder::getRight(node * t) {
    return matrix[t->x][t->y+1];
}
node* ladder::getLeft(node * t) {
    return matrix[t->x][t->y-1];
}
node* ladder::getUp(node * t) {
    return matrix[t->x-1][t->y];
}node* ladder::getDown(node * t) {
    return matrix[t->x+1][t->y];
}

void ladder::prims() {

    treeQueue.push(matrix[0][0]);
    matrix[0][0]->onQueue=true;
    matrix[0][0]->pv=matrix[0][0];
    matrix[0][0]->dv=0;
    node * right,* left,* up,* down;
    int a=1;
    node * top;
    while(!treeQueue.empty()){
        //cout<<a;
        top =treeQueue.top();
        top->known=true;
        treeQueue.pop();

//sağ
        if(borders(top->x,top->y+1)){
            //cout<<"right";
            right=getRight(top);
            if(!right->known && (abs(top->height-(right->height))<right->dv)){
                right->dv=abs(top->height-right->height);
                right->pv=top;
            }
            if(!right->onQueue){
                right->onQueue=true;
                treeQueue.push(right);
            }
        }
//sol
        if(borders(top->x,top->y-1)){
            left=getLeft(top);
            if(!left->known && (abs(top->height-(left->height))<left->dv)){
                left->dv=abs(top->height-left->height);
                left->pv=top;
            }
            if(!left->onQueue){
                left->onQueue=true;
                treeQueue.push(left);
            }
        }
//yukarı
        if(borders(top->x-1,top->y)){
             up=getUp(top);
            if(!up->known && (abs(top->height-(up->height))<up->dv)){
                up->dv=abs(top->height-up->height);
                up->pv=top;
            }
            if(!up->onQueue){
                up->onQueue=true;
                treeQueue.push(up);
            }
        }

        //aşağı
        if(borders(top->x+1,top->y)){
            down=getDown(top);
            if(!down->known && (abs(top->height-(down->height))<down->dv)){
                down->dv=abs(top->height-down->height);
                down->pv=top;
            }
            if(!down->onQueue){
                down->onQueue=true;
                treeQueue.push(down);
            }
        }
        //a++;
    } //while
   // cout<<"prims "<<a<<endl;
    createEdge();
}
ladder::~ladder() {

    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->column;j++){
            delete matrix[i][j];

    }
//    for(int i=0;i<this->Q;i++){
//        delete Q_values[i];
   }
}