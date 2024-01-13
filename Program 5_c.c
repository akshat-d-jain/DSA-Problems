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
        printf("AADHAR NUMBER is: %s\n", ptr->data);
        ptr = ptr->next;
    }
}

void reverseTraversal(struct Node * ptr)
{
    while(ptr != NULL)
    {
        ptr = ptr ->next;
    }
    while(ptr != NULL)
    {
        printf("AADHAR NUMBER is: %s\n", ptr->data);
        ptr = ptr ->prev;
    }
}

struct Node* insertAtIndex(struct Node* head, char data[30], int index) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 1;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    strcpy(ptr->data, data);
    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
    return head;
}
int calculateLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}
int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;
    int numNodes,indextoinsert,length;
    char aadnum[30];

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter AADHAR NUMBER: ");
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
            newNode->prev = current;
            current = newNode;
        }
    }
    printf("\n The list before insertion is :\n");
    linkedListTraversal(head);
    printf("Enter the Index Where You Want to Insert:");
    scanf("%d",&indextoinsert);
    length = calculateLength(head);
    printf("Length of the linked list: %d\n", length);
         if(indextoinsert>length || indextoinsert<0)
         {
            printf("Enter Valid Index!!\n");
         }
         else
         {
        printf("Enter the AADHAR NUMBER You Want to Insert:");
        scanf("%s",aadnum);
        //head = insertAtIndex(head, aadnum, indextoinsert);
        printf("\n The list after insertion is :\n");
        linkedListTraversal(head);
        reverseTraversal(head);
         }


    
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


