///
///
/// appcore ����� ��� qml ����� ���

#include "appcore.h"

AppCore::AppCore(QObject *parent) : QObject(parent)
{
    count = 0;
}

void AppCore::receiveFromQml()
{
    count++;
    emit sendToQml(count);
}
