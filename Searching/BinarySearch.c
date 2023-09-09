#include <stdio.h>
#include <stdlib.h>

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
int binarySearch(int Arr[], int n, int searchElement)
{
    int start = 0;
    int end = n - 1;
    int pos = -1;

    while (start <= end)
    {
        int mid = (int)((start + end) / 2);
        if (searchElement == Arr[mid])
        {
            pos = mid;
            break;
        }
        else if (searchElement < Arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return pos;
}
int main()
{
    int Arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(Arr) / sizeof(int);
    printArr(Arr, size);

    int searchItem;
    // printf("Enter Item To Search: ");
    // scanf("%d", &searchItem);

    for (int i = 0; i < 11; i++)
    {
        searchItem = i;
        int index = binarySearch(Arr, size, searchItem);
        printf("Searched Item: \'%d\'\tFound at index: %d\t(position: %d)\n", searchItem, index, index + 1);
    }

    return 0;
}