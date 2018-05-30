#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>

#include <QTranslator>
#include <QLibraryInfo>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator qtLanguageTranslator;
    qtLanguageTranslator.load(QString("QtLanguage_") + QString("ru_RU"));
    qApp->installTranslator(&qtLanguageTranslator); //перевод



    MainWindow w;
    w.show();



    return a.exec();
}
