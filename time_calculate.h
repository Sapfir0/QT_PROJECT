#ifndef TIME_CALCULATE_H
#define TIME_CALCULATE_H
#pragma once
#include <QMainWindow>
#include "secondwindow.h"
#include <QTranslator>
#include "calculating_time_sort.h"
#include <QTimer>
#include <QTime>
#include <QShortcut>
#include <QThread>

namespace Ui {
class time_calculate;
}

class time_calculate : public QMainWindow
{
    Q_OBJECT

public:
    explicit time_calculate(QWidget *parent = 0);



    ~time_calculate();
public slots:


protected:
    // Метод получения событий в главном окне приложения
    // В нём будет производиться проверка события смены перевода приложения
		void changeEvent(QEvent * event);// override;

private slots:
    void on_actionBack_triggered();

    void on_elements_count_valueChanged(int arg1);

    void on_consider_clicked();

    void on_actionRefresh_triggered();

    void on_progressBar_valueChanged(int value);

    void on_comboBox_currentIndexChanged(int index);

        void slotShortcutEnter();

         void myslot();


         void on_actionSettings_triggered();

private:
    Ui::time_calculate *ui;
    QTranslator qtLanguageTranslator;   // Выделяем перевод в отдельном поле, иначе ничего работать не будет
    QTimer *timer;
    QShortcut       *keyEnter;

   // QString threads_name;
};



#endif // TIME_CALCULATE_H
