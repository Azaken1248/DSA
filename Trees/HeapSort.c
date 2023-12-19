#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;

    return newnode;
}

struct node *insertNode(struct node *root, int data, int treeArr[], int size, int pos)
{
    if (pos < size)
    {
        if (root == NULL)
        {
            root = createnode(treeArr[pos]);
        }

        int leftData = 2 * pos + 1;
        int rightData = 2 * pos + 2;

        if (leftData < size)
        {
            root->left = insertNode(root->left, data, treeArr, size, leftData);
        }
        if (rightData < size)
        {
            root->right = insertNode(root->right, data, treeArr, size, rightData);
        }
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

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

void heapify(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    int largest = root->data;
    struct node *maxNode = root;

    if (root->left != NULL && root->left->data > largest)
    {
        largest = root->left->data;
        maxNode = root->left;
    }

    if (root->right != NULL && root->right->data > largest)
    {
        largest = root->right->data;
        maxNode = root->right;
    }

    if (maxNode != root)
    {
        int temp = root->data;
        root->data = maxNode->data;
        maxNode->data = temp;

        heapify(maxNode); // Recursive call on the affected subtree
    }
}

int main()
{
    int Arr[] = {9, 4, 5, 7, 1, 3, 8, 2, 6, 0};

    int size = (int)(sizeof(Arr) / sizeof(int));
    struct node *root = NULL;

    for (int i = 0; i < size; i++)
    {
        root = insertNode(root, Arr[i], Arr, size, i);
    }
    heapify(root);
    inorder(root);
    printf("\n");
    preorder(root);
}