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
    
public:
    Nodo(int b, Nodo* next);
    ~Nodo();
    void insert(int data, int i);
    int remove(int i);
    void replace(int v, int i);
    int at(int i);
    int getSize();
    int getB();
    Nodo* getNext();
    void setFather(NodoResumen* father);
    void setNext(Nodo* next);
    NodoResumen* getFather();
    size_t size_this();
};

#endif // NODO_H