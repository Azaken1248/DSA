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
void selectionSort(int Arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (Arr[j] < Arr[min])
            {
                min = j;
            }
        }
        int temp = Arr[i];
        Arr[i] = Arr[min];
        Arr[min] = temp;
    }
}

int main()
{
    int Arr[] = {2, 1, 2, 3, 1, 2, 4};

    int size = sizeof(Arr) / sizeof(int);
    selectionSort(Arr, size);
    printArr(Arr, size);

    return 0;
}