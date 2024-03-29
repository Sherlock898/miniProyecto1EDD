#include <queue>
#include "ListArr.h"
#include "NodoResumen.h"
#include "Nodo.h"

using namespace std;

template <class T>
ListArr<T>::ListArr(T b){
    this->root = nullptr;
    this->b = b;
    this->head = new Nodo(b, nullptr);
    this->tail = head;
    crearArbol();
}

template <class T>
ListArr<T>::~ListArr(){
    delete(root);
    while (head != nullptr)
    {
        Nodo* nodo = head;
        head = head->getNext();
        delete(nodo);
    }
}

//LISTO
template <class T>
void ListArr<T>::crearArbol(){
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
    this->cola.pop();
}

template <class T>
int ListArr<T>::size(){ //Retorna la cantidad de elementos almacenados en el ListArr
    return root->getSize();
} 

template <class T>
void ListArr<T>::insert_left(T v){ //Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
    if(head->getSize() == b){
        head = new Nodo(b, head);
        head->insert(v, 0);
        crearArbol();
        return;
    }

    head->insert(v, 0);
    actualizarNodos(head, 1);
} 

template <class T>
void ListArr<T>::insert_right(T v){ //Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
    insert(v, root->getSize());
} 
//LISTO

template <class T>
void ListArr<T>::insert(T v, T i){ //Inserta un nuevo valor v en el índice i del ListArr.
    if(i > this->size()){
        throw "IndexOutOfBoundsException";
    }

    if(i == 0){
        insert_left(v);
        return;
    }

    NodoResumen* nodoActual = root;
    while(nodoActual->getArrayLeft() == nullptr){
        if(nodoActual->getLeft()->getSize() >= i){
            nodoActual = nodoActual->getLeft();
        }
        else{
            i = i - nodoActual->getLeft()->getSize();
            nodoActual = nodoActual->getRight();
            
        }
    }

    Nodo* target;

    if(nodoActual->getArrayLeft()->getSize() >= i){
        target = nodoActual->getArrayLeft();
    }
    else{
        if(nodoActual->getArrayRight() == nullptr){
            nodoActual->getArrayLeft()->setNext(new Nodo(b, nullptr));
            target = nodoActual->getArrayLeft()->getNext();
            tail = target;
            target->getNext()->insert(target->at(b - 1), 0);
            target->replace(v, i);
            crearArbol();    
            return;    
        }
        i = i - nodoActual->getArrayLeft()->getSize();
        target = nodoActual->getArrayRight(); 
    }  

    if(target->getSize() == b){
        target->setNext(new Nodo(b, target->getNext()));
        if(target->getNext()->getNext() == nullptr){
            tail = target;
        }
        if(i == b){
            target->getNext()->insert(v, 0);
        }
        else{
            target->getNext()->insert(target->at(b-1), 0);
            target->remove(b - 1);
            target->insert(v, i);
        }
        crearArbol();
        return;
    }

    target->insert(v, i);
    actualizarNodos(target, 1);
} 

template <class T>
T ListArr<T>::delete_left(){ //Elimina y retorna el elemento que está a la izquierda del ListArr.
    if(root->getSize() <= 0){
        throw "EmptyListException";
    }

    T data = head->remove(0);
    if(head->getSize() == 0 && head->getNext() != nullptr){
        Nodo* aux = head;
        head = head->getNext();
        delete(aux);
        crearArbol();
    }
    else{
        actualizarNodos(head, -1);
    }
    return data;
} 

template <class T>
T ListArr<T>::delete_right(){ //Elimina y retorna el elemento que está a la derecha del ListArr.
    if(root->getSize() <= 0){
        throw "EmptyListException";
    }

    T i = root->getSize()  - 1;

    NodoResumen* nodoActual = root;
    while(nodoActual->getArrayLeft() == nullptr){
        if(nodoActual->getLeft()->getSize() > i){
            nodoActual = nodoActual->getLeft();
        }
        else{
            i = i - nodoActual->getLeft()->getSize();
            nodoActual = nodoActual->getRight();
            
        }
    }

    Nodo* target;

    if(nodoActual->getArrayLeft()->getSize() > i){
        target = nodoActual->getArrayLeft();
    }
    else{
        i = i - nodoActual->getArrayLeft()->getSize();
        target = nodoActual->getArrayRight(); 
    }  
    T data = target->remove(i);
    actualizarNodos(target, -1);
    if(target->getSize() == 0){
        if(head == target){
            return data;
        }
        Nodo* anterior = head;
        while(anterior->getNext() != target){
            anterior = anterior->getNext();
        }
        anterior->setNext(target->getNext());
        delete(target);
        crearArbol();
    }
    return data;
}

template <class T>
void ListArr<T>:: print(){ //Imprime por pantalla todos los valores almacenados en el ListArr.
    Nodo* nodo = head; //comienza prTeando desde el 1er arreglo y avanza hasta llegar a nullptr
    while(nodo != nullptr){
        for(T i = 0; i < nodo->getSize(); i++){
            cout << nodo->at(i) << " ";
        }
        nodo = nodo->getNext();
    }
} 

template <class T>
bool ListArr<T>::find(T v){ //Busca en el ListArr si el valor v se encuentra almacenado.
    Nodo* nodo = head;
    while(nodo != nullptr){
        for(T i = 0; i < nodo->getSize(); i++){
            if(nodo->at(i) == v){
                return true;
            }
        }
        nodo = nodo->getNext();
    }
    return false;
} 

template <class T>
void ListArr<T>::actualizarNodos(Nodo* nodo, int dx){
    NodoResumen* nodoResumen = nodo->getFather();
    while (nodoResumen != nullptr)
    {
        nodoResumen->setSize(nodoResumen->getSize() + dx);
        nodoResumen = nodoResumen->getFather();
    }   
}

template <class T>
size_t ListArr<T>::size_this(){
    return sizeof(this) + this->root->size_this();
}