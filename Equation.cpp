#include "Equation.h"
#include <math.h>

Equation::Equation(std::vector<std::vector<double>>& matrixA, std::vector<double>& vectorb){
}

double Equation::norm(std::vector<double>& v){
    double sum = 0;
    for(auto value: v){
        sum += value * value;
    }
    return sqrt(value);
}

std::vector<double> multiply_A_x(){
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

void subtract_b(std::vector<double>& v){
    for(size_t i = 0; i < v.size(); ++i) v[i] -= b[i];
}

void jacobi(){
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
        subtract_b(res);
        if(norm(res) < 10e-9) break;
    }
    std::cout << "Jacobi method, " <<  iterations << " iterations." << std::endl; 
    for(auto value: x) std::cout << value << ", ";
}

void gauss_seidel(){

}

void solve(){
    jacobi();   
}

Equation::~Equation(){

}
