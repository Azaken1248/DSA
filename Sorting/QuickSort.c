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

int partition(int Arr[], int start, int end)
{
    int pivot = Arr[end];
    int j = start - 1;
    for (int i = start; i <= end - 1; i++)
    {
        if (Arr[i] < pivot)
        {
            j++;
            int temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = temp;
        }
    }
    int temp = Arr[j + 1];
    Arr[j + 1] = Arr[end];
    Arr[end] = temp;

    return j + 1;
}
void quickSort(int Arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = partition(Arr, start, end);

    quickSort(Arr, start, pivot - 1);
    quickSort(Arr, pivot + 1, end);
}

int main()
{
    int Arr[] = {9, 4, 5, 7, 1, 3, 8, 2, 6, 0};

    int size = sizeof(Arr) / sizeof(int);
    quickSort(Arr, 0, size - 1);

    printArr(Arr, size);

    return 0;
}