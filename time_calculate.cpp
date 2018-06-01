#include "time_calculate.h"
#include "ui_time_calculate.h"

time_calculate::time_calculate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::time_calculate)
{
    ui->setupUi(this);
}

time_calculate::~time_calculate()
{
    delete ui;
}

void time_calculate::on_actionBack_triggered()
{
    hide();
    window_back = new secondwindow(this);   //////////////////////////////////////////раскомментить
    window_back->show();


}
