#include "time_calculate.h"
#include "ui_time_calculate.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDebug>

int arg1=0, arg2=0; //global variables

time_calculate::time_calculate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::time_calculate)
{
    ui->setupUi(this);

    connect(ui->consider, SIGNAL(clicked()),this, SLOT(on_consider_clicked(void)));

        ui->comboBox_2->addItems(QStringList() << "ru_RU" << "en_US");
        // подключаем к сигналу изменения пункта комбобокса лямбда функцию,
            // в которой будет изменяться перевод приложения
            // Здесь имеется интересный момент. Поскольку QComboBox имеет перегрузку сигнатуры сигнала,
            // то нам необходимо скастовать сигнал к нужной сигнатуре.
            // В данном случае будем использовать название пункта при его изменении
            connect(ui->comboBox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
                    [=](const QString &str){
                qtLanguageTranslator.load("QtLanguage_" + str, ".");   // Загружаем перевод
                qApp->installTranslator(&qtLanguageTranslator);        // Устанавливаем перевод в приложение
            });

            // Сделаем первоначальную инициализацию перевода для окна прилоежния
            qtLanguageTranslator.load(QString("QtLanguage_") + QString("ru_RU"));
            qApp->installTranslator(&qtLanguageTranslator);
}

time_calculate::~time_calculate()
{
    delete ui;
}

void time_calculate::on_actionBack_triggered()
{
//    hide();
//    window_back = new secondwindow(this);   //////////////////////////////////////////раскомментить
//    window_back->show();
}
void time_calculate::changeEvent(QEvent *event)
{
    // В случае получения события изменения языка приложения
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);    // переведём окно заново
    }
}

void time_calculate::on_elements_count_valueChanged(int arg12)
{
     arg1 = arg12;
}
