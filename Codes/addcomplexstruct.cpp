#include <bits/stdc++.h>
using namespace std;
struct complex{
float real;
float imag;
}first,sec,r;
int main()
{
 cout<<"enter ist complex";
 cout<<"enter real and imaginary";
 cin>>first.real>>first.imag;
 cout << "enter 2nd complex";
 cout << "enter real and imaginary"<<endl;
 cin >> sec.real >> sec.imag;
 r.real=first.real+sec.real;
 r.imag=first.imag+sec.imag;
 cout<<r.real<<"+i"<<r.imag;

 return 0;
}