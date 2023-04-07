/**
 * @file main.cpp
 * @name �߾��ȼ�����(����һ��λ)
 * @author lil_DengZi
 * @version v2.0
 * @date 2023/04/07
 * @todo ���ƼӼ��߾��ȼ���
 * @include highcalculator.hpp highnumber.hpp
 * @brief ����,yee~
 * 
 * @copyright    Copyright (c) 2023 lil_DengZi
 * 
*/

// === Region: Headers ===
// Do not include extra header files
// =======================
#include "highcalculator.hpp"
#include "highnumber.hpp"
#include <iostream>
#include <string>
using namespace std;

// === Region: Main Function ===
/**
 * @warning ��֧�����븺������
 * 
 */
int main(int argc, char* argv[])
{
    while(1)
    {
        string num_1, num_2;
        char option;

        cout << "������ļ�����ʽ" << endl;
        cout << "(��ʾ,������ʽ: calculate ����1 ���� ����2)" << endl;
        cin >> num_1 >> num_2 >> option;

        HighCalculator h1(num_1, num_2, option);
        cout << h1.getAnswer() << endl;
        system("pause");
        system("cls");
    }

    return 0;
}