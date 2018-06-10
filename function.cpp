#include "function.h"
#include "ui_function.h"
#include <QMessageBox>
#include <QPixmap>
#include "requests.h"
//#include "sortings.h"
#include "secondwindow.h"
#include <QBoxLayout>
#include "about_method.h"
#include "settings.h"

int func = 0;
int arg=0, arg2=0;
function::function(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::function)
{
    ui->setupUi(this);

   // resize(600,500);

    setWindowTitle(tr("Function. S.Prod."));

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


//    ui->verticalLayout_2->setContentsMargin(10,10,0,0);


}

function::~function()
{
    delete ui;
}

void function::on_actionBack_triggered()
{

    secondwindow *back = new secondwindow;
    hide();
   // back->setParent(this);
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
       // qDebug() << arg << " " <<  fact(arg);
        ui->printf_result->setText(QString::number(fact(arg)));
    }
    case 2:
    {

    }
    case 3:
    {

    }
    default:
        break;
    }

}

void function::on_first_count_valueChanged(int arg1)
{
    arg=arg1;
}



void function::on_actionRefresh_triggered()
{

}

void function::on_actionSettings_triggered()
{
    settings *back1 = new settings;
    back1->exec();
}

void function::on_pushButton_clicked()
{
   // hide();
    about_method *ITISMETHOD = new  about_method;
    ITISMETHOD->exec();
}

void function::on_actionApproximate_calculation_triggered()
{    setlocale (LC_ALL,""); // установить используемую системой локаль

    func = 3;
    ui->descripton->setText(tr("Approximate"));
    ui->desc_refinement->setText(tr("Rows."));

    ui->second_count->hide();
    ui->second_count_2->hide();

    ui->first_count->show();
    ui->first_count_2->show();
    ui->str->show();
    ui->str_2->show();
    ui->str_2->setText(tr("Enter str"));
    ui->first_count_2->setText(tr("Enter count"));
}

void function::on_str_blockCountChanged(int newBlockCount)
{
    //для поиска производной
    //разделим строку на слова
    QString diff_sin = "sinx";
    QString diff_arcsin = "arcsinx";
    QString diff_cos = "cosx";
    QString diff_arccos = "arccosx";
    QString diff_tg = "tgx";
    QString diff_arctg = "arctgx";
    QString diff_ctg = "ctgx";
    QString diff_arcctg = "arcctgx";


QString dif_result;
    if(newBlockCount==diff_sin)
    {
        dif_result = "cosx";
    }
    if(newBlockCount==diff_cos)
    {
        dif_result = "-sinx";
    }
    if(newBlockCount==diff_tg)
    {
        dif_result = "1/(cos^2 x)";
    }
    if(newBlockCount==diff_ctg)
    {
        dif_result = "-1/(sin^2 x)";
    }
}

void function::on_actionconversion_from_decimal_to_binary_triggered()
{
    func = 4;

    ui->second_count->hide();
    ui->second_count_2->hide();

    ui->first_count->show();
    ui->first_count_2->show();
    ui->str->hide();
    ui->str_2->hide();

    ui->first_count_2->setText("Enter number");


//    while(arg>2)
//    {
//      int ostatok = arg%2;
//      qDebug() << ostatok << " ";

//    }

}
