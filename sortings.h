#ifndef SORTINGS_H
#define SORTINGS_H
#include <cmath>

///

void merge(int *a, int n)
{
  int mid = n / 2; // находим середину сортируемой последовательности
  if (n % 2 == 1)
    mid++;
  int h = 1; // шаг
  // выделяем память под формируемую последовательность
  int *c = (int*)malloc(n * sizeof(int));
  int step;
  while (h < n)
  {
    step = h;
    int i = 0;   // индекс первого пути
    int j = mid; // индекс второго пути
    int k = 0;   // индекс элемента в результирующей последовательности
    while (step <= mid)
    {
      while ((i < step) && (j < n) && (j < (mid + step)))
      { // пока не дошли до конца пути
        // заполняем следующий элемент формируемой последовательности
        // меньшим из двух просматриваемых
        if (a[i] < a[j])
        {
          c[k] = a[i];
          i++; k++;
        }
        else {
          c[k] = a[j];
          j++; k++;
        }
      }
      while (i < step)
      { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
        c[k] = a[i];
        i++; k++;
      }
      while ((j < (mid + step)) && (j<n))
      {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
        c[k] = a[j];
        j++; k++;
      }
      step = step + h; // переходим к следующему этапу
    }
    h = h * 2;
    // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
    for (i = 0; i<n; i++)
      a[i] = c[i];
  }
}





template <class type, class type2>
void Qsort(type mas, int left, int right, type2 puk)
{
    //Указатели в начало и в конец массива
    int i = left;
    int j = right;
    //Центральный элемент массива
    type2 mid = mas[(i+j)/2];
    //Делим массив
    while (i <= j) {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) /*mas[i] < mid*/
        {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) /*mas[j] > mid*/
        {
            j--;
        }
        //Меняем элементы местами
        if (i <= j) {
            type2 tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    }
    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > left) {
        //"Левый кусок"
        Qsort(mas, left, j, mas[0]);
    }
    if (i < right) {
        //"Прaвый кусок"
        Qsort(mas, i, right, mas[0]);
    }
}



int pifagorianec(int arg1, int arg2)
{
    return (sqrt(arg1*arg1 + arg2*arg2)); //пифагор
}

void bubbleSort(int* arrayPtr, int length_array) // сортировка пузырьком
{
 int temp = 0; // временная переменная для хранения элемента массива
 bool exit = false; // болевая переменная для выхода из цикла, если массив отсортирован

 while (!exit) // пока массив не отсортирован
 {
  exit = true;
  for (int int_counter = 0; int_counter < (length_array - 1); int_counter++) // внутренний цикл
    //сортировка пузырьком по возрастанию - знак >
    //сортировка пузырьком по убыванию - знак <
    if (arrayPtr[int_counter] > arrayPtr[int_counter + 1]) // сравниваем два соседних элемента
    {
     // выполняем перестановку элементов массива
     temp = arrayPtr[int_counter];
     arrayPtr[int_counter] = arrayPtr[int_counter + 1];
     arrayPtr[int_counter + 1] = temp;
     exit = false; // на очередной итерации была произведена перестановка элементов
    }
 }
}





#endif // SORTINGS_H
