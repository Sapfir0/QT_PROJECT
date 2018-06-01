#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "time_calculate.h"
#include "function.h"

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = 0);
    ~secondwindow();

private slots:

    void on_function_button_clicked();

    void on_time_calculate_clicked();

private:
    Ui::secondwindow *ui;
    time_calculate *window12; //привзяка расчитывания времени
    function *window2;

};

#endif // SECONDWINDOW_H
