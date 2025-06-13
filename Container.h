#pragma once

#include <stdexcept>

class Container
{
private:
    struct Node {
        int type;
        Node* next;
    };
    typedef Node* PNode;
    PNode head;
    void change_size(int n);
    int ki;
public:
    Container();
    ~Container();
    void push_top(int number);
    void delete_top();
    void add(int number);
    int show(int number) const;
    int size();
    bool correct_analis();
    void clear();
};

