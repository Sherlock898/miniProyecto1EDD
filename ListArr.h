#ifndef LISTARR_H
#define LISTARR_H
#include<cstring>
#include<iostream>
#include"ListArrADT.h"
#include "NodoResumen.h"

using namespace std;

class ListArr : public ListArrADT
{
private:
    int b;
    Nodo* head;
    Nodo* tail;
    NodoResumen* root;
    void crearArbol();
    void actualizarNodos(Nodo* nodo, int dx);

public:
    ListArr(int b);
    ~ListArr();
    int size(); //Retorna la cantidad de elementos almacenados en el ListArr
    void insert_left(int v); //Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
    void insert_right(int v); //Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
    void insert(int v, int i); //Inserta un nuevo valor v en el índice i del ListArr.
    void print(); //Imprime por pantalla todos los valores almacenados en el ListArr.
    bool find(int v); //Busca en el ListArr si el valor v se encuentra almacenado.
    int delete_left(); //Elimina y retorna el elemento que está a la izquierda del ListArr
    int delete_right(); //Elimina y retorna el elemento que está a la derecha del ListArr.
};




#endif