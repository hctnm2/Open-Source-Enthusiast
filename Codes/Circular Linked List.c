#include <stdio.h>
struct Node{
    int value;
    struct Node* next;
}*start;
void insertbeg(int v)
{
    struct Node* n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->value=v;
    n->next=NULL;
    if(start==NULL){
        start=n;
        start->next=start;
    }
    else
    {  struct Node* k;
       k=start;
       while(k->next!=start)k=k->next;
       n->next=start;
       k->next=n;
       start=n;
    }
}
void deletebeg()
{
    struct Node* n;
    struct Node* k;
    if(start==NULL)printf("List is empty\n");
    else if(start->next==start)
    {
        k=start;
       free(k);
       start=NULL;
       printf("Value deleted successfully\n");
    }
    else 
    {
      k=start;
      while(k->next!=start)k=k->next;
      n=start;
      k->next=start->next;
      start=start->next;
      free(n);
      printf("Value deleted successfully\n");
    }
}
void insertend(int v)
{
   struct Node* n;
   struct Node* k;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->value=v;
    n->next=NULL;
    if(start==NULL)
    {
        start=n;
        start->next=start;
    }
    else
    {
        k=start;
    while(k->next!=start)k=k->next;
    k->next=n;
    n->next=start;
    }
}
void deleteend()
{
    struct Node* n;
    struct Node* k;
    if(start==NULL)printf("List is empty\n");
    else if(start->next==start)
    {
        k=start;
       free(k);
       start=NULL;
       printf("Value deleted successfully\n");
    }
    else
    {
        k=start;
        while((k->next)->next!=start)k=k->next;
        n=k->next;
        k->next=start;
        free(n);
        printf("Value deleted successfully\n");
    }
}
void insertbypos(int v,int p)
{
    struct Node* n;
   struct Node* k;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->value=v;
    n->next=NULL;
    if(p==1 && start==NULL)
    {
      start=n;
      start->next=start;
      printf("Value inserted successfully\n");
    }
    else if(p>1 && start==NULL)printf("Invalid position entered\n");
    else
    {
        int p1=1;
        k=start;
        while(p1<p-1 && k->next!=start)
        {
            k=k->next;
            p1++;
        }
        if(p1==p-1)
        {
            n->next=k->next;
            k->next=n;
            printf("Value inserted successfully\n");
        }
        else printf("Position not available\n");
        
        
    }
}
void deletebypos(int p)
{
struct Node* n;
   struct Node* k;
   if(start==NULL)printf("List is empty\n");
   else if(p==1)
   {
       k=start;
       free(k);
       start=NULL;
       printf("Value deleted successfully\n");
   }
   else 
   {
       int p1=1;
        k=start;
        while(p1<p-1 && k->next!=start)
        {
            k=k->next;
            p1++;
        }
        if(p1==p-1)
        {
            n=k->next;
            k->next=n->next;
            free(n);
            printf("Value inserted successfully\n");
        }
        else printf("Position not available\n");
   }
}
void display()
{   
    struct Node* n;
    if(start==NULL)printf("List is empty\n");
    else{
    n=start;
    while(n->next!=start)
    {
        printf("%d ",n->value);
        n=n->next;
    }
    printf("%d",n->value);
    }
    printf("\n");
}
void main()
{
    int k=1,n,choice,pos;
    while(k==1)
    {
        printf("Press 1 for insertion at beginning\n");
        printf("Press 2 for deletion at beginning\n");
        printf("Press 3 for insertion at end\n");
        printf("Press 4 for deletion at end\n");
        printf("Press 5 for insertion at position\n");
        printf("Press 6 for deletion at position\n");
        printf("Press 7 for display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter value to be inserted ");
            scanf("%d",&n);
            insertbeg(n);
            printf("Value inserted successfully\n");
            break;
            case 2:
            deletebeg();
            break;
            case 3:
            printf("Enter value to be inserted ");
            scanf("%d",&n);
            insertend(n);
            printf("Value inserted successfully\n");
            break;
            case 4:
            deleteend();
            break;
            case 5:
            printf("Enter value to be inserted ");
            scanf("%d",&n);
            printf("Enter postion for insertion ");
            scanf("%d",&pos);
            insertbypos(n,pos);
            break;
            case 6:
            printf("Enter position to be deleted ");
            scanf("%d",&pos);
            deleteend(pos);
            break;
            case 7:
            display();
            break;
            default:
            printf("Wrong option entered\n");
            
        }
        printf("Press 1 for repeat\n");
        scanf("%d",&k);
        if(k!=1)printf("Invalid choice entered\n");
        else continue;
    }
}