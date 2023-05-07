#include "NodoResumen.h"
#include "Nodo.h"

NodoResumen::NodoResumen(NodoResumen* left, NodoResumen* right){
    this->father = nullptr;
    this->b = left->getB();
    this->size = left->getSize();
    left->setFather(this);
    if(right != nullptr){
        this->size += right->getSize();
        right->setFather(this);
    }
    this->left = left;
    this->right = right;
    this->arregloLeft = nullptr;
    this->arregloRight = nullptr;
}

NodoResumen::NodoResumen(Nodo* arregloLeft, Nodo* arregloRight){
    this->father = nullptr;
    this->b = arregloLeft->getB();
    this->size = arregloLeft->getSize();
    arregloLeft->setFather(this);
    if(arregloLeft != nullptr){
        this->size += arregloRight->getSize();
        arregloRight->setFather(this);
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
