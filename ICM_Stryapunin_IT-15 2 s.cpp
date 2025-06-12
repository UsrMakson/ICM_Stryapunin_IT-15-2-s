#include "Container.h"
#include "Sort_Container.h"
#include "analysis.h"

#include <iostream>
#include <clocale>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(0, "");
    int n;
    vector<Container*> stack;
    Analysis::sub(0);
    cout << "Для инструкции введите help";
    Analysis::sub(0);
    cout << "(входные данные)\n";
    n = Analysis::get_cin_n();
    for (int i = 0; i < n; i++) {
        int ki;
        cin >> ki;
        Container* container = new Container();

        for (int j = 0; j < ki; j++) {
            int elem;
            cin >> elem;
            container->add(elem);
        }
        stack.push_back(container);
    }
    cout << "(выходные данные)\n";
    Sort_Container sorter;
    sorter.sort_and_print(stack);
    cout << '\n';
    system("pause");
    return 0;
}
