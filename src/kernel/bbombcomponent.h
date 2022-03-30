#ifndef BBOMBCOMPONENT_H
#define BBOMBCOMPONENT_H

#include <Bomb/bglobal.h>

#include <QtCore/qobject.h>
#include <QtCore/qscopedpointer.h>

class BBomb;

class BBombComponentPrivate;
class BOMB_EXPORT BBombComponent : public QObject
{
    Q_OBJECT
    Q_PROPERTY(BBomb *bomb WRITE setBomb READ bomb NOTIFY bombChanged)

public:
    virtual ~BBombComponent();

    BBomb *bomb() const;

public slots:
    void setBomb(BBomb *bo);

signals:
    void bombChanged(BBomb *bo);

protected:
    BBombComponent(BBombComponentPrivate &dd);

    QScopedPointer<BBombComponentPrivate> d;
};

#endif // BBOMBCOMPONENT_H
