#include "Container.h"
#include "analysis.h"
#include "Sort.h"

#include <iostream>
#include <vector>
#include <locale>
#include <cstdlib>
#include <set>

using namespace std;

int main() {
    setlocale(0, "");
    int n;
    vector<Container*> stack;
    Sort sorted;
    Analysis::sub(0);
    cout << "Для инструкции введите help";
    Analysis::sub(0);
    cout << "(входные данные)\n";

    n = Analysis::get_cin_n();// n

    for (int i = 0; i < n; i++) { // задать n контейнеров
        vector<int> arr = Analysis::get_cin(n);
        Container* container = new Container();
        for (int type : arr) {
            container->push_top(type);
        }
        stack.push_back(container);
    }

    cout << "(выходные данные)\n";
    sorted.sort_Container(stack, n);
    for (auto ptr : stack) {
        delete ptr;
    }

    system("pause");
    return 0;
}
