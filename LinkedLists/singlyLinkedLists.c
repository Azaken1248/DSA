#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *temp, struct node *head)
{
    temp = head;
    printf("[ ");
    while (temp != NULL)
    {
        printf("(0x%d : %d) ", temp->next, temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

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

    display(temp, head);

    int menuChoice, insertChoice, deleteChoice, pos, length = 0;

    printf("--------------Linked List Operations--------------\n");
    printf("1. Insert Node\n");
    printf("2. Delete Node\n");
    printf("3. Display Length\n");
    printf("4. Display List\n");
    printf("5. Reverse List\n");
    printf("Enter Your Choice : ");
    scanf("%d", &menuChoice);
    printf("--------------------------------------------------\n\n");

    switch (menuChoice)
    {
    case 1:
        printf("------------------Insert Options------------------\n");
        printf("1. Insert At Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Specific Position\n");
        printf("Enter Your Choice : ");
        scanf("%d", &insertChoice);
        printf("--------------------------------------------------\n\n");

        switch (insertChoice)
        {
        case 1:
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter Data For New Head Node : ");
            scanf("%d", &newNode->data);
            newNode->next = head;
            head = newNode;

            printf("Element inserted Successfully\n");
            break;

        case 2:
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter Data For New Tail Node : ");
            scanf("%d", &newNode->data);

            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;

            printf("Element inserted Successfully\n");
            break;
        case 3:
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter New Node Data : ");
            scanf("%d", &newNode->data);
            printf("Enter Position To Insert : ");
            scanf("%d", &pos);

            int count = 1;

            temp = head;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }

            if (count < pos || pos < 0)
            {
                printf("Invalid Position\n");
            }
            else
            {
                temp = head;
                int i = 1;
                while (i < pos)
                {
                    printf("IN");
                    temp = temp->next;
                    i++;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }

            printf("Element inserted Successfully\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
        break;

    case 2:
        printf("------------------Delete Options------------------\n");
        printf("1. Delete At Beginning\n");
        printf("2. Delete At End\n");
        printf("3. Delete At Specific Position\n");
        printf("Enter Your Choice : ");
        scanf("%d", &deleteChoice);
        printf("--------------------------------------------------\n\n");
        switch (deleteChoice)
        {
        case 1:
            temp = head;
            head = head->next;
            free(temp);
            printf("Element Deleted Successfully\n");
            break;

        case 2:
            temp = head;
            struct node *prevNode;
            while (temp->next != NULL)
            {
                prevNode = temp;
                temp = temp->next;
                // printf("%d#\n", temp->data);
            }
            if (temp == head)
            {
                head = 0;
            }
            else
            {
                prevNode->next = 0;
            }
            free(temp);

            printf("Element Deleted Successfully\n");
            break;

        case 3:
            break;
        }
        break;

    case 3:

        temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }

        printf("Length : %d\n\n", length);

        break;

    default:
        break;
    }

    display(temp, head);

    return 0;
}