#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data, struct node *next)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = next;

    return newnode;
}
int main()
{
    struct node *head = NULL;

    int choice = 0;
    do
    {
        printf("Choose An Operation:-\n");
        printf("1.Insert ELement In Beginning\n2.Insert ELement In End\n3.Insert ELement At Some Position\n");
        printf("4.Delete ELement In Beginning\n5.Delete ELement In End\n6.Delete ELement At Some Position\n");
        printf("7.Display The List\n");
        printf("Your choice(-1 to quit): ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            printf("Enter Data: ");
            scanf("%d", &data);

            struct node *newnode;
            if (head == NULL)
            {
                newnode = createnode(data, NULL);
            }
            else
            {
                newnode = createnode(data, head);
            }
            head = newnode;
        }
        else if (choice == 2)
        {
            int data;
            struct node *newnode;
            printf("Enter Data: ");
            scanf("%d", &data);
            if (head == NULL)
            {
                newnode = createnode(data, NULL);
                head = newnode;
            }
            else
            {
                newnode = createnode(data, NULL);
                struct node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }
        else if (choice == 3)
        {
            int pos, data;
            struct node *temp, *newnode;
            printf("Enter Data: ");
            scanf("%d", &data);
            printf("Enter Postion: ");
            scanf("%d", &pos);

            if (head == NULL)
            {
                newnode = createnode(data, NULL);
                head = newnode;
            }
            else
            {
                temp = head;
                for (int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }
                newnode = createnode(data, temp->next);
                temp->next = newnode;
            }
        }
        else if (choice == 4)
        {
            if (head != NULL)
            {
                struct node *temp = head;
                head = temp->next;

                free(temp);
            }
            else
            {
                printf("No Element To Delete!\n");
            }
        }
        else if (choice == 5)
        {
            if (head != NULL)
            {
                struct node *temp2;
                struct node *temp = head;
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                temp2 = temp->next;
                temp->next = NULL;
                free(temp2);
            }
            else
            {
                printf("No Element To Delete!\n");
            }
        }
        else if (choice == 6)
        {
            if (head != NULL)
            {
                int pos;
                printf("Enter Position: ");
                scanf("%d", &pos);

                if (pos == 1)
                {
                    struct node *temp = head;
                    head = head->next;
                    free(temp);
                }
                else
                {
                    struct node *temp = head;
                    for (int i = 1; i < pos - 1 && temp != NULL; i++)
                    {
                        temp = temp->next;
                    }

                    if (temp == NULL || temp->next == NULL)
                    {
                        printf("Invalid position to delete.\n");
                    }
                    else
                    {
                        struct node *temp2 = temp->next;
                        temp->next = temp->next->next;
                        free(temp2);
                    }
                }
            }
        }
        else if (choice == 7)
        {
            if (head == NULL)
            {
                printf("[]\n");
            }
            else
            {
                struct node *temp = head;
                printf("[");
                while (temp->next != NULL)
                {
                    printf("%d->", temp->data);
                    temp = temp->next;
                }
                printf("%d]\n", temp->data);
            }
        }
        else
        {
            printf("Invalid Choice!\n");
        }

    } while (choice != -1);

    // printf("Data : %d Next: %d\n", mynode->data, mynode->next);
}
