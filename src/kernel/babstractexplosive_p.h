#ifndef BABSTRACTEXPLOSIVE_P_H
#define BABSTRACTEXPLOSIVE_P_H

#include "babstractexplosive.h"

#include "bbombexplosive.h"

#include <QtCore/qobject.h>

class BBombPrivate;

class BAbstractExplosive;
class BAbstractExplosivePrivate : public QObject, public BBombExplosive
{
    Q_OBJECT
    Q_DISABLE_COPY(BAbstractExplosivePrivate)
    B_DECLARE_PUBLIC(BAbstractExplosive)

public:
    BAbstractExplosivePrivate(BAbstractExplosive &qq);
    ~BAbstractExplosivePrivate();

    inline QString explosiveName() const
    {return q->explosiveName();}

public slots:
    void explode();

signals:
    void exploded();

private slots:
    void explosion();

protected:
    BAbstractExplosive *q;

private:
    void changeBomb(BBombPrivate *b);

    BBombPrivate *bomb;
};

#endif // BABSTRACTEXPLOSIVE_P_H
