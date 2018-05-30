#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secondwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_consider_clicked();

    void on_catet_a_valueChanged(int arg1);

    void on_catet_b_valueChanged(int arg2);

    void test_na_pidor();

    void on_actionFactorial_triggered(/*int program*/);

    void on_actionPythagorean_theorem_triggered(/*int program*/);
    
    void on_actionBubble_sorting_triggered();

    void on_action_2_triggered();

    void on_actionRussian_triggered();

    void on_lcdNumber_overflow();

    void on_pushButton_2_clicked();

    void on_actionEnglish_triggered();

    void on_actionMerge_sorting_triggered();

    void on_actionSorting_for_daun_triggered();

private:
    Ui::MainWindow *ui;
//    SecondWindow *window;
};

#endif // MAINWINDOW_H
