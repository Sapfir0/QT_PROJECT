#ifndef EXAMPLETHREADS_H
#define EXAMPLETHREADS_H

#include <QThread>

class mythread : public QThread
{
public:
    explicit mythread(QString threadName);

    // �������������� ����� run(), � ������� �����
    // ������������� ����������� ���
    void run();
private:
    QString name;   // ��� ������
};

#endif // EXAMPLETHREADS_H

