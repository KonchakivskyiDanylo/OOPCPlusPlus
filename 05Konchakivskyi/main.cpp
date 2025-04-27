#include <iostream>
#include <string>
#include "BoundedArrayQueue.h"
#include "UnboundedArrayQueue.h"
#include "LinkedListQueue.h"

template <typename T, typename QueueType>
void testQueue(QueueType& queue, const std::string& queueName) {
	std::cout << "=== " << queueName << " ===:\n";

	queue.put(10);
	queue.put(20);
	queue.put(30);
	queue.put(40);
	queue.put(50);

	std::cout << "Size: " << queue.size() << "\n";

	std::cout << "Front element: " << queue.front() << "\n";

	std::cout << "Element at index 2: " << queue.peek(2) << "\n";

	std::cout << "Popping 3 elements\n";
	queue.pop();
	queue.pop();
	queue.pop();

	std::cout << "Size: " << queue.size() << "\n";
	std::cout << "Front element: " << queue.front() << "\n";

	std::cout << "Pushing elements: 60, 70\n";
	queue.put(60);
	queue.put(70);

	std::cout << "Size: " << queue.size() << "\n";
	std::cout << "Front element: " << queue.front() << "\n";

	std::cout << "Elements in queue: ";
	for (size_t i = 0; i < queue.size(); ++i) {
		std::cout << queue.peek(i) << " ";
	}
	std::cout << "\n\n";
}

template <typename QueueType>
void testCopyMove(const std::string& queueName) {
	std::cout << "=== " << queueName << "copy and move ===:\n";

	QueueType original(10);
	for (int i = 1; i <= 5; ++i) {
		original.put(i * 10);
	}

	std::cout << "Original queue: ";
	for (size_t i = 0; i < original.size(); ++i) {
		std::cout << original.peek(i) << " ";
	}
	std::cout << "\n";

	QueueType copied(original);
	std::cout << "Copied queue: ";
	for (size_t i = 0; i < copied.size(); ++i) {
		std::cout << copied.peek(i) << " ";
	}
	std::cout << "\n";

	original.pop();
	original.put(60);

	std::cout << "Original after modification: ";
	for (size_t i = 0; i < original.size(); ++i) {
		std::cout << original.peek(i) << " ";
	}
	std::cout << "\n";

	std::cout << "Copied queue: ";
	for (size_t i = 0; i < copied.size(); ++i) {
		std::cout << copied.peek(i) << " ";
	}
	std::cout << "\n";

	QueueType moved(std::move(original));
	std::cout << "Moved queue: ";
	for (size_t i = 0; i < moved.size(); ++i) {
		std::cout << moved.peek(i) << " ";
	}

	std::cout << "\n\n";
}

void testBoundedQueueCapacity() {
	std::cout << "=== BoundedArrayQueue capacity limitation ===\n";

	BoundedArrayQueue<int> queue(5);

	std::cout << "Queue capacity: " << queue.getCapacity() << "\n";

	for (int i = 1; i <= 5; ++i) {
		queue.put(i * 10);
	}

	try {
		std::cout << "Adding element";
		queue.put(60);
		std::cout << "Succeeded\n";
	}
	catch (const std::exception& e) {
		std::cout << "Failed: " << e.what() << "\n";
	}

	std::cout << "Size: " << queue.size() << "\n\n";
}

void testUnboundedQueueResizing() {
	std::cout << "=== Testing UnboundedArrayQueue automatic resizing ===\n";

	UnboundedArrayQueue<int> queue(5);

	std::cout << "Initial capacity: " << queue.getCapacity() << "\n";

	for (int i = 1; i <= 6; ++i) {
		queue.put(i * 10);
	}

	std::cout << "New capacity: " << queue.getCapacity() << "\n";
	std::cout << "Size: " << queue.size() << "\n";

	std::cout << "Elements in queue: ";
	for (size_t i = 0; i < queue.size(); ++i) {
		std::cout << queue.peek(i) << " ";
	}
}

int main() {
	BoundedArrayQueue<int> boundedQueue(10);
	testQueue<int>(boundedQueue, "BoundedArrayQueue");

	LinkedListQueue<int> linkedQueue;
	testQueue<int>(linkedQueue, "LinkedListQueue");

	UnboundedArrayQueue<int> unboundedQueue;
	testQueue<int>(unboundedQueue, "UnboundedArrayQueue");

	testCopyMove<BoundedArrayQueue<int>>("BoundedArrayQueue");
	testCopyMove<UnboundedArrayQueue<int>>("UnboundedArrayQueue");

	testBoundedQueueCapacity();
	testUnboundedQueueResizing();

	return 0;
}