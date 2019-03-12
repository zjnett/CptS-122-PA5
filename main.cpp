/*
Programmer: Zach Nett
Class: CptS 122; Lab Section 5
Programming Assignment: PA5
File: main.cpp
Description: This program simulates 2 queue-based grocery store lines.
*/

#include "PA5.h"
#include "Queue.h"
#include "Tests.h"

using std::cout;
using std::endl;

int main(void) {
	// Sets random number generation seed based on time
	srand(time(NULL));

	Tests t;
	t.runTests();

    return 0;
}

// runSimulation(), runs grocery store simulation with various counters and two queues according to problem specification.
/* SPECIFICATION:
1. Generate a random number between 1 – 5 and 3 – 8 for express and normal lanes, respectively. This represents the arrival time of the first customer into each lane. Set the variable for total time elapsed to 0.
2. As customers arrive into each line, randomly generate a service time for each. Start processing the customers in the lanes based on service time. Randomly generate the arrival time of the next customer into each line. Elapsed time should be updated by one unit.
3. As each minute elapses, a new customer may arrive and/or another customer may be done checking out. Display the appropriate messages as described above.
4. For every 10 minutes, print out the entire queue for each line
Repeat steps 2 through 4 for n minutes of simulation.
*/
void runSimulation(int numMinutes) {
	int totalTimeElapsed = 0;
	int customerCount = 1;
	int normalLaneArrival = rand() % 5 + 1;
	int expressLaneArrival = rand() % 8 + 3;

	Queue normalLane;
	Queue expressLane;

	int minsUntilNextNormal = normalLaneArrival;
	int minsUntilNextExpress = expressLaneArrival;

	int normalFrontTimer = 0;
	int expressFrontTimer = 0;

	// Simulation Loop Executes Once Per "Minute"
	while (totalTimeElapsed < numMinutes) {

		if (normalFrontTimer < 0 && !normalLane.isEmpty()) {
			normalFrontTimer = normalLane.getTail()->getData()->getServiceTime();
		}
		
		if (expressFrontTimer < 0 && !expressLane.isEmpty()) {
			expressFrontTimer = expressLane.getTail()->getData()->getServiceTime();
		}

		if (minsUntilNextNormal == 0) {
			// Add customer into normal line
			int serviceTime = rand() % 5 + 1;
			int sumTimes = normalLane.calculateSumServiceTimes(normalLane.getHead());
			int totalTime = serviceTime + sumTimes;
			Data *customer = new Data(customerCount++, serviceTime, totalTime);
			cout << "Customer #" << customer->getCustomerNumber() << " has entered the Normal Lane at Time " << totalTimeElapsed << "m." << endl;
			normalLane.enqueue(*customer);
			minsUntilNextNormal = rand() % 5 + 1;
		}
		else 
		{
			minsUntilNextNormal--;
		}

		if (minsUntilNextExpress == 0) {
			// Add customer into express line
			int serviceTime = rand() % 8 + 3;
			int sumTimes = expressLane.calculateSumServiceTimes(expressLane.getHead());
			int totalTime = serviceTime + sumTimes;
			Data *customer = new Data(customerCount++, serviceTime, totalTime);
			cout << "Customer #" << customer->getCustomerNumber() << " has entered the Express Lane at Time " << totalTimeElapsed << "m." << endl;
			expressLane.enqueue(*customer);
			minsUntilNextExpress = rand() % 8 + 3;
		}
		else 
		{
			minsUntilNextExpress--;
		}

		if (normalFrontTimer == 0 && !normalLane.isEmpty()) {
			cout << "Customer #" << normalLane.getHead()->getData()->getCustomerNumber() << " has finished checking out of the Normal Lane." << endl;
			int time = normalLane.getHead()->getData()->getTotalTime();
			cout << "They were in line for " << time << "m and exited at " << totalTimeElapsed << "m." << endl;
			normalLane.dequeue();
			//if (!normalLane.isEmpty())
			//	normalFrontTimer = normalLane.getTail()->getData()->getServiceTime();
			//else
			//	normalFrontTimer = 0;
		}

		if (expressFrontTimer == 0 && !expressLane.isEmpty()) {
			cout << "Customer #" << expressLane.getHead()->getData()->getCustomerNumber() << " has finished checking out of the Express Lane." << endl;
			int time = expressLane.getHead()->getData()->getTotalTime();
			cout << "They were in line for " << time << "m and exited at " << totalTimeElapsed << "m." << endl;
			expressLane.dequeue();
			//if (!expressLane.isEmpty())
			//	expressFrontTimer = expressLane.getTail()->getData()->getServiceTime();
			//else
			//	expressFrontTimer = 0;
		}

		if (totalTimeElapsed % 10 == 0) {
			cout << "TIME ELAPSED: " << totalTimeElapsed << "m" << endl;
			cout << "NORMAL LANE:" << endl;
			normalLane.printQueue(normalLane.getHead());
			cout << "EXPRESS LANE:" << endl;
			expressLane.printQueue(expressLane.getHead());
		}	

		totalTimeElapsed++;
		normalFrontTimer--;
		expressFrontTimer--;
	}
}