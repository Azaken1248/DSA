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
void merge(int leftArr[], int rightArr[], int Arr[], int leftSize, int rightSize)
{
    int l = 0;
    int r = 0;
    int i = 0;

    while (l < leftSize && r < rightSize)
    {
        if (leftArr[l] < rightArr[r])
        {
            Arr[i] = leftArr[l];
            i++;
            l++;
        }
        else
        {
            Arr[i] = rightArr[r];
            i++;
            r++;
        }
    }

    while (l < leftSize)
    {
        Arr[i] = leftArr[l];
        i++;
        l++;
    }

    while (r < rightSize)
    {
        Arr[i] = rightArr[r];
        i++;
        r++;
    }
}

void mergeSort(int Arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int middle = (int)(n / 2);
    int leftArr[middle];
    int rightArr[n - middle];

    int j = 0;
    for (int i = 0; i < middle; i++)
    {
        leftArr[i] = Arr[i];
    }
    for (int i = 0; i < n - middle; i++)
    {
        rightArr[i] = Arr[i + middle];
    }

    mergeSort(leftArr, middle);
    mergeSort(rightArr, n - middle);
    merge(leftArr, rightArr, Arr, middle, n - middle);
}

int main()
{
    int Arr[] = {9, 4, 5, 7, 1, 3, 8, 2, 6, 0};

    int size = sizeof(Arr) / sizeof(int);
    mergeSort(Arr, size);

    printArr(Arr, size);

    return 0;
}