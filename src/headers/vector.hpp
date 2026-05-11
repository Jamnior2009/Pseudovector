#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

namespace Pseudovector
{
    using type = int; // You can change this to any type you want.

    class vector
    {
    private:
        type* arr;
        std::size_t size, maxSize;

        // Information methods
        bool isFull() const;

    public:
        vector();

        // Information methods
        bool isEmpty() const;
        std::size_t retSize() const;

        // Access methods
        type& getValue(std::size_t index);
        type at(std::size_t index);

        // Modification methods
        bool pushBack(type value);
        bool pushBack(type* arr, std::size_t size);
        bool remove(std::size_t index);
        bool clean();

        // Memory management methods
        bool reserve(std::size_t newMaxSize);

        ~vector();
    };
}

#endif