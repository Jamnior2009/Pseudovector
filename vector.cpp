#include "headers/vector.hpp"

#include <limits>

ppm::vector::vector()
{
    arr = nullptr;
    size = 0;
    maxSize = 0;
    maxSizeSet = false;
}

bool ppm::vector::isEmpty() const
{
    return size == 0;
}

bool ppm::vector::isFull() const
{
    return size == maxSize && maxSizeSet;
}

bool ppm::vector::reserv(std::size_t newMaxSize)
{
    maxSizeSet = true;
    maxSize = newMaxSize;

    
    if(!isEmpty() && size < maxSize)
    {
        type* temp = new type[size];

        for(std::size_t i = 0; i < size; i++)
            temp[i] = arr[i];

        delete[] arr;
        arr = new type[maxSize];
     
        for(std::size_t i = 0; i < maxSize; i++)
            arr[i] = temp[i];

        delete[] temp;
    }
    else if(!isEmpty() && size >= maxSize)
    {
        type* temp = new type[maxSize];

        for(std::size_t i = 0; i < maxSize; i++)
            temp[i] = arr[i];

        delete[] arr;
        arr = new type[maxSize];

        for(std::size_t i = 0; i < maxSize; i++)
            arr[i] = temp[i];

        delete[] temp;
    }
    
    return true;
}

std::size_t ppm::vector::retSize() const
{
    return size;
}

bool ppm::vector::pushBack(type value)
{
    if(!isFull())
        return false;
    else
    {
        type* temp = new type[size];
        for(std::size_t i = 0; i < size; i++)
            temp[i] = arr[i];

        size++;

        delete[] arr;
        arr = new type[size];
        for(std::size_t i = 0; i < size - 1; i++)
            arr[i] = temp[i];
            
        delete[] temp;
        arr[size - 1] = value;
    }

    return true;
}

bool ppm::vector::pushBack(type* arr, std::size_t size)
{
    if((this->size + size > maxSize && maxSizeSet) || isFull())
        return false;
    else
    {
        type* temp = new type[this->size];
        for(std::size_t i = 0; i < this->size; i++)
            temp[i] = this->arr[i];

        this->size += size;

        delete[] this->arr;
        this->arr = new type[this->size];
        for(std::size_t i = 0; i < this->size - size; i++)
            this->arr[i] = temp[i];
            
        delete[] temp;

        for(std::size_t i = 0; i < size; i++)
            this->arr[this->size - size + i] = arr[i];
    }

    return true;
}

ppm::type& ppm::vector::pop(std::size_t index)
{
    if(isEmpty() || index >= size)
    {
        return 
    }

    return arr[index];
}

ppm::type& ppm::vector::at(std::size_t index)
{
    return pop(index % size);
}

bool ppm::vector::remove(std::size_t index)
{
    if(isEmpty() || index >= size)
        return false;
    else
    {
        type* temp = new type[size - 1];
        for(std::size_t i = 0; i < index; i++)
            temp[i] = arr[i];
        for(std::size_t i = index + 1; i < size; i++)
            temp[i - 1] = arr[i];

        size--;

        delete[] arr;
        arr = new type[size];
        for(std::size_t i = 0; i < size; i++)
            arr[i] = temp[i];
            
        delete[] temp;
    }

    return true;
}

bool ppm::vector::clean()
{
    if(isEmpty())
        return false;
    else
    {
        delete[] arr;
        arr = nullptr;
        size = 0;
    }

    return true;
}