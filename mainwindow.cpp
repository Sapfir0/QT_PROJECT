#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QLCDNumber>
#include "secondwindow.h"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "sortings.h"

int arg1=0, arg2=0; //global variables
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

  //  connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(on_lcdNumber_overflow(void)));

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

void MainWindow::on_consider_clicked(/*int arg1, int arg2*/)
{
    switch (program)
    {///////////////--------------------------------------CASE 1------------------------------------
    case 1:
    {
        if(arg1 == 0 || arg2 == 0 && DEVELOPER_MODE!=true)
        {
              QMessageBox::information(NULL,("Error 1"),("Why you pressed this button without catets?"));
            //i dont know why this alert play 2 times
            //and its work nestabillno
        }
        else
        ui->printf_result->setText(QString::number(pifagorianec(arg1, arg2)));

        break;
    }///////////////--------------------------------------CASE 2-------------------------------------

    case 2:
    {
        if(arg1 > 1000 && DEVELOPER_MODE!=true)
        {
            QMessageBox msgBox;
            msgBox.setText("Alert");
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setInformativeText("It's dangerous count of variable arg1.\n Do u want to reset arg1 to 100 ?");
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            switch (ret)
            {
            case QMessageBox::Save:
                 break;
              case QMessageBox::Ok:
                arg1=100;
                 break;
              default:
                 arg1=100;
                 break;
            }

        }
        else
        {
            ui->printf_result->setText(QString::number(fact(arg1)));
        }
        break;
    }///////////////-------------------------------------CASE 3---------------------------------
    case 3:
    {
        unsigned int start_time =  clock(); // начальное время
        int size_array = arg1; //первый инпут это колво элементов массива
        int *sorted_array = new int [size_array]; // одномерный динамический массив

        if(arg1>MAX_SIZE && DEVELOPER_MODE!=true)
        {
         QMessageBox msgBox;
         msgBox.setText("Alert");
         msgBox.setIcon(QMessageBox::Information);
         msgBox.setInformativeText("It's dangerous count of variable arg1.\n Do u want to reset arg1 to 9999 ?");
         msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
         msgBox.setDefaultButton(QMessageBox::Ok);
         int ret = msgBox.exec();
         switch (ret)
         {
         case QMessageBox::Save:
              break;
           case QMessageBox::Ok:
             arg1=MAX_SIZE;
              break;
           default:
              arg1=MAX_SIZE;
              break;
         }

        }


        for (int counter = 0; counter < size_array; counter++)
        {
                sorted_array[counter] = rand() % 100; // заполняем массив случайными числами
        }

        bubbleSort(sorted_array, size_array);

        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time; // искомое время

        //ui->printf_result->setText(QString::number(search_time));
        
        ui->lcdNumber->display(QString::number(search_time/1000.0));

        delete[] sorted_array;
        break;
    }///////////////-------------------------------------CASE 4---------------------------------
    case 4: { //merge sort
         unsigned int start_time_m =  clock(); // начальное время
         int size_array = arg1; //первый инпут это колво элементов массива
         int *a = new int [size_array]; // одномерный динамический массив

    if(arg1>MAX_SIZE && DEVELOPER_MODE!=true)
    {
        QMessageBox msgBox;
        msgBox.setText("Alert");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setInformativeText("It's dangerous count of variable arg1.\n Do u want to reset arg1 to 9999 ?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Save:
             break;
          case QMessageBox::Ok:
            arg1=MAX_SIZE;
             break;
          default:
             arg1=MAX_SIZE;
             break;
        }
    }

     for (int counter = 0; counter < size_array; counter++)
     {
             a[counter] = rand() % 100; // заполняем массив случайными числами
     }
       merge(a, 8); // вызов функции сортировки
       unsigned int end_time_m = clock(); // конечное время
       unsigned int search_time_m = end_time_m - start_time_m; // искомое время
       ui->lcdNumber->display(QString::number(search_time_m/1000.0));
    break;
    }///////////////-----------------------------------CASE 5------------------------------------------------

    case 5:
    {
        unsigned int start_time_q =  clock(); // начальное время

        int size_array = arg1; //первый инпут это колво элементов массива
        int *a = new int [size_array]; // одномерный динамический массив

        if(arg1>MAX_SIZE && DEVELOPER_MODE!=true)
        {
            QMessageBox msgBox;
            // Заголовок сообщения
            msgBox.setText("Alert");
            // Тип иконки сообщения
            msgBox.setIcon(QMessageBox::Information);
            // Основное сообщение Message Box
            msgBox.setInformativeText("It's dangerous count of variable arg1.\n Do u want to reset arg1 to 9999 ?");
            // Добавление реагирования на софт клавиши
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            // На какой кнопке фокусироваться по умолчанию
            msgBox.setDefaultButton(QMessageBox::Ok);
            /* Запускаем QMessageBox. После выполнения, в ret будет лежать значение кнопки, на которую нажали - это необходимо для дальнейшей обработки событий*/
            int ret = msgBox.exec();
            // Собственно вот этот case и отвечает за обработку событий
            switch (ret) {
            case QMessageBox::Save:
                 break;
              case QMessageBox::Ok:
                arg1=MAX_SIZE;
                 break;
              default:
                 arg1=MAX_SIZE;
                 // Сюда пишем обработку события по умолчанию
                 break;
            }
        }
        for (int counter = 0; counter < size_array; counter++)
        {
                a[counter] = rand() % 100; // заполняем массив случайными числами
        }
        int puk=0;
        Qsort( a, 0, size_array, puk);
        unsigned int end_time_q = clock(); // конечное время
        unsigned int search_time_q = end_time_q - start_time_q; // искомое время
        ui->lcdNumber->display(QString::number(search_time_q/1000.0));
    break;
    }



    default:
    {
        break;
    }

    }
}


void MainWindow::on_catet_a_valueChanged(int arg12)
{
    arg1 = arg12;
}
void MainWindow::on_catet_b_valueChanged(int arg22)
{
    arg2 = arg22;
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
