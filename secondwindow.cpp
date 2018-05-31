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
    hide();
    window = new time_calculate(this);
    window->show();
}
void secondwindow::on_function_clicked()
{
    hide();
    window2 = new function(this);
    window2->show();
}
