#include <iostream>
#include "Equation.h"

void test1(){
    std::vector<double> row1 = {1, 2, -1};
    std::vector<double> row2 = {1, -1, 2};
    std::vector<double> row3 = {2, 2, 2};
    std::vector<std::vector<double>> matrixA;
    matrixA.push_back(row1); 
    matrixA.push_back(row2); 
    matrixA.push_back(row3); 

    std::vector<double> vectorb = {2, 5, 12};
    
    Equation* Eq = new Equation(matrixA, vectorb);
    Eq->solve();
}
int main(){
    test1();
    return 0;
}
