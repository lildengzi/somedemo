// === Region: Headers ===
// iostream,string,algorithm and sstream are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _HIGHNNUMBER_HPP
#define _HIGHNNUMBER_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

// === Region: Type define ===
// define some complex typename 
// =======================
typedef unsigned short int usInt;//unsigned short int

// === Region: Constants ===
// Useful constants are defined for this project assignment
// =======================
const int MAX_LENGTH = 10000;// size of num

/** === Region: class HighNumber ===
 * @class HighNumber
 * @param number type:string description:stringSaveNumber大数的字符串形式.
 * @param big type:short* description:存放大数的数组.
 * @param count type:usInt 记录big数组长度.
 */
class HighNumber
{
    friend std::ostream& operator<<(std::ostream& out, const HighNumber& high);
private:
    std::string number;
    short big[MAX_LENGTH];
    usInt count;
public:
    HighNumber();
    ~HighNumber();

    void operator=(const std::string &str)
    {
        this->number = str;
        for (int i = 0; this->number[i] != '\0'; i++)
        {
            this->big[i] = this->number[i];
            count++;
        }
    }

    HighNumber operator+(HighNumber &num)
    {
        HighNumber answer;
        for(int i = 0; (i < num.count + 1) || (i < this->count + 1); i++)
        {
            answer.big[i] = this->big[i] + num.big[i];
            if (answer.big[i] >= 10)
            {
                answer.big[i] -= 10;
                answer.big[i + 1] += 1;
            }
        }
        return answer;
    }

    // HighNumber operator-(HighNumber num)
    // {
    //     return NULL;
    // }
};

HighNumber::HighNumber(): count(0)
{

}

HighNumber::~HighNumber()
{

}

std::ostream& operator<<(std::ostream& out, const HighNumber& high)
{
    for (int i = 0; i < high.count; i++)
    {
        out << high.big[i];
    }
    return out;
}

#endif // _HIGHNNUMBER_HPP
