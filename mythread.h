#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore>

class mythread : public QThread
{
public:
    mythread();
    void run();
    QString name;
};

#endif // MYTHREAD_H
