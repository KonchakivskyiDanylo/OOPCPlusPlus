#ifndef SEQUENCE_H
#define SEQUENCE_H

template <typename T>
class Sequence {
private:
	T* elements;
	int capacity;
	int size;

	void resize();

public:
	Sequence();

	~Sequence();

	void append(const T& element);

	bool remove(const T& element);

	bool contains(const T& element) const;

	bool isEmpty() const;

	void print() const;
};

#endif