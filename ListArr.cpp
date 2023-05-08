#include <queue>
#include "ListArr.h"
#include "NodoResumen.h"
#include "Nodo.h"

using namespace std;

ListArr::ListArr(int b){
    this->root = nullptr;
    this->b = b;
    this->head = new Nodo(b, nullptr, nullptr);
    this->tail = head;
    crearArbol();
}

ListArr::~ListArr(){
    delete(root);
    while (head != nullptr)
    {
        Nodo* nodo = head;
        head = head->getNext();
        delete(nodo);
    }
}

void ListArr::crearArbol(){
    if(root != nullptr) delete(root);
    queue<NodoResumen*> cola;
    Nodo* nodoSos = head;
    while(nodoSos != nullptr){ //que exista 1
        Nodo* next = nodoSos->getNext(); //ya tiene 1 par
        cola.push(new NodoResumen(nodoSos, next)); //crea nodo resumen
        if(next != nullptr){ //ver sgte nodo si es que hay 
            nodoSos = next->getNext();
        } 
        else{
            nodoSos = nullptr; //sino gg puto wp 
        }
    }
    
    while(cola.size() > 1){
        queue<NodoResumen*> cola2;
        while(!cola.empty()){
            NodoResumen* nodo1 = cola.front();
            cola.pop();
            NodoResumen* nodo2 = nullptr;
            if(!cola.empty()){
                nodo2 = cola.front();
                cola.pop();
            }
            cola2.push(new NodoResumen(nodo1, nodo2));
        }
        cola = cola2;
    }
    
    this->root = cola.front();
    cola.pop();
}

int ListArr::size(){ //Retorna la cantidad de elementos almacenados en el ListArr
    return root->getSize();
} 

void ListArr::insert_left(int v){ //Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
    if(head->getSize() == b){
        head->setNext(new Nodo(b, head->getNext(), head));
        head->getNext()->insert(head->at(b - 1), 0);
        head->insert(v, 0);
        crearArbol();
        return;
    }

    head->insert(v, 0);
    actualizarNodos(head, 1);
} 

void ListArr::insert_right(int v){ //Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
    if(tail->getSize() == b){
        tail = new Nodo(b, nullptr, tail);
        tail->insert(v, 0);
        crearArbol();
        return;
    }
    tail->insert(v, tail->getSize() - 1);
    actualizarNodos(tail, 1);
} 

void ListArr::insert(int v, int i){ //Inserta un nuevo valor v en el índice i del ListArr.
    if(i > this->size()){
        throw "IndexOutOfBoundsException";
    }

    NodoResumen* nodoActual = root;
    while(nodoActual->getArrayLeft() == nullptr){
        if(nodoActual->getLeft()->getSize() > i){
            nodoActual = nodoActual->getLeft();
        }
        else{
            nodoActual = nodoActual->getRight();
            i = i - nodoActual->getLeft()->getSize();
        }
    }

    Nodo* target;

    if(nodoActual->getArrayLeft() == nullptr){
        return;
    }
    else{
        int xd = nodoActual->getArrayLeft()->getSize();
    }

    if(nodoActual->getArrayLeft()->getSize() > i){
        target = nodoActual->getArrayLeft();
    }
    else{
        target = nodoActual->getArrayRight();
        i = i - nodoActual->getArrayLeft()->getSize();
    }  

    if(target->getSize() == b){
        target->setNext(new Nodo(b, target->getNext(), target->getPrevius()));
        if(target->getNext() != nullptr){
            target->getNext()->setPrevius(target);
        }
        else{
            tail = target;
        }
        target->getNext()->insert(target->at(b - 1), 0);
        target->insert(v, i);
        crearArbol();
        return;
    }

    target->insert(v, i);
    actualizarNodos(target, 1);
} 

int ListArr::delete_left(){ //Elimina y retorna el elemento que está a la izquierda del ListArr.
    if(root->getSize() <= 0){
        throw "EmptyListException";
    }

    int data = head->remove(0);
    if(head->getSize() == 0 && head->getNext() != nullptr){
        Nodo* aux = head;
        head = head->getNext();
        head->setPrevius(nullptr);
        delete(aux);
        crearArbol();
    }
    else{
        actualizarNodos(head, -1);
    }
    return data;
} 

int ListArr::delete_right(){ //Elimina y retorna el elemento que está a la derecha del ListArr.
    if(root->getSize() <= 0){
        throw "EmptyListException";
    }
    int data = tail->remove(tail->getSize() - 1);
    if(tail->getSize() == 0 && tail->getPrevius() != nullptr){
        Nodo* aux = tail;
        tail = tail->getPrevius();
        tail->setNext(nullptr);
        delete(aux);
        crearArbol();
    }
    else{
        actualizarNodos(tail, -1);
    }
    return data;
}

void ListArr:: print(){ //Imprime por pantalla todos los valores almacenados en el ListArr.
    Nodo* nodo = head;
    while(nodo != nullptr){
        for(int i = 0; i < nodo->getSize(); i++){
            cout << nodo->at(i) << " ";
        }
        nodo = nodo->getNext();
    }
} 
bool ListArr::find(int v){ //Busca en el ListArr si el valor v se encuentra almacenado.
    Nodo* nodo = head;
    while(nodo != nullptr){
        for(int i = 0; i < nodo->getSize(); i++){
            if(nodo->at(i) == v){
                return true;
            }
        }
        nodo = nodo->getNext();
    }
    return false;
} 

void ListArr::actualizarNodos(Nodo* nodo, int dx){
    NodoResumen* nodoResumen = nodo->getFather();
    while (nodoResumen != nullptr)
    {
        nodoResumen->setSize(nodoResumen->getSize() + dx);
        nodoResumen = nodoResumen->getFather();
    }   
}