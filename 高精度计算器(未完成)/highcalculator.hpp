// === Region: Headers ===
// iostream,string are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _HIGHCALCULATOR_HPP
#define _HIGHCALCULATOR_HPP

#include "highnumber.hpp"
#include <iostream>
#include <string>

/** === Region: class HighCalculator ===
 * @class HighCalculator
 * @param number_1 type:HighNumber description:the first number.
 * @param number_2 type:HighNumber description:the second number.
 * @param oper type:char description:the operator.
 * @param calculateAnswer type:HighNumber the output.
*/
class HighCalculator
{
private:
    HighNumber number_1;
    HighNumber number_2;
    HighNumber calculateAnswer;
    char oper;
public:
    HighCalculator(const std::string &num_1, const std::string &num_2, char &theOperator): oper(theOperator)
    {
        number_1 = num_1;
        number_2 = num_2;
    }
    ~HighCalculator();

    HighNumber getAnswer();
    HighNumber add();
    // HighNumber sub();
};

HighCalculator::~HighCalculator()
{

}

HighNumber HighCalculator::getAnswer()
{
    if (this->oper == '+')
    {
        this->calculateAnswer = this->add();
    }
    else if (this->oper == '-')
    {
        // calculateAnswer = this->sub();
    }

    return calculateAnswer;
}

HighNumber HighCalculator::add()
{
    return number_1 + number_2;
}

// HighNumber HighCalculator::sub()
// {
//     // return number_1 - number_2;
//     return null;
// }

#endif // _HIGHCALCULATOR_HPP
