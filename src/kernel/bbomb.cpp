#include "bbomb.h"
#include "bbomb_p.h"

BBomb::BBomb(QObject *parent) :
    QObject(parent),
    d(new BBombPrivate(*this))
{
}

BBomb::~BBomb()
{
}

bool BBomb::isArmed() const
{
    return d->armed;
}

void BBomb::setArmed(bool arm)
{
    if (d->armed != arm) {
        d->armed = arm;
        emit armedStateChanged(arm);
    }
}

void BBomb::arm()
{
    setArmed(true);
}

BBombPrivate::BBombPrivate(BBomb &qq) :
    q(&qq),
    armed(false)
{
}

BBombPrivate::~BBombPrivate()
{
}

void BBombPrivate::explode()
{
    if (armed) BBombExplosive::explode();
}

void BBombPrivate::switchTimer(bool on)
{
    if (armed != on) BBombTimer::switchTimer(on);
}

void BBombPrivate::startTimer()
{
    BBombTimer::startTimer();
}

void BBombPrivate::stopTimer()
{
    BBombTimer::stopTimer();
}

void BBombPrivate::pressDetonator()
{
    if (armed) BBombDetonator::pressDetonator();
}

void BBombPrivate::releaseDetonator()
{
    if (armed) {
        BBombDetonator::releaseDetonator();
        BBombTimer::startTimer();
    }
}
