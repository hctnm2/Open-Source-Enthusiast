#include<iostream>
using namespace std;

int main()
{
    int n, i, temp, j, k, a;
    cout<<"Enter the desired size of the array-\n";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements of the array-\n";
    for(i=0; i<n; i++)
        cin>>arr[i];
    for(i=0; i<n; i++)
    {
        temp = arr[i];
        for(j=(i+1); j<n; j++)
        {
            if(temp==arr[j])
            {
                for(k=j; k<n; k++)
                    arr[k]= arr[k+1];
                n--;
                j--;
            }
        }
    }
    cout<<"\nAfter removing the duplicate elements, the final array with unique elements is-\n\n";
    for(i=0; i<n; i++)
        cout<<arr[i]<<endl;
    return 0;
}