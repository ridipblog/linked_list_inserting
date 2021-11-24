#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
void linkedlisttraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct Node * insertAtFirst(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct Node * insertAtIndex(struct Node *head,int data,int index)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct Node * insertAtEnd(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
int main()
{
    struct Node *head;
    struct Node *newhead;
    struct Node *second;
    struct Node *thrid;
    //allocate memory for nodes in the linked list in heap
    head=(struct Node *)malloc(sizeof (struct Node));
    newhead=(struct Node *)malloc(sizeof (struct Node));
    second=(struct Node *)malloc(sizeof (struct Node));
    thrid=(struct Node *)malloc(sizeof (struct Node));
    //link frist and second nodes;
    head->data=7;
    head->next=second;
    //link second and thrid nodes;
    second->data=11;
    second->next=thrid;
    //terminate list at the thried node;
    thrid->data=66;
    thrid->next=NULL;
    linkedlisttraversal(head);
    //newhead=insertAtFirst(head,70);
    //head=insertAtIndex(head,10,1);
    head=insertAtEnd(head,5);
    linkedlisttraversal(head);

    return 0;
}
