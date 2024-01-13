#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data; // data = roll no.
    char name[30];
    int age;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Roll  is: %d\n", ptr->data);
        printf("Name is: %s\n", ptr->name);
        printf("Age is: %d\n", ptr->age);

        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    int numNodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter roll number: ");
        scanf("%d", &newNode->data);

        printf("Enter name: ");
        scanf("%s", newNode->name);

        printf("Enter age: ");
        scanf("%d", &newNode->age);

        newNode->next = NULL;

        if (current == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
    printf("The Linked List is :\n");
    linkedListTraversal(head);

    // Free allocated memory for all nodes
    current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    linkedListTraversal(head);

    return 0;
}