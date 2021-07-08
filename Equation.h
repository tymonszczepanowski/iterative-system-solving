#include <vector>

class Equation{
    private:
        std::vector<std::vector<double>> A;
        std::vector<double> x;
        std::vector<double> b;
        double norm(std::vector<double>& v);
        void jacobi();
        void gauss_seidel();
        
    public: 
        Equation(Matrix* matrixA, Matrix* vectorb);
        void solve();
        ~Equation();
}
