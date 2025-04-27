#ifndef UNBOUNDED_ARRAY_QUEUE_H
#define UNBOUNDED_ARRAY_QUEUE_H

#include "IQueue.h"
#include <stdexcept>

template <typename T>
class UnboundedArrayQueue : public IQueue<T> {
private:
    T* data;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t count;

    void resize(size_t newCapacity);

public:
    explicit UnboundedArrayQueue(size_t initialCapacity = 10);
    ~UnboundedArrayQueue() override;
    UnboundedArrayQueue(const UnboundedArrayQueue& other);
    UnboundedArrayQueue& operator=(const UnboundedArrayQueue& other);
    UnboundedArrayQueue(UnboundedArrayQueue&& other) noexcept;
    UnboundedArrayQueue& operator=(UnboundedArrayQueue&& other) noexcept;

    bool empty() const override;
    const T& front() const override;
    void pop() override;
    void put(const T& value) override;
    size_t size() const override;
    const T& peek(size_t index) const override;
    size_t getCapacity() const;
};

template <typename T>
UnboundedArrayQueue<T>::UnboundedArrayQueue(size_t initialCapacity)
    : capacity(initialCapacity), head(0), tail(0), count(0) {
    data = new T[capacity];
}

template <typename T>
UnboundedArrayQueue<T>::~UnboundedArrayQueue() {
    delete[] data;
}

template <typename T>
UnboundedArrayQueue<T>::UnboundedArrayQueue(const UnboundedArrayQueue& other)
    : capacity(other.capacity), head(other.head), tail(other.tail), count(other.count) {
    data = new T[capacity];
    for (size_t i = 0; i < capacity; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
UnboundedArrayQueue<T>& UnboundedArrayQueue<T>::operator=(const UnboundedArrayQueue& other) {
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
UnboundedArrayQueue<T>::UnboundedArrayQueue(UnboundedArrayQueue&& other) noexcept
    : data(other.data), capacity(other.capacity), head(other.head),
    tail(other.tail), count(other.count) {
    other.data = nullptr;
    other.capacity = 0;
    other.head = 0;
    other.tail = 0;
    other.count = 0;
}

template <typename T>
UnboundedArrayQueue<T>& UnboundedArrayQueue<T>::operator=(UnboundedArrayQueue&& other) noexcept {
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
void UnboundedArrayQueue<T>::resize(size_t newCapacity) {
    T* newData = new T[newCapacity];

    for (size_t i = 0; i < count; ++i) {
        newData[i] = data[(head + i) % capacity];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
    head = 0;
    tail = count;
}

template <typename T>
bool UnboundedArrayQueue<T>::empty() const {
    return count == 0;
}

template <typename T>
const T& UnboundedArrayQueue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return data[head];
}

template <typename T>
void UnboundedArrayQueue<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    head = (head + 1) % capacity;
    --count;
}

template <typename T>
void UnboundedArrayQueue<T>::put(const T& value) {
    if (count == capacity) {
        resize(capacity * 2);
    }
    data[tail] = value;
    tail = (tail + 1) % capacity;
    ++count;
}

template <typename T>
size_t UnboundedArrayQueue<T>::size() const {
    return count;
}

template <typename T>
const T& UnboundedArrayQueue<T>::peek(size_t index) const {
    if (index >= count) {
        throw std::out_of_range("Index out of range");
    }
    return data[(head + index) % capacity];
}

template <typename T>
size_t UnboundedArrayQueue<T>::getCapacity() const {
    return capacity;
}

#endif