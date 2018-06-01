#ifndef TIME_CALCULATE_H
#define TIME_CALCULATE_H

#include <QMainWindow>
#include "secondwindow.h"
#include <QTranslator>

namespace Ui {
class time_calculate;
}

class time_calculate : public QMainWindow
{
    Q_OBJECT

public:
    explicit time_calculate(QWidget *parent = 0);
    ~time_calculate();

protected:
    // Метод получения событий в главном окне приложения
    // В нём будет производиться проверка события смены перевода приложения
    void changeEvent(QEvent * event) override;

private slots:
    void on_actionBack_triggered();

    void on_elements_count_valueChanged(int arg1);

private:
    Ui::time_calculate *ui;
//    secondwindow *window_back;  //////////////////////////////////////////раскомментить
    QTranslator qtLanguageTranslator;   // Выделяем перевод в отдельном поле, иначе ничего работать не будет
};

#endif // TIME_CALCULATE_H
