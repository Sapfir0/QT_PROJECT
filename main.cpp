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



 //   qApp->setStyleSheet(file.readAll());

//    mythread threadA;
//    mythread  threadB;
//    mythread  threadC;

//    threadA.start();    // ��������� ������
//    threadB.start();
//    threadC.start();






//��� ��� ��� ���������� ��������
    /* ��� ���������� ����������� ���������� � ������������
     * ���������� ���������� �������� �����������, ����� �����������,
     * � ����� �������� ����������.
     * ��� ���������  ����� ��������� � ������������ ������� ��� �����
     * �������� ������� ����������
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
   // QTimer::singleShot(5000, &w, SLOT(close())); ��� ������� ������� ���� ����� 5������

    w.show();



    return a.exec();
}
