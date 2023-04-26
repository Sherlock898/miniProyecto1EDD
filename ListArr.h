#ifndef LISTARR_H
#define LISTARR_H
#include<cstring>
#include<iostream>
#include"ListArrADT.h"

using namespace std;

class ListArr : public ListArrADT
{
private:
    struct Node {
        int data;
        int b;
        int *arr;
        int size;
        Node* next;
        Node(int data, Node* next = nullptr){
            this->data = data;
            this->next = next;
        }
    };
public:
    int size(); //Retorna la cantidad de elementos almacenados en el ListArr
    void insert_left(int v); //Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
    void insert_right(int v); //Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
    void insert(int v, int i); //Inserta un nuevo valor v en el índice i del ListArr.
    void print(); //Imprime por pantalla todos los valores almacenados en el ListArr.
    bool find(int v); //Busca en el ListArr si el valor v se encuentra almacenado.

};




#endif