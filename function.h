#ifndef FUNCTION_H
#define FUNCTION_H

#include <QMainWindow>

namespace Ui {
class function;
}

class function : public QMainWindow
{
    Q_OBJECT

public:
    explicit function(QWidget *parent = 0);
    ~function();

private:
    Ui::function *ui;
};

#endif // FUNCTION_H
