#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 1000

// Adjacency list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adj[], int u, int v) {
    // Add edge u -> v
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
    
    // Add edge v -> u (for undirected graph)
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

bool dfs(int node, int parent, int vis[], Node* adj[]) {
    vis[node] = 1;
    
    // Traverse all adjacent nodes
    Node* temp = adj[node];
    while (temp != NULL) {
        int adjacentNode = temp->data;
        
        if (!vis[adjacentNode]) {
            if (dfs(adjacentNode, node, vis, adj))
                return true;
        }
        else if (adjacentNode != parent) {
            return true;
        }
        
        temp = temp->next;
    }
    return false;
}

bool isCycle(int V, Node* adj[]) {
    int* vis = (int*)calloc(V, sizeof(int));
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, vis, adj)) {
                free(vis);
                return true;
            }
        }
    }
    
    free(vis);
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    // Create adjacency list
    Node* adj[MAX_V] = {NULL};
    
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    
    bool ans = isCycle(V, adj);
    
    if (ans) 
        printf("1");
    else 
        printf("0");
    
    // Free allocated memory
    for (int i = 0; i < V; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    
    return 0;
}