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
#include <QKeyEvent>

QString task1 = "Write hello world";
//QString task2 = "Find most big element in array";

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
   // ui->centralwidget->setStyleSheet("background-color: green;");
     //Скрываем элементы управления и рамку окна...
   // setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
     //Включаем прозрачность главной формы...
    //ui->task->setAttribute(Qt::WA_TranslucentBackground);
   // ui->input_box->setAttribute(Qt::WA_TranslucentBackground);
     //Задаём параметры прозрачности...
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect -> setBlurRadius(9.0);
    shadowEffect -> setColor(QColor(0, 0, 0, 160));
    shadowEffect -> setOffset(4.0);

   // setWindowOpacity(0.98);

    ui -> task -> setGraphicsEffect(shadowEffect); //вроде как применили только для инпута
    ui -> input_box -> setGraphicsEffect(shadowEffect);

   // ui->input_box->setStyleSheet("QListWidget {background-color: rgba(107, 142, 35, 50);}");
    ui->levels->setStyleSheet("QListWidget {background-color: rgba(255, 85, 10, 100);}");
    ui->changer->setStyleSheet("QPushButton       {background-color: rgba(255, 85, 127, 10);}"
                               "QPushButton:hover {background-color: rgba(255, 255, 0, 10);}");

    //ui->errors->setStyleSheet("QLabel  {background-color: rgba(255, 85, 127, 10);}");
    //ui->task->setStyleSheet("QLabel {background-color: rgba(255, 85, 127, 10);}");
    ui->up->setStyleSheet("QPushButton {"
                          "background-image: url(:/new/prefix1/img/icons8-toDown-32.png);"
                          "background-position:absolute;"
                          "border-radius:12px;"
                          "background-repeat: no-repeat; "
                          "}"
                          "QPushButton:hover {"
                          "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2); "
                          "}"
                          "QPushButton:pressed {"
                          "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2);"
                          "margin-top:2px;"
                          "margin-left:1px;"
                          "}");
    ui->down->setStyleSheet("QPushButton {background-image: url(:/new/prefix1/img/icons8-toDown-32 (2).png); "
                            "background-repeat: no-repeat;"
                            "background-position:absolute;"
                            "border-radius:12px;"
                            "}"
                            "QPushButton:hover {"
                            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2); "
                            "}"
                            "QPushButton:pressed {"
                            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2);"
                            "margin-top:2px;"
                            "margin-left:1px;"
                            "}");
    ui->hint->setStyleSheet("QPushButton {/*background-image: url(:/new/prefix1/img/icons8-razer-32.png)*/; "
                            "background-repeat: no-repeat;"
                            "background-position:absolute;"
                            "border-radius:12px;"
                            "}"
                            "QPushButton:hover {"
                            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2); "
                            "}"
                            "QPushButton:pressed {"
                            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2);"
                            "margin-top:2px;"
                            "margin-left:1px;"
                            "}");
    ui->input_box->setStyleSheet("QListWidget {background-color: rgba(107, 142, 35, 250); border-radius:15px;    font-size: 20px;show-decoration-selected: 1; }"
                                 "QListWidget::item:alternate {background: #EEEEEE;}"
                                 "QListWidget::item:selected {border: 1px solid #6a6ea9;}"
                                 "QListWidget::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2);} "
                                 "QListWidget::item:selected:active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6a6ea9, stop: 1 #888dd9);}"
                                 "QListWidget::item:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FAFBFE, stop: 1 #DCDEF1);}");



    ui->centralwidget->setGraphicsEffect(shadowEffect);

    ;
}
void constructor::first_settings()
{
    ui->error->setText(" ");
    ui->input_box->addItems(List_items_left);
    ui->up->setToolTip("Mat svoyu podnimi");
    ui->levels->hide();
    newLevel();
    ui->changer->installEventFilter(this);


     QListWidgetItem *level1 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42578.jpg"), "Level 1");
     ui->levels->addItem(level1);
     QListWidgetItem *level2 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42569.jpg"), "Level 2");
     ui->levels->addItem(level2);
     ui->task->setText(task1);//should be take task from txt file?
}

void constructor::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
   // QImage img(":/new/prefix1/img/yannis-papanastasopoulos-340526-unsplash.jpg");

    QPainter painter(this); //новый объект "рисовальщика"
  //  painter.begin(&img);

    QRect roundedRect;
    roundedRect.setX(rect().x());
    roundedRect.setY(rect().y());
    roundedRect.setWidth(rect().width());
    roundedRect.setHeight(rect().height());
//    painter.setBrush(QBrush(QColor(0,0,0,180))); //разкомментить (то что ниже тоже оставить) для темной темы
//    painter.drawRoundedRect(roundedRect, 0, 0); //если светлая тема, нужно добавить такую фичу что при наведнии на первый жлемент списка, выделение должно становиться с бордер радиусом
    painter.setBrush(QBrush(QColor(10,10,10,10)));
    painter.drawRoundedRect(roundedRect,0,0);
//если светлая тема меняется - rgba фон у хайлайта списка

//понять как рисовать изображение
    //только ради бога не рисуй свои любимые 4к обои
}

bool constructor::eventFilter(QObject *obj, QEvent *event)
{
    static bool checked1 = false;

    if ( obj == ui->changer)
    {
        QEvent::Type type = event->type();

        if ( type == QEvent::HoverLeave)
        {
            ui->levels->hide();
            qDebug()<<"No curcor";
            if(checked1==true)
            {
                if (obj==ui->levels)
                {
                    if(type== QEvent::HoverLeave)
                    {
                        ui->levels->hide();//не робит
                    }
                }
            }
            checked1=false;
        }
        else if (type == QEvent::HoverEnter)
        {
            ui->levels->show();
            qDebug()<<"YES curcor";
            checked1=true;
        }
        else if (type == QEvent::MouseButtonPress)
        {
            qDebug()<<"Voy voy enter";
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
        ui->levels->clear();
        QListWidgetItem *level1 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42578.jpg"), "Level 1");
        ui->levels->addItem(level1);
        QListWidgetItem *level2 = new QListWidgetItem(QIcon(":/new/prefix1/img/no-translate-detected_318-42578.jpg"), "Level 2");
        ui->levels->addItem(level2);
        //ui->task->setText(task2);

    }
}


void constructor::on_levels_itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(*item);
    qDebug() << ui->levels->currentItem()->text();
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

void constructor::on_changer_clicked()
{
    static bool checked1 = false;
    if(checked1==false)
    {
        ui->levels->show();
        checked1=true;
    }
    else
    {
        ui->levels->hide();
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

void constructor::on_up_clicked()
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

void constructor::on_input_box_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if ( ui->input_box->currentRow() == 0 )
    {

    }
    else
    {
    }
}

bool constructor::check_first_el(QObject *obj, QEvent *event)
{
    //надо как-то отследить первый элемент списка и менять стайлшиты


//    if ( obj == ui->input_box->item(0))
//    {
//        QEvent::Type type = event->type();

//        if ( type == QEvent::HoverLeave)
//        {
//            ui->input_box->setStyleSheet("QListWidget {background-color: rgba(107, 142, 35, 190); border-radius:15px;    font-size: 20px;show-decoration-selected: 1; }"
//                                         "QListWidget::item:alternate {background: #EEEEEE;}"
//                                         "QListWidget::item:selected {border: 1px solid #6a6ea9;}"
//                                         "QListWidget::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2);} "
//                                         "QListWidget::item:selected:active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6a6ea9, stop: 1 #888dd9);}"
//                                         "QListWidget::item:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FAFBFE, stop: 1 #DCDEF1);}");
//        }
//        else if (type == QEvent::HoverEnter)
//        {
//            ui->input_box->setStyleSheet("QListWidget {background-color: rgba(107, 142, 35, 190); border-radius:15px;    font-size: 20px;show-decoration-selected: 1; }"
//                                         "QListWidget::item:alternate {background: #EEEEEE;}"
//                                         "QListWidget::item:selected {border: 1px solid #6a6ea9; border-radius: 15px 15px 0 0;}"
//                                         "QListWidget::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ABAFE5, stop: 1 #8588B2); border-radius: 15px 15px 0 0;} "
//                                         "QListWidget::item:selected:active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #6a6ea9, stop: 1 #888dd9); border-radius: 15px 15px 0 0;}"
//                                         "QListWidget::item:hover {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #FAFBFE, stop: 1 #DCDEF1); border-radius: 15px 15px 0 0;}");
//        }

//    }
    return QWidget::eventFilter(obj,event);
}
