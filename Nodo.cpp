#include "Nodo.h"

//Nodo con arreglo
Nodo::Nodo(int b, Nodo* next){
    this->b = b;
    arr = new int[b];
    size = 0 ;
    this->next = next;
}

Nodo::~Nodo(){
    delete[] arr;
}

int Nodo::at(int i){
    if(i > getSize() || i < 0){
        throw "IndexOutOfBounds";
    }
    return arr[i];
}

void Nodo::insert(int data, int i){
    if(i > getSize() || i < 0){
        throw "IndexOutOfBounds";
    }
    if(getSize() == b){
        throw "talleno";
    }
    for(int j = getSize(); j > i; j--){
        arr[j] = arr[j-1];
    }      
    arr[i] = data;
    size++;
}

void Nodo::remove(int i){
    if(i > getSize() || i < 0){
        throw "IndexOutOfBounds";
    }
    for(int j = i; j < getSize(); j++){
        arr[j] = arr[j + 1];
    }
    size--;
}

int Nodo::getSize(){
    return size;
}

int Nodo::getB(){
    return b;
}

Nodo* Nodo::getNext(){
    return this->next;
}

void Nodo::setFather(NodoResumen* father){
    this->father = father;
}

NodoResumen* Nodo::getFather(){
    return father;
}