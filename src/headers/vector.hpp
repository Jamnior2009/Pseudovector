#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

namespace Pseudovector
{
    using type = int;

    class vector
    {
    private:
        type* arr;
        std::size_t size, maxSize;
        bool maxSizeSet;

    public:
        vector();

        // Information methods
        bool isEmpty() const;
        bool isFull() const;
        std::size_t retSize() const;
        std::size_t getMaxSize() const;

        // Access methods
        type& getValue(std::size_t index);
        type& at(std::size_t index);

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