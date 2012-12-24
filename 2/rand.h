#pragma once
#include "cstdlib"
#include "randInterface.h"
#include "time.h"

class Rand : public RandInterface
{
public:
    int randi()
    {
        srand(time(NULL));
        int n = rand();
        return n;
    }
};

