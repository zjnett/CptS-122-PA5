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

	void printQueue(QueueNode *next);

	bool isEmpty();

	bool enqueue(Data &newData);

	void dequeue();

	QueueNode *getHead(void);

	QueueNode *getTail(void);

	int calculateSumServiceTimes(QueueNode *next);

private:
    QueueNode *pHead;
    QueueNode *pTail;
};