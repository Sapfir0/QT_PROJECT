#ifndef FUNCTION_H
#define FUNCTION_H

#include <QMainWindow>
#include "secondwindow.h"

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

private:
    Ui::function *ui;
//    secondwindow *window_back_f(); //////////////////////////////////////////раскомментить
};

#endif // FUNCTION_H
