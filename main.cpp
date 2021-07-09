#include <iostream>
#include "Equation.h"

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
}
int main(){
    test1();
    return 0;
}
