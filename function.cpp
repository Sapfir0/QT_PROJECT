#include "function.h"
#include "ui_function.h"

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
