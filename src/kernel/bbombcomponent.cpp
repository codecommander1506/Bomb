#include "bbombcomponent.h"
#include "bbombcomponent_p.h"

#include "bbomb.h"
#include "bbomb_p.h"

BBombComponent::BBombComponent(BBombComponentPrivate &dd) :
    QObject(dd.bomb),
    d(&dd)
{
    dd.init();
}

BBombComponent::~BBombComponent()
{
    d->cleanup();
}

BBomb *BBombComponent::bomb() const
{
    return d->bomb->bomb();
}

void BBombComponent::setBomb(BBomb *bo)
{
    if (d->bomb != BBombComponentPrivate::privateBomb(bo)) {
        d->setBomb(BBombComponentPrivate::privateBomb(bo));
        emit bombChanged(bo);
    }
}

BBombComponentPrivate::BBombComponentPrivate(BBombComponent &qq) :
    q(&qq),
    bomb(nullptr)
{
}

BBombComponentPrivate::~BBombComponentPrivate()
{
}

BBombPrivate *BBombComponentPrivate::privateBomb(BBomb *bo)
{
    return bo ? bo->d.data() : nullptr;
}

void BBombComponentPrivate::init()
{
    if (bomb) bombChanged(nullptr, bomb);
}

void BBombComponentPrivate::cleanup()
{
}

void BBombComponentPrivate::bombChanged(BBombPrivate *oldBomb, BBombPrivate *newBomb)
{
    Q_UNUSED(oldBomb)
    Q_UNUSED(newBomb)
}

void BBombComponentPrivate::setBomb(BBombPrivate *bo)
{
    BBombPrivate *old = bomb;
    bomb = bo;
    bombChanged(old, bo);
}
