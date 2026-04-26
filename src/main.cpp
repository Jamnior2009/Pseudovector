// Mateusz Ostaszewski, Szymon Trzaskoma, Jan Stańczak

#include <iostream>

#include "headers/vector.hpp"

int main()
{
    Pseudovector::vector vec;
    vec.reserv(5);
    vec.pushBack(10);
    vec.pushBack(20);
    vec.pushBack(30);
    
    std::cout << "Vector size: " << vec.retSize() << std::endl;
    
    vec.pushBack(40);
    vec.pushBack(50);
    vec.pushBack(60); // This will fail as the vector is full
     
    std::cout << "Test out of index access: " << vec.at(10) << std::endl; // This will return the lowest value of type

    std::cout << "Vector size: " << vec.retSize() << std::endl;
    
    for(std::size_t i = 0; i < vec.retSize(); i++)
    {
        std::cout << "Element at index " << i << ": " << vec.at(i) << std::endl;
    }

    return 0;
}