
// Binary Search
// Note: The array should be sorted in ascending order
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int key){

    // search for the required number will begin from index 's' to index 'e', which here initially are 0 and n.
    int s=0,e=n;
    while(s<=e){
        // this middle index will be used in searching the required number.
        int mid=(s+e)/2;
        
        if(arr[mid]==key)
        return mid;

        // if the number being searched is less than the mid element of the alloted array, then all elements greater than mid term will be excluded,
        // and our new alloted array's end point will be this mid term.
        else if(arr[mid]>key){
            e=mid-1;
        }

        // if the number being searched is more than the mid element of the alloted array, then all elements less than mid term will be excluded,
        // and our new alloted array's starting point will be this mid term.
        else{
            s=mid+1;
        }

    }
    return -1;
}

int main(){
    // Enter the length of the array
    int n;
    cin>>n;

    int arr[n];
    // Enter your array
    for(int i=0;i<n;i++)
    cin>>arr[i];

    // Enter the number to be searched in the array
    int key;
    cin>>key;

    cout<<binarySearch(arr,n,key);
}