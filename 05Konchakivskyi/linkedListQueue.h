#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include "IQueue.h"
#include <stdexcept>

template <typename T>
class LinkedListQueue : public IQueue<T> {
private:
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& value, Node* next = nullptr) : data(value), next(next) {}
    };

    Node* head;
    Node* tail;
    size_t count;

public:
    LinkedListQueue();
    ~LinkedListQueue() override;
    LinkedListQueue(const LinkedListQueue& other);
    LinkedListQueue& operator=(const LinkedListQueue& other);
    LinkedListQueue(LinkedListQueue&& other) noexcept;
    LinkedListQueue& operator=(LinkedListQueue&& other) noexcept;

    bool empty() const override;
    const T& front() const override;
    void pop() override;
    void put(const T& value) override;
    size_t size() const override;
    const T& peek(size_t index) const override;
};

template <typename T>
LinkedListQueue<T>::LinkedListQueue() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
LinkedListQueue<T>::~LinkedListQueue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
LinkedListQueue<T>::LinkedListQueue(const LinkedListQueue& other) : head(nullptr), tail(nullptr), count(0) {
    Node* current = other.head;
    while (current != nullptr) {
        put(current->data);
        current = current->next;
    }
}

template <typename T>
LinkedListQueue<T>& LinkedListQueue<T>::operator=(const LinkedListQueue& other) {
    if (this != &other) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
        count = 0;

        Node* current = other.head;
        while (current != nullptr) {
            put(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
LinkedListQueue<T>::LinkedListQueue(LinkedListQueue&& other) noexcept
    : head(other.head), tail(other.tail), count(other.count) {
    other.head = nullptr;
    other.tail = nullptr;
    other.count = 0;
}

template <typename T>
LinkedListQueue<T>& LinkedListQueue<T>::operator=(LinkedListQueue&& other) noexcept {
    if (this != &other) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        head = other.head;
        tail = other.tail;
        count = other.count;

        other.head = nullptr;
        other.tail = nullptr;
        other.count = 0;
    }
    return *this;
}

template <typename T>
bool LinkedListQueue<T>::empty() const {
    return count == 0;
}

template <typename T>
const T& LinkedListQueue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }
    return head->data;
}

template <typename T>
void LinkedListQueue<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Queue is empty");
    }

    Node* temp = head;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    --count;
}

template <typename T>
void LinkedListQueue<T>::put(const T& value) {
    Node* newNode = new Node(value);

    if (empty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    ++count;
}

template <typename T>
size_t LinkedListQueue<T>::size() const {
    return count;
}

template <typename T>
const T& LinkedListQueue<T>::peek(size_t index) const {
    if (index >= count) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->data;
}

#endif