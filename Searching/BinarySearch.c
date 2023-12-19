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
int binarySearch(int Arr[], int n, int searchElement)
{
    int FoundIndex = -1;

    int start = 0;
    int end = n;
    while (start <= end)
    {
        int mid = (int)((start + end) / 2);
        if (Arr[mid] == searchElement)
        {
            FoundIndex = mid;
            break;
        }
        else if (Arr[mid] > searchElement)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return FoundIndex;
}
int main()
{
    int Arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(Arr) / sizeof(int);

    int searchItem;
    printf("Enter Item To Search: ");
    scanf("%d", &searchItem);

    int index = binarySearch(Arr, size, searchItem);

    printArr(Arr, size);

    if (index != -1)
    {
        printf("Element : %d\tFound At Index : %d\n", searchItem, index);
    }
    else
    {
        printf("Element Not Found!\n");
    }
    return 0;
}