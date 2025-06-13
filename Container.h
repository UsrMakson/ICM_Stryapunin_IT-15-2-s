#pragma once

struct Node {// структура контейнера
    int type; 
    Node* next;
};

typedef Node* PNode;

class Container { // класс для структуры
private:
    PNode head;
    int ki;

public:
    Container();// конструктор
    ~Container();// деструктор
    void push_top(int number);// переместить на верх
    void delete_top();// удолить верхний
    void add(int number);// добавить элемент
    int show(int number) const;// вывести элемент
    int size();// вывести размер
    void change_size(int n);// изменить размер
    bool correct_analis();// проверить корректность
    void clear();// очистить 
};