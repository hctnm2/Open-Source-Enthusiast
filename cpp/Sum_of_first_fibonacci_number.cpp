#include <bits/stdc++.h>
using namespace  std;
#define int long long
const int N=1e5+2,MOD=1e9+7;

vector<vector<int>> multiply(vector<vector<int>> &a,vector<vector<int>> &b){

	int n=a.size();
	vector<vector<int>> ans(n,vector<int>(n,0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <n ; ++j)
		{

			for (int k = 0; k < n; ++k)
			{
				ans[i][j] +=a[i][k] * b[k][j];
		 	}
		} 
	}
	return ans;
}

vector<vector<int>> matrixExponentiate(vector<vector<int>> &a,int n){

	if(n==0){
	int sz=a.size();
	vector<vector<int> > ans(sz,vector<int>(sz,0));
	for(int i=0;i<sz;i++){
		ans[i][i]=1;
	}
	return ans;
	}
	if(n==1){
		return a;
	}

	vector<vector<int>> temp=matrixExponentiate(a,n/2);
	vector<vector<int>> ans=multiply(temp,temp);
	if(n&1)
		ans = multiply(ans,a);
	return ans;
}


signed main(){

	int n=7;
	vector<vector<int>> a(3,vector<int>(3,0));
	a[0][0]=a[0][1]=a[0][2]=1;
	a[1][1]=a[1][2]=1;
	a[2][1]=1;
	vector<vector<int>> ans= matrixExponentiate(a,n);
	int sz=3;
	for (int i = 0; i < sz; ++i)
	{
		for (int j = 0; j < sz; ++j)
		{	
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}