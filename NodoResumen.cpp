#include "Nodo.h"
//Constructor para NodosResumen superiores
NodoResumen::NodoResumen(NodoResumen* left, NodoResumen* right){
    this->father = nullptr;
    this->b = left->getB();
    this->size = left->getSize();
    left->setFather(this);
    if(right != nullptr){
        this->size += right->getSize();
        this->b += right->getB();
        right->setFather(this);
    }
    this->left = left;
    this->right = right;
    this->arrayLeft = nullptr;
    this->arrayRight = nullptr;
}

NodoResumen::NodoResumen(Nodo* arrayLeft, Nodo* arrayRight){
    this->father = nullptr;
    this->b = arrayLeft->getB();
    this->size = arrayLeft->getSize();
    this->arrayLeft = arrayLeft;
    this->arrayLeft->setFather(this);
    this->arrayRight = arrayRight;
    if(arrayRight != nullptr){
        this->b += arrayRight->getB();
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

size_t NodoResumen::size_this(){
    size_t resultado = sizeof(this);
    if(this->getArrayLeft() != nullptr) resultado += this->getArrayLeft()->size_this();
    if(this->getArrayRight() != nullptr) resultado += this->getArrayRight()->size_this();
    if(this->getLeft() != nullptr) resultado += this->getLeft()->size_this();
    if(this->getRight() != nullptr) resultado += this->getRight()->size_this();
    return resultado;
}