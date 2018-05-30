#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>

#include <QFile>

#include <QTranslator>
#include <QLibraryInfo>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator qtLanguageTranslator;
    qtLanguageTranslator.load(QString("QtLanguage_") + QString("ru_RU"));
    qApp->installTranslator(&qtLanguageTranslator); //перевод


//    QFile file(":/qss/style.qss");
//    file.open(QFile::ReadOnly);
//    a.setStyleSheet(file.readAll());
//    bool ok = a.exec();
//    return ok;


    MainWindow w;
    w.show();



    return a.exec();
}
