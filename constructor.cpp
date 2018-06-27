#include "constructor.h"
#include "ui_constructor.h"
#include "secondwindow.h"
 #include <QDrag>
#include <QFile>
#include <fstream>
#include <QListWidget>

QString include = "#include \"stdafx\"";
QString main = "int main {";
QString close = "}";

static const QStringList List_items_left =
        QStringList() << include << main << close;

static const QStringList List_items_right =
        QStringList() << include << main << close;


constructor::constructor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::constructor)
{
    ui->setupUi(this);
    QDrag *drag = new QDrag(this);


    ui->input_box->addItems(List_items_left);
    ui->input_box->setAcceptDrops(true);
    ui->input_box->setDragEnabled(true);
    ui->input_box->setDragDropMode(QAbstractItemView::InternalMove);

//    ui->output_box->setAcceptDrops(true);
//    ui->output_box->setDragEnabled(true);
//    ui->output_box->setDragDropMode(QAbstractItemView::InternalMove);

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


void constructor::on_transfer_clicked()
{

    qDebug() << ui->input_box->currentRow();

    ui->statusbar->showMessage(ui->input_box->currentItem()->text());
    ui->input_box->takeItem(ui->input_box->currentRow()); //это тоже удаление

}

void constructor::on_input_box_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}


void constructor::on_down_clicked()
{

}

void constructor::on_up_clicked()
{


    ui->input_box->selectedItems();
}




void constructor::on_compile_clicked()
{

}
