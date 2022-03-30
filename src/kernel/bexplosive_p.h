#ifndef BEXPLOSIVE_P_H
#define BEXPLOSIVE_P_H

#include "bexplosive.h"

class BExplosivePrivate
{
    B_DECLARE_PUBLIC(BExplosive)

public:
    BExplosivePrivate(BExplosive &qq, const QString &name);
    ~BExplosivePrivate();

    inline QString explosiveName() const
    {return explosive;}

private:
    BExplosive *q;
    const QString explosive;
};

#endif // BEXPLOSIVE_P_H
