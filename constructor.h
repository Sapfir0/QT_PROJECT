#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <QMainWindow>
#include <QListWidget>
#include "popup.h"
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
    QStringList List_items_left;
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

    void on_down_clicked();

    bool errors();

    void levels();
    void newLevel();

    void on_changer_clicked();

    void on_levels_itemClicked(QListWidgetItem *item);

    void paintEvent(QPaintEvent *event);

    void on_hint_clicked();
    void setFormStyle();
    void first_settings();


    void on_up_clicked();

    void on_input_box_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    bool check_first_el(QObject *obj, QEvent *event);

private:
    int current_level = 0;
    const int maxlevel = 3;
    Ui::constructor *ui;
    PopUp *popUp;       // ќбъ€вл€ем объект всплывающего сообщени€
};

#endif // CONSTRUCTOR_H#ifndef CONSTRUCTOR_H
