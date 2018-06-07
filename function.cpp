#include "function.h"
#include "ui_function.h"
#include <QMessageBox>
#include <QPixmap>
#include "requests.h"
//#include "sortings.h"
#include "secondwindow.h"

int func = 0;
int arg=0, arg2=0;
function::function(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::function)
{
    ui->setupUi(this);

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
    function *back = new function;
    back->setParent(this);
    back->show();

}

void function::on_actionFactorial_triggered()
{
    func = 1;
    ui->description->setText(tr("Factorial"));
    ui->desc_refinement->setText(tr("Multing elements"));
    QPixmap pix(":/new/prefix1/img/fact.png");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
    ui->second_count->hide();
    ui->second_count_2->hide();
}
void function::on_actionDerivative_triggered()
{
    func = 2;
    ui->description->setText(tr("Derivative"));
    ui->desc_refinement->setText(tr("Deratives elements"));
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


