#include "Sort.h"

#include <iostream>

using namespace std;

void Sort::sort_Container(vector<Container*> stack, int n)
{
    bool moved_something = true;
    int iterations = 0;

    while (moved_something && iterations < 1000)
    {
        moved_something = false;
        iterations++;
        for (int i = 0; i < n; i++)
        {
            if (stack[i]->size() > 0)
            {
                int top_element = stack[i]->show(0);
                int correct_stack = top_element - 1;
                if (correct_stack >= 0 && correct_stack < n && correct_stack != i) 
                {
                    bool can_move = false;
                    if (stack[correct_stack]->size() == 0) 
                    {
                        can_move = true;
                    }
                    else 
                    {
                        int target_top = stack[correct_stack]->show(0);
                        if (top_element < target_top) 
                        {
                            can_move = true;
                        }
                    }
                    if (can_move)
                    {
                        stack[i]->delete_top();
                        stack[correct_stack]->push_top(top_element);
                        cout << (i + 1) << " " << (correct_stack + 1) << "\n";
                        moved_something = true;
                        break;
                    }
                }
            }
        }
        if (!moved_something)
        {
            for (int i = 0; i < n && !moved_something; i++)
            {
                if (stack[i]->size() > 0) {
                    int top_element = stack[i]->show(0);
                    int correct_stack = top_element - 1;

                    if (correct_stack >= 0 && correct_stack < n && correct_stack != i)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (j != i) {
                                bool can_move = false;

                                if (stack[j]->size() == 0)
                                {
                                    can_move = true;
                                }
                                else
                                {
                                    int target_top = stack[j]->show(0);
                                    if (top_element < target_top)
                                    {
                                        can_move = true;
                                    }
                                }

                                if (can_move)
                                {
                                    stack[i]->delete_top();
                                    stack[j]->push_top(top_element);
                                    cout << (i + 1) << " " << (j + 1) << "\n";
                                    moved_something = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}