#ifndef NETWORKTEST_H
#define NETWORKTEST_H

#include <QObject>
#include "network.h"
#include <sstream>

class NetworkTest : public QObject
{
    Q_OBJECT
public:
    explicit NetworkTest(QObject *parent = 0): QObject(parent){}
private slots:
    void init()
    {
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
        test = new Network(1, Computers, netw, 1);
    }
    void cleanup()
    {
        for (int i = 0; i < 10; i++)
        {
            delete Computers[i];
        }
        delete test;
    }
    void testHalting()
    {
        srand(1000);
        test->run(kink);
        QVERIFY(true);
    }

private:
    Computer* Computers[10];
    Network* test;
    std::stringstream kink;
};

#endif // NETWORKTEST_H
