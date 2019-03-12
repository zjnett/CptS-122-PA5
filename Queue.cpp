/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA5
File: Queue.cpp
Description: This program simulates 2 queue-based grocery store lines.
*/

#include "Queue.h"

// printQueue(), recursively prints the queue by printing the customer number. Ends queue printing with newline.
void Queue::printQueue(QueueNode *next) {
	if (next != nullptr) {
		std::cout << "[" << next->getData()->getCustomerNumber() << "] <-- ";
		printQueue(next->getNext());
	}
	else
	{
		std::cout << std::endl;
	}
}

// Predicate function isEmpty, checks if pHead in queue is nullptr (empty if true, else false)
bool Queue::isEmpty() {
	return pHead == nullptr;
}

// enqueue(), takes data provided and inserts it into current instance of queue.
// enqueue function reated based off of class code by Andrew O'Fallon.
bool Queue::enqueue(Data &newData) {
	bool success = false;
	Data *pData = new Data(newData);
	QueueNode *node = new QueueNode(pData);
	if (pData != nullptr) {
		success = true;
		if (pHead == nullptr) {
			pHead = pTail = node;
		}
		else 
		{
			pTail->setNext(node);
			pTail = node;
		}
	}
	return success;
}

// dequeue(), frees the memory associated with pHead (thus removing it from the queue).
// dequeue function reated based off of class code by Andrew O'Fallon.
void Queue::dequeue() {
	QueueNode *temp = nullptr;
	if (pHead == pTail) {
		//one node
		temp = pHead;
		pHead = pTail = nullptr;
		delete temp;
	}
	else
	{
		//more than one node
		temp = pHead;
		pHead = pHead->getNext();
		delete temp;
	}
}

// getHead(), accessor, returns head pointer.
QueueNode *Queue::getHead(void) {
	return pHead;
}

// getTail(), accessor, returns tail pointer.
QueueNode *Queue::getTail(void) {
	return pTail;
}

// calculateSumServiceTimes(), used in simulation to calculate the time spent in a line based on customers in front of the head.
// Note this is prior to insertion.
int Queue::calculateSumServiceTimes(QueueNode *next) {
	int time = 0;
	if (next != nullptr) {
		time = next->getData()->getServiceTime();
		return calculateSumServiceTimes(next->getNext()) + time;
	}
	return time;
}