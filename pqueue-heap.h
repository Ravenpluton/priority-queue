/**********************************************
 * File: pqueue-heap.h
 *
 * A priority queue class backed by a binary
 * heap.
 */
#ifndef PQueue_Heap_Included
#define PQueue_Heap_Included

#include <string>
using namespace std;

/* A class representing a priority queue backed by an
 * binary heap.
 */
class HeapPriorityQueue {
public:
	/* Constructs a new, empty priority queue backed by a binary heap. */
	HeapPriorityQueue();
	
	/* Cleans up all memory allocated by this priority queue. */
	~HeapPriorityQueue();
	
	/* Returns the number of elements in the priority queue. */
	int size();
	
	/* Returns whether or not the priority queue is empty. */
	bool isEmpty();
	
	/* Enqueues a new string into the priority queue. */
	void enqueue(string value);
	
	/* Returns, but does not remove, the lexicographically first string in the
	 * priority queue.
	 */
	string peek();
	
	/* Returns and removes the lexicographically first string in the
	 * priority queue.
	 */
	string dequeueMin();

private:
	// there is start capacity for heap and
	// method do expand capacity when needed
	static const int CAPACITY = 8;
	void expandCapacity();

	// heap
	string* heap;

	// count holds information about values stored in 
	// heap and capacity holds information about heap capacity
	int count;
	int capacity;

	// method to move value from up to down in heap 
	// if its value is more than value of its child
	void bubbleDown(int index);

	// method to move value from down to up in heap
	// if its value is less than value of its parent
	void bubbleUp(int index);
};

#endif
