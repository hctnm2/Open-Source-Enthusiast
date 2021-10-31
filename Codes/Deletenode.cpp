
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
}*head=NULL;

void create(int a[],int n){
    struct node* newnode,*temp;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=NULL;
    temp=head;

       for(int i=1;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=a[i];
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
        }
}

void deletenode(int x){
      struct node *p,*q;
      int res;
         p=head;
      if(x==1){
        head=head->next;
         res=p->data;
        cout<<"deleted..."<<res<<endl;
        delete p;
      }
      else{
             p=head;
            q=NULL;

            for(int i=0;i<x-1;i++){
    /*        p=p->next;
        }
        res=p->data;
        p=p->next->next;
        */
            q=p;
            p=p->next;
      }
      if(p){
        q->next=p->next;
        res=p->data;


         cout<<"deleted..."<<res<<endl;
        delete p;
      }

}

}
void display(struct node *k){
    while(k!=NULL){
        cout<<k->data<<" ";
        k=k->next;
    }
}
int main(){
   int a[]={4,2,7,12,9};
     create(a,5);
     int x;
      cout<<"enter pos:\n";
     cin>>x;
     display(head);
     deletenode(x);
     display(head);
return 0;

}

