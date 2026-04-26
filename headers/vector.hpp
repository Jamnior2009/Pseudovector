#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

namespace ppm
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

        bool isEmpty() const;
        bool isFull() const;

        bool reserv(std::size_t newMaxSize);
        std::size_t retSize() const;
        bool pushBack(type value);
        bool pushBack(type* arr, std::size_t size);
        type& pop(std::size_t index);
        type& at(std::size_t index);
        bool remove(std::size_t index);
        bool clean();

        ~vector();
    };
}

#endif