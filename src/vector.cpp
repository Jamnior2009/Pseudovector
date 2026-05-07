#include "headers/vector.hpp"

#include <stdexcept>

constexpr std::size_t DEFAULT_MAX_SIZE = 10;

Pseudovector::vector::vector()
{
    arr = nullptr;
    size = 0;
    maxSize = DEFAULT_MAX_SIZE;
}

// Information methods

bool Pseudovector::vector::isFull() const
{
    return size == maxSize;
}

bool Pseudovector::vector::isEmpty() const
{
    return size == 0;
}

std::size_t Pseudovector::vector::retSize() const
{
    return size;
}

// Access methods

Pseudovector::type& Pseudovector::vector::getValue(std::size_t index)
{
    if(isEmpty() || index > size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    return arr[index];
}

Pseudovector::type Pseudovector::vector::at(std::size_t index)
{
    return getValue(index % size);
}

// Modification methods

bool Pseudovector::vector::pushBack(type value)
{
    if(isEmpty())
    {
        arr = new type[maxSize];
        size++;
        arr[size - 1] = value;
    }
    else if(isFull())
    {
        type* temp = new type[size];
        for(std::size_t i = 0; i < size; i++)
            temp[i] = arr[i];

        delete[] arr;

        maxSize += DEFAULT_MAX_SIZE;
        arr = new type[maxSize];
        for(std::size_t i = 0; i < size; i++)
            arr[i] = temp[i];

        delete[] temp;
        size++;
        arr[size - 1] = value;
    }
    else
    {
        size++;
        arr[size - 1] = value;
    }

    return true;
}

bool Pseudovector::vector::pushBack(type* arr, std::size_t size)
{
    if(isEmpty())
    {
        this->size = size;
        while(maxSize < this->size)
            maxSize += DEFAULT_MAX_SIZE;

        this->arr = new type[maxSize];
        for(std::size_t i = 0; i < this->size; i++)
            this->arr[i] = arr[i];
    }
    else if(isFull() || this->size + size > maxSize)
    {
        type* temp = new type[this->size];
        for(std::size_t i = 0; i < this->size; i++)
            temp[i] = this->arr[i];

        delete[] this->arr;

        while(maxSize < this->size + size)
            maxSize += DEFAULT_MAX_SIZE;

        this->arr = new type[maxSize];
        for(std::size_t i = 0; i < this->size; i++)
            this->arr[i] = temp[i];

        delete[] temp;

        for(std::size_t i = 0; i < size; i++)
            this->arr[this->size + i] = arr[i];

        this->size += size;
    }
    else
    {
        for(std::size_t i = 0; i < size; i++)
            this->arr[this->size + i] = arr[i];

        this->size += size;
    }

    return true;
}


bool Pseudovector::vector::remove(std::size_t index)
{
    if(isEmpty() || index >= size)
        return false;
    else if(size == 1)
    {
        delete[] arr;
        arr = nullptr;
        size = 0;
        maxSize = DEFAULT_MAX_SIZE;
    }
    else
    {
        type* temp = new type[size - 1];

        for(std::size_t i = 0; i < size; i++)
            if(i != index)
                temp[i < index ? i : i - 1] = arr[i];

        delete[] arr;
        arr = new type[maxSize];

        for(std::size_t i = 0; i < size - 1; i++)
            arr[i] = temp[i];

        delete[] temp;
        size--;
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
        maxSize = DEFAULT_MAX_SIZE;
    }

    return true;
}

// Memory management methods

bool Pseudovector::vector::reserve(std::size_t newMaxSize)
{
    maxSize = newMaxSize;

    if(maxSize < size && arr != nullptr)
    {
        size = maxSize;
        type* temp = new type[maxSize];
        for(std::size_t i = 0; i < size; i++)
            temp[i] = arr[i];

        delete[] arr;

        arr = new type[maxSize];
        for(std::size_t i = 0; i < size; i++)
            arr[i] = temp[i];
        
        delete[] temp;
    }
    else if(maxSize > size && arr != nullptr)
    {
        type* temp = new type[size];
        for(std::size_t i = 0; i < size; i++)
            temp[i] = arr[i];

        delete[] arr;

        arr = new type[maxSize];
        for(std::size_t i = 0; i < size; i++)
            arr[i] = temp[i];

        delete[] temp;
    }
    else if(maxSize < size && arr == nullptr)
    {
        size = maxSize;
    }
    else if(maxSize > size && arr == nullptr)
    {
        arr = new type[maxSize];
    }
    
    return true;
}

Pseudovector::vector::~vector()
{
    delete[] arr;
}