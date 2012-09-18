#ifndef COMPUTER_H
#define COMPUTER_H
#include "cstdlib"
#include "os.h"
#include "time.h"

const int NUMELTS = 100;

class Computer
{
public:
    Computer(OS* g, bool state): operate(g), isInfected_m(state) {}
    void virus()
    {
        srand(time(NULL));
        int n = rand() % (NUMELTS + 1);
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

};

#endif // COMPUTER_H
