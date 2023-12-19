#include <stdio.h>

#define N 100

int front = -1;
int rear = -1;

int Queue[N];

void enqueue(int data)
{
    if (rear == N)
    {
        printf("Queue Overflow!\n");
    }
    else if (front == -1 && rear == -1)
    {
        front += 1;
        rear += 1;

        Queue[rear] = data;
    }
    else
    {
        rear += 1;
        Queue[rear] = data;
    }
}
int dequeue()
{
    int item;
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow!\n");
    }
    else if (front == rear)
    {
        item = Queue[front];
        front = -1;
        rear = -1;
    }
    else
    {
        item = Queue[front];
        front += 1;
    }
    return item;
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("No Elements In Queue!\n");
    }
    else
    {
        printf("Peek Element : %d\n", Queue[front]);
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue : []\n");
    }
    else
    {
        printf("Queue  : [");
        for (int i = front; i <= rear; i++)
        {
            if (i != rear)
            {
                printf("%d,", Queue[i]);
            }
            else
            {
                printf("%d]\n", Queue[i]);
            }
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("Queue Options:-\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n\nEnter Your Choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("Enter Data To Enqueue : ");
            scanf("%d", &data);

            enqueue(data);
        }
        else if (choice == 2)
        {
            printf("Dequeued Item : %d\n", dequeue());
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