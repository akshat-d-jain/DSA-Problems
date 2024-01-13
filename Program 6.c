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

// Function to create a new node
struct Node *createNode()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    return newNode;
}



// Function to display the circular linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node *current = head;

    do
    {
        printf("Roll is: %d\n", current->data);
        printf("Name is: %s\n", current->name);
        printf("Age is: %d\n", current->age);
        current = current->next;
    } while (current != head);
}

// Function to insert a node at the end of the circular linked list
struct Node *insertEnd(struct Node *head)
{
    struct Node *newNode = createNode();
    
    printf("Enter roll number: ");
    scanf("%d", &newNode->data);
    printf("Enter name: ");
    scanf("%s", newNode->name);
    printf("Enter age: ");
    scanf("%d", &newNode->age);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted at the end successfully.\n");
    return head;
}

// Function to create a circular linked list
struct Node *createList()
{
    struct Node *head = NULL;
    int numNodes, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0)
    {
        printf("Invalid number of nodes. Must be greater than 0.\n");
        return head;
    }

    for (i = 0; i < numNodes; i++)
    {
        head = insertEnd(head);
    }

    printf("Circular Linked List created successfully.\n");
    return head;
}

// Function to insert a node at a specific position in the circular linked list
struct Node *insertPosition(struct Node *head, int position)
{
    if (position < 1)
    {
        printf("Invalid position. Position should be >= 1.\n");
        return head;
    }

    else if (head == NULL)
    {
        printf("Linked List Is Empty and Cannot Insert!!");
    }

    else
    {
    struct Node *newNode = createNode();
    
    printf("Enter roll number: ");
    scanf("%d", &newNode->data);
    printf("Enter name: ");
    scanf("%s", newNode->name);
    printf("Enter age: ");
    scanf("%d", &newNode->age);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return head;
    }

    if (position == 1)
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
        printf("Node inserted at position %d successfully.\n", position);
        return head;
    }

    struct Node *current = head;
    int count = 1;

    do
    {
        if (count == position - 1)
        {
            newNode->next = current->next;
            current->next = newNode;
            printf("Node inserted at position %d successfully.\n", position);
            return head;
        }

        current = current->next;
        count++;
    } while (current != head);



    printf("Position %d not found in the Circular Linked List.\n", position);
    return head;
    }
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



// Function to delete a node at a specific position
struct Node *deletePosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty. Cannot delete.\n");
        return head;
    }

    struct Node *current = head;
    struct Node *previous = NULL;
    int count = 1;

    do
    {
        if (count == position)
        {
            if (previous == NULL)
            {
                struct Node *temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = head->next;
                head = head->next;
            }
            else
            {
                previous->next = current->next;
                free(current);
            }
            printf("Node at position %d deleted successfully.\n", position);
            return head;
        }

        previous = current;
        current = current->next;
        count++;
    } while (current != head);

    printf("Position %d not found in the Circular Linked List.\n", position);
    return head;
}

// Function to search for a node by roll number and delete it
struct Node *searchAndDelete(struct Node *head, int rollNumber)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty. Cannot delete.\n");
        return head;
    }

    struct Node *current = head;
    struct Node *previous = NULL;

    do
    {
        if (current->data == rollNumber)
        {
            if (previous == NULL)
            {
                struct Node *temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = head->next;
                head = head->next;
            }
            else 
            {
                previous->next = current->next;
                free(current);
            }
            printf("Node with roll number %d deleted successfully.\n", rollNumber);
            return head;
        }

        previous = current;
        current = current->next;
    } while (current != head);

    printf("Node with roll number %d not found in the Circular Linked List.\n", rollNumber);
    return head;
}

// Function to reverse the circular linked list
struct Node *reverse(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty. Cannot reverse.\n");
        return head;
    }

    struct Node *prevNode = NULL;
    struct Node *current = head;
    struct Node *nextNode;

    do
    {
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    } while (current != head);

    head->next = prevNode;
    head = prevNode;

    printf("Circular Linked List reversed successfully.\n");
    return head;
}

int main()
{
    struct Node *head = NULL;
    int choice, position, rollNumber;

    while (1)
    {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Create\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from any position\n");
        printf("5. Search and delete by roll number\n");
        printf("6. Reverse\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = createList(); // Call a function to create the circular linked list
            break;
        case 2:
            head = insertEnd(head);
            break;
        case 3:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            head = insertPosition(head, position);
            break;
           
        case 4:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            head = deletePosition(head, position);
            break;
        case 5:
            printf("Enter the roll number to search and delete: ");
            scanf("%d", &rollNumber);
            head = searchAndDelete(head, rollNumber);
            break;
        case 6:
            head = reverse(head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

