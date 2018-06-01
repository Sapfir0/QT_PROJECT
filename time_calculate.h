#ifndef TIME_CALCULATE_H
#define TIME_CALCULATE_H

#include <QMainWindow>
#include "secondwindow.h"

namespace Ui {
class time_calculate;
}

class time_calculate : public QMainWindow
{
    Q_OBJECT

public:
    explicit time_calculate(QWidget *parent = 0);
    ~time_calculate();

private slots:
    void on_actionBack_triggered();

private:
    Ui::time_calculate *ui;
//    secondwindow *window_back;  //////////////////////////////////////////раскомментить
};

#endif // TIME_CALCULATE_H
