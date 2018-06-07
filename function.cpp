#include "function.h"
#include "ui_function.h"
#include <QMessageBox>
#include <QPixmap>
#include "requests.h"
//#include "sortings.h"
#include "secondwindow.h"
#include "method.h"

int func = 0;
int arg=0, arg2=0;
function::function(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::function)
{
    ui->setupUi(this);

    ui->second_count->hide();
    ui->second_count_2->hide();
    ui->first_count->hide();
    ui->first_count_2->hide();
    ui->str->hide();
    ui->str_2->hide();

    QPixmap pix(":/new/prefix1/img/laptop.png");

    int w = ui->image->width();
    int h = ui->image->height();

    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

}

function::~function()
{
    delete ui;
}

void function::on_actionBack_triggered()
{
    hide();
    secondwindow *back = new secondwindow;
    back->setParent(this);
    back->exec();

}

void function::on_actionFactorial_triggered()
{
    QString center_style= "QLabel {text-align: center;}";

    func = 1;
    ui->descripton->setText(tr("Factorial"));
    ui->descripton->setStyleSheet(center_style);
    ui->desc_refinement->setText(tr("Multing elements"));
    ui->desc_refinement->setStyleSheet(center_style);
    QPixmap pix(":/new/prefix1/img/fact.png");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    ui->second_count->hide();
    ui->second_count_2->hide();
    ui->str->hide();
    ui->str_2->hide();

    ui->first_count->show();
    ui->first_count_2->show();
}
void function::on_actionDerivative_triggered()
{
    QString center_style= "QLabel {text-align: center;}";
    ui->descripton->setStyleSheet(center_style);
    ui->desc_refinement->setStyleSheet(center_style);

    func = 2;
    ui->descripton->setText(tr("Derivative"));
    ui->desc_refinement->setText(tr("Deratives elements"));
    QPixmap pix(":/new/prefix1/img/unnamed.png");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    ui->second_count->hide();
    ui->second_count_2->hide();
    ui->first_count->hide();
    ui->first_count_2->hide();

    ui->str->show();
    ui->str_2->show();
}


void function::on_consider_clicked()
{
    switch (func) {
    case 0:
    {
    }
       break;
    case 1:
    {
        ui->printf_result->setText(QString::number(fact(arg)));
    }
    case 2:
    {

    }
    default:
        break;
    }

}

void function::on_first_count_valueChanged(int arg1)
{
    arg1=arg;
}



void function::on_actionRefresh_triggered()
{

}

void function::on_actionSettings_triggered()
{

}

void function::on_pushButton_clicked()
{
//    method *back2 = new method;
//    back2->setParent(this);
//    back2->show();
}

void function::on_actionApproximate_calculation_triggered()
{    setlocale (LC_ALL,""); // установить используемую системой локаль

    func = 3;
    ui->descripton->setText(tr("Приближенные вычисления"));
    ui->desc_refinement->setText(tr("С помощью рядов."));

    ui->second_count->hide();
    ui->second_count_2->hide();

    ui->first_count->show();
    ui->first_count_2->show();
    ui->str->show();
    ui->str_2->show();
    ui->str_2->setText(tr("Введите уравнение"));
    ui->first_count_2->setText(tr("Введите точность для вычислений"));
}
