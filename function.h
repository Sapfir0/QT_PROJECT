#ifndef FUNCTION_H
#define FUNCTION_H

#include <QMainWindow>
#include "secondwindow.h"
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>

namespace Ui {
class function;
}

class function : public QMainWindow
{
    Q_OBJECT

public:
    explicit function(QWidget *parent = 0);
    ~function();

private slots:
    void on_actionBack_triggered();

    void on_actionFactorial_triggered();

    void on_consider_clicked();

    void on_first_count_valueChanged(int arg1);

    void on_actionDerivative_triggered();

    void on_actionRefresh_triggered();

    void on_actionSettings_triggered();

    void on_pushButton_clicked();

    void on_actionApproximate_calculation_triggered();

    void on_str_blockCountChanged(int newBlockCount);

private:
    Ui::function *ui;

};

#endif // FUNCTION_H
