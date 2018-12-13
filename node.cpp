//
// Created by student on 11.12.2018.
//

#include "node.h"
#include "limits.h"
node::node(int height,int x , int y) {
    this->height=height;
    this->pv=nullptr;
    this->dv=INT_MAX;
    this->onQueue=false;
    this->x=x;
    this->y=y;
    this->known=false;
    this->edges= {};
}
node::node() {
    this->height=0;
    this->pv=nullptr;
    this->dv=INT_MAX;
    this->onQueue=false;
    this->x=0;
    this->y=0;
    this->edges= {};
    this->known=false;
}

