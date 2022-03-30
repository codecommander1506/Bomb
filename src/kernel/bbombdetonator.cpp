#include "bbombdetonator.h"

BBombDetonator::BBombDetonator()
{
}

BBombDetonator::~BBombDetonator()
{
}

void BBombDetonator::pressDetonator()
{
    detonatorPressed();
}

void BBombDetonator::releaseDetonator()
{
    detonatorReleased();
    detonatorTriggered();
}

void BBombDetonator::detonatorPressed()
{
}

void BBombDetonator::detonatorReleased()
{
}
