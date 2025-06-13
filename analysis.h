#pragma once
#include <vector>
#include <string>

class Analysis
{
public:
    static std::vector<int> get_cin(int n);// ввод для элементов
    static int get_cin_n();// ввод для n
    static void sub(int code);// вспомогательная ф-ия
};