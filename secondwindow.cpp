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
    hide();
    window12 = new time_calculate(this);   //////////////////////////////////////////раскомментить
    window12->show();
}
void secondwindow::on_function_button_clicked()
{
    hide();
    window2 = new function(this);   //////////////////////////////////////////раскомментить
    window2->show();
}
