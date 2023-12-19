#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createNode(int data, struct node *next)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = next;

    return newnode;
}

void push(int data)
{
    struct node *newnode;
    if (head == NULL)
    {
        newnode = createNode(data, NULL);
    }
    else
    {
        newnode = createNode(data, head);
    }
    head = newnode;
}

int pop()
{
    int item = head->data;
    if (head == NULL)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return item;
}

void peek()
{
    if (head == NULL)
    {
        printf("No Elements In Stack!\n");
    }
    else
    {
        printf("Peek Element : %d\n", head->data);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Stack : []\n");
    }
    else
    {
        struct node *temp = head;
        printf("Stack : [");
        while (temp->next != NULL)
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