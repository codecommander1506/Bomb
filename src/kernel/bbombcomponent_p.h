#ifndef BBOMBCOMPONENT_P_H
#define BBOMBCOMPONENT_P_H

#include "bbombcomponent.h"

class BBombPrivate;

class BBombComponentPrivate
{
    B_DECLARE_PUBLIC(BBombComponent)

public:
    BBombComponentPrivate(BBombComponent &qq);
    ~BBombComponentPrivate();

    inline BBombComponent *bombComponent() const
    {return q;}

    inline BBombPrivate *getBomb() const
    {return bomb;}

    static BBombPrivate *privateBomb(BBomb *bo);

protected:
    virtual void init();
    virtual void cleanup();

    virtual void bombChanged(BBombPrivate *oldBomb, BBombPrivate *newBomb);

    BBombComponent *q;

private:
    void setBomb(BBombPrivate *bo);

    BBombPrivate *bomb;
};

#endif // BBOMBCOMPONENT_P_H
