#include <bits/stdc++.h>
using namespace  std;
#define vi vector<int> 
#define pii pair<int,int>
#define vii vector<pii>
#define  rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
const int N=1e5+2;


int main(){
	int n=5;
	vi dp(n+1);
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	rep(i,3,n+1){
	 	dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	cout<<dp[n]<<endl;
	return 0;
} 