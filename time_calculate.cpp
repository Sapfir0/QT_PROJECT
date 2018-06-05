#include "time_calculate.h"
#include "ui_time_calculate.h"
#include <QApplication>
#include <QTranslator>
#include <QMessageBox>
#include <QLibraryInfo>
#include <QDebug>
#include <QProgressBar>
#include "sortings.h"
//#include "coloredprogressbar.h" //������� � ������ ���� �����


int arg1=0; //global variable
int program2 = 1;
bool DEV_MODE=false;
int MAX_ACCEPTABLY=9999;

time_calculate::time_calculate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::time_calculate)
{
    ui->setupUi(this);

    //ui->label->setStyleSheet("QLabel{background-color: rgba(135, 206, 235, 80);}");

    connect(ui->consider, SIGNAL(clicked()),this, SLOT(on_consider_clicked(void)));

        ui->comboBox_2->addItems(QStringList() << "ru_RU" << "en_US");
        // ���������� � ������� ��������� ������ ���������� ������ �������,
            // � ������� ����� ���������� ������� ����������
            // ����� ������� ���������� ������. ��������� QComboBox ����� ���������� ��������� �������,
            // �� ��� ���������� ���������� ������ � ������ ���������.
            // � ������ ������ ����� ������������ �������� ������ ��� ��� ���������
            connect(ui->comboBox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
                    [=](const QString &str){
                qtLanguageTranslator.load("QtLanguage_" + str, ".");   // ��������� �������
                qApp->installTranslator(&qtLanguageTranslator);        // ������������� ������� � ����������
            });

            // ������� �������������� ������������� �������� ��� ���� ����������
            qtLanguageTranslator.load(QString("QtLanguage_") + QString("ru_RU"));
            qApp->installTranslator(&qtLanguageTranslator);
}

time_calculate::~time_calculate()
{
    delete ui;
}

void time_calculate::on_actionBack_triggered()
{
//    hide();
//    window_back = new secondwindow(this);   //////////////////////////////////////////�������������
//    window_back->show();
}
void time_calculate::changeEvent(QEvent *event)
{
    // � ������ ��������� ������� ��������� ����� ����������
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);    // �������� ���� ������
    }
}

void time_calculate::on_elements_count_valueChanged(int arg12)
{
     arg1 = arg12;
}

void time_calculate::on_consider_clicked()
{
    switch (program2) {
    case 1:
    {
        unsigned int start_time =  clock(); // ��������� �����
        int size_array = arg1; //������ ����� ��� ����� ��������� �������
        int *sorted_array = new int [size_array]; // ���������� ������������ ������

        if(arg1>MAX_ACCEPTABLY && DEV_MODE!=true)
        {
         QMessageBox msgBox;
         msgBox.setText("Alert");
         msgBox.setIcon(QMessageBox::Information);
         msgBox.setInformativeText("It's dangerous count of variable ppp.\n Do u want to reset ppp to 9999 ?");
         msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
         msgBox.setDefaultButton(QMessageBox::Ok);
         int ret = msgBox.exec();
         switch (ret)
         {
         case QMessageBox::Save:
              break;
           case QMessageBox::Ok:
             arg1=MAX_ACCEPTABLY;
              break;
           default:
              arg1=MAX_ACCEPTABLY;
              break;
         }

        }

        for (int counter = 0; counter < size_array; counter++)
        {
                sorted_array[counter] = rand() % 100; // ��������� ������ ���������� �������
        }

        bubbleSort(sorted_array, size_array);

        unsigned int end_time = clock(); // �������� �����
        unsigned int search_time = end_time - start_time; // ������� �����

        //ui->printf_result->setText(QString::number(search_time));

        ui->lcdNumber->display(QString::number(search_time/1000.0));

        delete[] sorted_array;
     break;
    }


    default:
        break;
    }


}

void time_calculate::on_actionRefresh_triggered()
{
    setlocale (LC_ALL,""); // ���������� ������������ �������� ������
    int trollface=0;
    QMessageBox::critical(NULL,QObject::tr("Error #0"),tr("�������� �������� �������, �����? ������ �������� ������ ��� ���."));
    return;
    trollface++;
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
value=20;

QString style_p = "QProgressBar {border: 2px solid grey;background-color: #02315F;border-radius: 5px;text-align: center;}";

QString red_style = "QProgressBar::chunk {background: red;}";
QString orange_style= "QProgressBar::chunk {background: orange;}";
QString yellow_style= "QProgressBar::chunk {background: yellow;}";
QString green_style= "QProgressBar::chunk {background: green;}";
//    1. C � ���������
//    2. log(log(N))
//    3. log(N)
//    5. N
//    6. N*log(N)
//    9. N!
//QProgressBar {
//    border: 2px solid grey;
//    background-color: #02315F;
//    border-radius: 5px;
//    text-align: center;
//    color: red;
//}
//QProgressBar::chunk {
//    background-color: #05B8CC;  /*  */
//    width: 20px;

ui->progressBar->setStyleSheet(style_p);

    if (ui->progressBar->value()<30)
    {

        ui->progressBar->setStyleSheet(green_style);


    }


    //���� green
    //����� ������ = 30%
    //������� log(n)

    else if (ui->progressBar->value()>=30 &&ui->progressBar->value()<50)
    {
        ui->progressBar->setStyleSheet(yellow_style);

    //���� yellow
    //����� ������ = 50%
    //������� n
    }
    else if (ui->progressBar->value()>=50 && ui->progressBar->value() < 70)
    {
        ui->progressBar->setStyleSheet(orange_style);

    //���� orange
    //����� ������ = 70%
    //������� n^2
    }
    else if (ui->progressBar->value()>=70 && ui->progressBar->value() <= 100)
    {
        ui->progressBar->setStyleSheet(red_style);

    //���� red
    //����� ������ = 90%
    //������� 2^n
    }

}
