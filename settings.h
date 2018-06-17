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
    /* ����������� ������� ������������� ������ � ����� ������
     * ���������������� ��� ��������� ��������� ����������,
     *  ����� ��� ������������� � ����, ����� �� ����� �����
     */
    void closeEvent(QCloseEvent * event);



private slots:
    /* ����, ������� ����� ��������� ������ �� �������
     * ������� �� ������ ���������� � ����
     */
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_dev_mode_stateChanged(int arg1);

    void on_saveButton_clicked();

    void on_checkBox_stateChanged(int arg1);


//void set_image_on_desktop(char directoriya_and_filename[]);
private:
    Ui::settings *ui;
    /* ��������� ������ ������� ������ ���������� ��� ���� */
    QSystemTrayIcon         * trayIcon;
};

#endif // SETTINGS_H
