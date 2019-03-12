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

	void setData(Data *_pData);
	Data *getData(void);
	void setNext(QueueNode* _pNext);
	QueueNode *getNext(void);

private:
    Data *pData;
    QueueNode *pNext;
};