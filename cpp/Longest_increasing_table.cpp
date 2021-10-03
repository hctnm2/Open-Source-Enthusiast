#include <bits/stdc++.h>
using namespace  std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define  rep(i,a,b) for(int i=a;i<b;i++)
const int N=1e5+2;
 
  
int main(){

	int n =9;
	vi a={10,22,9,33,21,50,52,60,80};
	vi dp(n,1);
	int ans=0;

	rep(i,1,n){
		rep(j,0,i){
			if(a[i]>a[j])
				dp[i]=max(dp[i],1+dp[j]);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}