#include <stdio.h>

#define N 100

int top = -1;
int Arr[N];

void push(int data)
{
    if (top == N - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top += 1;
        Arr[top] = data;
    }
}
int pop()
{
    int item;
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        item = Arr[top];
        top -= 1;
    }

    return item;
}
void peek()
{
    if (top == -1)
    {
        printf("No Elements In Stack\n");
    }
    else
    {
        printf("Peek Element : %d\n", Arr[top]);
    }
}
void display()
{
    if (top == -1)
    {
        printf("stack : []\n");
    }
    else
    {
        printf("stack : [");
        for (int i = top; i >= 0; i--)
        {
            if (i != 0)
            {
                printf("%d,", Arr[i]);
            }
            else
            {
                printf("%d]\n", Arr[i]);
            }
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("Stack Options:-\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n\nEnter Your Choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("Enter Data To Push : ");
            scanf("%d", &data);

            push(data);
        }
        else if (choice == 2)
        {
            printf("Popped Item : %d\n", pop());
        }
        else if (choice == 3)
        {
            peek();
        }
        else if (choice == 4)
        {
            display();
        }
        else
        {
            if (choice != -1)
            {
                printf("INVALID CHOICE!!\n");
            }
        }

    } while (choice != -1);
}