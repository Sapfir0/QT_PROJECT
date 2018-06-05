#ifndef SORTINGS_H
#define SORTINGS_H
#include <cmath>

///

void merge(int *a, int n)
{
  int mid = n / 2; // ������� �������� ����������� ������������������
  if (n % 2 == 1)
    mid++;
  int h = 1; // ���
  // �������� ������ ��� ����������� ������������������
  int *c = (int*)malloc(n * sizeof(int));
  int step;
  while (h < n)
  {
    step = h;
    int i = 0;   // ������ ������� ����
    int j = mid; // ������ ������� ����
    int k = 0;   // ������ �������� � �������������� ������������������
    while (step <= mid)
    {
      while ((i < step) && (j < n) && (j < (mid + step)))
      { // ���� �� ����� �� ����� ����
        // ��������� ��������� ������� ����������� ������������������
        // ������� �� ���� ���������������
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
      { // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
        c[k] = a[i];
        i++; k++;
      }
      while ((j < (mid + step)) && (j<n))
      {  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
        c[k] = a[j];
        j++; k++;
      }
      step = step + h; // ��������� � ���������� �����
    }
    h = h * 2;
    // ��������� ������������� ������������������ (������������� �������) � �������� ������
    for (i = 0; i<n; i++)
      a[i] = c[i];
  }
}





template <class type, class type2>
void Qsort(type mas, int left, int right, type2 puk)
{
    //��������� � ������ � � ����� �������
    int i = left;
    int j = right;
    //����������� ������� �������
    type2 mid = mas[(i+j)/2];
    //����� ������
    while (i <= j) {
        //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
        //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
        while(mas[i] < mid) /*mas[i] < mid*/
        {
            i++;
        }
        //� ������ ����� ���������� ��������, ������� ������ ������������
        while (mas[j] > mid) /*mas[j] > mid*/
        {
            j--;
        }
        //������ �������� �������
        if (i <= j) {
            type2 tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    }
    //����������� ������, ���� ��������, ��� �����������
    if(j > left) {
        //"����� �����"
        Qsort(mas, left, j, mas[0]);
    }
    if (i < right) {
        //"��a��� �����"
        Qsort(mas, i, right, mas[0]);
    }
}



int pifagorianec(int arg1, int arg2)
{
    return (sqrt(arg1*arg1 + arg2*arg2)); //�������
}

void bubbleSort(int* arrayPtr, int length_array) // ���������� ���������
{
 int temp = 0; // ��������� ���������� ��� �������� �������� �������
 bool exit = false; // ������� ���������� ��� ������ �� �����, ���� ������ ������������

 while (!exit) // ���� ������ �� ������������
 {
  exit = true;
  for (int int_counter = 0; int_counter < (length_array - 1); int_counter++) // ���������� ����
    //���������� ��������� �� ����������� - ���� >
    //���������� ��������� �� �������� - ���� <
    if (arrayPtr[int_counter] > arrayPtr[int_counter + 1]) // ���������� ��� �������� ��������
    {
     // ��������� ������������ ��������� �������
     temp = arrayPtr[int_counter];
     arrayPtr[int_counter] = arrayPtr[int_counter + 1];
     arrayPtr[int_counter + 1] = temp;
     exit = false; // �� ��������� �������� ���� ����������� ������������ ���������
    }
 }
}





#endif // SORTINGS_H
