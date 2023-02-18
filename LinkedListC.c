#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

//print all elements from list
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

//add node to the end of the list
void addNode(Node* head, int value) {
    Node* curr = head;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = malloc(sizeof(struct node));
    curr->next->value = value;
    curr->next->next = NULL;
}

//delete node at index
void delNode(Node* head, int index) {
    Node* curr = head;
    int i = 0;

    while (i != (index - 1)) {
        curr = curr->next;
        i++;
    }

    Node* nodeToDelete = curr->next;

    curr->next = nodeToDelete->next;
    free(nodeToDelete);
}

//frees all elements in list recursively
void freeAllList(Node* head) {
    if (head == NULL)
        return;
    freeAllList(head->next);
    free(head);
}

//insert new node at index
void insertNode(Node* head, int index, int value) {
    Node* curr = head;
    int i = 0;

    while (i != (index - 1)) {
        curr = curr->next;
        i++;
    }

    Node* nextNode = curr->next;
    curr->next = malloc(sizeof(struct node));
    curr->next->value = value;
    curr->next->next = nextNode;
}

//rewrite the value at index
void setValueOfNode(Node* head, int index, int value) {
    Node* curr = head;
    int i = 0;

    while (i != index) {
        curr = curr->next;
        i++;
    }

    curr->value = value;
}

//returns a value from list at index
int getValueOfNode(Node* head, int index) {
    Node* curr = head;
    int i = 0;

    while (i != index) {
        curr = curr->next;
        i++;
    }

    return curr->value;
}

int main()
{
    Node* head = malloc(sizeof(struct node));
    head->value = 1;
    head->next = NULL;
   
    for (size_t i = 2; i < 11; i++)
    {
        addNode(head, i);
    }

    printList(head);

    return 0;
}

