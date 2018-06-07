//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")

#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "time_calculate.h"
#include "function.h"


secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_time_calculate_clicked()
{
    time_calculate *ad = new time_calculate;
    ad->setParent(this);
    ad->show();
//    time_calculate *add = new time_calculate; //хороший код, но нет
//    add->show();
}
void secondwindow::on_function_button_clicked()
{
    function *ad = new function; // или можно new AddDialog( this ); тогда не надо ad->setParent( this ) вызывать. //нет не будет ты пидр
    ad->setParent(this);
    ad->show();

}
