#include "bbombexplosive.h"

BBombExplosive::BBombExplosive()
{    
}

BBombExplosive::~BBombExplosive()
{
}

void BBombExplosive::explode()
{
    if (!explosiveName().isEmpty()) {
        explosion();
        exploded();
    }
}

void BBombExplosive::exploded()
{
}
