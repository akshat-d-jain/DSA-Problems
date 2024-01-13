#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data[30]; // data = roll no.
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("PAN NUMBER is: %s\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtFirst(struct Node *head, char data[30])
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    head->prev = ptr;
    strcpy(ptr->data, data);
    head = ptr;
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    int numNodes;
    char pannum[10];

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter PAN NUMBER: ");
        scanf("%s", newNode->data);

        newNode->next = NULL;

        if (current == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            newNode->prev = head;
            current = newNode;
        }
    }

    linkedListTraversal(head);
    printf("Enter Pan Number to Insert:");
    scanf("%s",pannum);
    head = insertAtFirst(head, pannum);
    printf("\n The list after insertion is :\n");
    linkedListTraversal(head);

    // Free allocated memory for all nodes
    current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}