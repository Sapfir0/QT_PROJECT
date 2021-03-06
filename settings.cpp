#include "settings.h"
#include "ui_settings.h"
#include <QPixmap>
#include <QMenu>
#include <QDebug>
//#include <QFile>
//#include <QTextStream>
//#include <QTime>
//#include <Windows.h>
//#include "kypluk_api/kyplukOSfunction.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);

    setWindowTitle(tr("Settings"));

    QPixmap pix(":/new/prefix1/img/Manager_Icon_thumb.png");

    int w = ui->image->width();
    int h = ui->image->height();

////------------

   // file.close();/////////////----------------------------

///+-----------------------



    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    /* ��� �������� �������� ���� ���������� ��������� ��������� ����������
         * �� ��������, ����������� � ������������ �������
         * */
        QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
        /* ������������� ��������� �������� �� �������� ���������� �� ��������� �����.
         * ���� ���� �� ����������, �� ����� ���������� �������� �� ���������,
         * �� ���� false
         * */
        ui->trayCheckBox->setChecked(settings.value(SETTINGS_TRAY, false).toBool());

    /* �������������� ������ ����, ������������� ������ �� ������ ��������� ������,
     * � ����� ������ ����������� ���������
     * */
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("Tray Program" "\n"
                         "Hide app");
    /* ����� ���� ������� ����������� ���� �� ���� �������*/
    QMenu * menu = new QMenu(this);
	QAction * viewWindow = new QAction("Deploy window", this);
	QAction * quitAction = new QAction("Exit", this);

    /* ���������� ������� ������� �� ������ ���� � �������������� ������.
     * ������ ����� ���� ������������� ���������� �� ����,
     * � ������ ����� ���� ��������� ����������
     * */
    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    /* ������������� ����������� ���� �� ������
     * � ���������� ������ ���������� � ����
     * */
    trayIcon->setContextMenu(menu);
    trayIcon->show();

    /* ����� ���������� ������ ������� �� ������ � �����������
     * ������� �������
     * */
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

settings::~settings()
{
    delete ui;
}


/* �����, ������� ������������ ������� �������� ���� ����������
 * */
void settings::closeEvent(QCloseEvent * event)
{
    /* ���� ���� ������ � ������� �������, �� ���������� ����������
     * ������������, � ���� ������ ����������, ��� ��������������
     * ��������������� ����������� ����������
     */
    if(this->isVisible() && ui->trayCheckBox->isChecked())
    {
        event->ignore();
        this->hide();
		QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

		trayIcon->showMessage("Tray Program",
		"App folded into tray, if u wonna "
		"to deploy app, click on app in tray",
                              icon,
		2000);
    }
}

/* �����, ������� ������������ ������� �� ������ ���������� � ����
 * */
void settings::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
        /* ������� ������������ � ��� ������, ���� ������� �� �������
         * */
        if(ui->trayCheckBox->isChecked())
        {
            /* �����, ���� ���� ������, �� ��� ����������,
             * � ��������, ���� ������, �� ��������������� �� �����
             * */
            if(!this->isVisible())
            {
                this->show();
            }
            else
            {
                this->hide();
            }
        }
        break;
    default:
        break;
    }
}
/* �����, ������� ��������� ������ ������� ������
 * � ��������� ���������� �������� ����������
 * */
void settings::on_dev_mode_stateChanged(int arg1)
{
arg1++;


}


void settings::on_saveButton_clicked()
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    /* ���������� ���������� � ������������ ������� ������������
     * � ���� ������������ � ������������ � ���������� ��������.
     * */
    if(ui->trayCheckBox->isChecked())
    {
        settings.setValue(SETTINGS_TRAY, true);

        QFile file("settings.txt");
        QString str = "setting saved = true";

        if(file.open(QIODevice::WriteOnly))
        {
            qDebug() << "File is open";
            QTextStream writeStream(&file); // ������� ������ ������ QTextStream
    // � �������� ��� ����� ������� file
            writeStream << str; // �������� ������ � ����� ��� ������
            file.close(); // ��������� ����

            if (writeStream.status() != QTextStream::Ok)
                qDebug() << "������ ������ �����";
        }

        else if(!file.isOpen())
            qDebug() << "File is NOT open";

        if(file.exists())
            qDebug() << "File is exist";
               ////----------------------------------------------

    }
    else
    { //�� ��� �������� ���������� ��������� ��� ���� - �� ����� �����
        settings.setValue(SETTINGS_TRAY, false);


        QFile file("settings.txt");
        QString str = "setting saved = false";

        if(file.open(QIODevice::ReadWrite))
        {
            qDebug() << "File is open";

            QTextStream writeStream(&file); // ������� ������ ������ QTextStream
    // � �������� ��� ����� ������� file
            while (!writeStream.atEnd())
            {
                str = writeStream.readLine();
                qDebug() << str;
            }

            writeStream << str; // �������� ������ � ����� ��� ������

            file.close(); // ��������� ����
        }
        else if(!file.isOpen())
            qDebug() << "File is NOT open";


        if(file.exists())
            qDebug() << "File is exist";

    }
    settings.sync();

    /* ���������� ���������, ������� ������������� �� ����������
     * ���������� ��������
     * */
	/*QMessageBox::information(this,
                             trUtf8("Save settings"),
							 trUtf8("Success save settings"));*/
}

void settings::on_checkBox_stateChanged(int arg1)
{
	arg1++;
	//���� ����� �����
    //������ �������� �������� �����
    //���� ����� ������ 20:00
    //� �� 8:00
    if(ui->desctop_background->isChecked())
    {

;
    }
}
