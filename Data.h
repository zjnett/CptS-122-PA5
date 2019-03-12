/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA5
File: Data.h
Description: This program simulates 2 queue-based grocery store lines.
*/

#pragma once

#include "PA5.h"

class Data {
public:
    // Default Constructor
    Data() : customerNumber(0), serviceTime(0), totalTime(0) {}
    // Value Constructor
    Data(int _customerNumber, int _serviceTime, int _totalTime) : customerNumber(_customerNumber), serviceTime(_serviceTime), totalTime(_totalTime) {}
    // Copy Constructor
    Data(Data &old) : customerNumber(old.customerNumber), serviceTime(old.serviceTime), totalTime(old.totalTime) {}

	// getCustomerNumber(), accessor, returns customer #.
	int getCustomerNumber(void);

	// getServiceTime(), accessor, returns service time.
	int getServiceTime(void);

	// getTotalTime(), accessor, returns total time.
	int getTotalTime(void);

private:
    int customerNumber;
    int serviceTime;
    int totalTime;
};