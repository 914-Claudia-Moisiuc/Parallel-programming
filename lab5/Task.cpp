#include "PolynomialUtils.cpp"

class Task{
private:
    int start;
    int end;
    My_Polynomial p1;
    My_Polynomial p2;
    My_Polynomial result;

public:
    Task(int start, int end, My_Polynomial& p1, My_Polynomial& p2, My_Polynomial& result)
    :start(start), end(end), p1(p1), p2(p2), result(result) {}

    My_Polynomial execute(){
        for(int i = start; i < end; i++){
            if(i >= result.getCoefficients().size()){
                return 0 ;
            }

            for(int j = 0; j <= i; j++){
                if(j < p1.getCoefficients().size() && (i - j) < p2.getCoefficients().size()){
                    int val = p1.getCoefficients()[j] * p2.getCoefficients()[i - j];
                    result.getCoefficients()[i] += val;
                }
            }
        }
        return result;
    }

};
