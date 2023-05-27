/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

// constructos
// intialises capacity of heap, heap itself and count to zero.
HeapPriorityQueue::HeapPriorityQueue() {
	capacity = CAPACITY;
	heap = new string[capacity];
	count = 0;
}

// deconstructor
HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] heap;
}

// returns size of heap by returnning count
int HeapPriorityQueue::size() {	
	return count;
}

// checks if heap has any elements by checking if count is zero.
bool HeapPriorityQueue::isEmpty() {
	return count == 0;
}

// enqueues new element at the bottom of heap and moves it up if needed.
void HeapPriorityQueue::enqueue(string value) {
	if(count == capacity - 1){
		expandCapacity();
	}

	heap[++count] = value;
	bubbleUp(count);
}

/* returns top element of heap
 * if heap is empty puts out error
 */
string HeapPriorityQueue::peek() {
	if(isEmpty()){
		error("Can't peek. Queue is empty.");
	}
	return heap[1];
}

/* moves top element of heap to bottom, returns
 * and deletes it. moves new top element to
 * bottom if needed.
 * if heap is empty puts out error.
 */
string HeapPriorityQueue::dequeueMin() {
	if(isEmpty()){
		error("Can't dequeue. Queue is empty.");
	}

	string minValue = peek();

	heap[1] = heap[count--];
	bubbleDown(1);

	return minValue;
}

// doubles capacity if new space is needed
void HeapPriorityQueue::expandCapacity(){
	string* old = heap;
	capacity *= 2;
	heap = new string[capacity];
	
	for(int i = 1; i <= count; i++){
		heap[i] = old[i];
	}

	delete[] old;
}

/* moves bottom element to top if it
 * is smaller than its parent element.
 */
void HeapPriorityQueue::bubbleUp(int index){
	if(index <= 1) return;

	int parentsIndex = index / 2;
	if(heap[parentsIndex] > heap[index]){
		swap(heap[parentsIndex], heap[index]);
		bubbleUp(parentsIndex);
	}
}

/* moves top element to bottom if it
 * if bigger than its child element.
 */
void HeapPriorityQueue::bubbleDown(int index){
	int leftIndex = 2 * index;
	int rightIndex = 2 * index + 1;

	if(leftIndex <= count && rightIndex <= count){
		int minIndex;

		if(heap[leftIndex] < heap[rightIndex]){
			minIndex = leftIndex;
		} else {
			minIndex = rightIndex;
		}

		if(heap[index] > heap[minIndex]){
			swap(heap[index], heap[minIndex]);
			bubbleDown(minIndex);
		}
	}
	
	if(leftIndex <= count){
		if(heap[index] > heap[leftIndex]){
			swap(heap[index], heap[leftIndex]);
		}
	}
}
