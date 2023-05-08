#ifndef NODO_H
#define NODO_H

#include "NodoResumen.h"

class NodoResumen;
class Nodo
{
private:
    int b;                              //capacidad
    int *arr;                               
    int size;                           //cantidad de datos dentro del arreglo
    NodoResumen* father;
    Nodo* next;
    Nodo* previus;
    
public:
    Nodo(int b, Nodo* next, Nodo* previus);
    ~Nodo();
    void insert(int data, int i);
    int remove(int i);
    int at(int i);
    int getSize();
    int getB();
    Nodo* getNext();
    Nodo* getPrevius();
    void setFather(NodoResumen* father);
    void setNext(Nodo* next);
    void setPrevius(Nodo* previus);
    NodoResumen* getFather();
};

#endif // NODO_H