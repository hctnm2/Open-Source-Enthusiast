#include <stdio.h>
struct Node
{
    int value;
    struct Node *next;
}*start;
void insertbeg(int v)
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->value=v;
    n->next=NULL;
    if(start==NULL)start=n;
    else{
        n->next=start;
        start=n;
    }
}
void deletebeg()
{
    struct Node* n;
    if(start==NULL)printf("Lst is empty\n");
    else
    {
        n=start;
        start=start->next;
        free(n);
        printf("Value deleted successfully\n");
    }
}
void insertend(int v){
    struct Node* n;
    struct Node* k;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->value=v;
    n->next=NULL;
    if(start==NULL)start=n;
    else
    {
        k=start;
      while(k->next!=NULL)k=k->next;
      k->next=n;
    }
}
void deleteend()
{
    struct Node* n;
    struct Node* k;
    if(start==NULL)printf("Invalid, list is empty\n");
    else
    {
        k=start;
        while((k->next)->next!=NULL)k=k->next;
        n=k->next;
        k->next=NULL;
        free(n);
        printf("Value deleted successfully\n");
    }
}
void insertbypos(int v,int p)
{
    struct Node* n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->value=v;
    n->next=NULL;
    int p1=1;
    
    if(p==1)insertbeg(v);
    
    else{
        struct Node* k;
        k=start;
    
        while(p1<p-1 && k->next!=NULL)
        {
            k=k->next;
            p1++;
        
        }
        if(p1==p-1)
        {
            n->next=k->next;
            k->next=n;
        
        }    
        else printf("Positon not avialable\n");
    }
}
void deletebypos(int p)
{
    struct Node* n;
    struct Node* k;
    if(start==NULL)printf("List is empty\n");
    else if(p==1)deletebeg();
    else{
        int p1=1;
        while(p1<p-1 && k->next!=NULL)
        {
            k=k->next;
            p1++;
        }
        if(p1==p-1)
        {
            n=k->next;
            k->next=n->next;
            free(n);
            printf("Value deleted successfully\n");
            
        }
        }
    
}
void sort()
{
    struct Node *m,*n,*x,*k;
    int a=0;
    while(a!=1)
    {
        n=start;
        k=n->next;
        x=start;
        int c=1;
        a=1;
        while(k!=NULL)
        {
            if(n->value>k->value)
            {
                n->next=k->next;
                k->next=n;
                a++;
                if(c==1){
                    start=k;
                }
                else{
                x->next=k;
                }
                x=k;
                k=n->next;
            }
            else
            {
                x=n;
                n=k;
                k=k->next;
            }
            c++;
        }
    }
}
void display()
{
    struct Node *n;
    if(start==NULL)printf("List is empty\n");
    else
    {
    n=start;
    while(n!=NULL){printf("%d ",n->value);n=n->next;}
    printf("\n");
    }
}
void main()
{   
int choice,n,a,k=1,pos;
while(k==1){
    printf("1 for insert from beginning\n2 for delete from beginning\n3 for insert from end\n4 for delete from end\n5 for insert by position\n6 for delete by position\n7 for diaplay\n8 for sorting\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Enter value to be inserted ");
        scanf("%d",&n);
        insertbeg(n);
        break;
        case 2:
        deletebeg();
        break;
        case 3:
        printf("Enter value to be inserted ");
        scanf("%d",&n);
        insertend(n);
        break;
        case 4:
        deleteend();
        break;
        case 5:
        printf("Enter value to be inserted ");
        scanf("%d",&n);
        printf("Enter position to be inserted at ");
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
        case 8:
        sort();
        break;
        default:
        printf("Invalid value entered\n");
        break;
    }
    printf("Press 1 to repeat\n");
    scanf("%d",&k);
}
    
}
