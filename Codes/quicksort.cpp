#include<iostream>

using namespace std;

int partition(int arr[],int start,int end){
	int pivot=arr[start];
	int i=start;
	int j=end;
	while(i<j){
		 do{i++;}while( i<end && arr[i]<=pivot);
	     do{j--;}while(j>=0 && arr[j]>pivot);
		if(i<j)
			swap(arr[i],arr[j]);
	}

	swap(arr[start],arr[j]);
	return j;
}

void quicksort(int arr[],int start,int end){

	if(start<end){
		int j=partition(arr,start,end);
		quicksort(arr,start,j);
		quicksort(arr,j+1,end);
	}
}

int main(){

    int arr[]={10,9,8,7,6};
    int n=5;

    quicksort(arr,0,n);

    for(int x:arr)
    cout<<x<<" ";

    return 0;
}