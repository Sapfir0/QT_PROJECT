#include "time_calculate.h"
#include "function.h"
#include "secondwindow.h"
#include "settings.h"
#include <QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QQmlContext>
 #include <QQmlApplicationEngine>
#include <QTranslator>
#include <QLibraryInfo>
#include "about_method.h"
//#include <QtConcurrentRun>
#include <QThread>
//#include "constructor.h"
//#include "mythread.h"
#include <QHBoxLayout>
#include "popup.h"
#include "testing_window.h"
/// \brief main         такая система ветвления:   time_calculate.cpp->sortings.h->calculating_time_sort.h
/// \param argc
/// \param argv
/// \return
///

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



 //   qApp->setStyleSheet(file.readAll());


//это все для сохранения настроек
    /* Для адекватной регистрации приложения в операционной
     * необходимо установить название организации, домен организации,
     * а также название приложения.
     * Все настройки  будут храниться в операционной системе под этими
     * учетными данными приложения
     * */
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);






time_calculate mTimer;


 // constructor w;
secondwindow w;
 //   testing_window w;
//   w.setMinimumHeight(480);
//   w.setMaximumHeight(480);
//   w.setMinimumWidth(650);
//   w.setMaximumWidth(650);
// QTimer::singleShot(5000, &w, SLOT(close()));// эта фунцкия закроет окно через 5секунд

    w.show();



    return a.exec();
}
