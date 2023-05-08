#include <iostream>
#include "ListArr.h"

using namespace std;

int main(){
    ListArr lista(6);
    for(int i = 0; i < 15; i++){
        lista.insert(i, i);
    }
    lista.print();
    return 0;
}