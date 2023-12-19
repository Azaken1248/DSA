#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};

struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (data == -1)
    {
        return NULL;
    }
    newnode->data = data;

    int left, right;

    printf("Enter Left Node Data of \'%d\' (-1 for no node) : ", newnode->data);
    scanf("%d", &left);
    newnode->left = create(left);

    printf("Enter Right Node Data of \'%d\' (-1 for no node) : ", newnode->data);
    scanf("%d", &right);
    newnode->right = create(right);

    return newnode;
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
int main()
{
    int data;
    printf("Enter Data(-1 for no node): ");
    scanf("%d", &data);

    struct node *root = create(data);

    printf("Preorder : ");
    preorder(root);
    printf("\n");

    printf("Inorder : ");
    inorder(root);
    printf("\n");

    printf("Postorder : ");
    postorder(root);
    printf("\n");

    return 0;
}