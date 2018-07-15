#include "testing_window.h"
#include "ui_testing_window.h"
#include <QPainter>
#include <QGraphicsEffect>
 #include <QGraphicsOpacityEffect>
#include <QDebug>

testing_window::testing_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testing_window)
{
    QString task1 = "Write hello world";
    ui->setupUi(this);
    QListWidgetItem *level1 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42578.jpg"), "Level 1");
    ui->levels->addItem(level1);
    QListWidgetItem *level2 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42569.jpg"), "Level 2");
    ui->levels->addItem(level2);
    ui->task->setText(task1);//should be take task from txt file?
}

testing_window::~testing_window()
{
    delete ui;
}

void testing_window::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this); //новый объект "рисовальщика"
    QRect roundedRect;
    roundedRect.setX(rect().x());
    roundedRect.setY(rect().y());
    roundedRect.setWidth(rect().width());
    roundedRect.setHeight(rect().height());
    painter.setBrush(QBrush(QColor(0,0,0,180)));
    painter.drawRoundedRect(roundedRect, 0, 0);

    painter.setBrush(QBrush(QColor(10,10,10,10)));
    painter.drawRoundedRect(roundedRect,0,0);


ui->input_box->setStyleSheet("QListWidget {background-color: rgba(255, 85, 127, 5);}");
ui->levels->setStyleSheet("QListWidget {background-color: rgba(255, 85, 10, 100);}");
ui->changer->setStyleSheet("QPushButton       {background-color: rgba(255, 85, 127, 10);}"
                           "QPushButton:hover {background-color: rgba(255, 255, 0, 10);}");

//ui->errors->setStyleSheet("QLabel  {background-color: rgba(255, 85, 127, 10);}");
//ui->task->setStyleSheet("QLabel {background-color: rgba(255, 85, 127, 10);}");


    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect -> setBlurRadius(9.0);
    shadowEffect -> setColor(QColor(0, 0, 0, 255));
    shadowEffect -> setOffset(4.0);


    ui ->centralwidget -> setGraphicsEffect(shadowEffect);


}

bool testing_window::eventFilter(QObject *obj, QEvent *event)
{
    if ( obj == ui->changer)
    {
        QEvent::Type type = event->type();
        if ( type == QEvent::HoverLeave)
        {
            ui->levels->hide();
            qDebug()<<"No curcor";
        }
        else if (type == QEvent::HoverEnter)
        {
            ui->levels->show();
            qDebug()<<"YES curcor";
        }
        else if (type == QEvent::MouseButtonPress)
        {
            qDebug()<<"Voy voy enter";
        }

    }
    return QWidget::eventFilter(obj,event);
}
