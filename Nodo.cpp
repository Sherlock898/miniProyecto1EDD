#include "NodoResumen.h"

//Constructor nodo con arreglo
Nodo::Nodo(int b, Nodo* next, Nodo* previus){
    this->b = b;
    arr = new int[b];
    this->size = 0;
    this->next = next;
    this->previus = previus;
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

int Nodo::remove(int i){
    if(i > getSize() || i < 0){
        throw "IndexOutOfBounds";
    }
    int data = arr[i];
    for(int j = i; j < getSize(); j++){
        arr[j] = arr[j + 1];
    }
    size--;
    return data;
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

Nodo* Nodo::getPrevius(){
    return this->previus;
}

void Nodo::setFather(NodoResumen* father){
    this->father = father;
}

void Nodo::setNext(Nodo* next){
    this->next = next;
}

void Nodo::setPrevius(Nodo* previus){
    this->previus = previus;
}

NodoResumen* Nodo::getFather(){
    return father;
}