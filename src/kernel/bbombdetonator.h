#ifndef BBOMBDETONATOR_H
#define BBOMBDETONATOR_H

class BBombDetonator
{
public:
    BBombDetonator();
    virtual ~BBombDetonator();

    virtual void pressDetonator();
    virtual void releaseDetonator();

protected:
    virtual void detonatorPressed();
    virtual void detonatorReleased();

    virtual void detonatorTriggered() = 0;
};

#endif // BBOMBDETONATOR_H
