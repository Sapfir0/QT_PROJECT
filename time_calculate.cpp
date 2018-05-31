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
