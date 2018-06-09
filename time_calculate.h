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


protected:
    // ����� ��������� ������� � ������� ���� ����������
    // � ��� ����� ������������� �������� ������� ����� �������� ����������
    void changeEvent(QEvent * event) override;

private slots:
    void on_actionBack_triggered();

    void on_elements_count_valueChanged(int arg1);

    void on_consider_clicked();

    void on_actionRefresh_triggered();

    void on_progressBar_valueChanged(int value);

    void on_comboBox_currentIndexChanged(int index);

        void slotShortcutEnter();

        void slotTimerAlarm();


private:
    Ui::time_calculate *ui;
    QTranslator qtLanguageTranslator;   // �������� ������� � ��������� ����, ����� ������ �������� �� �����
    QTimer *timer;
    QShortcut       *keyEnter;


};

#endif // TIME_CALCULATE_H
