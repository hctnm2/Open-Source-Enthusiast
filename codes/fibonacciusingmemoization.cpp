#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626
#define ll long long
#define lli long long int
#define fo(i,a,n) for(int i=a;i<n;i++)
#define pr(i,arr) for(auto i:arr)

typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<ll,ll> ml;
typedef map<int,int> mi;

int dp[1000];

int fib(int n)
{
    if(n<=1)
    {
        return n;
    }

    int a,b;
    if(dp[n-1]!=-1)
    {
        a = dp[n-1];
    }
    else
    {
        a = fib(n-1);
    }

    if(dp[n-2]!=-1)
    {
        b = dp[n-2];
    }
    else
    {
        b = fib(n-2);
    }

    return dp[n] = a + b;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=0;i<=n;i++)
    {
        dp[i] = -1;
    }

    cout<<fib(n)<<endl;

}

int main() {

    solve();

    return 0;
}
