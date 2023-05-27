/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

// constructor
VectorPriorityQueue::VectorPriorityQueue() {
	// done automatically
}

// deconstructor
VectorPriorityQueue::~VectorPriorityQueue() {
	// done automatically
}

// returns size of queue by calling size of vector
int VectorPriorityQueue::size() {
	return priorityQueue.size();
}

// returns if queue is empty by checking if vector in empty
bool VectorPriorityQueue::isEmpty() {
	return priorityQueue.isEmpty();
}

// enqueues new value by adding it to vector
void VectorPriorityQueue::enqueue(string value) {
	priorityQueue.add(value);
}

// finds and returns smallest value from vector.
// puts out error if queue is empty.
string VectorPriorityQueue::peek() {
	if (isEmpty()) {
		error("Can't peek. Queue is empty.");
	}

	string min = priorityQueue[0];
	for(int i = 0; i < priorityQueue.size(); i++){
		if(priorityQueue[i] < min){
			min = priorityQueue[i];
		}
	}

	return min;
}

// finds and returns smalles element, also 
// removes it
string VectorPriorityQueue::dequeueMin() {
	if (isEmpty()) {
		error("Can't dequeue. Queue is empty.");
	}

	int minIndex = 0;
	for(int i = 0; i < priorityQueue.size(); i++){
		if(priorityQueue[i] < priorityQueue[minIndex]){
			minIndex = i;
		}
	}

	string result = priorityQueue[minIndex];
	priorityQueue.remove(minIndex);
	return result;
}
