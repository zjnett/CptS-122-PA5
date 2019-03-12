/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA5
File: QueueNode.h
Description: This program simulates 2 queue-based grocery store lines.
*/

#pragma once

#include "PA5.h"
#include "Data.h"

class QueueNode {
public:
    // Default Constructor
    QueueNode() : pData(nullptr), pNext(nullptr) {}
    // Value Constructor
    QueueNode(Data *_pData, QueueNode *_pNext) : pData(_pData), pNext(_pNext) {}
	// Data-only Value Constructor
	QueueNode(Data *_pData);
    // Copy Constructor
    QueueNode(QueueNode &old) : pData(old.pData), pNext(old.pNext) {}
	// Explicit setData mutator for node
	void setData(Data *_pData);
	// Explicit getData accessor for node
	Data *getData(void);
	// Explicit setNext mutator for next node pointer (data member) in class node
	void setNext(QueueNode* _pNext);
	// Explicit getNext accessor for next node pointer
	QueueNode *getNext(void);

private:
    Data *pData;
    QueueNode *pNext;
};