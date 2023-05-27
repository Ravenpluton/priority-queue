/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

// constructor
// initilises head to null and count to 0
DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head = NULL;
	count = 0;
}

// deconstructor
DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	Cell* current = head;
    while (current != NULL) {
        Cell* prev = current;
        current = current->next;
        delete prev;
    }
}

// returns size of list which is count
int DoublyLinkedListPriorityQueue::size() {
	return count;
}

/* returns if list has any elements by checking
 * if count is zero
 */
bool DoublyLinkedListPriorityQueue::isEmpty() {
	return count == 0;
}

/* enqueues new value. creates new cell and give
 * it values then adds it to the head of the list
 */
void DoublyLinkedListPriorityQueue::enqueue(string value) {
	Cell* current = new Cell;
	current->value = value;
	current->previous = NULL;

	if(head == NULL){
		current->next = NULL;
	} else {
		current->next = head;
		current->next->previous = current;
	}

	head = current;
	count++;
}

/* finds and returns smallest element of list
 * by going over it.
 */
string DoublyLinkedListPriorityQueue::peek() {
	if(isEmpty()){
		error("Can't peek. Queue is empty.");
	}

	string minValue = head->value;
	for(Cell* ptr = head; ptr != NULL; ptr = ptr->next){
		if(ptr->value < minValue){
			minValue = ptr->value;
		}
	}

	return minValue;
}

/* finds and returns smallest element of list by going over it
 * and then removes it by cutting out that element.
 */
string DoublyLinkedListPriorityQueue::dequeueMin() {
	if(isEmpty()){
		error("Can't dequeue. Queue is empty.");
	}

	string minValue = peek();

	Cell* current = head;
	while(current->value != minValue){
		current = current->next;
	}

	if(current->next == NULL && current->previous == NULL){
		head = NULL;
	} else if(current->next != NULL && current->previous == NULL){
		head = current->next;
		head->previous = NULL;
	} else if(current->next == NULL && current->previous != NULL){
		current->previous->next = NULL;
	} else{
		current->previous->next = current->next;
		current->next->previous = current->previous;
	}

	count--;
	delete current;
	return minValue;
}