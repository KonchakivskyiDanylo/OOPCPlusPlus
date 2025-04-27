# C++ OOP Fifth Project - NaUKMA
This repository contains my fifth project for the C++ Object-Oriented Programming course at the National University of Kyiv-Mohyla Academy (NaUKMA).

## Task Description
Define an abstract queue class according to the provided template and implement multiple realizations of this abstract class:
1. Array-based implementation (bounded queue)
2. List-based implementation
3. Array-based implementation (unbounded queue)

Additionally, implement a "peek" functionality for the queue (bonus option).

The abstract class template is provided as:
```cpp
template class IQueue {
public:
    IQueue() {}
    virtual ~IQueue() {}
    bool empty() const;
    const T& front() const;
    void pop();
    void put(const T& value);
    size_t size() const;
}
```

## Implementation
This repository contains the implementation of an abstract queue interface and three different concrete implementations, following object-oriented programming principles and best practices in C++. The implementation focuses on proper inheritance hierarchy, virtual methods, and efficient data management specific to each implementation.

## Project Structure
- `IQueue<T>` - abstract base class template for queue interface
- `ArrayQueue<T>` - bounded queue implementation using fixed-size array
- `ListQueue<T>` - queue implementation using linked list
- `DynamicArrayQueue<T>` - unbounded queue implementation using dynamic array
- Peek functionality implementation
- Test cases demonstrating functionality

## Current Evaluation: TBD (Not yet evaluated)
