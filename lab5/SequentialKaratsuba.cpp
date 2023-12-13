#include "SequentialClassic.cpp"

class SequentialKaratsuba{
public:
    My_Polynomial multiply(My_Polynomial& p1, My_Polynomial& p2){
        SequentialClassic sequentialClassic;
        PolynomialUtils polynomialUtils;
        if (p1.getDegree() < 2 || p2.getDegree() < 2) {
            return sequentialClassic.multiply(p1, p2);
        }


        int len = std::max(p1.getDegree(), p2.getDegree()) /2;
        My_Polynomial low_p1({p1.getCoefficients().begin(), p1.getCoefficients().begin() + len});
        My_Polynomial high_p1({p1.getCoefficients().begin() + len, p1.getCoefficients().end()});
        My_Polynomial low_p2({p2.getCoefficients().begin(), p2.getCoefficients().begin() + len});
        My_Polynomial high_p2({p2.getCoefficients().begin() + len, p2.getCoefficients().end()});

        My_Polynomial z1 = multiply(low_p1, low_p2);
        My_Polynomial p = polynomialUtils.add(low_p1, high_p1);
        My_Polynomial pp = polynomialUtils.add(low_p2, high_p2);
        My_Polynomial z2 = multiply(p, pp);
        My_Polynomial z3 = multiply(high_p1, high_p2);

        My_Polynomial r1 = polynomialUtils.addZeros(z3, 2 * len);
        My_Polynomial r2 = polynomialUtils.addZeros(polynomialUtils.subtract(polynomialUtils.subtract(z2, z3), z1), len);

        return polynomialUtils.add(polynomialUtils.add(r1, r2), z1);

    }
};