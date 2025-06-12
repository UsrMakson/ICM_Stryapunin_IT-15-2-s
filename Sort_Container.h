#pragma once

#include "Container.h"
#include <vector>

class Sort_Container {
public:
    void sort_and_print(std::vector<Container*>& stacks);
private:
    bool is_sorted(const std::vector<Container*>& stacks) const;
};