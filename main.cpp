#include "Vector.h"
#include <iostream>
#include <string>
#include <chrono>

void vector_status(auto& vec) {
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector contents: ";

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) {
            std::cout << ", ";
        }
    }
}

int main() {
    auto start_1 = std::chrono::high_resolution_clock::now();
    Vector<std::string> names_1{};
    vector_status(names_1);
    std::cout << std::endl << std::endl;

    names_1.push_back("Nate Skibidi Skibidi Skibidi");
    vector_status(names_1);
    std::cout << std::endl << std::endl;

    names_1.push_back("Daniel Skibidi Skibidi Skibidi");
    vector_status(names_1);
    std::cout << std::endl << std::endl;

    names_1.push_back("Bryant Skibidi Skibidi Skibidi");
    vector_status(names_1);
    std::cout << std::endl << std::endl;

    names_1.push_back("Hunter Skibidi Skibidi Skibidi");
    vector_status(names_1);
    std::cout << std::endl << std::endl;

    names_1.push_back("Shane Skibidi Skibidi Skibidi");
    vector_status(names_1);
    std::cout << std::endl;
    auto end_1 = std::chrono::high_resolution_clock::now();

    double runtime_1 = std::chrono::duration<double>(end_1 - start_1).count();

    auto start_2 = std::chrono::high_resolution_clock::now();
    Vector<std::string> names_2{};
    vector_status(names_2);
    std::cout << std::endl << std::endl;

    names_2.push_back(std::string("Nate Skibidi Skibidi Skibidi"));
    vector_status(names_2);
    std::cout << std::endl << std::endl;

    names_2.push_back(std::string("Daniel Skibidi Skibidi Skibidi"));
    vector_status(names_2);
    std::cout << std::endl << std::endl;

    names_2.push_back(std::string("Bryant Skibidi Skibidi Skibidi"));
    vector_status(names_2);
    std::cout << std::endl << std::endl;

    names_2.push_back(std::string("Hunter Skibidi Skibidi Skibidi"));
    vector_status(names_2);
    std::cout << std::endl << std::endl;

    names_2.push_back(std::string("Shane Skibidi Skibidi Skibidi"));
    vector_status(names_2);
    std::cout << std::endl << std::endl; 
    auto end_2 = std::chrono::high_resolution_clock::now();

    double runtime_2 = std::chrono::duration<double>(end_2 - start_2).count();

    std::cout << "lvalue time: " << runtime_1 << std::endl;
    std::cout << "rvalue time: " << runtime_2 << std::endl;

    return 0;
}