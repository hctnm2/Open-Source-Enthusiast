#include <bits/stdc++.h>
using namespace  std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define  rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

const int N=1e5+2,MOD=1e9+7;
int dp[N];

int Minsquare(int n){
	if(n==1 || n==2 || n==3 || n==0 ){
		return n;
	}
	if(dp[n]!=MOD)
		return dp[n];

	for (int i = 1; i*i <= n; i++)
	{
		dp[n]=min(dp[n],1+Minsquare(n-i*i));
	}
	return dp[n];
}

int main(){
	rep(i,0,N)
		dp[i]=MOD;
	cout<<Minsquare(1024)<<endl;
	return 0;
}