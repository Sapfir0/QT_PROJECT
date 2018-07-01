#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <QMainWindow>
#include <QListWidget>

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
protected:
  bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_actionBack_triggered();

    void on_compile_clicked();

    void on_up_clicked();

    void on_up_button_clicked();

    void on_down_clicked();
    void errors();



    void on_pushButton_clicked(bool checked);

private:
    Ui::constructor *ui;
};

#endif // CONSTRUCTOR_H
