#pragma once
#include "Container.h"

#include <vector>
#include <iostream>

using namespace std;

class Container;

class Sort {
public:
    static void sort_Container(std::vector<Container*>& stack, int n);
};
