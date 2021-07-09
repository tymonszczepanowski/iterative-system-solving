#include "Equation.h"
#include <iostream>
#include <math.h>

Equation::Equation(std::vector<std::vector<double>>& matrixA, std::vector<double>& vectorb){
    for(auto row: matrixA){
        A.push_back(row);
        x.push_back(0);
    }
    std::copy(vectorb.begin(), vectorb.end(), std::back_inserter(b));
}

double Equation::norm(std::vector<double>& v){
    double sum = 0;
    for(auto value: v){
        sum += value * value;
    }
    return sqrt(sum);
}

void Equation::print(){
    std::cout << "A size: " << A.size() << " x " << A[0].size() << std::endl;
    for(auto row: A){
        for(auto value: row) std::cout << value << ", ";
        std::cout << std::endl;
    }
    std::cout << std::endl << "b size: " << b.size() << std::endl;
    for(auto value: b) std::cout << value << ", ";
    std::cout << std::endl;
}

std::vector<double> Equation::multiply_A_x(){
    std::vector<double> result;
    double temp;
    for(auto row: A){
        temp = 0;
        for(size_t i = 0; i < row.size(); ++i){
           temp += row[i] * x[i]; 
        }
        result.push_back(temp);
    }
    return result;
}

void Equation::jacobi(){
    int size = b.size();
    int iterations = 0;
    double sigma;
    std::vector<double> next_x(size, 0);
    while(true){
        iterations++;
        for(int i = 0; i < size; ++i){
            sigma = 0;
            for(int j = 0; j < size; ++j){
                if(i != j){
                    sigma += A[i][j] * x[j];
                }
            }
            next_x[i] = (b[i] - sigma) / A[i][i];
        } 
        copy(next_x.begin(), next_x.end(), std::back_inserter(x));
        std::vector<double> res = multiply_A_x(); 
        for(auto v: res) std::cout << v << ", ";
        for(size_t i = 0; i < res.size(); ++i) res[i] -= b[i];
        std::cout << std::endl;
        for(auto v: res) std::cout << v << ", ";
        if(norm(res) < 10e-4) break;
    }
    std::cout << "Jacobi method, " <<  iterations << " iterations." << std::endl; 
    for(auto value: x) std::cout << value << ", ";
}

void gauss_seidel(){

}

void Equation::solve(){
    print();
    jacobi();   
}

Equation::~Equation(){

}
