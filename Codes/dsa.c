//insertion, bubble, selection, merge sort
#include <stdio.h>
//bubble
void bubbleSort(int *a, int n)
{
    
        int i, j; 
        
        int count=0; int temp=0;
    
    for (i = 0; i < n-1; i++)       
        { 
            count=0;
            
        for (j = 0; j < n-i-1; j++)  
            {
                if (a[j] > a[j+1]) 
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    count++;
                }
            }
            if(count==0) //already sorted, no swaps during a traversal
            break;
    }

}
//selection
void selectionSort(int *a, int n)
{
    int i, j, min, temp; 
    
    for (i = 0; i < n-1; i++) 
    { 
        
        min = i; 
        for (j = i+1; j < n; j++) 
            if (a[j] < a[min]) 
            min = j; 

        // Swap the found minimum element with the first element 
                temp=a[min];
                a[min]=a[i];
                a[i]=temp;
        
    } 
}
//merge
int m;
void mergeSort(int *a, int l, int u)
{
    
    
    if(l<u)
    {
        m=(l+u)/2;
        mergeSort(a,l,m);
        mergeSort(a, m+1, u);

        merge(a,l,m,u);
    }
    
}
void merge(int *a, int l, int m, int u)
{
    int i,j,k=0;
    int *f=(int *)malloc((u-l+1)*sizeof(int));
    i=0;j=m+1;

    while(i<=m && j<=u)
    {
        if(a[i]<a[j])
        f[k++]=a[i++];
        else f[k++]=a[j++];
    }
    while(i<=m)
    {
        f[k++]=a[i++];
    }
    while(j<=u)
    f[k++]=a[j++];

    for(i=0;i<u-l;i++)
    { a[l+i]=f[i];
    printf("-%d-", f[i]);}
    printf("  ");
}
//insertion
void insertionSort(int *a, int n)
{
     int i, el, j;  
    for (i = 1; i < n; i++) 
    {  
        el = a[i];  
        j = i - 1;  
  
       
        while (j >= 0 && a[j] > el) 
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = el;  
    }  
}



int main()
{
    int a[]={10,56,43,90,53,89,76,2,90,8,0,986,34};
    int c=0;
    int n=sizeof(a)/sizeof(int); 
    printf("enter 1-bubble sort; 2-selection sort; 3-merge sort; 4-insertion sort\n");
    scanf("%d", &c);
        if(c==1)
        bubbleSort(a, n);
    else if(c==2)
        selectionSort(a, n);
    else if(c==3)
        mergeSort(a,0,n-1);
    else if(c==4)
        insertionSort(a, n);
        else printf("\nwrong input\n");
        
    printf("\n sorted elements\n");
    for(int i=0;i<n;i++)
    {
        printf(" %d ", a[i]);
    }
    
    
}
