#ifndef IQUEUE_H
#define IQUEUE_H

#include <cstddef>

template <typename T>
class IQueue {
public:
	IQueue() {}
	virtual ~IQueue() {}

	virtual bool empty() const = 0;
	virtual const T& front() const = 0;
	virtual void pop() = 0;
	virtual void put(const T& value) = 0;
	virtual size_t size() const = 0;

	virtual const T& peek(size_t index) const = 0;
};

#endif