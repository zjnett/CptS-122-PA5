#include "PA5.h"
#include "QueueNode.h"

class Queue {
public:
    // Default Constructor
    Queue() : pHead(nullptr), pTail(nullptr) {}
    // Value Constructor
    Queue(QueueNode *_pHead, QueueNode *_pTail) : pHead(_pHead), pTail(_pTail) {}
    // Copy Constructor
    Queue(Queue &old) : pHead(old.pHead), pTail(old.pTail) {}
private:
    QueueNode *pHead;
    QueueNode *pTail;
}