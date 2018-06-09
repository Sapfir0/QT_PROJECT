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
/// \brief main         ����� ������� ���������:   time_calculate.cpp->sortings.h->calculating_time_sort.h
/// \param argc
/// \param argv
/// \return
///

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator qtLanguageTranslator;
    qtLanguageTranslator.load(QString("QtLanguage_") + QString("ru_RU"));
    qApp->installTranslator(&qtLanguageTranslator); //�������


//    QFile file(":/qss/style.qss");
//    file.open(QFile::ReadOnly);
//    a.setStyleSheet(file.readAll());
//    bool ok = a.exec();
//    return ok;

    QQmlApplicationEngine engine; // ������ ������ qml

    AppCore appCore;    // ������ ���� ����������
    QQmlContext *context = engine.rootContext();    // ������ �������� ��������
    /* ��������� ������ � �������� ��� ��������� ����������,
     * � ����� ���������� ���, �� �������� ����� ����������� ����������
     * */
    context->setContextProperty("appCore", &appCore);

    // � ��������� � ���� ��������� qml
  //  engine.load(QUrl(QStringLiteral("qrc:/qss/Secondwindow.qml")));



 //   qApp->setStyleSheet(file.readAll());







  secondwindow w;

  // about_method w;
   w.setMinimumHeight(480);
   w.setMaximumHeight(480);
   w.setMinimumWidth(650);
   w.setMaximumWidth(650);
   // QTimer::singleShot(5000, &w, SLOT(close())); ��� ������� ������� ���� ����� 5������

    w.show();



    return a.exec();
}
