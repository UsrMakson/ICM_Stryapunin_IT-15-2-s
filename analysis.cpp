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
        cout << "� ������ ������ �������� ���� ����������� ����� N, �� ������������� 500. � ��������� N ������� \n������� ������ ����������� : ������� �������� ����� ki � ���������� ����������� � ������, � ����� ki ����� ���� ������ � ����������� � ������ ������, ����� �����.� ������ ������\n������� �� ����� 500 �����������(� �������� �������� ����������� ��� ����������� ����� ���� ��������). ";
        sub(0);
        cout << "(������� ������)\n";
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
                cout << "\n����������:\n";
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
            cout << "���������:\n";
            continue;
        }

        int number;
        while (iss >> number) {
            if (number >= 0 && number <= max_ki_temp)
                result.push_back(number);
        }

        if (result.size() == static_cast<size_t>(ki_temp))
            return result;

        cout << "���������:\n";
        result.clear();
    }
}
