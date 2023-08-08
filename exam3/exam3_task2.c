#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void print(struct Node *cll){
    Node* current = cll;
    
    do{
        printf("%d ",current->data);
        current = current->next;
    }while(current != cll);
    printf("\n");
    
}

struct Node* insertAfter(struct Node* cll, int skipCount, int newElem) {
    if (cll == NULL || skipCount < 0 || newElem < 0) {
        printf("errorrrr, inlid input.\n");
        return NULL;
    }
    
    Node* current = cll;
    
    for (int i = 0; i < skipCount; i++) {
        current = current->next;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("error while memory alloc");
        return NULL;
    }
    
    newNode->data = newElem;
    newNode->next = current->next;
    current->next = newNode;
    
    return newNode;
}

int main(void){
    int N;
    printf("Input N: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    int firstElement;
    printf("Enter the first element: ");
    scanf("%d", &firstElement);
    
    Node* cll = (Node*)malloc(sizeof(Node));
    if (cll == NULL) {
        perror("error while memory alloc");
        return 1;
    }
    cll->data = firstElement;
    cll->next = cll;

    Node* current = cll;
    for (int i = 1; i < N; i++) {
        int element;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);

        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            perror("error while memory alloc");
        }

        newNode->data = element;
        newNode->next = cll;  
        current->next = newNode;  
        current = newNode; 
    }

    printf("Cyclic linked list: ");
    print(cll);

    int skipCount, newElem;
    printf("Enter the skip count and new element: ");
    scanf("%d %d", &skipCount, &newElem);
    
    Node* insertedNode = insertAfter(cll, skipCount, newElem);
    if (insertedNode != NULL) {
        printf("Inserted element: %d\n", insertedNode->data);
        printf("Cyclic linked list after insertion: ");
        print(cll);
    }

    current = cll->next; 
    while (current != cll) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    free(cll);

    return 0;
}