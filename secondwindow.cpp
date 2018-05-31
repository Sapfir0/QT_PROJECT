#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "time_calculate.h"

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

void secondwindow::on_pushButton_clicked()
{

    hide();
    window = new time_calculate(this);
    window->show();
}
