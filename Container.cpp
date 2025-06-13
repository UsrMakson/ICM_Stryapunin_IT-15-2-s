#include "Container.h"

Container::Container()
    : head(nullptr)
    , ki(0)
{
}

Container::~Container()
{
    PNode P = head;
    while (P != nullptr) {
        PNode P1 = P->next;
        delete P;
        P = P1;
    }
    head = nullptr;
}

void Container::push_top(int number)
{
    PNode P = new Node;
    P->type = number;
    P->next = head;
    head = P;
    ki++;
}

void Container::delete_top()
{
    if (head == nullptr) return;
    PNode temp = head;
    head = head->next;
    delete temp;
    ki--;
}

void Container::add(int number)
{
    PNode P2 = new Node;
    P2->type = number;
    P2->next = nullptr;

    if (head == nullptr)
    {
        head = P2;
    }
    else
    {
        PNode P1 = head;
        while (P1->next != nullptr)
        {
            P1 = P1->next;
        }
        P1->next = P2;
    }
    ki++;
}

int Container::show(int number) const 
{
    PNode P = head;
    for (int i = 0; i < number; ++i) 
    {
        P = P->next;
    }
    return P->type;
}

int Container::size()
{
    return ki;
}

void Container::change_size(int n)
{
    if (n == -1)
    {
        ki--;
    }
    else if (n == 1)
    {
        ki++;
    }
    else
    {
        ki = n;
    }
}

bool Container::correct_analis()
{
    if (show(0) == ki)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Container::clear()
{
    PNode P = head;
    while (head != nullptr) 
    {
        PNode P = head;
        head = head->next;
        delete P;
    }
    ki = 0;
}