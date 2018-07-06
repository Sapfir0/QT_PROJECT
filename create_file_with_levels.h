#ifndef CREATE_FILE_WITH_LEVELS_H
#define CREATE_FILE_WITH_LEVELS_H

#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QFile>
#include <fstream>
#include <QTextStream>
//удалить если решу что это не нужно

void levels()
{
    QFile level1 ("level 1.txt");
    if (level1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream write_level1 (&level1);
        //записать сюда QStringlist
    }
}
#endif // CREATE_FILE_WITH_LEVELS_H
