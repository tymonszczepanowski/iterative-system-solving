#include <vector>

class Equation{
    private:
        std::vector<std::vector<double>> A;
        std::vector<double> x;
        std::vector<double> b;
        double norm(std::vector<double>& v);
        std::vector<double> multiply_A_x();
        void jacobi();
        void gauss_seidel();
        void print();
        
    public: 
        Equation(std::vector<std::vector<double>>&  matrixA, std::vector<double>& vectorb);
        void solve();
        ~Equation();
};
