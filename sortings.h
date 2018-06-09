#ifndef SORTINGS_H
#define SORTINGS_H
#include <cmath>
#include "calculating_time_sort.h"
///

inline void merge(int *a, int n)
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
inline void Qsort(type mas, int left, int right, type2 puk)
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


inline void bubbleSort(int* arrayPtr, int length_array) // ���������� ���������
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



///-------------------------tree sort----------------

struct Node
{
    int key;
    struct Node *left, *right;
};

// A utility function to create a new BST Node
inline struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Stores inoder traversal of the BST
// in arr[]
inline void storeSorted(Node *root, int a[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, a, i);
        a[i++] = root->key;
        storeSorted(root->right, a, i);
    }
}

/* A utility function to insert a new
   Node with given key in BST */
inline Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) Node pointer */
    return node;
}

// This function sorts arr[0..n-1] using Tree Sort
inline void treeSort(int a[], int size_array)
{
    struct Node *root = NULL;

    // Construct the BST
    root = insert(root, a[0]);
    for (int i=1; i<size_array; i++)
        insert(root, a[i]);

    // Store inoder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, a, i);
}


///-------------------------tree sort----------------


#endif // SORTINGS_H
