// Mateusz Ostaszewski, Szymon Trzaskoma, Jan Stańczak

#include <iostream>

#include "headers/vector.hpp"

int main()
{
    // Creating an instance of the vector class
    Pseudovector::vector vec;
    
    // Reserving space for 5 elements
    vec.reserve(5);

    // Adding elements to the vector
    vec.pushBack(10);
    vec.pushBack(20);
    vec.pushBack(30);
    
    // Output the current size of the vector
    std::cout << "Vector size: " << vec.retSize() << std::endl;

    // Adding an array of elements to the vector
    int* arr = new int[5]{70, 80, 90, 100, 110};
    vec.pushBack(arr, 5);
    
    // Accessing elements in the vector
    std::cout << "Test out of index access: " << vec.at(100) << std::endl;

    // Output the current size of the vector and its elements
    std::cout << "Vector size: " << vec.retSize() << std::endl;
    
    // Output the elements in the vector
    for(std::size_t i = 0; i < vec.retSize(); i++)
    {
        std::cout << "Element at index " << i << ": " << vec.at(i) << std::endl;
    }

    // Removing an element from the vector
    vec.remove(1);

    // Output the current size of the vector and its elements after removal
    std::cout << "After removing element at index 1:" << std::endl;
    for(std::size_t i = 0; i < vec.retSize(); i++)
    {
        std::cout << "Element at index " << i << ": " << vec.getValue(i) << std::endl;
    }
    // Cleaning the vector
    vec.clean();

    // Checking if the vector is empty after cleaning
    std::cout << "After cleaning the vector, is it empty? " << (vec.isEmpty() ? "Yes" : "No") << std::endl;

    // Attempting to access an element after cleaning the vector to demonstrate exception handling
    std::cout << "Trying to access element at index 0 after cleaning: " << std::endl;
    try
    {
        std::cout << vec.getValue(0) << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Clean up the dynamically allocated array
    delete[] arr;
    return 0;
}