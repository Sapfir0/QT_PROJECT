#include "constructor.h"
#include "ui_constructor.h"
#include "secondwindow.h"
 #include <QDrag>
#include <QFile>
#include <fstream>
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <iso646.h> //and|or|not|not_eq and others
#include "create_file_with_levels.h"
#include <QTimer>
#include <ctime>
#include <QTime>
#include <QGraphicsOpacityEffect>
 #include <QBrush>
//#include "popup.h"
#include "constructor_functions.h"
#include <QGraphicsView>
#include <QPainter>

QString task1 = "Write hello world";
QString task2 = "Find most big element in array";

//нужно сделать прозрачные формы на 10% и дать бекграунду картинку
constructor::constructor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::constructor)
{
    ui->setupUi(this);

    first_settings();
    this->setFormStyle();
}
void constructor::setFormStyle()
{
    ui->centralwidget->setStyleSheet("background-color: green;");
     //Скрываем элементы управления и рамку окна...
   // setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
     //Включаем прозрачность главной формы...
    ui->task->setAttribute(Qt::WA_TranslucentBackground);
   // ui->input_box->setAttribute(Qt::WA_TranslucentBackground);
     //Задаём параметры прозрачности...
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect -> setBlurRadius(9.0);
    shadowEffect -> setColor(QColor(0, 0, 0, 160));
    shadowEffect -> setOffset(4.0);

    setWindowOpacity(0.98);

    ui -> task -> setGraphicsEffect(shadowEffect); //вроде как применили только для инпута
    ui -> input_box -> setGraphicsEffect(shadowEffect);
}
void constructor::first_settings()
{
    ui->error->setText(" ");
     ui->input_box->addItems(List_items_left);

     ui->pushButton->installEventFilter(this);
     ui->up_button->setToolTip("Mat svoyu podnimi");

     ui->listWidget->hide();

     newLevel();

   //  ui->error->setText("Empty error field");

     QListWidgetItem *level1 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42578.jpg"), "Level 1");
     ui->listWidget->addItem(level1);
     QListWidgetItem *level2 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42569.jpg"), "Level 2");
     ui->listWidget->addItem(level2);
     ui->task->setText(task1);//should be take task from txt file?

}

void constructor::paintEvent(QPaintEvent *event)
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
}

bool constructor::eventFilter(QObject *obj, QEvent *event)
{

    if ( obj == ui->pushButton)
    {
        QEvent::Type type = event->type();
        if ( type == QEvent::HoverLeave)
        {
            ui->listWidget->hide();
            qDebug()<<"No curcor";
        }
        else if (type == QEvent::HoverEnter)
        {
            ui->listWidget->show();
            qDebug()<<"YES curcor";
        }
        else if (type == QEvent::MouseButtonPress)
        {
            qDebug()<<"Voy voy enter";
        }

    }

        if ( obj == ui->listWidget)
        {
            QEvent::Type type = event->type();
            if ( /*ui->listWidget->show() and*/ type == QEvent::HoverLeave)
            {
                ui->listWidget->hide();
                qDebug()<<"No curcor list";
            }
            else if ( /*ui->listWidget->hide() or */type == QEvent::HoverEnter)
            {
                ui->listWidget->show();
                qDebug()<<"YES curcor list";
            }
        }

    return QWidget::eventFilter(obj,event);
}




void constructor::on_compile_clicked()
{
    QString critical_error = "QLabel {border: 2px solid grey;background-color: red; border-radius: 5px;text-align: center;} "
    "QLabel::hover {background: #02315F; color: white;}";
    QString no_emergency_error = "QLabel {border: 2px solid grey; background-color: yellow; border-radius: 5px;text-align: center;} "
    "QLabel::hover {background: #02315F; color: white;}";
    QString all_right = "QLabel {border: 2px solid grey; background-color: GreenYellow; border-radius: 5px;text-align: center;} "
    "QLabel::hover {background: #02315F; color: white;}";

    QString success_compile = "ure cool. its working";
    QString achiviement_level1_complete = "Level 1 competed! Congratulations!";

    if (errors())
    {
        ui->error->setStyleSheet(critical_error);
    }
    else
    {
        ui->error->setStyleSheet(all_right);
        ui->error->setText(success_compile);
// new below | may be unite in class

        popUp = new PopUp();
        popUp->setPopupText(achiviement_level1_complete);
        popUp->show();
        newLevel();
        ui->listWidget->clear();
        QListWidgetItem *level1 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42578.jpg"), "Level 1");
        ui->listWidget->addItem(level1);
        QListWidgetItem *level2 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42578.jpg"), "Level 2");
        ui->listWidget->addItem(level2);
        ui->task->setText(task2);

    }
}


void constructor::on_listWidget_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(*item);
    qDebug() << ui->listWidget->currentItem()->text();
}

void constructor::on_hint_clicked()//dont working
{
    QString current_item = ui->input_box->currentItem()->text();
    qDebug() << current_item;
    //найти строку в файле для выбранного элемента
    QFile file("1");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream writeStream(&file);
        while (!writeStream.atEnd())
            List_items_left.append(writeStream.readLine());

        if (current_item == writeStream.readLine())
            qDebug() << "find";
        else
            qDebug() << "oops";
        file.close();
    }
    else
    {
        throw 0;
    }
}

///----perfect function ---------------------------


bool constructor::errors()
{
    QStringList srv;
    QString tmp;
    tmp.setNum(current_level);
    readFileInStringList(tmp, srv);

    return srv != List_items_left;
}

void constructor::newLevel()
{
    QString name, tmp;

    tmp.setNum(++current_level);
    name += tmp;
    if (current_level <= maxlevel)
    {
        List_items_left.clear();
        readFileInStringList(name, List_items_left);
    }
    randomList(List_items_left);
    ui->input_box->clear();
    ui->input_box->addItems(List_items_left);
}

void constructor::levels()
{
    qDebug() << "Voy voy using function \"levels\"";
}


void constructor::on_up_button_clicked()
{

    QString tmp;
    int for_opredelniya_chto_vverh = ui->input_box->currentRow();
    if(for_opredelniya_chto_vverh > 0 and for_opredelniya_chto_vverh < List_items_left.size())
    {
        int for_opredelniya_chto_vniz = for_opredelniya_chto_vverh-1;
        tmp = List_items_left[for_opredelniya_chto_vniz];
        List_items_left[for_opredelniya_chto_vniz] = List_items_left[for_opredelniya_chto_vverh];
        List_items_left[for_opredelniya_chto_vverh]=tmp;
        ui->input_box->clear();
        ui->input_box->addItems(List_items_left);
      //  qDebug() << List_items_left << " - this ""on_up_button_clicked""";
    }
}

void constructor::on_down_clicked()
{
    QString tmp;
    int for_opredelniya_chto_vniz = ui->input_box->currentRow();
    if(for_opredelniya_chto_vniz < List_items_left.size()-1 and for_opredelniya_chto_vniz >= 0)
    {
        int for_opredelniya_chto_vverh = for_opredelniya_chto_vniz+1;
        tmp = List_items_left[for_opredelniya_chto_vverh];
        List_items_left[for_opredelniya_chto_vverh] = List_items_left[for_opredelniya_chto_vniz];
        List_items_left[for_opredelniya_chto_vniz]=tmp;
        ui->input_box->clear();
        ui->input_box->addItems(List_items_left);
     //   qDebug() << List_items_left  << " - this ""on_down_clicked""";
    }
}

void constructor::on_pushButton_clicked()
{
    static bool checked1 = false;
    if(checked1==false)
    {
        ui->listWidget->show();
        checked1=true;
    }
    else
    {
        ui->listWidget->hide();
        checked1=false;
    }
}

constructor::~constructor()
{
    delete ui;
}

void constructor::on_actionBack_triggered()
{
    secondwindow *back = new secondwindow;
    hide();
   // back->setParent(this);
    back->exec();

}
