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

int Analysis::get_cin_n() {
    string temp;
    while (true) {
        getline(cin, temp);
        if (temp == "help") {
            sub(1);
            continue;
        }
        istringstream iss(temp);
        int number;
        if (iss >> number && number >= 1 && number <= 500) {
            return number;
        }
        cout << "������������ ����. ���������: ";
    }
}

vector<int> Analysis::get_cin(int n) {
    vector<int> result;
    string temp;
    while (true) {
        getline(cin, temp);
        istringstream iss(temp);
        int number;
        result.clear();

        while (iss >> number) {
            result.push_back(number);
        }
        if (result.empty()) {
            cout << "���������:\n";
            continue;
        }

        int ki = result[0];
        if (ki < 0 || ki > 500) {
            cout << "���������:\n";
            continue;
        }

        if (!result.empty() && result.size() > 1) {
            return { result.begin() + 1, result.end() };
        }

        cout << "���������:\n";
    }
}