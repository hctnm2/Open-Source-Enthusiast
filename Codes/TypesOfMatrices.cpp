#include <iostream>
using namespace std;

int main()
{
    int choice;
    char ch;
    int n, i, j, k, l;

    ch = 'y';
    while (ch == 'y')
    {
        cout << "\nMENU-\n\n1. Diagonal Matrix\n2. Tri-Diagonal Matrix\n3. Lower Triangular Matrix\n4. Upper Triangular Matrix\n5. Symmetric Matrix\n\n";
        cout << "Enter your choice-\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                cout<<"\nDIAGONAL MATRIX\n\n";
                cout << "Enter the order of the matrix, n= \n";       //always a square matrix
                cin >> n;
                int arr[n];
                cout << "Enter the (n) diagonal elements -\n";
                for (i = 0; i < n; i++)
                    cin >> arr[i];
                cout<<"The Diagonal Matrix is -\n\n";
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < i; j++)
                    {
                        cout << "0"
                            << " ";
                    }
                    cout << arr[i] << " ";
                    for (j = 0; j < (n - i - 1); j++)
                    {
                        cout << "0"
                            << " ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                break;
            }

            case 2:
            {
                cout<<"\nTRI-DIAGONAL MATRIX\n\n";
                cout << "Enter the order of the matrix, n=\n";       //always a square matrix
                cin >> n;
                int pd[n], pda[n-1], pdb[n-1];
                cout<<"Enter the (n) elements of principle diagonal -\n";
                for(i=0; i<n; i++)
                    cin>>pd[i];
                cout<<"Enter the (n-1) elements of the diagonal above principle diagonal -\n";
                for(j=0; j<(n-1); j++)
                    cin>>pda[j];
                cout<<"Enter the (n-1) elements of the diagonal below principle diagonal -\n";
                for(k=0; k<(n-1); k++)
                    cin>>pdb[k];

                cout<<"The Tri-Diagonal Matrix is -\n\n";
                for (i = 0; i < n; i++)
                {
                    for (k = 0; k < i; k++)
                    {
                        if(k==(i-1))
                            {cout<<pdb[k]<<" ";
                            break;
                            }
                        else
                            cout << "0"<< " ";
                        
                    }
                    cout << pd[i] << " ";
                    for (j = (i+1); j < n; j++)
                    {
                        if(j==(i+1))
                            cout<<pda[j-1]<<" ";
                        else
                            cout << "0"<< " ";
                    }
                    cout<<endl;
                }
                cout<<endl;
                break;
            }

            case 3:
            {
                cout<<"\nLOWER-TRIANGULAR MATRIX\n\n";
                cout << "Enter the order of the matrix, n=\n";       //always a square matrix
                cin >> n;
                int el;
                el = (n*(n+1)/2);
                int lt[el];
                cout<<"Enter the elements of the lower-triangle (row-wise) -\n";
                for(j=0; j<el; j++)
                    cin>>lt[j];
                
                cout<<"The Lower-Triangular Matrix is -\n\n";
                k=0;
                for(i=0; i<n; i++)
                {
                    for(j=0; j<=i; j++)
                    {
                        cout<<lt[k]<<" ";
                        k++;
                    } 
                    for(l=0; l<(n-j); l++)
                    {
                        cout<<"0"<<" ";
                    }
                    cout<<endl;        
                }
                break;
            }

            case 4:
            {
                cout<<"\nUPPER-TRIANGULAR MATRIX\n\n";
                cout << "Enter the order of the matrix, n=\n";       //always a square matrix
                cin >> n;
                int ele;
                ele = (n*(n+1)/2);
                int ut[ele];
                cout<<"Enter the elements of the upper-triangle (row-wise) -\n";
                for(j=0; j<ele; j++)
                    cin>>ut[j];
                    
                cout<<"The Upper-Triangular Matrix is -\n\n";
                k=0;
                for(i=0; i<n; i++)
                {
                    for(l=0; l<i; l++)
                    {
                        cout<<"0"<<" ";
                    }
                    for(j=i; j<n; j++)
                    {
                        cout<<ut[k]<<" ";
                        k++;
                    } 
                    
                    cout<<endl;        
                }
                break;
            }

            case 5:
            {
                cout<<"\nSYMMETRIC MATRIX\n\n";
                cout<<"Enter the order of the symmetric matrix, n=\n";
                cin>>n;
                int elem;
                elem = (n*(n+1)/2);
                int sm[elem];
                cout<<"Enter the elements of the upper-triangle (row-wise) -\n";
                for(j=0; j<elem; j++)
                    cin>>sm[j];

                cout<<"The Symmetric Matrix is -\n\n";
                k=0;
                
                for(i=0; i<n; i++)
                {
                    for(l=0; l<i; l++)
                    {
                        int temp = i + (l*n) - ((l*(l+1))/2);
                        cout<<sm[temp]<<" ";
                    }
                    for(j=i; j<n; j++)
                    {
                        cout<<sm[k]<<" ";
                        k++;
                    } 
                    
                    cout<<endl;        
                }
                break;
            }
            default:
                break;
        }
            cout << "Do you want to continue? (y/n)\n";
            cin >> ch;
            cout<<endl;
    }
    return 0;
}