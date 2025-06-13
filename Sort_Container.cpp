#include "Sort_Container.h"

#include <iostream>

using namespace std;

void Sort_Container::sort_and_print(vector<Container*>& stacks) {
    int N = stacks.size();
    vector<pair<int, int>> actions;

    bool changed = true;
    while (changed) {
        changed = false;
        for (int from = 0; from < N; ++from) {
            if (stacks[from]->size() == 0) continue;
            int top_type = stacks[from]->show(0); 
            int to = top_type - 1;
            if (to != from && to >= 0 && to < N) {
                stacks[to]->push_top(top_type);
                stacks[from]->delete_top();
                actions.emplace_back(from + 1, to + 1);
                changed = true;
                break;
            }
        }
    }

    if (!is_sorted(stacks)) {
        cout << "0" << endl;
        return;
    }

    for (const auto& act : actions) {
        cout << act.first << " " << act.second << endl;
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
