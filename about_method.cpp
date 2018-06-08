#include "about_method.h"
#include "ui_about_method.h"
#include <QtWidgets>

about_method::about_method(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about_method)
{
    ui->setupUi(this);


 //   ui->label->hide();

    /* Инициализируем Таймер и подключим его к слоту,
     * который будет обрабатывать timeout() таймера
     * */
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(do_timer()));
 //connect(timer, SIGNAL(timeout()), SLOT(slotTimerAlarm()));
    timer->start(100); // И запустим таймер

}

about_method::~about_method()
{
    delete ui;
}

void about_method::slotTimerAlarm()
{
    int  mSecondsToEnd = 60;


        if(mSecondsToEnd>0)
        {
            --mSecondsToEnd;
            QString time = QString::number(mSecondsToEnd);

        ui->label->setText(time);//если это время больше времени сортировки - остановить
        }
        else
        {
            timer->stop();
        }

}
void about_method::do_timer()
{
    //QString time = 60;

    ui->pushButton->move(QPoint( ui->pushButton->pos().x()+10, ui->pushButton->pos().y()));
    ui->label->setText(QTime::currentTime().toString("hh:mm:ss"));}

void about_method::on_pushButton_clicked()
{
    if (!timer->isActive())
        timer->start(50);
    else
        timer->stop();
}
