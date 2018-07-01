#include "constructor.h"
#include "ui_constructor.h"
#include "secondwindow.h"
 #include <QDrag>
#include <QFile>
#include <fstream>
#include <QListWidget>
#include <QFile>
#include <QTextStream>

QString include = "#include \"stdafx\"";
QString main = "int main {";
QString close1 = "}";

static  QStringList List_items_left =
        QStringList() << include << main << close1;

constructor::constructor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::constructor)
{
    ui->setupUi(this);

    ui->error->setText(" ");
    ui->input_box->addItems(List_items_left);
    /*
    ui->input_box->setAcceptDrops(true);
    ui->input_box->setDragEnabled(true);
    ui->input_box->setDragDropMode(QAbstractItemView::InternalMove);
ЧТО МЫ ГОВОРИМ ДРАГ ЭНД ДРОПУ
пнх пдр
*/
    ui->error->setText("Empty error field");
   // ui->input_box ->setSelectionMode(QAbstractItemView::ExtendedSelection);
//это для перебора элементов
    ui->pushButton->installEventFilter(this);
    ui->up_button->setToolTip("Mat svoyu podnimi");

    ui->listView->hide();


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


void constructor::errors()
{
    QString critical_error = "QLabel {border: 2px solid grey;background-color: red; border-radius: 5px;text-align: center;} "
                        "QLabel::hover {background: #02315F; color: white;}";
    QString no_emergency_error = "QLabel {border: 2px solid grey; background-color: yellow; border-radius: 5px;text-align: center;} "
                        "QLabel::hover {background: #02315F; color: white;}";
    QString all_right = "QLabel {border: 2px solid grey; background-color: GreenYellow; border-radius: 5px;text-align: center;} "
                        "QLabel::hover {background: #02315F; color: white;}";
    if ( include != List_items_left[0] )
    {
        ui->error->setStyleSheet(critical_error);
        ui->error->setText("include should be first. finally");
    }
    else if ( main != List_items_left[1] )
    {
        ui->error->setStyleSheet(critical_error);
        ui->error->setText("figurnaya.");
    }
    else
    {
        ui->error->setStyleSheet(all_right);
        ui->error->setText("ure cool. its working");
    }


}
void constructor::on_compile_clicked()
{
    errors();



///блок файла
    QFile file("your_first_program.txt");
    QString str = "//я люблю тебя, литовкин";
    QTextStream writeStream(&file);
    //допустим пока что аутпут бокс не нужен //сделаем все в инпуте


  //  qDebug() << "first element" << List_items_left[0];


 /*   if(file.open(QIODevice::WriteOnly))
    {
        writeStream << include << main;
    }
    if(file.open(QIODevice::ReadOnly))
    {
        prog = writeStream.readAll();
    }*/
    //нам надо проверить какой индекс у каждого из элементов
    //например инклуд
//    qDebug() << List_items_right[1]; //ЕЕЕЕ бой работает обращение как к обычному массиву

//    for(int i=0;i<3;i++)
//    {
//        if (List_items_right[i]==main)
//            qDebug() << "perfect";
//        else
//            qDebug() << "shut";
//    }
}

void constructor::on_up_clicked()
{
    QString tmp;
    tmp = List_items_left[0];
    List_items_left[0]=List_items_left[1]; //0 что вниз
    List_items_left[1]=tmp;                 // 1 что в верх
    ui->input_box->clear();
    ui->input_box->addItems(List_items_left);
    qDebug() << List_items_left;
}

void constructor::on_up_button_clicked()
{
    QString tmp;
    int for_opredelniya_chto_vverh = ui->input_box->currentRow();
    if(for_opredelniya_chto_vverh>0)
    {
        int for_opredelniya_chto_vniz = for_opredelniya_chto_vverh-1;
        tmp = List_items_left[for_opredelniya_chto_vniz];
        List_items_left[for_opredelniya_chto_vniz] = List_items_left[for_opredelniya_chto_vverh];
        List_items_left[for_opredelniya_chto_vverh]=tmp;
        ui->input_box->clear();
        ui->input_box->addItems(List_items_left);
        qDebug() << List_items_left;
    }
}

void constructor::on_down_clicked()
{
    QString tmp;
    int for_opredelniya_chto_vniz = ui->input_box->currentRow();
    if(for_opredelniya_chto_vniz<2 )
    {
        int for_opredelniya_chto_vverh = for_opredelniya_chto_vniz+1;
        tmp = List_items_left[for_opredelniya_chto_vverh];
        List_items_left[for_opredelniya_chto_vverh] = List_items_left[for_opredelniya_chto_vniz];
        List_items_left[for_opredelniya_chto_vniz]=tmp;
        ui->input_box->clear();
        ui->input_box->addItems(List_items_left);
        qDebug() << List_items_left;
    }
}





bool checked = true;
void constructor::on_pushButton_clicked(bool checked)
{
    qDebug() << "first|"<< checked;
    if(checked==false)
    {
        ui->listView->show();
        checked=true;
       qDebug() <<  checked;
    }
    else if (checked==true)
    {
        ui->listView->hide();
        checked=false;
        qDebug() << "third if true|"<< checked;
    }
}
