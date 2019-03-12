/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA5
File: QueueNode.h
Description: This program simulates 2 queue-based grocery store lines.
*/

#include "QueueNode.h"

// Specific Data Value Constructor (explicit)
QueueNode::QueueNode(Data *_pData) {
	pData = _pData;
}

// Explicit setData mutator for node
void QueueNode::setData(Data *_pData) {
	pData = _pData;
}

// Explicit getData accessor for node
Data *QueueNode::getData(void) {
	return pData;
}

// Explicit setNext mutator for next node pointer (data member) in class node
void QueueNode::setNext(QueueNode* _pNext) {
	pNext = _pNext;
}

// Explicit getNext accessor for next node pointer
QueueNode *QueueNode::getNext(void) {
	return pNext;
}