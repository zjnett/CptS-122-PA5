/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA5
File: Queue.h
Description: This program simulates 2 queue-based grocery store lines.
*/

#pragma once

#include "PA5.h"
#include "QueueNode.h"
#include "Data.h"

class Queue {
public:
    // Default Constructor
    Queue() : pHead(nullptr), pTail(nullptr) {}
    // Value Constructor
    Queue(QueueNode *_pHead, QueueNode *_pTail) : pHead(_pHead), pTail(_pTail) {}
    // Copy Constructor
    Queue(Queue &old) : pHead(old.pHead), pTail(old.pTail) {}

	// printQueue(), recursively prints the queue by printing the customer number. Ends queue printing with newline.
	void printQueue(QueueNode *next);

	// Predicate function isEmpty, checks if pHead in queue is nullptr (empty if true, else false)
	bool isEmpty();

	// enqueue(), takes data provided and inserts it into current instance of queue.
	// enqueue function reated based off of class code by Andrew O'Fallon.
	bool enqueue(Data &newData);

	// dequeue(), frees the memory associated with pHead (thus removing it from the queue).
	// dequeue function reated based off of class code by Andrew O'Fallon.
	void dequeue();

	// getHead(), accessor, returns head pointer.
	QueueNode *getHead(void);

	// getTail(), accessor, returns tail pointer.
	QueueNode *getTail(void);

	// calculateSumServiceTimes(), used in simulation to calculate the time spent in a line based on customers in front of the head.
	// Note this is prior to insertion.
	int calculateSumServiceTimes(QueueNode *next);

private:
    QueueNode *pHead;
    QueueNode *pTail;
};