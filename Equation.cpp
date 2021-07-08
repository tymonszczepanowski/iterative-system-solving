#include "Equation.h"
#include <math.h>

Equation::Equation(Matrix* matrixA, Matrix* vectorb){
}

double Equation::norm(Matrix* v){
    double sum = 0;
    for(auto value: v->values){
        sum += value * value;
    }
    return sqrt(value);
}

Equation::~Equation(){

}
