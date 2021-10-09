#include<iostream>
using namespace std;
void swap(int &n1,int &n2)
{
    int t = n1;
    n1 = n2;
    n2 = t;
}
void heapify(int arr[], int n, int i)  
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest])
    {
        largest = l;
    }
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
    
}

//Function to build a Heap from array.
void buildHeap(int arr[], int n)  
{ 
    //here n/2-1 gives the first element of the last but one level. this way we are avoiding the leaf nodes.
    for(int i=n/2 -1; i>=0;i--)
    {
        heapify(arr,n,i);
    }
}


//Function to sort an array using Heap Sort.
void heapSort(int arr[], int n)
{
    buildHeap(arr,n);
    for(int i=n-1;i>0;i--)
    {
        //this way all the highest elements sit in the back and thus finally array will be sorted.
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    cout<<"Struggling with unsorted numbers array??\nDon't worry. We are here to sort them using \"HeapSort\" \n \n";
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"\nwhile entering the numbers please make sure that all the numbers are seperated by a space or new line ";
    cout<<"\nNow it's time to enter the numbers in the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapSort(arr,n);
    cout<<"\nIt's magic time...";
    cout<<"\nHere is your sorted array. \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nYou can thank me later!!";
}