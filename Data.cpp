/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA5
File: Data.cpp
Description: This program simulates 2 queue-based grocery store lines.
*/

#include "Data.h"

// getCustomerNumber(), accessor, returns customer #.
int Data::getCustomerNumber(void) {
	return customerNumber;
}

// getServiceTime(), accessor, returns service time.
int Data::getServiceTime(void) {
	return serviceTime;
}

// getTotalTime(), accessor, returns total time.
int Data::getTotalTime(void) {
	return totalTime;
}