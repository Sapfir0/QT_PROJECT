#include "function.h"
#include "ui_function.h"
#include <QMessageBox>

function::function(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::function)
{
    ui->setupUi(this);
}

function::~function()
{
    delete ui;
}

void function::on_actionBack_triggered()
{
//    hide();
//    window_back_f = new secondwindow(this);   //////////////////////////////////////////раскомментить
//    window_back_f->show(); //error here

}

void function::on_actionFactorial_triggered()
{
    ui->description->setText(tr("Factorial"));
    ui->desc_refinement->setText(tr("Sum elements"));


}
