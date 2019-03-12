#include "PA5.h"

class Data {
public:
    // Default Constructor
    Data() : customerNumber(0), serviceTime(0), totalTime(0) {}
    // Value Constructor
    Data(int _customerNumber, int _serviceTime, int _totalTime) : customerNumber(_customerNumber), serviceTime(_serviceTime), totalTime(_totalTime) {}
    // Copy Constructor
    Data(Data &old) : customerNumber(old.customerNumber), serviceTime(old.serviceTime), totalTime(old.totalTime) {}
private:
    int customerNumber;
    int serviceTime;
    int totalTime;
};