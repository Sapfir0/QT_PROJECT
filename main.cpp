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
//#include "mythread.h"
///
/// \brief main         така€ система ветвлени€:   time_calculate.cpp->sortings.h->calculating_time_sort.h
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

//    mythread threadA;
//    mythread  threadB;
//    mythread  threadC;

//    threadA.start();    // «апускаем потоки
//    threadB.start();
//    threadC.start();






//это все дл€ сохранени€ настроек
    /* ƒл€ адекватной регистрации приложени€ в операционной
     * необходимо установить название организации, домен организации,
     * а также название приложени€.
     * ¬се настройки  будут хранитьс€ в операционной системе под этими
     * учетными данными приложени€
     * */
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);






time_calculate mTimer;


  secondwindow w;

  // about_method w;
   w.setMinimumHeight(480);
   w.setMaximumHeight(480);
   w.setMinimumWidth(650);
   w.setMaximumWidth(650);
   // QTimer::singleShot(5000, &w, SLOT(close())); эта фунцки€ закроет окно через 5секунд

    w.show();



    return a.exec();
}
