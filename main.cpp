#include <iostream>
#include "Vector.h"

int main() {
    Vector<int> nums(5);

    nums.push_back(11);
    nums.push_back(727);
    nums.push_back(69);

    size_t nums_size = nums.get_size();

    std::cout << "Vector Length: " << nums_size << std::endl;
    for (size_t i = 0; i < nums_size; i++) 
        std::cout << "Element " << i << " Value: " << nums[i] << std::endl;

    return 0;
}