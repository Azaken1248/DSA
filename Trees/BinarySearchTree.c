#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};

struct node *newnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node *createBST(struct node *root, int data)
{
    if (root == NULL)
    {
        return newnode(data);
    }
    else if (data < root->data)
    {
        root->left = createBST(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = createBST(root->right, data);
    }

    return root;
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorderArray(struct node *root, int Arr[], int *index)
{
    if (root == NULL)
    {
        return;
    }

    inorderArray(root->left, Arr, index);
    Arr[(*index)++] = root->data;
    inorderArray(root->right, Arr, index);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void printArr(int Arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            printf("%d,", Arr[i]);
        }
        else
        {
            printf("%d]\n", Arr[i]);
        }
    }
}

int main()
{
    int Arr[] = {9, 4, 5, 7, 1, 3, 8, 2, 6, 0};
    int size = (int)(sizeof(Arr) / sizeof(int));

    struct node *root = NULL;
    for (int i = 0; i < size; i++)
    {
        root = createBST(root, Arr[i]);
    }

    int inorderArr[size];

    int index = 0;

    inorderArray(root, inorderArr, &index);

    printArr(inorderArr, size);

    printf("Min = %d\n", inorderArr[0]);
    printf("Max = %d\n", inorderArr[size - 1]);

    int k;
    printf("Enter K for Kth Mininum element: ");
    scanf("%d", &k);
    printf("Kth Min = %d\n", inorderArr[k - 1]);
}