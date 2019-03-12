/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA5
File: Tests.h
Description: This program simulates 2 queue-based grocery store lines.
*/

#include "PA5.h"
#include "Queue.h"

#pragma once

class Tests {
public:
    Tests() {}
    ~Tests() {}

	// Function runTests(), test wrapper for test functions
    void runTests(void);

	// testEnqueueEmpty(), tests enqueue() function on empty queue
    void testEnqueueEmpty(void);

	// testEnqueueOneNode(), tests enqueue() function on a queue with one node
    void testEnqueueOneNode(void);

	// testDequeueOneNode(), tests dequeue() function on a queue with one node
    void testDequeueOneNode(void);

	// testDequeueTwoNodes(), tests dequeue() function on a queue with two nodes
    void testDequeueTwoNodes(void);

	// runSim24Hours(), uses runSimuation() function defined in PA5.h to run the simulation for 24 hours
    void runSim24Hours(void);

private:
    //data members
};