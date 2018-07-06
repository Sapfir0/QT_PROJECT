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
//#include "popup.h"

QString task1 = "Write hello world";
QString task2 = "Find most big element in array";

//����� ������� ���������� ����� �� 10% � ���� ���������� ��������
constructor::constructor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::constructor)
{
    ui->setupUi(this);

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

    //this->centralWidget()->setStyleSheet("background-image:url(:/new/prefix1/img/yannis-papanastasopoulos-340526-unsplash.jpg); background-position: center; ");
   // ui->task->setStyleSheet(invisible_style);
//    ui->listWidget->setStyleSheet( "background-color: rgb(98, 95, 107);  selection-background-color: orange; color: white;");

}

void constructor::levels()
{
    qDebug() << "Voy voy using function \"levels\"";
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
bool constructor::eventFilter(QObject *obj, QEvent *event)
{

//    if ( obj == ui->pushButton)
//    {
//        QEvent::Type type = event->type();
//        if ( type == QEvent::HoverLeave)
//        {
//            ui->listView->hide();
//            qDebug()<<"No curcor";
//        }
//        else if (type == QEvent::HoverEnter)
//        {
//            ui->listView->show();
//            qDebug()<<"YES curcor";
//        }
//        else if (type == QEvent::MouseButtonPress)
//        {
//            qDebug()<<"Voy voy enter";
//        }

//    }

    return QWidget::eventFilter(obj,event);
}

void readFileInStringList(QString filename, QStringList &List)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream writeStream(&file);
        while (!writeStream.atEnd())
            List.append(writeStream.readLine());
        file.close();
    }
    else
    {
        throw 0;
    }
}

void randomList(QStringList &List)
{
    for (int i = 0; i < List.size(); i++)
    {
        for (int j = 0; j < List.size(); j++)
        {
            if (rand()%2)
            {
                std::swap(List[i], List[j]);
            }
        }
    }
}

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


void constructor::on_compile_clicked()
{
    QString critical_error = "QLabel {border: 2px solid grey;background-color: red; border-radius: 5px;text-align: center;} "
    "QLabel::hover {background: #02315F; color: white;}";
    QString no_emergency_error = "QLabel {border: 2px solid grey; background-color: yellow; border-radius: 5px;text-align: center;} "
    "QLabel::hover {background: #02315F; color: white;}";
    QString all_right = "QLabel {border: 2px solid grey; background-color: GreenYellow; border-radius: 5px;text-align: center;} "
    "QLabel::hover {background: #02315F; color: white;}";

    if (errors())
    {
        ui->error->setStyleSheet(critical_error);
    }
    else
    {
        ui->error->setStyleSheet(all_right);
        ui->error->setText("ure cool. its working");
// new below | may be unite in class
        QString achiviement_level1_complete = "Level 1 competed! Congratulations!";
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

void constructor::on_listWidget_itemClicked(QListWidgetItem *item)
{
    qDebug() << ui->listWidget->currentItem()->text();
}
