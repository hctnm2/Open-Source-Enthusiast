#include <bits/stdc++.h>
using namespace  std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define  rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second


int N=1e5+2;
int staircase(int n){
	if(n==0 ){
		return 1;
	}
	if(n==1 || n==2)
		return n;
	return staircase(n-1)+staircase(n-2)+staircase(n-3);
} 

int main(){
	int n=5;
	cout<<staircase(n)<<endl;
	return 0;
}