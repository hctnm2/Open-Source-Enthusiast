#include <stdio.h>
struct Node
{
    int value;
    struct Node *next,*prev;
}*start;
void insertbeg(int v)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->value=v;
    n->next=NULL;
    n->prev=NULL;
    if(start==NULL)start=n;
    else{
        start->prev=n;
        n->next=start;
        start=n;
    }
}
void deletebeg()
{
    struct Node* n;
    if(start==NULL)printf("List is empty\n");
    else
    {
        n=start;
        (n->next)->prev=NULL;
        start=n->next;
        free(n);
       
    }
}
void insertend(int v){
    struct Node* n;
    struct Node* k;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->value=v;
    n->next=NULL;
    n->prev=NULL;
    if(start==NULL)start=n;
    else
    {
        k=start;
      while(k->next!=NULL)k=k->next;
      k->next=n;
      n->prev=k;
    }
}
void deleteend()
{
    struct Node* n;
    struct Node* k;
    if(start==NULL)printf("Invalid operation, list is empty\n");
    else
    {
        k=start;
        while((k->next)->next!=NULL)k=k->next;
        n=k->next;
        k->next=NULL;
        free(n);
    }
}
void insertbypos(int v,int p)
{
    struct Node* n;
    struct Node* k;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->value=v;
    n->next=NULL;
    n->prev=NULL;
    if(p==1)insertbeg(v);
    else if(p!=1 && start==NULL)printf("List is empty\n");
    else
    {
        k=start;
        int p1=1;
        while(p1<p-1 && k->next!=NULL)
        {
            k=k->next;
            p1++;
        }
        n->next=k->next;
        (n->next)->prev=n;
        n->prev=k;
        k->next=n;
    }
}
void deletebypos(int p)
{
    struct Node* n;
    struct Node* k;
    if(start!=NULL && p==1)deletebeg();
    else if(p!=1 && start==NULL)printf("List is empty\n");
    else
    {
        k=start;
        int p1=1;
        while(p1<p-1 && (k->next)->next!=NULL)
        {
            k=k->next;
            p1++;
        }
        n=k->next;
        k->next=n->next;
        (n->next)->prev=k;
        free(n);
    }
}
void display()
{
    struct Node *n;
    n=start;
    while(n!=NULL){
        printf("%d",n->value);
        n=n->next;
    }
}
void main()
{   int choice,n,a,k=1,pos;
while(k==1){
    printf("Press 1 for insertion from beginning\nPress 2 for deletion from beginning\nPress 3 for insertion from end\nPress 4 for deletion from end\nPress 5 for insertion by position\nPress 6 for deletion by position\nPress 7 for display\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("enter value to be inserted ");
        scanf("%d",&n);
        insertbeg(n);
        break;
        case 2:
        deletebeg();
        break;
        case 3:
        printf("enter value to be inserted ");
        scanf("%d",&n);
        insertend(n);
        break;
        case 4:
        deleteend();
        break;
        case 5:
        printf("Enter value to be inserted ");
        scanf("%d",&n);
        printf("Enter position ");
        scanf("%d",&pos);
        insertbypos(n,pos);
        break;
        case 6:
        printf("Enter position to be deleted ");
        scanf("%d",&pos);
        deletebypos(pos);
        break;
        case 7:
        display();
        break;
        default:
        printf("Invalid choice entered\n");
        break;
    }
    printf("press 1 for reapetition");
    scanf("%d",&k);
}
    
}