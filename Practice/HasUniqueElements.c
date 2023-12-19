#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasUniqueElements(int n, int Arr[])
{
    bool is_unique = true;

    for (int i = 0; i < n; i++)
    {
        int current_elem = Arr[i];
        int current_count = 0;

        for (int j = i + 1; j < n; j++)
        {
            if (Arr[j] == current_elem)
            {
                current_count += 1;
            }
        }
        if (current_count > 1)
        {
            is_unique = false;
            break;
        }
    }
    return is_unique;
}
int main()
{
    int arr[] = {1, 4, 7, 9, 2, 3, 4};
    int size = (int)(sizeof(arr) / sizeof(int));
    if ((int)(hasUniqueElements(size, arr)) == 1)
    {
        printf("Array Is Unique.");
    }
    else
    {
        printf("Array Is Not Unique.");
    }
}