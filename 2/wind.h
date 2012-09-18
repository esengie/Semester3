#ifndef WIND_H
#define WIND_H
#include "os.h"
class Wind : public OS
{
public:
    Wind()
    {
        virus_prob = 50;
    }
};

#endif // WIND_H
