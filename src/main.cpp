#include <iostream>
#include <ctime>
#include <fstream>
#include "Multiplicator.h"

typedef std::unique_ptr<Multiplicator> M_ptr;

double call_multiply(M_ptr methd, Number& fst, Number& scnd)
{
    clock_t time1;
    double timefinal = 0;
    for(int i = 0; i < 3 ;i++)
    {
        time1 = clock();
        Number c = methd->multiply(fst,scnd);
        time1 = clock() - time1;
        double time_taken1 = ((double)time1) / CLOCKS_PER_SEC;
        timefinal += time_taken1;
    }
    return timefinal / 3;
}

void conduct_experiment(int k)
{
    std::fstream result_file;
    result_file.open("/Users/dimasokolov/Desktop/MultiplicationData12.csv", std::ios::out | std::ios::app);
    int j = 0;
    result_file << "dalenna" << ',' << "gsa" << ',' << "Kara" << ',' << "DiC" << '\n';
    for(int i = 1; i < k; i++)
    {
        Number first = Multiplicator::generate_random(i, j);
        j++;
        Number second = Multiplicator::generate_random(i, j);
        auto Pointer_method1 =  std::make_unique<GradeSchool> ();
        auto Pointer_method2 =  std::make_unique<Karatsuba_M> ();
        auto Pointer_method3 =  std::make_unique<Divide_Conquere> ();
        double time_of_GSM = call_multiply(std::move(Pointer_method1),first,second);
        double time_of_Karatsuba = call_multiply(std::move(Pointer_method2),first,second);
        double time_of_D_C = call_multiply(std::move(Pointer_method3),first,second);
        std::cout << time_of_GSM << "GSM" << std::endl;
        std::cout << time_of_Karatsuba << "Karatsuba" << std::endl;
        std::cout << time_of_D_C << "D_C" << std::endl;
        result_file << i << ',' << time_of_GSM << ',' << time_of_Karatsuba << ',' << time_of_D_C << '\n';
        if(i > 300)
            i += 100;
    }
    result_file.close();
}

int main()
{
    conduct_experiment(10000);
}
