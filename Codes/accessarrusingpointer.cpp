#include <bits/stdc++.h>
using namespace std;
int main()
{
   int a[10]={0};
   int m,n,v;
   cout<<"number of element";
   cin>>n;
 
   for (int i=0;i<n;i++)
   {
       cin>>*(a+i);
   }
    for (int i = 0; i < n; i++)
   {
       cout << *(a + i);
   }

    return 0;
}