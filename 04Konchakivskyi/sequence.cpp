#include <iostream>
#include "sequence.h"
#include "Point.h"

template <typename T>
Sequence<T>::Sequence() {
	capacity = 5; // Starting with a small capacity to test resizing
	size = 0;
	elements = new T[capacity];
}

template <typename T>
Sequence<T>::~Sequence() {
	delete[] elements;
}

template <typename T>
void Sequence<T>::resize() {
	capacity *= 2;
	std::cout << "Resizing array to new capacity: " << capacity << std::endl;

	T* newElements = new T[capacity];

	for (int i = 0; i < size; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
}

template <typename T>
void Sequence<T>::append(const T& element) {
	if (size >= capacity) {
		resize();
	}

	elements[size++] = element;
}

template <typename T>
bool Sequence<T>::remove(const T& element) {
	for (int i = 0; i < size; i++) {
		if (elements[i] == element) {
			for (int j = i; j < size - 1; j++) {
				elements[j] = elements[j + 1];
			}

			size--;
			return true;
		}
	}

	return false;
}

template <typename T>
bool Sequence<T>::contains(const T& element) const {
	for (int i = 0; i < size; i++) {
		if (elements[i] == element) {
			return true;
		}
	}

	return false;
}

template <typename T>
bool Sequence<T>::isEmpty() const {
	return size == 0;
}

template <typename T>
void Sequence<T>::print() const {
	if (isEmpty()) {
		std::cout << "Sequence is empty" << std::endl;
		return;
	}

	std::cout << "Sequence elements: ";
	for (int i = 0; i < size; i++) {
		std::cout << elements[i];
		if (i < size - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

template class Sequence<int>;
template class Sequence<Point>;