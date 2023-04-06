// === Region: Headers ===
// iostream,string,algorithm are included.
// Do not include extra header files
// =======================
#pragma once
#ifndef _HIGHNNUMBER_HPP
#define _HIGHNNUMBER_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

/**
 * === Region: Type define ===
 * define some complex typename 
 * ===========================
 */
typedef unsigned short int usInt; // unsigned short int

// === Region: Constants ===
// Useful constants are defined for this project assignment
// =======================
const int MAX_LENGTH = 10000;// size of num

/** === Region: class HighNumber ===
 * @class HighNumber
 * @param number string 大数的字符串形式.
 * @param big short* 存放大数的数组.
 * @param count usInt 记录big数组长度.
 * @param FU_SHU bool 判断是否为负数.
 */
class HighNumber
{
    friend std::ostream& operator<<(std::ostream& out, const HighNumber& high);
private:
    std::string number;
    short big[MAX_LENGTH]={0};
    usInt count;
    bool FU_SHU;
public:
    HighNumber();
    ~HighNumber();

    HighNumber& operator=(const std::string &str)
    {
        this->number = str;
        for (int i = str.length() - 1, j = 0; i >= 0 ; i--, j++)
        {
            this->big[j] = this->number[i] - '0';
            count++;
        }

        return *this;
    }

    HighNumber operator+(HighNumber &num)
    {
        HighNumber answer;
        for(int i = 0; (i < num.count) || (i < this->count); i++)
        {
            answer.big[i] += this->big[i] + num.big[i];
            if (answer.big[i] >= 10)
            {
                answer.big[i] -= 10;
                answer.big[i + 1] += 1;
            }
        }
        int max = num.count > this->count ? num.count : this->count;
        answer.count = answer.big[max] != 0 ? max + 1 : max;
        return answer;
    }

    // HighNumber operator-(HighNumber &num)
    // {
    //     HighNumber answer;

    //     if ((num.count > this->count) && (num.big[num.count] > this->big[this->count]))
    //     {
    //         HighNumber temp = num;
    //         num = *this;
    //         *this = temp;
    //         answer.FU_SHU = true;
    //     }
        
    //     for(int i = 0; (i < num.count) || (i < this->count); i++)
    //     {
    //         answer.big[i] += this->big[i] - num.big[i];
    //         if (answer.big[i] < 0)
    //         {
    //             answer.big[i + 1] -= 1;
    //         }
    //     }

    //     int max = num.count > this->count ? num.count : this->count;
    //     answer.count = answer.big[max] == 0 ? max - 1 : max;

    //     if (answer.FU_SHU == true)
    //         {std::cout << '-';}
        
    //     return answer;
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
    for (int i = high.count - 1; i >= 0; i--)
    {
        out << high.big[i];
    }
    return out;
}

#endif // _HIGHNNUMBER_HPP
