// Mateusz Ostaszewski, Szymon Trzaskoma, Jan Stańczak

#include <iostream>

#include "headers/vector.hpp"

int main()
{
    Pseudovector::vector vec;
    
    vec.reserve(5);
    vec.pushBack(10);
    vec.pushBack(20);
    vec.pushBack(30);
    
    std::cout << "Vector size: " << vec.retSize() << std::endl;
    
    int* arr = new int[5]{70, 80, 90, 100, 110};
    vec.pushBack(arr, 5);
    
    std::cout << "Test out of index access: " << vec.at(100) << std::endl;

    std::cout << "Vector size: " << vec.retSize() << std::endl;
    
    for(std::size_t i = 0; i < vec.retSize(); i++)
    {
        std::cout << "Element at index " << i << ": " << vec.at(i) << std::endl;
    }

    vec.remove(1);

    std::cout << "After removing element at index 1:" << std::endl;
    for(std::size_t i = 0; i < vec.retSize(); i++)
    {
        std::cout << "Element at index " << i << ": " << vec.getValue(i) << std::endl;
    }

    vec.clean();

    std::cout << "After cleaning the vector, is it empty? " << (vec.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "Trying to access element at index 0 after cleaning: " << std::endl;
    try
    {
        std::cout << vec.getValue(0) << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}