#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <QMainWindow>

namespace Ui {
class constructor;
//class QDragEnterEvent;
//class QDropEvent;
}

class constructor : public QMainWindow
{
    Q_OBJECT

public:
    explicit constructor(QWidget *parent = 0);
    ~constructor();

//protected:
//    void dragEnterEvent(QDragEnterEvent *event) override;
//       void dragMoveEvent(QDragMoveEvent *event) override;
//       void dropEvent(QDropEvent *event) override;
//       void mousePressEvent(QMouseEvent *event) override;

private slots:
    void on_actionBack_triggered();

private:
    Ui::constructor *ui;
};

#endif // CONSTRUCTOR_H
