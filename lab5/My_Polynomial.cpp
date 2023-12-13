#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

class My_Polynomial {
private:
    std::vector<int> coefficients;
    int degree;

    void generateCoefficients(int degree) {
        coefficients.clear();
        std::srand(static_cast<unsigned int>(std::time(0)));
        for (int i = 0; i <= degree; i++) {
            int coefficient = std::rand() % 10 * (std::rand() % 2 == 0 ? 1 : -1);
            while (coefficient == 0 && i == degree) {
                coefficient = std::rand() % 10 * (std::rand() % 2 == 0 ? 1 : -1);
            }
            coefficients.push_back(coefficient);
        }
    }

public:
    My_Polynomial(const std::vector<int>& coefficients) : coefficients(coefficients), degree(coefficients.size() - 1) {}

    My_Polynomial(int degree) : degree(degree) {
        generateCoefficients(degree);
    }

     std::vector<int>& getCoefficients()  {
        return coefficients;
    }

    int getDegree()  {
        return degree;
    }

    void setCoefficients( std::vector<int>& coefficients) {
        this->coefficients = coefficients;
        this->degree = coefficients.size() - 1;
    }

    void setDegree(int degree) {
        this->degree = degree;
        generateCoefficients(degree);
    }

    std::string toString()  {
        std::ostringstream oss;
        if (coefficients[degree] != 0) {
            oss << coefficients[degree] << "x^" << degree;
        }
        for (int i = degree - 1; i > 0; --i) {
            if (coefficients[i] != 0) {
                oss << (coefficients[i] > 0 ? "+" : "") << coefficients[i] << "x^" << i;
            }
        }
        if (coefficients[0] != 0) {
            oss << (coefficients[0] > 0 ? "+" : "") << coefficients[0];
        }
        return oss.str();
    }
};
