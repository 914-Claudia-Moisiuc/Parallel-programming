#include "My_Polynomial.cpp"

class PolynomialUtils {
public:
    My_Polynomial add(My_Polynomial p1, My_Polynomial p2) {
        int minDegree = std::min(p1.getDegree(), p2.getDegree());
        int maxDegree = std::max(p1.getDegree(), p2.getDegree());
        std::vector<int> coefficients(maxDegree + 1, 0);

        // Add the two polynomials
        for (int i = 0; i <= minDegree; i++) {
            coefficients[i] = (p1.getCoefficients()[i] + p2.getCoefficients()[i]);
        }

        if (minDegree != maxDegree) {
            if (maxDegree == p1.getDegree()) {
                for (int i = minDegree + 1; i <= maxDegree; i++) {
                    coefficients[i] = p1.getCoefficients()[i];
                }
            } else {
                for (int i = minDegree + 1; i <= maxDegree; i++) {
                    coefficients[i] = p2.getCoefficients()[i];
                }
            }
        }
        return My_Polynomial(coefficients);
    }

    My_Polynomial subtract(My_Polynomial p1, My_Polynomial p2) {
        int minDegree = std::min(p1.getDegree(), p2.getDegree());
        int maxDegree = std::max(p1.getDegree(), p2.getDegree());
        std::vector<int> coefficients(maxDegree + 1, 0);

        // Subtract the two polynomials
        for (int i = 0; i <= minDegree; i++) {
            coefficients[i] = p1.getCoefficients()[i] - p2.getCoefficients()[i];
        }

        if (minDegree != maxDegree) {
            if (maxDegree == p1.getDegree()) {
                for (int i = minDegree + 1; i <= maxDegree; i++) {
                    coefficients[i] = p1.getCoefficients()[i];
                }
            } else {
                for (int i = minDegree + 1; i <= maxDegree; i++) {
                    coefficients[i] = -p2.getCoefficients()[i];
                }
            }
        }

        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
        return My_Polynomial(coefficients);
    }

    My_Polynomial addZeros(My_Polynomial p, int offset) {
        std::vector<int> coefficients(offset, 0);
        coefficients.insert(coefficients.end(), p.getCoefficients().begin(), p.getCoefficients().end());
        return My_Polynomial(coefficients);
    }
};