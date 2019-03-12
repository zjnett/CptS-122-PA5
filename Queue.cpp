#include "Queue.h"

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

bool Queue::isEmpty() {
	return pHead == nullptr;
}


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

QueueNode *Queue::getHead(void) {
	return pHead;
}

QueueNode *Queue::getTail(void) {
	return pTail;
}

int Queue::calculateSumServiceTimes(QueueNode *next) {
	int time = 0;
	if (next != nullptr) {
		time = next->getData()->getServiceTime();
		return calculateSumServiceTimes(next->getNext()) + time;
	}
	return time;
}