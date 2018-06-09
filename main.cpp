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

#include "appcore.h"
///
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

    QQmlApplicationEngine engine; // Создаём движок qml

    AppCore appCore;    // Создаём ядро приложения
    QQmlContext *context = engine.rootContext();    // Создаём корневой контекст
    /* Загружаем объект в контекст для установки соединения,
     * а также определяем имя, по которому будет происходить соединение
     * */
    context->setContextProperty("appCore", &appCore);

    // И загружаем в него исходники qml
  //  engine.load(QUrl(QStringLiteral("qrc:/qss/Secondwindow.qml")));



 //   qApp->setStyleSheet(file.readAll());







  secondwindow w;

  // about_method w;
   w.setMinimumHeight(480);
   w.setMaximumHeight(480);
   w.setMinimumWidth(650);
   w.setMaximumWidth(650);
   // QTimer::singleShot(5000, &w, SLOT(close())); эта фунцкия закроет окно через 5секунд

    w.show();



    return a.exec();
}
