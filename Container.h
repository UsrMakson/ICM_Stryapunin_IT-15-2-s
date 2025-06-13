#pragma once

struct Node {
    int type;
    Node* next;
};

typedef Node* PNode;

class Container {
private:
    PNode head;
    int ki;

public:
    Container();
    ~Container();
    void push_top(int number);
    void delete_top();
    void add(int number);
    int show(int number) const;
    int size();
    void change_size(int n);
    bool correct_analis();
    void clear();
};