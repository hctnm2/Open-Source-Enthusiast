#include <bits/stdc++.h>
using namespace  std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define  rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
 
const int N=1e5+2;
int dp[N];
int staircase(int n){
	if(n==0 ){
		return 1;
	}

	if(n==1 || n==2)
		return n;

	if(dp[n]!=-1)
		return dp[n];
 
	dp[n]= staircase(n-1)+staircase(n-2)+staircase(n-3);
	
	return dp[n];
}

int main(){

	rep(i,0,N){
		dp[i]=-1;
	}
	int n=5;
	cout<<staircase(n)<<endl;
	return 0;
}