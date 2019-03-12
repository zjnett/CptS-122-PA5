/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA5
File: PA5.h
Description: This program simulates 2 queue-based grocery store lines.
*/

#pragma once

#include <iostream>
#include <string>
#include <time.h>

// Constant macro for number of minutes in an hour. Used for readability.
#define MIN_IN_HOUR 60

// runSimulation(), runs grocery store simulation with various counters and two queues according to problem specification.
void runSimulation(int numMinutes);