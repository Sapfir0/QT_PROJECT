#include "time_calculate.h"
#include "ui_time_calculate.h"
#include <QApplication>
#include <QTranslator>
#include <QMessageBox>
#include <QLibraryInfo>
#include <QDebug>
#include "sortings.h"


int arg1=0; //global variable
int program2 = 0;
bool DEV_MODE=false;
int MAX_ACCEPTABLY=9999;

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
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);    // переведём окно заново
    }
}

void time_calculate::on_elements_count_valueChanged(int arg12)
{
     arg1 = arg12;
}

void time_calculate::on_consider_clicked()
{
    switch (program2) {
    case 1:
    {
        unsigned int start_time =  clock(); // начальное время
        int size_array = arg1; //первый инпут это колво элементов массива
        int *sorted_array = new int [size_array]; // одномерный динамический массив

        if(arg1>MAX_ACCEPTABLY && DEV_MODE!=true)
        {
         QMessageBox msgBox;
         msgBox.setText("Alert");
         msgBox.setIcon(QMessageBox::Information);
         msgBox.setInformativeText("It's dangerous count of variable ppp.\n Do u want to reset ppp to 9999 ?");
         msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
         msgBox.setDefaultButton(QMessageBox::Ok);
         int ret = msgBox.exec();
         switch (ret)
         {
         case QMessageBox::Save:
              break;
           case QMessageBox::Ok:
             arg1=MAX_ACCEPTABLY;
              break;
           default:
              arg1=MAX_ACCEPTABLY;
              break;
         }

        }

        for (int counter = 0; counter < size_array; counter++)
        {
                sorted_array[counter] = rand() % 100; // заполняем массив случайными числами
        }

        bubbleSort(sorted_array, size_array);

        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time; // искомое время

        //ui->printf_result->setText(QString::number(search_time));

        ui->lcdNumber->display(QString::number(search_time/1000.0));

        delete[] sorted_array;
     break;
    }


    default:
        break;
    }


}

void time_calculate::on_actionRefresh_triggered()
{
    setlocale (LC_ALL,""); // установить используемую системой локаль
    int trollface=0;
    QMessageBox::critical(NULL,QObject::tr("Error #0"),tr("Страницу обновить вздумал, мразь? Только попробуй нажать еще раз."));

    trollface++;
    if(trollface==1)
    {
        QMessageBox::critical(NULL,QObject::tr("Error #1"),tr("Ты шо нажал еще раз? Нажмешь еще раз, я тебя накажу."));
        trollface++;

    }
    if(trollface==2)
    {
        QMessageBox::critical(NULL,QObject::tr("Error #2"),tr("Пшел вон, непокорный."));
        QApplication::quit();
    }


}
