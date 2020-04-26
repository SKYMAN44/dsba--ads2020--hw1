//
// Created by Дмитрий Соколов on 26.04.2020.
//

#ifndef UNTITLED2_MULTIPLICATOR_H
#define UNTITLED2_MULTIPLICATOR_H

#endif //UNTITLED2_MULTIPLICATOR_H
#include <random>
#include <ctime>
#include "Number.h"

class Multiplicator
{
public:

    virtual Number multiply(Number& a, Number& b) = 0;

    static Number generate_random(size_t k, int seed);

    virtual ~Multiplicator() {}
};

class GradeSchool : public Multiplicator
{
public:

    Number multiply(Number &num_1, Number &num_2) override;

    ~GradeSchool () {}
};

class Karatsuba_M : public Multiplicator
{
public:

    Number multiply(Number &fst, Number &scnd)  override;

    ~Karatsuba_M() {}
};

class Divide_Conquere : public Multiplicator
{
public:
    Number multiply(Number& fst,Number& scnd) override;

    ~Divide_Conquere () {}
};
