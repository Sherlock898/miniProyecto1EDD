#ifndef NODORESUMEN_H
#define NODORESUMEN_H

#include "Nodo.h"

class NodoResumen
{
private:
    int b;                      //Capacidad
    int size;                   //Cantidad de datos
    NodoResumen* left;
    NodoResumen* right;
    NodoResumen* father;
    Nodo* arregloLeft;
    Nodo* arregloRight;
public:     
    NodoResumen(NodoResumen* left, NodoResumen* right);
    NodoResumen(Nodo* arregloLeft, Nodo* arregloRight);
    ~NodoResumen();    
    void setFather(NodoResumen* NodoResumen);
    int getSize();
    int getB();
};

#endif // NODORESUMEN_H