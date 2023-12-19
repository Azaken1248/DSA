#include <stdio.h>

void printArr(int Arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            printf("%d,", Arr[i]);
        }
        else
        {
            printf("%d]\n", Arr[i]);
        }
    }
}
void InsertionSort(int Arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = Arr[i];
        while (j >= 0 && temp < Arr[j])
        {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = temp;
    }
}

int main()
{
    int Arr[] = {9, 4, 5, 7, 1, 3, 8, 2, 6, 0};

    int size = sizeof(Arr) / sizeof(int);
    InsertionSort(Arr, size);

    printArr(Arr, size);

    return 0;
}