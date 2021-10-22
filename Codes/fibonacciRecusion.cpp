#include<iostream>
using namespace std;
int fib(int n){
if(n==1){
    return 0;
}
if(n==2){
    return 1;
}

    // fib(n) = fib(n - 1) + fib(n - 2);
    return fib(n - 1) + fib(n - 2);
}

int main(){
    int n;
   
    cin >> n;
    cout << fib(n);
    return 0;
}
