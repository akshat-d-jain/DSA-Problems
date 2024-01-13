#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;   // data = height in inches
    char name[30];
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        printf("Roll  is: %d\n", ptr->data);
        printf("Name is: %s\n", ptr->name);
        ptr = ptr->next;
    }
}

struct Node* DeleteAtFirst(struct Node * head)
{
   struct Node * ptr = head;
   head=head->next;
   free(ptr);
   return head;
}

struct Node* DeleteAtIndex(struct Node * head,int index)
{
   struct Node * p = head;
   struct Node * q = head->next;
   for(int i=0;i<index-1;i++){
      p=p->next;
      q=q->next;
   }
   p->next=q->next;
   free(q);
   return head;
}

struct Node* DeleteAtEnd(struct Node * head)
{
   struct Node * p = head;
   struct Node * q = head->next;
   while(q->next!=NULL)
   {
      p=p->next;
      q=q->next;
   }
   p->next=NULL;
   free(q);
   return head;
}

int main(){
    struct Node* head = NULL;
    struct Node* current = NULL;
    int numNodes,choice;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    

    for (int i = 0; i < numNodes; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter Height in inches : ");
        scanf("%d", &newNode->data);

        printf("Enter name: ");
        scanf("%s", newNode->name);

        newNode->next = NULL;

        if (current == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    printf("Enter the Choice:\n 1:Deletion At Beginning\n 2:Deletion At Index\n 3:Deletion at End\n 0:For Exit\n");

    printf("Enter the choice:");
    scanf("%d",&choice);    
    do{
    switch (choice)
    {
    case 1:
        printf("Linked List Before Deletion\n");   
         linkedListTraversal(head);
        head=DeleteAtFirst(head);
        printf("Linked List After Deletion from beginning:\n");   
        linkedListTraversal(head);
        break;

    case 2:
        printf("Linked List Before Deletion\n");   
         linkedListTraversal(head);
        head=DeleteAtIndex(head,5);
         printf("Linked List After Deletion at given Index\n");   
        linkedListTraversal(head);

    case 3:
         printf("Linked List Before Deletion from end\n");   
        linkedListTraversal(head);
        head=DeleteAtEnd(head);
        printf("Linked List After Deletion from end\n");   
        linkedListTraversal(head);
    
    default:
        break;
    }
    printf("Enter the choice:");
    scanf("%d",&choice);   
    }while(choice!=0);
    

    // Free allocated memory for all nodes
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}   