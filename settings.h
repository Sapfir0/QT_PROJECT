#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QMessageBox>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>

/* Defining */
#define ORGANIZATION_NAME "EVILEG"
#define ORGANIZATION_DOMAIN "www.evileg.ru"
#define APPLICATION_NAME "QSettings Program"

#define SETTINGS_TRAY "settings/tray"

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = 0);
    ~settings();

protected:
    /* Виртуальная функция родительского класса в нашем классе
     * переопределяется для изменения поведения приложения,
     *  чтобы оно сворачивалось в трей, когда мы этого хотим
     */
    void closeEvent(QCloseEvent * event);



private slots:
    /* Слот, который будет принимать сигнал от события
     * нажатия на иконку приложения в трее
     */
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_dev_mode_stateChanged(int arg1);

    void on_saveButton_clicked();

    void on_checkBox_stateChanged(int arg1);


//void set_image_on_desktop(char directoriya_and_filename[]);
private:
    Ui::settings *ui;
    /* Объявляем объект будущей иконки приложения для трея */
    QSystemTrayIcon         * trayIcon;
};

#endif // SETTINGS_H
