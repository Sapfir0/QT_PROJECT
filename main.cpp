#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>

#include <QFile>
#include <QQmlContext>
 #include <QQmlApplicationEngine>
#include <QTranslator>
#include <QLibraryInfo>

#include "appcore.h"



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



  // secondwindow w;
   //MainWindow w;
  //  time_calculate w;
    function w;
    w.show();



    return a.exec();
}
