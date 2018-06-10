#ifndef EXAMPLETHREADS_H
#define EXAMPLETHREADS_H

#include <QThread>

class mythread : public QThread
{
public:
    explicit mythread(QString threadName);

    // Переопределяем метод run(), в котором будет
    // располагаться выполняемый код
    void run();
private:
    QString name;   // Имя потока
};

#endif // EXAMPLETHREADS_H

