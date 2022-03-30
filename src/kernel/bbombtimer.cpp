#include "bbombtimer.h"

#include <QtCore/qcoreevent.h>

BBombTimer::BBombTimer() :
    _countDown(0),
    _running(false)
{
}

BBombTimer::~BBombTimer()
{
}

void BBombTimer::setCountDown(int c)
{
    if (c < 0) c = 0;
    _countDown = c;
}

int BBombTimer::countDown() const
{
    return _countDown;
}

void BBombTimer::switchTimer(bool on)
{
    setTimerActive(on);
}

bool BBombTimer::startTimer()
{
    switchTimer(true);
    return isTimerActive();
}

void BBombTimer::stopTimer()
{
    switchTimer(false);
}

bool BBombTimer::isTimerActive() const
{
    return _running;
}

void BBombTimer::setTimerActive(bool act)
{
    _running = act;
}

void BBombTimer::updateTimer()
{
    if (!_running) return;

    countDownUpdated(_countDown);
    if (--_countDown < 0) {
        _countDown = 0;
        timeout();
        stopTimer();
    }
}
