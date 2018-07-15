#ifndef TESTING_WINDOW_H
#define TESTING_WINDOW_H

#include <QMainWindow>

namespace Ui {
class testing_window;
}

class testing_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit testing_window(QWidget *parent = 0);
    ~testing_window();
private slots:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
private:
    Ui::testing_window *ui;
};

#endif // TESTING_WINDOW_H
