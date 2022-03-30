#include "bexplosive.h"
#include "bexplosive_p.h"

#include "bbomb.h"
#include "bbomb_p.h"

BExplosive::BExplosive(BBomb *bomb, const QString &name) :
    BAbstractExplosive(bomb),
    d(new BExplosivePrivate(*this, name.isEmpty() && bomb ? bomb->d->explosiveName() : name))
{
}

BExplosive::~BExplosive()
{
}

QString BExplosive::explosiveName() const
{
    B_D(const BExplosive);
    return d->explosive;
}

void BExplosive::explosion()
{
    emit explosionOcccured();
}

BExplosivePrivate::BExplosivePrivate(BExplosive &qq, const QString &name) :
    explosive(name)
{
}

BExplosivePrivate::~BExplosivePrivate()
{
}
