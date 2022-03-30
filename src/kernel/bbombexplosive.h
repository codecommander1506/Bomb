#ifndef BBOMBEXPLOSIVE_H
#define BBOMBEXPLOSIVE_H

#include <QtCore/qstring.h>

class BBombExplosive
{
public:
    BBombExplosive();
    virtual ~BBombExplosive();

    virtual QString explosiveName() const = 0;

    virtual void explode();

protected:
    virtual void explosion() = 0;
    virtual void exploded();
};

#endif // BBOMBEXPLOSIVE_H
