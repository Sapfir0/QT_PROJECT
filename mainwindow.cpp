#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap> /////////////////////////��� arg1 � ooo �������� �� ppppp
#include <QMessageBox>
#include <QLCDNumber>
//#include "secondwindow.h"
#include <ctime>
//#include "sortings.h"

int ppp=0, ooo=0; //global variables
int program=3;
////
/// \brief DEVELOPER_MODE
///     true - without alerts
///     false - with alert
bool DEVELOPER_MODE=true;

//////////
int MAX_SIZE = 9999;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->consider, SIGNAL(clicked()),this, SLOT(on_consider_clicked(void)));
    connect(ui->test_na_tebya, SIGNAL(clicked()),this, SLOT(test_na_pidor(void)));

    //image
    QPixmap pix(":/new/prefix1/img/logo.png");
    
    int w = ui->label_logo->width();
    int h = ui->label_logo->height();

    ui->label_logo->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));


    ui->printf_result->setText(tr("jopa")); //default
    on_actionPythagorean_theorem_triggered();
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static int count;
    count++;
    ui->printf_result->setText(QString::number(count));
}

void MainWindow::on_consider_clicked(/*int ppp, int ooo*/)
{
    switch (program)
    {///////////////--------------------------------------CASE 1------------------------------------
    case 1:
    {
        if(ppp == 0 || ooo == 0 && DEVELOPER_MODE!=true)
        {
              QMessageBox::information(NULL,("Error 1"),("Why you pressed this button without catets?"));
            //i dont know why this alert play 2 times
            //and its work nestabillno
        }
        else
        //ui->printf_result->setText(QString::number(pifagorianec(ppp, ooo)));

        break;
    }///////////////--------------------------------------CASE 2-------------------------------------

    case 2:
    {
        if(ppp > 1000 && DEVELOPER_MODE!=true)
        {
            QMessageBox msgBox;
            msgBox.setText("Alert");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setInformativeText("It's dangerous count of variable ppp.\n Do u want to reset ppp to 100 ?");
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            switch (ret)
            {
            case QMessageBox::Save:
                 break;
              case QMessageBox::Ok:
                ppp=100;
                 break;
              default:
                 ppp=100;
                 break;
            }

        }
        else
        {
            //ui->printf_result->setText(QString::number(fact(ppp)));
        }
        break;
    }///////////////-------------------------------------CASE 3---------------------------------
    case 3:
    {
        unsigned int start_time =  clock(); // ��������� �����
        int size_array = ppp; //������ ����� ��� ����� ��������� �������
        int *sorted_array = new int [size_array]; // ���������� ������������ ������

        if(ppp>MAX_SIZE && DEVELOPER_MODE!=true)
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
             ppp=MAX_SIZE;
              break;
           default:
              ppp=MAX_SIZE;
              break;
         }

        }


        for (int counter = 0; counter < size_array; counter++)
        {
                sorted_array[counter] = rand() % 100; // ��������� ������ ���������� �������
        }

        //bubbleSort(sorted_array, size_array);

        unsigned int end_time = clock(); // �������� �����
        unsigned int search_time = end_time - start_time; // ������� �����

        //ui->printf_result->setText(QString::number(search_time));
        
        ui->lcdNumber->display(QString::number(search_time/1000.0));

        delete[] sorted_array;
        break;
    }///////////////-------------------------------------CASE 4---------------------------------
    case 4: { //merge sort
         unsigned int start_time_m =  clock(); // ��������� �����
         int size_array = ppp; //������ ����� ��� ����� ��������� �������
         int *a = new int [size_array]; // ���������� ������������ ������

    if(ppp>MAX_SIZE && DEVELOPER_MODE!=true)
    {
        QMessageBox msgBox;
        msgBox.setText("Alert");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setInformativeText("It's dangerous count of variable ppp.\n Do u want to reset ppp to 9999 ?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Save:
             break;
          case QMessageBox::Ok:
            ppp=MAX_SIZE;
             break;
          default:
             ppp=MAX_SIZE;
             break;
        }
    }

     for (int counter = 0; counter < size_array; counter++)
     {
             a[counter] = rand() % 100; // ��������� ������ ���������� �������
     }
       //merge(a, 8); // ����� ������� ����������
       unsigned int end_time_m = clock(); // �������� �����
       unsigned int search_time_m = end_time_m - start_time_m; // ������� �����
       ui->lcdNumber->display(QString::number(search_time_m/1000.0));
    break;
    }///////////////-----------------------------------CASE 5------------------------------------------------

    case 5:
    {
        unsigned int start_time_q =  clock(); // ��������� �����

        int size_array = ppp; //������ ����� ��� ����� ��������� �������
        int *a = new int [size_array]; // ���������� ������������ ������

        if(ppp>MAX_SIZE && DEVELOPER_MODE!=true)
        {
            QMessageBox msgBox;
            // ��������� ���������
            msgBox.setText("Alert");
            // ��� ������ ���������
            msgBox.setIcon(QMessageBox::Information);
            // �������� ��������� Message Box
            msgBox.setInformativeText("It's dangerous count of variable ppp.\n Do u want to reset ppp to 9999 ?");
            // ���������� ������������ �� ���� �������
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            // �� ����� ������ �������������� �� ���������
            msgBox.setDefaultButton(QMessageBox::Ok);
            /* ��������� QMessageBox. ����� ����������, � ret ����� ������ �������� ������, �� ������� ������ - ��� ���������� ��� ���������� ��������� �������*/
            int ret = msgBox.exec();
            // ���������� ��� ���� case � �������� �� ��������� �������
            switch (ret) {
            case QMessageBox::Save:
                 break;
              case QMessageBox::Ok:
                ppp=MAX_SIZE;
                 break;
              default:
                 ppp=MAX_SIZE;
                 // ���� ����� ��������� ������� �� ���������
                 break;
            }
        }
        for (int counter = 0; counter < size_array; counter++)
        {
                a[counter] = rand() % 100; // ��������� ������ ���������� �������
        }
        int puk=0;
        //Qsort( a, 0, size_array, puk);
        unsigned int end_time_q = clock(); // �������� �����
        unsigned int search_time_q = end_time_q - start_time_q; // ������� �����
        ui->lcdNumber->display(QString::number(search_time_q/1000.0));
    break;
    }



    default:
    {
        break;
    }

    }
}


void MainWindow::on_catet_a_valueChanged(int ppp2)
{
    ppp = ppp2;
}
void MainWindow::on_catet_b_valueChanged(int ooo2)
{
    ooo = ooo2;
}

void MainWindow::test_na_pidor()
{
    ui->printf_result->setText(tr("Yes, you are pidor"));
}

void MainWindow::on_actionFactorial_triggered(/*int program*/)
{
    program=2;
    ui->statusBar->showMessage(tr("Factorial"));

}

void MainWindow::on_actionPythagorean_theorem_triggered(/*int program*/)
{
    program=1;
    ui->statusBar->showMessage(tr("Phyphagorian"));
}

void MainWindow::on_actionBubble_sorting_triggered() {
    program=3;

    ui->statusBar->showMessage(tr("Bubble sort"));
}


void MainWindow::on_action_2_triggered()
{
    if(DEVELOPER_MODE!=true)
    {
        QMessageBox::critical(NULL,QObject::tr("Error #0"),tr("Pidors cant have access. Idi nahui!"));
        QApplication::quit();
    }
    else
        QMessageBox::information(NULL,QObject::tr("Error #0"),tr("Ure damn right.\n your cod is very well!"));

}

void MainWindow::on_actionRussian_triggered()
{
    QMessageBox::information(NULL,QObject::tr("Error #0"),tr("Idi nahui, moskal!"));
    QApplication::quit();
}


void MainWindow::on_lcdNumber_overflow()
{
    
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    window = new secondwindow(this);
    window->show();

}

void MainWindow::on_actionEnglish_triggered()
{
    QMessageBox::information(NULL,QObject::tr("Error #0"),tr("Idi nahui, pendos!"));
    QApplication::quit();
}

void MainWindow::on_actionMerge_sorting_triggered()
{
    program=4;
    ui->statusBar->showMessage(tr("Merge sort"));

}

void MainWindow::on_actionSorting_for_daun_triggered()
{
    program=5;
    ui->statusBar->showMessage(tr("Nekit's sort(slowly)"));


}
