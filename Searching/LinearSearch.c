#include <stdio.h>
#include <stdlib.h>

void printArr(int Arr[], int n)
{
    printf("[");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d,", Arr[i]);
    }
    printf("%d]\n", Arr[n - 1]);
}

int linearSearch(int Arr[], int n, int searchElement)
{
    int foundIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (searchElement == Arr[i])
        {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}
int main()
{
    int Arr[] = {9, 4, 5, 7, 1, 3, 8, 2, 6, 0};

    int len = sizeof(Arr) / sizeof(int);

    int search;
    printf("Enter Element To Search: ");
    scanf("%d", &search);

    printArr(Arr, len);

    if (linearSearch(Arr, len, search) != -1)
    {
        printf("Element : %d\tFound At Index : %d\n", search, linearSearch(Arr, len, search));
    }
    else
    {
        printf("Element Not Found!\n");
    }

    return 0;
}