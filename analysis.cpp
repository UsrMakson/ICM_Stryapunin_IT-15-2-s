#include "analysis.h"
#include <iostream>
#include <sstream>

using namespace std;

void Analysis::sub(int code) 
{
    if (code == 0)
    {
        cout << "\n--------------------------------------------------------------------\n";
    }
    else if (code == 1)
    {
        system("clear");
        sub(0);
        cout << "в первой строке задается одно натуральное число N, не превосходящее 500. В следующих N строках \nописаны стопки контейнеров : сначала записано число ki — количество контейнеров в стопке, а затем ki чисел— виды товара в контейнерах в данной стопке, снизу вверх.В каждой стопке\nвначале не более 500 контейнеров(в процессе переноса контейнеров это ограничение может быть нарушено). ";
        sub(0);
        cout << "(входные данные)\n";
    }
}

int Analysis::get_cin_n() 
{
    string temp;
    while (true) 
    {
        getline(cin, temp);
        if (temp == "help") 
        {
            sub(1);
            continue;
        }
        istringstream iss(temp);
        int number;
        if (iss >> number && number >= 1 && number <= 500) 
        {
            return number;
        }
        cout << "Некорректный ввод. Повторите: ";
    }
}

vector<int> Analysis::get_cin(int n) 
{
    vector<int> result;
    string temp;
    while (true) {
        getline(cin, temp);
        istringstream iss(temp);
        int ki;
        if (!(iss >> ki) || ki < 0 || ki > 500) 
        {
            cout << "Некорректное количество контейнеров. Повторите:\n";
            continue;
        }
        result.clear();
        int number;
        while (iss >> number) {
            if (number < 1 || number > n) 
            {
                cout << "Повторите:\n";
                result.clear();
                break;
            }
            result.push_back(number);
        }
        if (result.size() == static_cast<size_t>(ki)) 
        {
            return result;
        }

        cout << "Неверное количество элементов. Ожидалось " << ki << ", получено " << result.size() << ". Повторите: ";
    }
}