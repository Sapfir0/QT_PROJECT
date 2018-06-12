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
                         "Работа со сворачиванием программы трей");
    /* После чего создаем контекстное меню из двух пунктов*/
    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction(trUtf8("Развернуть окно"), this);
    QAction * quitAction = new QAction(trUtf8("Выход"), this);

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
                              trUtf8("Приложение свернуто в трей. Для того чтобы, "
                                     "развернуть окно приложения, щелкните по иконке приложения в трее"),
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
                             trUtf8("Сохранение настроек"),
                             trUtf8("Сохранение настроек выполнено успешно"));
}
