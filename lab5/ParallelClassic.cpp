#include "ParallelKaratsuba.cpp"
#include <vector>
#include <iostream>
#include <future>
#include <cmath>
#include <algorithm>

class ParallelClassic{
public:
    static My_Polynomial multiply(My_Polynomial& p1, My_Polynomial& p2){
        PolynomialUtils polynomialUtils;
        int sizeOfResultCoefficientList = p1.getDegree() + p2.getDegree() +1;
        std::vector<int> coefficients(sizeOfResultCoefficientList, 0);
        My_Polynomial result(coefficients);

        int nrOfTasks = sizeOfResultCoefficientList / 4;
        if (nrOfTasks == 0){
            nrOfTasks = 1;
        }

        std::vector<std::future<My_Polynomial>> futures;

        int end;
        for(int i = 0; i < sizeOfResultCoefficientList; i += nrOfTasks){
            end = std::min(i + nrOfTasks, sizeOfResultCoefficientList);
            Task task(i, end, p1, p2, result);
            futures.push_back(std::async(std::launch::async, &Task::execute, task));
        }

        My_Polynomial finalResult(coefficients);  // Create a result object to accumulate task results

        for (auto& future : futures) {
            My_Polynomial taskResult = future.get();
            finalResult = polynomialUtils.add(finalResult, taskResult);
        }
        return finalResult;
    }

};