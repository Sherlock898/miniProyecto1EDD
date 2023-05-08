#ifndef NODORESUMEN_H
#define NODORESUMEN_H

#include "Nodo.h"

class Nodo;
class NodoResumen
{
private:
    int b;                      //Capacidad
    int size;                   //Cantidad de datos
    NodoResumen* left;
    NodoResumen* right;
    NodoResumen* father;
    Nodo* arrayLeft;
    Nodo* arrayRight;
public:     
    NodoResumen(NodoResumen* left, NodoResumen* right);
    NodoResumen(Nodo* arrayLeft, Nodo* arrayRight);
    ~NodoResumen();    
    void setFather(NodoResumen* NodoResumen);
    void setSize(int size);
    int getSize();
    int getB();
    NodoResumen* getFather();
    NodoResumen* getLeft();
    NodoResumen* getRight();
    Nodo* getArrayLeft();
    Nodo* getArrayRight();
};


#endif // NODORESUMEN_H