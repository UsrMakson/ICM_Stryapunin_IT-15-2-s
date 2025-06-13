#include "analysis.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

void Analysis::sub(int code) {
    if (code == 0) {
        cout << "\n----------------------------------------------------------------\n";
    }
    else if (code == 1) {
        system("cls");
        sub(0);
        cout << "� ������ ������ �������� ���� ����������� ����� N, �� ������������� 500. � ��������� N �������\n";
        cout << "������� ������ �����������: ������� �������� ����� ki � ���������� ����������� � ������, � ����� ki �����\n";
        cout << "� ���� ������ � ����������� � ������ ������, ����� �����. � ������ ������\n";
        cout << "������� �� ����� 500 ����������� (� �������� �������� ����������� ��� ����������� ����� ���� ��������). ";
        sub(0);
        cout << "(������� ������)\n";
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
        cout << "���������: ";
    }
}

vector<int> Analysis::get_cin(int n) 
{
    vector<int> result;
    string temp;
    while (true) 
    {
        getline(cin, temp);
        istringstream iss(temp);
        int ki;
        if (!(iss >> ki) || ki < 0 || ki > 500) 
        {
            cout << "���������:\n";
            continue;
        }
        result.clear();
        int number;
        while (iss >> number) 
        {
            if (number < 1 || number > n) 
            {
                cout << "���������:\n";
                result.clear();
                break;
            }
            result.push_back(number);
        }
        if (result.size() == static_cast<size_t>(ki)) 
        {
            return result;
        }

        cout << "���������: ";
    }
}