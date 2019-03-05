#include "PA5.h"
#include "Data.h"

class QueueNode {
public:
    // Default Constructor
    QueueNode() : pData(nullptr), pNext(nullptr) {}
    // Value Constructor
    QueueNode(Data *_pData, QueueNode *_pNext) : pData(_pData), pNext(_pNext) {}
    // Copy Constructor
    QueueNode(QueueNode &old) : pData(old.pData), pNext(old.pNext) {}
private:
    Data *pData;
    QueueNode *pNext;
}