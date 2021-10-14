#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    void reverse(int arr[], int i, int j )
    
    { int li=i;
    int ri=j;
    while(li<ri)
    {
        int temp =arr[li];
        arr[li]=arr[ri];
        arr[ri]=temp;
        li++;
        ri--;
        
    }
    
        
    }
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        reverse(arr,0,d-1);
         reverse(arr,d,n-1);
          reverse(arr,0,n-1);
    }
};

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
