#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to create a linked list from an array
struct Node* createList(int arr[], int size) {
    struct Node* head = NULL;
    for (int i = 0; i < size; i++) {
        insertAtEnd(&head, arr[i]);
    }
    return head;
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    // If one list is empty, return the other
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    struct Node* result = NULL;
    struct Node* tail = NULL;
    
    // Compare nodes and merge
    while (list1 != NULL && list2 != NULL) {
        struct Node* temp;
        
        if (list1->data <= list2->data) {
            temp = list1;
            list1 = list1->next;
        } else {
            temp = list2;
            list2 = list2->next;
        }
        
        // Add the smaller node to the result list
        if (result == NULL) {
            result = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        tail->next = NULL;
    }
    
    // Attach remaining nodes
    if (list1 != NULL) {
        tail->next = list1;
    }
    if (list2 != NULL) {
        tail->next = list2;
    }
    
    return result;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free memory allocated for the list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int n, m;
    
    // Read first list
    scanf("%d", &n);
    int* arr1 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    
    // Read second list
    scanf("%d", &m);
    int* arr2 = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }
    
    // Create linked lists
    struct Node* list1 = createList(arr1, n);
    struct Node* list2 = createList(arr2, m);
    
    // Merge the lists
    struct Node* mergedList = mergeSortedLists(list1, list2);
    
    // Display the merged list
    displayList(mergedList);
    
    // Free allocated memory
    free(arr1);
    free(arr2);
    freeList(mergedList);
    
    return 0;
}