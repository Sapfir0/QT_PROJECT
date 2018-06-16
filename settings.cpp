#include "settings.h"
#include "ui_settings.h"
#include <QPixmap>
#include <QMenu>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QTime>
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
    QFile file("settings.txt");
    file.open(QIODevice::WriteOnly);

    if(file.open(QIODevice::WriteOnly))
    {
        qDebug() << "File is open";
        QTextStream writeStream(&file); // Создаем объект класса QTextStream
// и передаем ему адрес объекта file
        writeStream << "setting saved = true;"; // Посылаем строку в поток для записи
        file.write("Test string\n");
        file.write("Test string2");
        file.close(); // Закрываем файл
    }
    else if(!file.isOpen())
    {
        qDebug() << "File is NOT open";
    }

    if(file.exists())
    {
        qDebug() << "File is exist";
    }

   // file.close();/////////////----------------------------

///+-----------------------



    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    /* При создании главного окна производим установку начальных параметров
         * из настроек, сохранённых в операционной системе
         * */
        QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
        /* Устанавливаем состояние чекбокса из настроек приложения по заданному ключу.
         * Если ключ не существует, то будет установлен параметр по умолчанию,
         * то есть false
         * */
        ui->trayCheckBox->setChecked(settings.value(SETTINGS_TRAY, false).toBool());


    /* Инициализируем иконку трея, устанавливаем иконку из набора системных иконок,
     * а также задаем всплывающую подсказку
     * */
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("Tray Program" "\n"
                         "Hide app");
    /* После чего создаем контекстное меню из двух пунктов*/
    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction(trUtf8("Deploy window"), this);
    QAction * quitAction = new QAction(trUtf8("Exit"), this);

    /* подключаем сигналы нажатий на пункты меню к соответсвующим слотам.
     * Первый пункт меню разворачивает приложение из трея,
     * а второй пункт меню завершает приложение
     * */
    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    /* Устанавливаем контекстное меню на иконку
     * и показываем иконку приложения в трее
     * */
    trayIcon->setContextMenu(menu);
    trayIcon->show();

    /* Также подключаем сигнал нажатия на иконку к обработчику
     * данного нажатия
     * */
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

settings::~settings()
{
    delete ui;
}


/* Метод, который обрабатывает событие закрытия окна приложения
 * */
void settings::closeEvent(QCloseEvent * event)
{
    /* Если окно видимо и чекбокс отмечен, то завершение приложения
     * игнорируется, а окно просто скрывается, что сопровождается
     * соответствующим всплывающим сообщением
     */
    if(this->isVisible() && ui->trayCheckBox->isChecked())
    {
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Tray Program",
                              trUtf8("App folded into tray, if u wonna "
                                     "to deploy app, click on app in tray"),
                              icon,
                              2000);
    }
}

/* Метод, который обрабатывает нажатие на иконку приложения в трее
 * */
void settings::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::Trigger:
        /* Событие игнорируется в том случае, если чекбокс не отмечен
         * */
        if(ui->trayCheckBox->isChecked())
        {
            /* иначе, если окно видимо, то оно скрывается,
             * и наоборот, если скрыто, то разворачивается на экран
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
/* Метод, который принимает сигнал нажатия кнопки
 * и выполняет сохранение настроек приложения
 * */
void settings::on_dev_mode_stateChanged(int arg1)
{
//    if(arg1=true)


}


void settings::on_saveButton_clicked()
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    /* Сохранение информации о включённости функции сворачивания
     * в трей производится в соответствии с состоянием чекбокса.
     * */
    if(ui->trayCheckBox->isChecked())
    {
        settings.setValue(SETTINGS_TRAY, true);
        ////----------------------------------------------

    }
    else
    {
        settings.setValue(SETTINGS_TRAY, false);
    }
    settings.sync();

    /* Диалоговое сообщение, которое сигнализирует об успешности
     * сохранения настроек
     * */
    QMessageBox::information(this,
                             trUtf8("Save settings"),
                             trUtf8("Success save settings"));
}

void settings::on_checkBox_stateChanged(int arg1)
{
    //если стоит галка
    //менять картинку рабочего стола
    //если время больше 20:00
    //и до 8:00
    if(ui->desctop_background->isChecked())
    {
        //        QTime time = QTime::currentTime().toString("hh:mm:ss");
        //        if ( ) //если ща 20часов, менять на ночное
        //        {

        //        }
        //        else if(  )//если ща 8 часов менять изображение на дневное
        //        {

        //        }

    }
}
