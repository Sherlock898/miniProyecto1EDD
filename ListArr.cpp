#include <queue>
#include "ListArr.h"
#include "NodoResumen.h"

using namespace std;

ListArr::ListArr(int b){
    this->root = nullptr;
    this->b = b;
    this->head = new Nodo(b, nullptr);
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
    delete(root);
    queue<NodoResumen*> cola;
    Nodo* nodoSos = head;
    while(nodoSos != nullptr){ //que exista 1
        Nodo* next = nodoSos->getNext(); //ya tiene 1 par
        cola.push(new NodoResumen(nodoSos, next)); //crea nodo resumen
        if(next != nullptr){ //ver sgte nodo si es que hay (para ver otro par)
            nodoSos = next->getNext();
        } 
        else{
            nodoSos = nullptr; //sino gg puto wp 
        }
    }
    
    while(cola.size() == 1){
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

} 
void ListArr::insert_right(int v){ //Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1

} 
void ListArr::insert(int v, int i){ //Inserta un nuevo valor v en el índice i del ListArr.

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