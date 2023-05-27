/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

// constructor
// initialises head as null and count as 0
LinkedListPriorityQueue::LinkedListPriorityQueue() {
	head = NULL;
	count = 0;
}

// deconstructor
LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	Cell* current = head;
    while (current != NULL) {
        Cell* previous = current;
        current = current->next;
        delete previous;
    }
}

// returns size of linked list which is count
int LinkedListPriorityQueue::size() {
	return count;
}

// returns if linked list has any elements by 
// checking if count is 0 or not
bool LinkedListPriorityQueue::isEmpty() {
	return count == 0;
}

// enqueues new element. creates new cell and adds
// it at its proper place, which does not mess up
// list and we still have sorted list.
void LinkedListPriorityQueue::enqueue(string value) {
	Cell* current = new Cell;
	current->value = value;
	current->next = NULL;
	
	Cell** previous = &head;
    while((*previous) != NULL && (*previous)->value < value){
        previous = &((*previous)->next);
    }
    current->next = *previous;
	*previous = current;

	count++;
}

// if list is empty puts out error, if not
// returns first value
string LinkedListPriorityQueue::peek() {
	if(isEmpty()){
		error("Can't peek. Queue is empty.");
	}
	return head->value;
}

// if list is empty puts out error, if not
// returns and deletes first value.
string LinkedListPriorityQueue::dequeueMin() {
	if(isEmpty()){
		error("Can't dequeue. Queue is empty.");
	}
	Cell* current = head;
    head = current->next;
    string value = current->value;
    delete current;
    count--;
    return value;
}

