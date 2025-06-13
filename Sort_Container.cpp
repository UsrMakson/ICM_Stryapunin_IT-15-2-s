#include "Sort_Container.h"
#include <iostream>

using namespace std;

void Sort_Container::sort_and_print(vector<Container*>& stacks)
{
    int N = stacks.size();
    vector<int> froms, tos;
    bool changed = true;
    int iterations = 0;
    while (changed && iterations < 100)
    {
        changed = false;
        iterations++;
        for (int from = 0; from < N; ++from)
        {
            if (stacks[from]->size() == 0) continue;
            int top_type = stacks[from]->show(0);
            int to = top_type - 1;
            if (top_type != from + 1 && to >= 0 && to < N)
            {
                stacks[to]->push_top(top_type);
                stacks[from]->delete_top();
                froms.push_back(from + 1);
                tos.push_back(to + 1);
                changed = true;
                break;
            }
        }
    }
    if (!is_sorted(stacks))
    {
        cout << "0" << endl;
        return;
    }
    for (size_t i = 0; i < froms.size(); ++i)
    {
        cout << froms[i] << " " << tos[i] << endl;
    }
}

bool Sort_Container::is_sorted(const std::vector<Container*>& stacks) const
{
    int N = stacks.size();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < stacks[i]->size(); ++j)
        {
            if (stacks[i]->show(j) != i + 1)
                return false;
        }
    }
    return true;
}