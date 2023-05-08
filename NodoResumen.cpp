
#include "Nodo.h"
//Constructor para NodosResumen superiores
NodoResumen::NodoResumen(NodoResumen* left, NodoResumen* right){
    this->father = nullptr;
    this->b = left->getB()*2;
    this->size = left->getSize();
    left->setFather(this);
    if(right != nullptr){
        this->size += right->getSize();
        right->setFather(this);
    }
    this->left = left;
    this->right = right;
    this->arrayLeft = nullptr;
    this->arrayRight = nullptr;
}

NodoResumen::NodoResumen(Nodo* arrayLeft, Nodo* arrayRight){
    this->father = nullptr;
    this->b = arrayLeft->getB()*2;
    this->size = arrayLeft->getSize();
    arrayLeft->setFather(this);
    if(arrayRight != nullptr){
        this->size += arrayRight->getSize();
        arrayRight->setFather(this);
    }
    this->left = nullptr;
    this->right = nullptr;
}

NodoResumen::~NodoResumen(){
    delete(left);
    delete(right);
}

int NodoResumen::getSize(){
    return size;
}
void NodoResumen::setSize(int size){
    this->size = size;
}
int NodoResumen::getB(){
    return b;
}

void NodoResumen::setFather(NodoResumen* father){
    this->father = father;
}

NodoResumen* NodoResumen::getFather(){
    return this->father;
}

NodoResumen* NodoResumen::getLeft(){
    return this->left;
}

NodoResumen* NodoResumen::getRight(){
    return this->right;
}

Nodo* NodoResumen::getArrayLeft(){
    return this->arrayLeft;
}   

Nodo* NodoResumen::getArrayRight(){
    return this->arrayRight;
}

