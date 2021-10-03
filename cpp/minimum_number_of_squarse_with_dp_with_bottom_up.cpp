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

int main(){

	int n=1025;
	rep(i,0,N)
		dp[i]=MOD;

	vi dp(n+1,MOD);
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;

	for (int i = 1; i*i <= n; ++i)
	{
		for (int j = 0; i*i+j <=n; ++j)
		{
				
			dp[i*i+j]=min(dp[i*i+j],1+dp[j]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
} 