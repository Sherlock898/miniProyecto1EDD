#ifndef LISTARR_H
#define LISTARR_H
#include<cstring>
#include<iostream>
#include"ListArrADT.h"
#include "NodoResumen.h"

using namespace std;

template <class T>
class ListArr : public ListArrADT
{
private:
    T b;
    Nodo* head;
    Nodo* tail;
    NodoResumen* root;
    void crearArbol();
    void actualizarNodos(Nodo* nodo, int dx);

public:
    ListArr(T b);
    ~ListArr();
    int size(); //Retorna la cantidad de elementos almacenados en el ListArr
    void insert_left(T v); //Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
    void insert_right(T v); //Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
    void insert(T v, T i); //Inserta un nuevo valor v en el índice i del ListArr.
    void print(); //Imprime por pantalla todos los valores almacenados en el ListArr.
    bool find(T v); //Busca en el ListArr si el valor v se encuentra almacenado.
    T delete_left(); //Elimina y retorna el elemento que está a la izquierda del ListArr
    T delete_right(); //Elimina y retorna el elemento que está a la derecha del ListArr.
    size_t size_this();
};




#endif