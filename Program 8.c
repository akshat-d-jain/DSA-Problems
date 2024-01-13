#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjacency_list;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
} 

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjacency_list = (struct Node**)malloc(V * sizeof(struct Node*));
    
    for (int i = 0; i < V; i++) {
        graph->adjacency_list[i] = NULL;
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = newNode;
    
    newNode = createNode(src);
    newNode->next = graph->adjacency_list[dest];
    graph->adjacency_list[dest] = newNode;
}

void deleteNode(struct Graph* graph, int node) {
    struct Node* current, *temp;
    
    for (int i = 0; i < graph->V; i++) {
        current = graph->adjacency_list[i];
        while (current) {
            if (current->data == node) {
                temp = current;
                graph->adjacency_list[i] = current->next;
                free(temp);
            } else if (current->next && current->next->data == node) {
                temp = current->next;
                current->next = temp->next;
                free(temp);
            } else {
                current = current->next;
            }
        }
    }
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* current = graph->adjacency_list[i];
        printf("Adjacency list of vertex %d: ", i);
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Initial Graph:\n");
    printGraph(graph);

    int deleteNodeValue;
    printf("Enter a node to delete: ");
    scanf("%d", &deleteNodeValue);
    deleteNode(graph, deleteNodeValue);

    printf("\nGraph after deleting node %d:\n", deleteNodeValue);
    printGraph(graph);

    return 0;
}

