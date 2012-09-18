#ifndef NETWORK_H
#define NETWORK_H
#include "mac.h"
#include "linux.h"
#include "wind.h"
#include "computer.h"
#include "QTest"

class Network
{
public:
    Network(int waiter, Computer** comp, int* net[10]): wait_m(waiter)
    {
        Computers = comp;
        for (int i = 0; i < 10; ++i)
        {
            net_m[i] = net[i];
        }
    }
    void run()
    {
        while (check())
        {
            for (int i = 0; i < 10; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    if (net_m[i][j])
                    {
                        if (Computers[i]->isInfected())
                            Computers[j]->virus();
                    }
                }
            }
        wait();
        }
    }
    bool check()
    {
        int k = 0;
        for (int i = 0; i < 10; i++)
        {
            if (Computers[i])
                k++;
        }
        return (k > 9);
    }

private:
    void wait()
    {
        QTest::qSleep((wait_m * 100));
    }
    int wait_m;
    Computer** Computers;
    int* net_m[10];
};

#endif // NETWORK_H
