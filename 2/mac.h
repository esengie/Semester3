#ifndef MAC_H
#define MAC_H

#include "os.h"
class Mac : public OS
{
public:
    Mac()
    {
        virus_prob = 20;
    }
};

#endif // MAC_H
