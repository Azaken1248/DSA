#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *createNode(int data, struct node *next)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = next;

    return newnode;
}

void enqueue(int data)
{
    struct node *newnode;
    newnode = createNode(data, NULL);

    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
int dequeue()
{
    int item;
    if (rear == NULL && front == NULL)
    {
        printf("Stack Underflow!\n");
    }
    else if (rear == front)
    {
        struct node *temp1, *temp2;
        item = front->data;

        temp1 = rear;
        temp2 = front;

        rear = NULL;
        front = NULL;

        free(temp1);
        free(temp2);
    }
    else
    {
        item = front->data;

        struct node *temp;
        temp = front;
        front = front->next;
        free(temp);
    }
    return item;
}
void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("No Elements In Queue!\n");
    }
    else
    {
        printf("Peek Element : %d\n", front->data);
    }
}
void display()
{
    if (front == NULL && rear == NULL)
    {
        printf("Queue : []\n");
    }
    else
    {
        struct node *temp = front;
        printf("Queue : [");
        while (temp != rear)
        {
            printf("%d,", temp->data);
            temp = temp->next;
        }
        printf("%d]\n", temp->data);
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