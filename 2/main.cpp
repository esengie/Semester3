#pragma once
#include "mac.h"
#include "linux.h"
#include "wind.h"
#include "computer.h"
#include "network.h"
int main()
{
    Computer* Computers[10];
    Computers[0] = new Computer(new(Mac), 1);
    Computers[1] = new Computer(new(Wind), 1);
    Computers[2] = new Computer(new(Mac), 0);
    Computers[3] = new Computer(new(Linux), 0);
    Computers[4] = new Computer(new(Wind), 0);
    Computers[5] = new Computer(new(Linux), 0);
    Computers[6] = new Computer(new(Wind), 0);
    Computers[7] = new Computer(new(Mac), 1);
    Computers[8] = new Computer(new(Linux), 0);
    Computers[9] = new Computer(new(Linux), 1);
    int network_m[10][10] =
    {
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };
    int *netw[10];
    for (int i = 0; i < 10; ++i)
    {
        netw[i] = network_m[i];
    }
    Network test(1, Computers, netw);
    test.run();
    //NetworkTest test;
    //QTest::qExec(&test);
    return 0;
}
