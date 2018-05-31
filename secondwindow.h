#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "time_calculate.h"

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
    void on_pushButton_clicked();

private:
    Ui::secondwindow *ui;
    time_calculate *window; //привзяка расчитывания времени

};

#endif // SECONDWINDOW_H
