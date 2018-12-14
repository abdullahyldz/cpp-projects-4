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
    // visited=new bool *[this->row];

    matrix.assign(x,vector<node*>(y,nullptr));
    //printMatrix();
    int temp;
    for(int i=0;i<row;i++) {
        // visited[i]=new bool[this->column];
        for (int j = 0; j < column; j++) {

            myfile >> temp;
            matrix[i][j] = new node(temp, i, j);

        }
    }
        for(int i=0;i<row;i++) {
        for (int j = 0; j < column; j++) {
            if(borders(i,j+1)){
                matrix[i][j]->edgespv.push_back(matrix[i][j+1]);
            }
//sol
            if(borders(i,j-1)) {
                matrix[i][j]->edgespv.push_back(matrix[i][j-1]);
            }

//yukarı
            if(borders(i-1,j)){
                matrix[i][j]->edgespv.push_back(matrix[i-1][j]);
            }

            //aşağı
            if(borders(i+1,j)){
                matrix[i][j]->edgespv.push_back(matrix[i+1][j]);
            }
        }
    }

    myfile>>this->Q;
    //Q_values=new int*[this->Q];
    solutions=new int[this->Q];

//    for(int i=0;i<this->Q;i++)
//        Q_values[i]=new int[4];
    int fx,fy,tx,ty;
    for(int i=0;i<this->Q;i++){
        myfile>>fx>>fy>>tx>>ty;
        matrix[fx][fy]->query.push_back(matrix[tx][ty]);
//        Q_target.push_back(matrix[tx][ty]);
    }

    this->final_ladder_height=LONG_LONG_MAX;
}


//void ladder::printMatrix() {
//    std::list<node*>::iterator it;
//    for(int i=0;i<this->row;i++){
//        for(int j=0;j<this->column;j++){
//            cout<<find_set(matrix[i][j])->height;
//            //cout<<matrix[i][j]->edgespv.size();
//
//            cout<<"\t";
//        }
//        cout<<endl;
//    }
//}
bool ladder::borders(int r, int c) {
    if(r>=0 && r<(this->row) && c>=0 && c<(this->column))
        return true;
    return false;
}

//void ladder::union_sets(node *v, node *u) {
//
//    node * xRoot=find_set(v);
//    node * yRoot=find_set(u);
//
//    yRoot->pv = xRoot;
//
//}
//node * ladder::find_set(node * v) {
//    if(v->pv!=v){
//       return find_set(v->pv);
//    }
//    return matrix[v->x][v->y];
//}
//void ladder::dfs(node * v,int h)
//{
//
//    v->known =true;
//    v->pv = v;
//    int temp;
//for(node * u: v->edgespv){
//        if(!u->known){
//            temp=max(abs(v->height-u->height),h);
//            dfs(u,temp);
//            union_sets(v, u);
//            find_set(v)->pv= v;
//        }
//}
//for (node * other_node:v->query) {
//        if (other_node->known){
//            cout<<find_set(other_node)->pv->height;
//            cout<<temp;
//        }
//    }
//}

//void compute_LCAs() {
//    // initialize n, adj and DSU
//    // for (each query (u, v)) {
//    //    queries[u].push_back(v);
//    //    queries[v].push_back(u);
//    // }
//
//    dfs(matrix[0][0]);
//}

//node* ladder::getRight(node * t) {
//    return matrix[t->x][t->y+1];
//}
//node* ladder::getLeft(node * t) {
//    return matrix[t->x][t->y-1];
//}
//node* ladder::getUp(node * t) {
//    return matrix[t->x-1][t->y];
//}node* ladder::getDown(node * t) {
//    return matrix[t->x+1][t->y];
//}


ladder::~ladder() {

//    for(int i=0;i<this->row;i++){
//        //delete visited[i];
//        for(int j=0;j<this->column;j++){
//            //delete matrix[i][j];
//
//        }
////    for(int i=0;i<this->Q;i++){
////        delete Q_values[i];
//    }
}