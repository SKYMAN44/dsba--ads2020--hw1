//
// Created by Дмитрий Соколов on 26.04.2020.
//
#include "Multiplicator.h"
#include <random>
#include <ctime>

Number Multiplicator::generate_random(size_t k, int seed)
{
    std::string s;
    int c;
    srand(seed);
    for (size_t i = 0; i < k; i++)
    {
        if (i == 0)
        {
            c = rand() % 9 + 1;
            s += std::to_string(c);
        }
        else
        {
            c = rand() % 10;
            s += std::to_string(c);
        }
    }
    Number random(s);
    return random;
}

Number GradeSchool::multiply(Number &num_1, Number &num_2)
{
    int temp = 0;
    std::string a = "0";
    Number total_result(a);
    for (int i = num_2.size() - 1; i >= 0; i--)
    {
        std::string result = "";
        int sc = num_2[i];
        for(int j = num_1.size() - 1; j >= 0; j--)
        {
            int fst = num_1[j];
            std::string temp2 = std::to_string(sc * fst + temp);
            if( temp2.length() == 2)
            {
                temp = temp2[0] - '0';
                result += temp2[1];
            }
            else
            {
                result += temp2;
                temp = 0;
            }
        }
        if (temp != 0)
        {
            result += std::to_string(temp);
        }
        std::reverse(result.begin(), result.end());
        for (size_t k = 0; k < num_2.size() - 1 - i; k++)
        {
            result += "0";
        }
        Number temp_res(result);
        total_result = total_result + temp_res;
        temp = 0;
    }
    return total_result;
}


Number Karatsuba_M::multiply(Number &fst, Number &scnd)
{
    std::string zero = "0";
    int max_len = (std::max(fst.size(), scnd.size()));
    if (max_len == 1)
        return fst * scnd;
    if (max_len == 0)
        return Number(zero);
    fst.addZeros(0, max_len);
    scnd.addZeros(0, max_len);
    int n = max_len / 2;
    std::pair<Number, Number> first_pair = fst.split(max_len);
    std::pair<Number, Number> second_pair = scnd.split(max_len);
    Number a = first_pair.first;
    Number b = first_pair.second;
    Number c = second_pair.first;
    Number d = second_pair.second;
    Number A = multiply(a, c);
    Number C = multiply(b, d);
    Number sum1 = a + b;
    Number sum2 = c + d;
    Number D = multiply(sum1, sum2);
    Number B = D - C - A;
    B.addZeros(B.size(), n + B.size());
    A.addZeros(A.size(), (2 * n) + A.size());
    return A + B + C;
}

Number Divide_Conquere::multiply(Number& fst,Number& scnd)
{
    int max_len = (std::max(fst.size(), scnd.size()));
    if(max_len == 1)
        return fst * scnd;
    fst.addZeros(0,max_len);
    scnd.addZeros(0,max_len);
    int n = max_len / 2;
    std::pair<Number,Number> first_pair = fst.split(max_len);
    std::pair<Number,Number> second_pair = scnd.split(max_len);
    Number a = first_pair.first;
    Number b = first_pair.second;
    Number c = second_pair.first;
    Number d = second_pair.second;
    Number A = multiply(a, c);
    Number B = multiply(a, d);
    Number C = multiply(b, c);
    Number D = multiply(b, d);
    A.addZeros(A.size(), A.size() + n * 2);
    B.addZeros(B.size(), B.size() + n);
    C.addZeros(C.size(), C.size() + n);
    return A + B + C + D;
}
