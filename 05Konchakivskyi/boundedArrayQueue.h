#ifndef BOUNDED_ARRAY_QUEUE_H
#define BOUNDED_ARRAY_QUEUE_H

#include "IQueue.h"
#include <stdexcept>

template <typename T>
class BoundedArrayQueue : public IQueue<T> {
private:
    T* data;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t count;

public:
    explicit BoundedArrayQueue(size_t capacity);
    ~BoundedArrayQueue() override;
    BoundedArrayQueue(const BoundedArrayQueue& other);
    BoundedArrayQueue& operator=(const BoundedArrayQueue& other);
    BoundedArrayQueue(BoundedArrayQueue&& other) noexcept;
    BoundedArrayQueue& operator=(BoundedArrayQueue&& other) noexcept;

    bool empty() const override;
    const T& front() const override;
    void pop() override;
    void put(const T& value) override;
    size_t size() const override;
    const T& peek(size_t index) const override;
    bool full() const;
    size_t getCapacity() const;
};

template <typename T>
BoundedArrayQueue<T>::BoundedArrayQueue(size_t capacity)
    : capacity(capacity), head(0), tail(0), count(0) {
    data = new T[capacity];
}

template <typename T>
BoundedArrayQueue<T>::~BoundedArrayQueue() {
    delete[] data;
}

template <typename T>
BoundedArrayQueue<T>::BoundedArrayQueue(const BoundedArrayQueue& other)
    : capacity(other.capacity), head(other.head), tail(other.tail), count(other.count) {
    data = new T[capacity];
    for (size_t i = 0; i < capacity; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
BoundedArrayQueue<T>& BoundedArrayQueue<T>::operator=(const BoundedArrayQueue& other) {
    if (this != &other) {
        delete[] data;

        capacity = other.capacity;
        head = other.head;
        tail = other.tail;
        count = other.count;

        data = new T[capacity];
        for (size_t i = 0; i < capacity; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
BoundedArrayQueue<T>::BoundedArrayQueue(BoundedArrayQueue&& other) noexcept
    : data(other.data), capacity(other.capacity), head(other.head),
    tail(other.tail), count(other.count) {
    other.data = nullptr;
    other.capacity = 0;
    other.head = 0;
    other.tail = 0;
    other.count = 0;
}

template <typename T>
BoundedArrayQueue<T>& BoundedArrayQueue<T>::operator=(BoundedArrayQueue&& other) noexcept {
    if (this != &other) {
        delete[] data;

        data = other.data;
        capacity = other.capacity;
        head = other.head;
        tail = other.tail;
        count = other.count;

        other.data = nullptr;
        other.capacity = 0;
        other.head = 0;
        other.tail = 0;
        other.count = 0;
    }
    return *this;
}

template <typename T>
bool BoundedArrayQueue<T>::empty() const {
    return count == 0;
}

template <typename T>
const T& BoundedArrayQueue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data[head];
}

template <typename T>
void BoundedArrayQueue<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    head = (head + 1) % capacity;
    --count;
}

template <typename T>
void BoundedArrayQueue<T>::put(const T& value) {
    if (full()) {
        throw std::out_of_range("Queue is full");
    }
    data[tail] = value;
    tail = (tail + 1) % capacity;
    ++count;
}

template <typename T>
size_t BoundedArrayQueue<T>::size() const {
    return count;
}

template <typename T>
const T& BoundedArrayQueue<T>::peek(size_t index) const {
    if (index >= count) {
        throw std::out_of_range("Index out of range");
    }
    return data[(head + index) % capacity];
}

template <typename T>
bool BoundedArrayQueue<T>::full() const {
    return count == capacity;
}

template <typename T>
size_t BoundedArrayQueue<T>::getCapacity() const {
    return capacity;
}

#endif