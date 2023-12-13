#include "Task.cpp"

class SequentialClassic {
public:
    My_Polynomial multiply(My_Polynomial& p1, My_Polynomial& p2){
        std::vector<int> coefficients(p1.getDegree() + p2.getDegree() + 1, 0);
        My_Polynomial result(coefficients);

        for(int i = 0; i <= p1.getDegree(); i++){
            for( int j = 0; j <= p2.getDegree(); j++){
                int new_val = result.getCoefficients()[i + j] + p1.getCoefficients()[i] * p2.getCoefficients()[j];
                result.getCoefficients()[i + j] = new_val;
            }
        }
        return result;
    }
};

