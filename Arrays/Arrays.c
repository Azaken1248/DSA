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

int main()
{
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++)
    {
        int element;
        element = 0;
        scanf("%d", &element);
        A[i] = element;
    }

    int max = A[0];
    int min = A[0];

    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
        if (A[i] < min)
        {
            min = A[i];
        }
    }

    printArr(A, n);
    printf("Min : %d\n", min);
    printf("Max : %d\n", max);
    return 0;
}