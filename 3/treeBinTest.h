#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include "treeBin.h"

class TreeBinTest : public QObject
{
    Q_OBJECT
public:
    explicit TreeBinTest(QObject *parent = 0): QObject(parent) {}
private slots:
    void init()
    {
        mTree = new TreeBin();
    }
    void cleanup()
    {
        delete mTree;
    }
    void iteratorTest()
    {
        mTree->insert(3);
        mTree->insert(7);
        mTree->insert(9);
        mTree->insert(5);
        TreeBin::iterator one(mTree);
        QVERIFY(one.next() == 3);
        QVERIFY(one.next() == 7);
    }

private:
    TreeBin* mTree;
};

