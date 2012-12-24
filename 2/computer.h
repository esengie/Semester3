#ifndef COMPUTER_H
#define COMPUTER_H
#include "randInterface.h"
#include "os.h"
#include "time.h"

const int NUMELTS = 100;

class Computer
{
public:
    Computer(OS* g, bool state, RandInterface* randi): operate(g), isInfected_m(state), rand(randi) {}
    void virus()
    {
        int n = rand->randi() % (NUMELTS + 1);

        if (n > operate->get_prob())
        {
            isInfected_m = true;
        }
    }
    bool isInfected()
    {
        return isInfected_m;
    }
private:
    OS* operate;
    bool isInfected_m;
    RandInterface* rand;
};

#endif // COMPUTER_H
