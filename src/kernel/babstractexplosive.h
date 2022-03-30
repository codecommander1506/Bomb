#ifndef BABSTRACTEXPLOSIVE_H
#define BABSTRACTEXPLOSIVE_H

#include <Bomb/bglobal.h>
#include <Bomb/bbomb.h>

#include <QtCore/qobject.h>
#include <QtCore/qscopedpointer.h>

class BAbstractExplosivePrivate;
class BOMB_EXPORT BAbstractExplosive : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(BAbstractExplosive)
    Q_PROPERTY(QString explosiveName READ explosiveName CONSTANT)
    Q_PROPERTY(BBomb *bomb READ bomb CONSTANT)
    B_DECLARE_PRIVATE(BAbstractExplosive)

public:
    explicit BAbstractExplosive(BBomb *bomb = nullptr);
    virtual ~BAbstractExplosive();

    virtual QString explosiveName() const = 0;

    void setBomb(BBomb *b);
    BBomb *bomb() const;

public slots:
    virtual void explode();

signals:
    void exploded();

protected:
    virtual void explosion() = 0;

private:
    QScopedPointer<BAbstractExplosivePrivate> d;
};

#endif // BABSTRACTEXPLOSIVE_H
