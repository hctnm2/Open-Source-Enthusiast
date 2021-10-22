#include<iostream> //importing input output package
using namespace std;
int fib(int n){//fibonacci sumation function
if(n==1){
    return 0;
}
if(n==2){
    return 1;
}

    // fib(n) = fib(n - 1) + fib(n - 2);
    return fib(n - 1) + fib(n - 2);
}//end of fib function

int main(){// main function
    int n;
    cin >> n;//entering the limit of series
    cout << fib(n);//displaying the fibonacci series
    return 0;
}//end of main function
