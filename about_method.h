#ifndef ABOUT_METHOD_H
#define ABOUT_METHOD_H

#include <QDialog>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>

namespace Ui {
class about_method;
}

class about_method : public QDialog
{
    Q_OBJECT

public:
    explicit about_method(QWidget *parent = 0);
    ~about_method();

private slots:
        void slotTimerAlarm();

        void on_pushButton_clicked();

        void do_timer();

private:
    Ui::about_method *ui;
        QTimer *timer;

};




#endif // ABOUT_METHOD_H
