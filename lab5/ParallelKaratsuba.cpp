#include <future>
#include "SequentialKaratsuba.cpp"

class ParallelKaratsuba {
private:
    int NR_THREADS = 4;
    int MAX_DEPTH = 4;

public:
    My_Polynomial multiply(My_Polynomial& p1, My_Polynomial& p2, int currentDepth) {
        SequentialKaratsuba sequentialKaratsuba;
        ParallelKaratsuba parallelKaratsuba;
        PolynomialUtils polynomialUtils;

        if (currentDepth > MAX_DEPTH) {
            return sequentialKaratsuba.multiply(p1, p2);
        }

        if(p1.getDegree() < 2 || p2.getDegree() <2){
            return sequentialKaratsuba.multiply(p1, p2);
        }

        int len = std::max(p1.getDegree(), p2.getDegree()) / 2;
        My_Polynomial lowP1({p1.getCoefficients().begin(), p1.getCoefficients().begin() + len});
        My_Polynomial highP1({p1.getCoefficients().begin() + len, p1.getCoefficients().end()});
        My_Polynomial lowP2({p2.getCoefficients().begin(), p2.getCoefficients().begin() + len});
        My_Polynomial highP2({p2.getCoefficients().begin() + len, p2.getCoefficients().end()});


        std::vector<std::future<My_Polynomial>> futures;

        auto multiplyTask = [currentDepth, &parallelKaratsuba](My_Polynomial p1, My_Polynomial p2) {
            return parallelKaratsuba.multiply(p1, p2, currentDepth + 1);
        };

        futures.push_back(std::async(std::launch::async, multiplyTask, std::ref(lowP1), std::ref(lowP2)));
        futures.push_back(std::async(std::launch::async, multiplyTask, polynomialUtils.add(lowP1, highP1), polynomialUtils.add(lowP2, highP2)));
        futures.push_back(std::async(std::launch::async, multiplyTask, std::ref(highP1), std::ref(highP2)));

        // Wait for all threads to finish
        for (auto& future : futures) {
            future.wait();
        }

        My_Polynomial z1 = futures[0].get();
        My_Polynomial z2 = futures[1].get();
        My_Polynomial z3 = futures[2].get();

        My_Polynomial r1 = polynomialUtils.addZeros(z3, 2 * len);
        My_Polynomial r2 = polynomialUtils.addZeros(polynomialUtils.subtract(polynomialUtils.subtract(z2, z3), z1), len);
        return polynomialUtils.add(polynomialUtils.add(r1, r2), z1);
    }
};