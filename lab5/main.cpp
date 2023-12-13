#include <iostream>

#include "ParallelClassic.cpp"

void run(My_Polynomial p1, My_Polynomial p2) {
    int option1, option2;
    std::cout << "1. SEQUENTIAL\n2. PARALLEL\n0. Exit\nOption: ";
    std::cin >> option1;
    My_Polynomial result(0);
    SequentialClassic sequentialClassic;
    SequentialKaratsuba sequentialKaratsuba;
    ParallelClassic parallelClassic;
    ParallelKaratsuba parallelKaratsuba;

    while (option1 != 0) {
        std::cout << "\n1.CLASSIC\n2.KARATSUBA\n";
        std::cin >> option2;
        auto startTime = std::chrono::high_resolution_clock::now();
        if (option1 == 1) {
            if (option2 == 1) {
                result = sequentialClassic.multiply(p1, p2);
            }
            else {
                result = sequentialKaratsuba.multiply(p1, p2);
            }
        } else if (option1 == 2) {
            if (option2 == 1) {
                result = parallelClassic.multiply(p1, p2);
            } else {
                result = parallelKaratsuba.multiply(p1, p2, 1);
            }
        }
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() ;

        std::cout << "result: ";
        std::cout << result.toString();
        std::cout << "\nDuration: " << duration << " microseconds" << std::endl;

        std::cout << "\n1. SEQUENTIAL\n2. PARALLEL\n0. Exit\nOption: ";
        std::cin >> option1;
    }

}


int main() {
    My_Polynomial p1 = My_Polynomial(3);
    std::cout<<"p1=  "<< p1.toString()<<'\n';
    My_Polynomial p2 = My_Polynomial(5);
    std::cout<<"p2=  " << p2.toString()<<'\n';
    run(p1, p2);

    return 0;
}
