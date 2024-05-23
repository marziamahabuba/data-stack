
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void firstnode(int data)
{
    head=(struct node*)malloc(sizeof(struct node));
    head->data=data;
    head->next=NULL;
}

void addnode(int data)
{
    struct node *a;
    a=head;
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    while(a->next!=NULL)
    {
        a=a->next;
    }
    a->next=temp;
}


void printnode()
{
    struct node *temp;
    temp=head;
    printf("Linked List: ");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}

int main()
{
    firstnode(5);
    addnode(10);
    addnode(15);
    printnode();

    return 0;
}
