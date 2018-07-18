#ifndef TESTING_WINDOW_H
#define TESTING_WINDOW_H

#include <QMainWindow>
#include "popup.h"
#include <QListWidget>


namespace Ui {
class testing_window;
}

class testing_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit testing_window(QWidget *parent = 0);
     QStringList levels_list;
    ~testing_window();
private slots:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);



private:
    Ui::testing_window *ui;

    PopUp *popUp;       // ќбъ€вл€ем объект всплывающего сообщени€
};



#endif // TESTING_WINDOW_H
