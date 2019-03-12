#include "QueueNode.h"

// Specific Data Value Constructor (explicit)
QueueNode::QueueNode(Data *_pData) {
	pData = _pData;
}

void QueueNode::setData(Data *_pData) {
	pData = _pData;
}

Data *QueueNode::getData(void) {
	return pData;
}

void QueueNode::setNext(QueueNode* _pNext) {
	pNext = _pNext;
}

QueueNode *QueueNode::getNext(void) {
	return pNext;
}