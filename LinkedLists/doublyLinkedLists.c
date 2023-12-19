#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *createNode(int data, struct node *prev, struct node *next)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = prev;
    newnode->next = next;

    return newnode;
}

int len(struct node *head)
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

struct node *insertNode(struct node *head, int data, int pos)
{
    struct node *newnode;
    if (head == NULL)
    {
        newnode = createNode(data, NULL, NULL);
        head = newnode;
    }
    else
    {
        if (pos == 1)
        {
            newnode = createNode(data, NULL, head);
            head = newnode;
        }
        else if (pos == len(head) + 1)
        {
            struct node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            newnode = createNode(data, temp, NULL);
        }
        else
        {
            struct node *temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            newnode = createNode(data, temp, temp->next);
            temp->next->prev = newnode;
            temp->next = newnode;
        }
    }

    printf("Inserting node: %d\n", newnode->data);
    return head;
}
struct node *deleteNode(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("No Element In List!\n");
        return head; // Return the unmodified head pointer
    }

    struct node *temp = head;

    if (pos == 1) // Deleting the first node
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
    else
    {
        int length = len(head);
        if (pos < 1 || pos > length)
        {
            printf("Invalid Position!\n");
            return head; // Return the unmodified head pointer
        }

        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        free(temp);
    }

    return head;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("\n\n[]\n\n");
    }
    else
    {
        printf("\n\nList: [");
        struct node *temp = head;
        while (temp->next != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d]\n\n", temp->data);
    }
}

int main()
{
    int choice = 0;
    struct node *head = NULL;
    do
    {
        printf("List Options:-\n");
        printf("1.Insert Element\n2.Delete Element\n3.Display List\nChoose An Option(-1 to quit): ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data, pos;
            printf("Enter Data: ");
            scanf("%d", &data);
            printf("Enter Position: ");
            scanf("%d", &pos);

            head = insertNode(head, data, pos);
        }
        else if (choice == 2)
        {
            int pos;
            printf("Enter Position: ");
            scanf("%d", &pos);
            head = deleteNode(head, pos);
        }
        else if (choice == 3)
        {
            display(head);
        }
        else
        {
            printf("INVALID CHOICE!\n");
        }
    } while (choice != -1);
}