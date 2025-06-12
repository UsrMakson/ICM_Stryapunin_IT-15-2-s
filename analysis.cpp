#include "analysis.h"

#include <iostream>
#include <sstream>


using namespace std;

void Analysis::sub(int code) {
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
        cin >> temp;
        int number;
        if (temp == "help")
        {
            sub(1);
        }
        else
        {
            istringstream iss(temp);
            bool is_valid = (iss >> number) && iss.eof();
            bool in_range = (number >= 0) && (number <= 500);
            if (is_valid && in_range)
            {
                return number;
            }
            else
            {
                cout << "\nПерепишите:\n";
            }
        }
    }
} 

vector<int> Analysis::get_cin(int max_ki_temp) {
    vector<int> result;
    string temp;
    while (true) {
        getline(cin, temp);
        istringstream iss(temp);
        int ki_temp;
        if (!(iss >> ki_temp) || ki_temp < 0 || ki_temp > 500) {
            cout << "Повторите:\n";
            continue;
        }

        int number;
        while (iss >> number) {
            if (number >= 0 && number <= max_ki_temp)
                result.push_back(number);
        }

        if (result.size() == static_cast<size_t>(ki_temp))
            return result;

        cout << "Повторите:\n";
        result.clear();
    }
}
