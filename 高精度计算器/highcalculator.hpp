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
 * @param number_1 HighNumber 第一个大数.
 * @param number_2 HighNumber 第二个大数.
 * @param oper char 运算符.
 * @param calculateAnswer HighNumber 计算结果.
*/
class HighCalculator
{
private:
    HighNumber number_1;///< 大数
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
    HighNumber sub();
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
        this->calculateAnswer = this->sub();
    }

    return calculateAnswer;
}

HighNumber HighCalculator::add()
{
    return number_1 + number_2;
}

HighNumber HighCalculator::sub()
{
    return number_1 - number_2;
}

#endif // _HIGHCALCULATOR_HPP
