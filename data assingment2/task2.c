
#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};
    struct node* head = NULL;

void insertBeginning(int data){
   struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int data){
    struct node* newnNode = (struct node*)malloc(sizeof(struct node));
    newnNode->data = data;
    newnNode->next = NULL;
    if (head == NULL)
    {
        head = newnNode;
    }
    else
    {
        struct node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnNode;
    }
}

void insertPosition(int position , int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct node* temp = head;
        for (int i = 1; i < position -1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(int position){
    if (position == 1)
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        struct node* temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position\n");
            return;
        }
        struct node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    }
}

void printList(){
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    insertBeginning(5);
    insertEnd(10);
    insertEnd(15);
    insertPosition(3,25);
    deleteNode(1);
    printList();
    return 0;
}
