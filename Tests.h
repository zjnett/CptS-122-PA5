#include "PA5.h"
#include "Queue.h"

#pragma once

class Tests {
public:
    Tests() {}
    ~Tests() {}
    void runTests(void);
    void testEnqueueEmpty(void);
    void testEnqueueOneNode(void);
    void testDequeueOneNode(void);
    void testDequeueTwoNodes(void);
    void runSim24Hours(void);
private:
    //data members
};