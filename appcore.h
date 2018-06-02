#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>

class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = 0);

signals:
    // ������ ��� �������� ������ � qml-���������
    void sendToQml(int count);

public slots:
    // ���� ��� ����� ������ �� qml-����������
    void receiveFromQml();

private:
    int count;  // �������, ������� ����� �����������
};

#endif // APPCORE_H
