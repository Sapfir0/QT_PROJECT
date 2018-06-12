#include "settings.h"
#include "ui_settings.h"
#include <QPixmap>
#include <QMenu>


settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);

    setWindowTitle(tr("Settings"));

    QPixmap pix(":/new/prefix1/img/Manager_Icon_thumb.png");

    int w = ui->image->width();
    int h = ui->image->height();

    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    /* ��� �������� �������� ���� ���������� ��������� ��������� ����������
         * �� ��������, ���������� � ������������ �������
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
                         "������ �� ������������� ��������� ����");
    /* ����� ���� ������� ����������� ���� �� ���� �������*/
    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction(trUtf8("���������� ����"), this);
    QAction * quitAction = new QAction(trUtf8("�����"), this);

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
                              trUtf8("���������� �������� � ����. ��� ���� �����, "
                                     "���������� ���� ����������, �������� �� ������ ���������� � ����"),
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
    }
    else
    {
        settings.setValue(SETTINGS_TRAY, false);
    }
    settings.sync();

    /* ���������� ���������, ������� ������������� �� ����������
     * ���������� ��������
     * */
    QMessageBox::information(this,
                             trUtf8("���������� ��������"),
                             trUtf8("���������� �������� ��������� �������"));
}
