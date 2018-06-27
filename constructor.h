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

private slots:
    void on_actionBack_triggered();

    void on_transfer_clicked();

    void on_input_box_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_down_clicked();

    void on_up_clicked();

    void on_compile_clicked();

private:
    Ui::constructor *ui;
};

#endif // CONSTRUCTOR_H
