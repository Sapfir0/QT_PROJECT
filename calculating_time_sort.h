#ifndef CALCULATING_TIME_SORT_H
#define CALCULATING_TIME_SORT_H


#include "time_calculate.h"
#include "sortings.h"
#include <QMessageBox>
#include <QDebug>


extern int MAX_ACCEPTABLY;
extern bool DEV_MODE;
//extern int arg1;

inline double bubble_sort_time(int arg1, int MAX_ACCEPTABLY, bool DEV_MODE)
{

unsigned int start_time =  clock(); // начальное время
int size_array = arg1; //первый инпут это колво элементов массива
int *sorted_array = new int [size_array]; // одномерный динамический массив


if(arg1>MAX_ACCEPTABLY && DEV_MODE!=true)
{
 QMessageBox msgBox;
 msgBox.setText("Alert");
 msgBox.setIcon(QMessageBox::Information);
 msgBox.setInformativeText("It's dangerous count of variable ppp.\n Do u want safe mod?");
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

delete[] sorted_array;
//unsigned int result = (search_time/1000.0);

return (search_time/1000.0);
}



inline  double merge_sort_time(int arg1)
{
unsigned int start_time_m =  clock(); // начальное время
int size_array = arg1; //первый инпут это колво элементов массива
int *a = new int [size_array]; // одномерный динамический массив

for (int counter = 0; counter < size_array; counter++)
{
    a[counter] = rand() % 100; // заполняем массив случайными числами
}
merge(a, 8); // вызов функции сортировки
unsigned int end_time_m = clock(); // конечное время
unsigned int search_time_m = end_time_m - start_time_m; // искомое время
return (search_time_m/1000.0);
}


inline unsigned int quick_sort_time(int arg1)
{
unsigned int start_time_q =  clock(); // начальное время
int size_array = arg1; //первый инпут это колво элементов массива
int *a = new int [size_array]; // одномерный динамический массив

for (int counter = 0; counter < size_array; counter++)
{
        a[counter] = rand() % 100; // заполняем массив случайными числами
}
int puk=0;
Qsort( a, 0, size_array, puk);
unsigned int end_time_q = clock(); // конечное время
unsigned int search_time_q = end_time_q - start_time_q; // искомое время
qDebug() << search_time_q/1000.0 << " ";
return (search_time_q/1000.0);
}


inline unsigned int tree_sort_time(int arg1)
{
unsigned int start_time_t =  clock(); // начальное время
int size_array = arg1; //первый инпут это колво элементов массива
int *a = new int [size_array]; // одномерный динамический массив

for (int counter = 0; counter < size_array; counter++)
{
        a[counter] = rand() % 100; // заполняем массив случайными числами
}
   // int n = sizeof(a)/sizeof(a[0]);
treeSort(a, size_array);

unsigned int end_time_t = clock(); // конечное время
unsigned int search_time_t = end_time_t - start_time_t; // искомое время
qDebug() << search_time_t/1000.0 << " ";

return (search_time_t/1000.0);
}



#endif // CALCULATING_TIME_SORT_H
