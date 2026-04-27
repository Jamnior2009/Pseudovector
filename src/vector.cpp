#include "headers/vector.hpp"

#include <stdexcept>

Pseudovector::vector::vector()
{
    arr = nullptr;
    size = 0;
    maxSize = 0;
    maxSizeSet = false;
}

// Information methods

bool Pseudovector::vector::isEmpty() const
{
    return size == 0;
}

bool Pseudovector::vector::isFull() const
{
    return size == maxSize && maxSizeSet;
}

std::size_t Pseudovector::vector::retSize() const
{
    return size;
}

std::size_t Pseudovector::vector::getMaxSize() const
{
    if(!maxSizeSet)
        return 0;
    
    return maxSize;
}

// Access methods

Pseudovector::type& Pseudovector::vector::getValue(std::size_t index)
{
    if(isEmpty() || index >= size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return arr[index];
}

Pseudovector::type& Pseudovector::vector::at(std::size_t index)
{
    return getValue(index % size);
}

// Modification methods

bool Pseudovector::vector::pushBack(type value)
{
    if(isFull())
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

bool Pseudovector::vector::pushBack(type* arr, std::size_t size)
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


bool Pseudovector::vector::remove(std::size_t index)
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

bool Pseudovector::vector::clean()
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

// Memory management methods

bool Pseudovector::vector::reserve(std::size_t newMaxSize)
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

Pseudovector::vector::~vector()
{
    delete[] arr;
}