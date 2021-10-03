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
		return 1;
	}
	int ans=MOD;
	for (int i = 1; i*i <n; i++)
	{
		ans=min(ans,1+Minsquare(n-i*i));
	}
	return ans;
}
 
int main(){
	cout<<Minsquare(5)<<endl;
	return 0;
}

