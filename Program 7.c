#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newnode(int data)
{
    struct Node *t = (struct Node*) malloc(sizeof(struct Node));
    t->data=data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

struct Node *create(struct Node* root,int data)
{
    if(root == NULL)
    {
        root = newnode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = create(root->left,data);
    }
    else
    {
        root->right = create(root->right,data);
    }
    return root;
}

void Preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf(" %d",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(struct Node *root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        printf(" %d",root->data);
        Inorder(root->right);
    }
}

void Postorder(struct Node *root)
{
    if(root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d",root->data);
    }
}

int main()
{
    struct Node *root;
    int data,num,i;
    root = NULL;
    printf("Enter the Number of Entries In the Tree:");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        printf("Enter the %d data:\n");
        scanf("%d",&data);
        root = create(root,data);
    }
    //root = create(root,data);
    printf("The Preorder Traversal Is:");
    Preorder(root);
    printf("\nThe Inorder Traversal Is:");
    Inorder(root);
    printf("\nThe Postorder Traversal Is:\n");
    Postorder(root);
    return 0;
}