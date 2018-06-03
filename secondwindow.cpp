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

    //time_window = new time_calculate();
    //connect(time_window, &time_calculate::firstWindow, this, &secondwindow::show);

}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_time_calculate_clicked()
{
//    time_window->show();
//    this->close();    // Закрываем основное окно
}
void secondwindow::on_function_button_clicked()
{
//    hide();
//    window2 = new function(this);   //////////////////////////////////////////раскомментить
//    window2->show();
}
