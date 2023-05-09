#include <iostream>
#include <chrono>
#include <list>
#include <algorithm>
#include "ListArr.h"

using namespace std;

double test_List(int inputSize, int b) {
    double result = 0;
    for(int i = 0; i < 20; i++){
        ListArr l(b);
        //cout << "a " << endl;
        //l.print();
        for (int j = 0; j < inputSize; j++) {
            l.insert_right(j);
        }
        auto start = chrono::high_resolution_clock::now();
        
        for (int j = 0; j < inputSize; j++) {
            //l.insert_left(j);
            //l.insert_right(j);
            //cout << j << endl;
        }
        
        l.find(-1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        result += diff.count();
        //cout << result << endl;
    }
    return result/20;
}

double test_dList(int inputSize, int b) {
    double result = 0;
    for(int i = 0; i < 20; i++){
        int* arr = new int[inputSize + 1];
        for (int j = 0; j < inputSize; j++) {
            arr[j] = j;
        }
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j < inputSize; j++) {
            //Insert_Left
            for(int k = j; k > 0; k--){
                arr[k - 1] = arr[k];
            } 
            arr[0] = j;
            //if(arr[j] == -1){
            //    return 0; 
            //}
            //Insert_Right
            //arr[j] = j;
            //cout << j << endl;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        result += diff.count();
    }
    return result / 20;
}
double test_xdList(int inputSize, int b) {
    double result = 0;
    for(int i = 0; i < 20; i++){
        list<int> lista;
        list<int>::iterator it;
        for (int j = 0; j < inputSize; j++) {
            lista.push_front(j);
        }
        auto start = chrono::high_resolution_clock::now();
        //for (int j = 0; j < inputSize; j++) {
            //lista.push_back(j);
            //lista.push_front(j);
        //}
        it = find(lista.begin(), lista.end(), -1);
        if (it != lista.end()) {
            std::cout << "Found 3 in the list!" << std::endl;
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        result += diff.count();
    }
    return result/20;
}

int main(){
    
    /*
    srand (time(NULL)); 
    cout << "Coso | 10.000 | 100.000 | 1.000.000" << endl;
    cout << "512 | " << test_List(10000, 512) << " | " <<  test_List(100000, 512) << " | " <<  test_List(1000000, 512) << endl;  
    //cout << test_List(1000000, 1024);
    cout << "1024 | " << test_List(10000, 1024) << " | " <<  test_List(100000, 1024) << " | " <<  test_List(1000000, 1024) << endl; 
    cout << "n | " << test_List(10000, 10000) << " | " <<  test_List(100000, 100000) << " | " << test_List(1000000, 1000000) << endl; 
    */


    ListArr lista1(128);
    ListArr lista2(512);
    ListArr lista3(1024);
    size_t size_lista10 = lista1.size_this();
    size_t size_lista20 = lista2.size_this();
    size_t size_lista30 = lista3.size_this();

    cout << " 1 | 2 | 3 " << endl;
    //cout << lista1.size_this() << " | " << lista2.size_this() << " | " << lista3.size_this() << endl;

    
    for(int i = 0; i < 3000; i++){
        lista1.insert_right(i);
        lista2.insert_right(i);
        lista3.insert_right(i);
    }
    cout << lista1.size_this() << " | " << lista2.size_this() << " | " << lista3.size_this() << endl;
    for(int i = 0; i < 3000; i++){
        lista1.delete_left();
        lista2.delete_left();
        lista3.delete_left();
    }

    cout << lista1.size_this() << " | " << lista2.size_this() << " | " << lista3.size_this() << endl;
    for(int i = 0; i < 1000; i++){
        lista1.insert_right(i);
        lista2.insert_right(i);
        lista3.insert_right(i);
    }

    cout << lista1.size_this() << " | " << lista2.size_this() << " | " << lista3.size_this() << endl;


    int xd;
    scanf("%d", &xd);
    return 0;
}