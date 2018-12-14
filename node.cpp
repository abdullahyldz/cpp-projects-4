//
// Created by student on 11.12.2018.
//

#include "node.h"
#include "limits.h"
node::node(int height,int x , int y) {
    this->height=height;
    this->pv=this;
    //this->rank=1;
    //this->onQueue=false;
    this->x=x;
    this->y=y;
    this->known=false;
    this->query= {};
    this->edgespv= {};
   // this->edgesdv= {};
}
node::node() {
    this->height=0;
    this->pv=nullptr;
    //this->rank=1;
    //this->onQueue=false;
    this->x=0;
    this->y=0;
    this->edgespv= {};
    this->query= {};
   // this->edgesdv= {};
    this->known=false;
}
node::~node() {
    delete pv;
    //delete edgespv;
}
