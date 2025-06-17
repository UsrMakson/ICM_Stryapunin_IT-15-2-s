#include "Sort.h"
#include <vector>
#include <iostream>
using namespace std;

bool canMoveTo(const vector<Container*>& stack, int from, int to) {
    if (stack[from]->size() == 0) return false;
    int top = stack[from]->show(0);
    if (to >= 0 && to < stack.size() && to != from) {
        if (stack[to]->size() == 0) return true;
        int targetTop = stack[to]->show(0);
        return top < targetTop;
    }
    return false;
}

void move(vector<Container*>& stack, int from, int to) {
    int top = stack[from]->show(0);
    stack[from]->delete_top();
    stack[to]->push_top(top);
    cout << (from + 1) << " " << (to + 1) << endl;
}

void Sort::sort_Container(vector<Container*>& stack, int n) {
    bool moved_something = true;
    int iterations = 0;
    while (moved_something && iterations < 1000) {
        moved_something = false;
        iterations++;
        for (int i = 0; i < n && !moved_something; i++) {
            if (stack[i]->size() == 0) continue;
            int top = stack[i]->show(0);
            int correct = top - 1;
            if (canMoveTo(stack, i, correct)) {
                move(stack, i, correct);
                moved_something = true;
                break;
            }
            for (int j = 0; j < n && !moved_something; j++) {
                if (j == correct || j == i) continue;
                if (canMoveTo(stack, i, j)) {
                    move(stack, i, j);
                    moved_something = true;
                    break;
                }
            }
        }
    }
}
