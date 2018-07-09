#ifndef CONSTRUCTOR_FUNCTIONS_H
#define CONSTRUCTOR_FUNCTIONS_H

#include "constructor.h"


void randomList(QStringList &List)
{
    for (int i = 0; i < List.size(); i++)
    {
        for (int j = 0; j < List.size(); j++)
        {
            if (rand()%2)
            {
                std::swap(List[i], List[j]);
            }
        }
    }
}

void readFileInStringList(QString filename, QStringList &List)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream writeStream(&file);
        while (!writeStream.atEnd())
            List.append(writeStream.readLine());
        file.close();
    }
    else
    {
        throw 0;
    }
}


#endif // CONSTRUCTOR_FUNCTIONS_H
