#include "babstractexplosive.h"
#include "babstractexplosive_p.h"

#include "bbomb_p.h"

BAbstractExplosive::BAbstractExplosive(BBomb *bomb) :
    QObject(bomb),
    d(new BAbstractExplosivePrivate(*this))
{
    connect(d.data(), &BAbstractExplosivePrivate::exploded, this, &BAbstractExplosive::exploded);

    setBomb(bomb);
}

BAbstractExplosive::~BAbstractExplosive()
{
}

void BAbstractExplosive::setBomb(BBomb *b)
{
    if (d->bomb != (b ? b->d.data() : nullptr))
        d->changeBomb(b ? b->d.data() : nullptr);
}

BBomb *BAbstractExplosive::bomb() const
{
    return d->bomb ? d->bomb->bomb() : nullptr;
}

void BAbstractExplosive::explode()
{
    d->explode();
}

BAbstractExplosivePrivate::BAbstractExplosivePrivate(BAbstractExplosive &qq) :
    q(&qq),
    bomb(nullptr)
{
}

BAbstractExplosivePrivate::~BAbstractExplosivePrivate()
{
}

void BAbstractExplosivePrivate::explode()
{
    BBombExplosive::explode();
}

void BAbstractExplosivePrivate::explosion()
{
    q->explosion();
}

void BAbstractExplosivePrivate::changeBomb(BBombPrivate *b)
{
    if (bomb == b) return;

    if (bomb)
        disconnect(bomb, &BBombPrivate::explosion, this, &BAbstractExplosivePrivate::explode);

    bomb = b;

    if (bomb)
        connect(bomb, &BBombPrivate::explosion, this, &BAbstractExplosivePrivate::explode);
}
