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
int linearSearch(int Arr[], int n, int searchElement)
{
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (Arr[i] == searchElement)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
int main()
{
    int Arr[] = {9, 4, 5, 7, 1, 3, 8, 2, 6, 0};
    int size = sizeof(Arr) / sizeof(int);
    printArr(Arr, size);

    int searchItem;
    // printf("Enter Item To Search: ");
    // scanf("%d", &searchItem);

    for (int i = 0; i < 11; i++)
    {
        searchItem = i;
        int index = linearSearch(Arr, size, searchItem);
        printf("Searched Item: \'%d\'\tFound at index: %d\t(position: %d)\n", searchItem, index, index + 1);
    }

    return 0;
}