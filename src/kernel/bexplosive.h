#ifndef BEXPLOSIVE_H
#define BEXPLOSIVE_H

#include <Bomb/bglobal.h>
#include <Bomb/babstractexplosive.h>

#include <QtCore/qscopedpointer.h>

class BExplosivePrivate;
class BOMB_EXPORT BExplosive : public BAbstractExplosive
{
    Q_OBJECT
    Q_DISABLE_COPY(BExplosive)
    B_DECLARE_PRIVATE(BExplosive)

public:
    explicit BExplosive(BBomb *bomb = nullptr, const QString &name = QString());
    ~BExplosive();

    QString explosiveName() const;

signals:
    void explosionOcccured();

protected:
    void explosion();

private:
    QScopedPointer<BExplosivePrivate> d;
};

#endif // BEXPLOSIVE_H
