#ifndef BABSTRACTTIMER_H
#define BABSTRACTTIMER_H

#include <Bomb/bglobal.h>

#include <QtCore/qobject.h>
#include <QtCore/qscopedpointer.h>

class BAbstractTimerPrivate;
class BAbstractTimer : public QObject
{
public:
    BAbstractTimer();
};

#endif // BABSTRACTTIMER_H
