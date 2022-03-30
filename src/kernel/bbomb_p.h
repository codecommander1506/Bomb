#ifndef BBOMB_P_H
#define BBOMB_P_H

#include "bbomb.h"

#include "bbombexplosive.h"
#include "bbombtimer.h"
#include "bbombdetonator.h"

#include <QtCore/qobject.h>

class BBombPrivate : public QObject, public BBombExplosive, public BBombTimer, public BBombDetonator
{
    Q_OBJECT
    Q_DISABLE_COPY(BBombPrivate)
    B_DECLARE_PUBLIC(BBomb)

public:
    BBombPrivate(BBomb &qq);
    virtual ~BBombPrivate();

    inline QString explosiveName() const
    {return QStringLiteral("C4");}

    inline bool isArmed() const
    {return armed;}

    inline BBomb *bomb() const
    {return q;}

public slots:
    void explode();

    void switchTimer(bool on);
    void startTimer();
    void stopTimer();

    void pressDetonator();
    void releaseDetonator();

signals:
    void explosion();
    void exploded();

    void countDownUpdated(int value);
    void timeout();

    void detonatorPressed();
    void detonatorReleased();
    void detonatorTriggered();

private:
    BBomb *q;
    bool armed;
};

#endif // BBOMB_P_H
