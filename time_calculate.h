#ifndef TIME_CALCULATE_H
#define TIME_CALCULATE_H

#include <QMainWindow>

namespace Ui {
class time_calculate;
}

class time_calculate : public QMainWindow
{
    Q_OBJECT

public:
    explicit time_calculate(QWidget *parent = 0);
    ~time_calculate();

private:
    Ui::time_calculate *ui;
};

#endif // TIME_CALCULATE_H
