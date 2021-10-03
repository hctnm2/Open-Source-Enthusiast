#include <bits/stdc++.h>
using namespace  std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define  rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
const int N=1e3+2;

int dp[N][N];
int  solve(string s) {
    int n=s.length();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
     
    for(int i=0;i<n;i++){
        dp[i][i]=1;
    }
    for(int i=n-2;i>=0;i--){
    for(int j=i+1;j<n;j++){
        if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
        else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}


int main(){

	rep(i,0,N){
		rep(j,0,N){
			dp[i][j]=-1;
		}
	}

	string s1="bebeeed";
	cout<<solve(s1)<<endl;
	return 0;
}