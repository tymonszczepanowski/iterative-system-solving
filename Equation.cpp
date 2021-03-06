#include "Equation.h"
#include <iostream>
#include <math.h>
#include <chrono>

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
        for(auto value: row) std::cout << value << "  ";
        std::cout << std::endl;
    }
    std::cout << std::endl << "b size: " << b.size() << std::endl;
    for(auto value: b) std::cout << value << "  ";
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
    double sigma, diff;
    std::vector<double> res;
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
        x.clear();
        res.clear();
        copy(next_x.begin(), next_x.end(), std::back_inserter(x));
        res = multiply_A_x(); 
        for(size_t i = 0; i < res.size(); ++i) res[i] -= b[i];
        diff = norm(res);
        if(diff < 10e-9) break;
    }
    std::cout << std::endl << "Jacobi method, " <<  iterations << " iterations." << std::endl; 
    std::cout << "Difference: " << diff << std::endl;
}

void Equation::gauss_seidel(){
    x.clear();
    int size = b.size();
    for(int i = 0; i < size; ++i) x.push_back(0);
    int iterations = 0;
    double sigma, diff;
    std::vector<double> res;
    while(true){
        iterations++;
        for(int i = 0; i < size; ++i){
            sigma = 0;
            for(int j = 0; j < size; ++j){
                if(i != j){
                    sigma += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sigma) / A[i][i];
        } 
        res.clear();
        res = multiply_A_x(); 
        for(size_t i = 0; i < res.size(); ++i) res[i] -= b[i];
        diff = norm(res);
        if(diff < 10e-9) break;
    }
    std::cout << std::endl << "Gauss seidel method, " <<  iterations << " iterations."<< std::endl; 
    std::cout << "Difference: " << diff << std::endl;
}

void Equation::solve(){
    auto start_jacobi = std::chrono::high_resolution_clock::now();
    jacobi();
    auto stop_jacobi = std::chrono::high_resolution_clock::now();
    auto duration_jacobi = std::chrono::duration_cast<std::chrono::milliseconds>(stop_jacobi - start_jacobi);
    std::cout << "Time Jacobi: " << duration_jacobi.count() << "ms" << std::endl;  

    auto start_gauss = std::chrono::high_resolution_clock::now();
    gauss_seidel(); 
    auto stop_gauss = std::chrono::high_resolution_clock::now();
    auto duration_gauss = std::chrono::duration_cast<std::chrono::milliseconds>(stop_gauss - start_gauss);
    std::cout << "Time Gauss-Seidel: " << duration_gauss.count() << "ms" << std::endl << std::endl << std::endl;  
}

Equation::~Equation(){

}
