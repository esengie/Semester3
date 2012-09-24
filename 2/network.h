#ifndef NETWORK_H
#define NETWORK_H
#include "mac.h"
#include "linux.h"
#include "wind.h"
#include "computer.h"
#include "QTest"
#include "sstream"

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
    void run(std::stringstream &chick)
    {
        int j = 0;
        if (!check())
        {
            do
            {
                chick << "New Epoch:" "take " << ++j << std::endl;
                for (int i = 0; i < 10; ++i)
                {
                    if (Computers[i]->isInfected())
                    {
                        chick << "Computer # " << i << " is infected";
                    }
                    else
                    {
                        chick << "Computer # " << i << " isn't' infected";
                    }
                    chick << std::endl;
                }
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
            } while (!check());
        }
        chick << "New Epoch:" "take " << ++j << std::endl;
        for (int i = 0; i < 10; ++i)
        {
            if (Computers[i]->isInfected())
            {
                chick << "Computer # " << i << " is infected";
            }
            else
            {
                chick << "Computer # " << i << " isn't' infected";
            }
            chick << std::endl;
        }
    }
    bool check()
    {
        int k = 0;
        for (int i = 0; i < 10; i++)
        {
            if (Computers[i]->isInfected())
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
