#ifndef BBOMB_H
#define BBOMB_H

#include <Bomb/bglobal.h>

#include <QtCore/qobject.h>
#include <QtCore/qscopedpointer.h>

class BBombPrivate;
class BOMB_EXPORT BBomb : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool armed WRITE setArmed READ isArmed NOTIFY armedStateChanged)
    Q_DISABLE_COPY(BBomb)

public:
    explicit BBomb(QObject *parent = nullptr);
    ~BBomb();

    bool isArmed() const;

public slots:
    void setArmed(bool arm);
    void arm();

signals:
    void armedStateChanged(bool arm);

private:
    QScopedPointer<BBombPrivate> d;

    friend class BBombComponentPrivate;
};

#endif // BBOMB_H
