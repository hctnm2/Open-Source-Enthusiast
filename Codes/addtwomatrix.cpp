#include <bits/stdc++.h>
using namespace std;
int main()
{
   int a[100][100],b[100][100],d[100][100];
   int c,r;
   int r1,c1;
   cout<<"give rows and column of  matrixs";
   cin>>r;
   cin>>c;
   for (int i = 0; i < r; i++)
   {
      for (int j = 0; j < c; j++)
      {
          cout<<"enter a"<<i+1<<j+1;
          cin>>a[i][j];
      }
   }
   for (int i = 0; i < r; i++)
   {
       for (int j = 0; j < c; j++)
       {
           cout << "enter b" << i + 1 << j + 1;
           cin >> b[i][j];
       }
   }
    cout<<"your matrix is";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            d[i][j]=a[i][j]+b[i][j];
            cout<<d[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}