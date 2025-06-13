#include "Container.h"

#include <stdexcept>

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
void Container::push_top(int number) {
    PNode P = new Node{ number, head };
    head = P;
    ki++;
}

void Container::delete_top() {
    if (head == nullptr) return;
    PNode temp = head;
    head = head->next;
    delete temp;
    ki--;
}

int Container::show(int index) const {
    if (head == nullptr || index < 0) throw std::out_of_range("Invalid index");
    PNode current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
        if (current == nullptr) throw std::out_of_range("Index out of bounds");
    }
    return current->type;
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
    while (head != nullptr) {
        PNode P = head;
        head = head->next;
        delete P;
    }
    ki = 0;
}