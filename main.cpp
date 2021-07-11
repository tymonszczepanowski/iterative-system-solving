#include <iostream>
#include "Equation.h"
#include <math.h>

void test1(){
    std::cout << "Test 1, exact solution: (1, 2, -1, 1)" << std::endl;
    std::vector<double> row1 = {10, -1, 2, 0};
    std::vector<double> row2 = {-1, 11, -1, 3};
    std::vector<double> row3 = {2, -1, 10, -1};
    std::vector<double> row4 = {0, 3, -1, 8};
    std::vector<std::vector<double>> matrixA;
    matrixA.push_back(row1); 
    matrixA.push_back(row2); 
    matrixA.push_back(row3); 
    matrixA.push_back(row4); 

    std::vector<double> vectorb = {6, 25, -11, 15};
    
    Equation* Eq = new Equation(matrixA, vectorb);
    Eq->solve();
    delete Eq;
}

void test2(int size){
    std::cout << "Diagonally dominant matrix of size: " << size  << std::endl;
    
    std::vector<std::vector<double>> matrixA;
    std::vector<double> vectorb;
    
    std::vector<double> row(size, 0);
    for(int i = 0; i < size; ++i) matrixA.push_back(row);
    
    for(int i = 0; i < size; ++i) matrixA[i][i] = 10;
    for(int i = 0; i < size; ++i){
        if(i - 1 >= 0) matrixA[i-1][i] = -1;
        if(i + 1 < size) matrixA[i+1][i] = -1;
        vectorb.push_back(sin(i * 2));
    } 

    Equation* Eq = new Equation(matrixA, vectorb);
    Eq->solve();
    delete Eq;
}
int main(){
    test1();
    //for(int size = 1e2; size < 1e5; size *= 10) test2(size);

    return 0;
}
