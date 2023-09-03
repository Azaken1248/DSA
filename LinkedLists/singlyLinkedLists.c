#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *newNode, *temp;
    head = NULL;

    int choice = 1;

    while (choice)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }

        printf("Do You Want To Continue [0/1] : ");
        scanf("%d", &choice);
    }

    temp = head;

    printf("[ ");
    while (temp != NULL)
    {
        printf("(0x%d : %d) ", temp->next, temp->data);
        temp = temp->next;
    }
    printf("]\n");

    return 0;
}