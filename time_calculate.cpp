#include "time_calculate.h"
#include "ui_time_calculate.h"
#include <QApplication>
#include <QTranslator>
#include <QMessageBox>
#include <QLibraryInfo>
#include <QDebug>
#include "settings.h"

#include "sortings.h"
#include "QRoundProgressBar.h"
 #include <QGraphicsWidget>

#include <QProgressBar>
#include <QThread>

////            ����� ������� ���������:   time_calculate.cpp->calculating_time_sort.h->sortings.h
int arg1=0; //global variable
int program2 = 0;
bool DEV_MODE=true;
int MAX_ACCEPTABLY=9999;


time_calculate::time_calculate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::time_calculate)
{
    ui->setupUi(this);
    ui->progressBar->setValue(85);
    setWindowTitle(tr("Time calculate. S.Prod."));

    resize(650,500); //w/h

	//this->setStyleSheet("QWidget{background-image: url(img/blue-bubbles-9789.jpg);}");  //////////////////////�� ����� (��� ��� ������� �������� ���� �����������)


    connect(ui->consider, SIGNAL(clicked()),this, SLOT(on_consider_clicked(void)));


	ui->comboBox_2->addItems(QStringList() << "ru_RU" << "en_US");
        // ���������� � ������� ��������� ������ ���������� ������ �������,
            // � ������� ����� ���������� ������� ����������
            // ����� ������� ���������� ������. ��������� QComboBox ����� ���������� ��������� �������,
            // �� ��� ���������� ���������� ������ � ������ ���������.
            // � ������ ������ ����� ������������ �������� ������ ��� ��� ���������
	/*connect(ui->comboBox, static_cast<void (QComboBox::*)(const QString&)>(&QComboBox::currentIndexChanged),
                    [=](const QString &str){
		qtLanguageTranslator.load("QtLanguage_" + str, ".");   // ��������� �������
				qApp->installTranslator(&qtLanguageTranslator);       // ������������� ������� � ����������
	});

            // ������� �������������� ������������� �������� ��� ���� ����������
            qtLanguageTranslator.load(QString("QtLanguage_") + QString("ru_RU"));
			qApp->installTranslator(&qtLanguageTranslator);*/


    keyEnter = new QShortcut(this);
    keyEnter->setKey(Qt::Key_Enter);
    connect(keyEnter, SIGNAL(activated()), this, SLOT(slotShortcutEnter()) );//������� ������ ����� - �� �����

////----------------

    timer=new QTimer(this); //��� ��������� ������
    connect(timer, SIGNAL(timeout()), this, SLOT(myslot())); //��� ������ ������ ���


    ui->centralwidget->setStyleSheet("background-image: url(:/new/prefix1/img/blue-bubbles-9789.jpg);");
}

time_calculate::~time_calculate()
{
    delete ui;
}

void time_calculate::on_actionBack_triggered()
{

    secondwindow *back_to_main = new secondwindow;
      hide();
   // back_to_main->setParent(this);
    back_to_main->show();
}
void time_calculate::changeEvent(QEvent *event)
{
    // � ������ ��������� ������� ��������� ����� ����������
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);    // �������� ���� ������
    }
}



void time_calculate::myslot()//������ �������
{

    static double p = 0.001; //���������� ����� 1 ��
    ui->lcdNumber->display(QString::number(p+=0.01)); //+10�� ������ ���
    qDebug() << "timer executed"<< p;

//    if (p>= bubble_sort_time(arg1,MAX_ACCEPTABLY, DEV_MODE) && program2==0) //������� ��� ������
//    {
//        timer->stop();
//        p=(bubble_sort_time(arg1,MAX_ACCEPTABLY, DEV_MODE));
//        ui->lcdNumber->display(QString::number(p));

//    }
}



void time_calculate::on_consider_clicked()
{
    switch (program2)
    {
    case 0:
    {
        timer->start(10);

//        if (p>=bubble_sort_time(arg1,MAX_ACCEPTABLY, DEV_MODE))
//            timer->stop();
        break;
    }
    case 1:
    { //merge sort /////////////////////////---����� ����� ������� �������� �������������, �� ����� ��������� � ���� �����(��� � �� ���� ������� � calculating_time_sort)
        QTime time;
        time.start();
        (merge_sort_time(arg1));
        ui->lcdNumber->display(QString::number(time.elapsed()/1000.0));
        qDebug() << time.elapsed()/1000.0 << " ";

        break;
    }
    case 2:
    {
        ui->lcdNumber->display(QString::number(quick_sort_time(arg1)));
        break;
    }
    case 3:
    {
        ui->lcdNumber->display(QString::number(tree_sort_time(arg1)));
        break;
    }
    case 4:
    {
        ui->lcdNumber->display(QString::number(radix_sort_time(arg1)));
        break;
    }
    default:
        ui->lcdNumber->display("666");

        break;
    }
}

void time_calculate::on_actionRefresh_triggered()
{
    setlocale (LC_ALL,""); // ���������� ������������ �������� ������
    int trollface=0;
    if( trollface==0)
    {
        QMessageBox::critical(NULL,QObject::tr("Error #0"),tr("�������� �������� �������, �����? ������ �������� ������ ��� ���."));
        trollface++;
    }
    if(trollface==1)
    {
        QMessageBox::critical(NULL,QObject::tr("Error #1"),tr("�� �� ����� ��� ���? ������� ��� ���, � ���� ������."));
        trollface++;
    }
    if(trollface==2)
    {
        QMessageBox::critical(NULL,QObject::tr("Error #2"),tr("���� ���, ����������."));
        QApplication::quit();
    }
}

void time_calculate::on_progressBar_valueChanged(int value)
{
//��������
//qlineargradient(linear, 0% 0%, 100%, 0%, color-stop(0,rgb(0,199,0)),color-stop(1,rgb(253,255,0)));
//� ��������� QString green_style= "QProgressBar {border: 2px solid grey;background-color: #02315F;border-radius: 5px;text-align: center;} QProgressBar::chunk {}";

QString red_style = "QProgressBar {border: 2px solid grey;background-color: #02315F;border-radius: 5px;text-align: center;} "
                    "QProgressBar::chunk {background: red;}";
QString orange_style= "QProgressBar {border: 2px solid grey;background-color: #02315F;border-radius: 5px;text-align: center;} "
                      "QProgressBar::chunk {background: orange;}";
QString yellow_style= "QProgressBar {border: 2px solid grey;background-color: #02315F;border-radius: 5px;text-align: center;} "
                      "QProgressBar::chunk {background: yellow;}";
QString green_style= "QProgressBar {border: 2px solid grey;background-color: #02315F;border-radius: 5px;text-align: center;} "
                     "QProgressBar::chunk {background: green;}";
QString green_light_style= "QProgressBar {border: 2px solid grey;background-color: #02315F;border-radius: 5px;text-align: center;} "
                     "QProgressBar::chunk {background: GreenYellow;}";


    if (ui->progressBar->value()<=10)
    {
        ui->progressBar->setStyleSheet(green_style);
        //���� green        //����� ������ = 10%        //������� (c)
    }
    else if (ui->progressBar->value()>10 && ui->progressBar->value()<30)
    {
        ui->progressBar->setStyleSheet(green_light_style);
        //���� green        //����� ������ = 30%        //������� log(n)
    }
    else if (ui->progressBar->value()>=30 &&ui->progressBar->value()<50)
    {
        ui->progressBar->setStyleSheet(yellow_style);
    //���� yellow    //����� ������ = 50%    //������� n
    }
    else if (ui->progressBar->value()>=50 && ui->progressBar->value() < 70)
    {
        ui->progressBar->setStyleSheet(orange_style);
    //���� orange    //����� ������ = 70%    //������� nlog(n)
    }
    else if (ui->progressBar->value()>=70 && ui->progressBar->value() <= 100)
    {
        ui->progressBar->setStyleSheet(red_style);
    //���� red    //����� ������ = 90%    //������� n^2
    }
	value++;

}

void time_calculate::on_comboBox_currentIndexChanged(int index)
{
    if(index==0) //bubble
    {
        ui->statusbar->showMessage(tr("Bubble sort"));
        program2 = index;
        ui->progressBar->setValue(90);
    }
    else if(index==1) //merge
    {
        ui->statusbar->showMessage(tr("Merge sort"));
        program2 = index;
        ui->progressBar->setValue(65);

    }
    else if(index==2) //quick
    {
        ui->statusbar->showMessage(tr("Quick sort"));
        program2 = index;
        ui->progressBar->setValue(45);
    }
    else if(index==3) //tree
    {
        ui->statusbar->showMessage(tr("Tree sort"));
        program2 = index;
        ui->progressBar->setValue(35);
    }
    else if(index==4) //radix
    {
        ui->statusbar->showMessage(tr("Radix sort"));
        program2 = index;
        ui->progressBar->setValue(20);
    }


}

void time_calculate::slotShortcutEnter()
{
    QMessageBox::information(this,
                             "������� �������",
                             "��� ������������!!! ������� ������� ��������",
                             QMessageBox::Ok);
}


void time_calculate::on_elements_count_valueChanged(int arg12)
{
     arg1 = arg12;
}

void time_calculate::on_actionSettings_triggered()
{
    settings *back2 = new settings;
    back2->exec();
}
