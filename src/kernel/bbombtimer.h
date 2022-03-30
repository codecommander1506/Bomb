#ifndef BBOMBTIMER_H
#define BBOMBTIMER_H

class BBombTimer
{
public:
    BBombTimer();
    virtual ~BBombTimer();

    void setCountDown(int c);
    int countDown() const;

    virtual void switchTimer(bool on);
    bool startTimer();
    void stopTimer();
    bool isTimerActive() const;

protected:
    void setTimerActive(bool act);

    void updateTimer();

    virtual void countDownUpdated(int countDown) = 0;
    virtual void timeout() = 0;

private:
    int _countDown;
    bool _running;
};

#endif // BBOMBTIMER_H
