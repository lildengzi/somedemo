/**
 * @file main.cpp
 * @name 高精度计算器
 * @author lil_DengZi
 * @version v0.1beta
 * @date 2023/04/05
 * @todo 完善加减高精度加减法（从网上搜索）
 * @include highcalculator.hpp highnumber.hpp
 * @copyright    Copyright (c) 2023 lil_DengZi
*/

// === Region: Headers ===
// Do not include extra header files
// =======================
#include "highcalculator.hpp"
#include "highnumber.hpp"
#include <iostream>
#include <string>
using namespace std;

// void HELP()
// {
//     cout << "0.退出" << endl;
//     cout << "1.计算" << endl;
// }

// void calculate()
// {
//     while(
//         []{
//             cout << "继续计算?" << endl;
//             char a;
//             cin >> a;
//             if (a == 'Y' || a == 'y')
//             {
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     )
//     {
        
//     }
// }


// === Region: Main Function ===
/**
 * @code
 * input:123 321 +
 * output:0x61b0ec
 * 这是一个错误情况
 * @endcode
 */
int main(int argc, char* argv[])
{
    // usInt selection = 0;
    
    // while (1)
    // {
        // HELP();
        // cout << "请输入一个数字(0,1):";
        // cin >> selection;
        // switch (selection)
        // {
        // case 0:
        //     exit(0);
        // case 1:
        //     calculate();
        //     break;
        // default:
        //     cout << "你的输入有问题，请重新输入。" << endl;
        //     break;
        // }

        string num_1, num_2;
        char option;

        // cout << "输入你的计算表达式" << endl;
        // cout << "(提示,计算表达式: calculate 数字1 符号 数字2)" << endl;
        cin >> num_1 >> num_2 >> option;

        HighCalculator h1(num_1, num_2, option);
        cout << h1.getAnswer() << endl;
    // }

    system("pause");
    return 0;
}