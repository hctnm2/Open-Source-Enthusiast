#include <bits/stdc++.h>
using namespace  std;
int int_size=32;

class node{
public:
	node *next[2];
	node(){
		for (int i = 0; i < 2; ++i)
		{
		  next[i]=NULL;
		}
	} 
};
node *trie;
void insert(int num){
	node *it=trie;
	for (int i = int_size -1; i >=0 ; i--)
	{
		int curr_bit=(num>>i) & 1;
		if(!it->next[curr_bit])
			it->next[curr_bit]=new node();
		it=it->next[curr_bit];
	}
}

int query(int num){
	node *it=trie;
	int ans=0;
	for (int i = int_size-1; i >=0 ; i--)
	{
		int curr_bit=(num>>i) & 1;
		int opposite=curr_bit xor 1;
		if(it->next[opposite]){
			it=it->next[opposite];
			ans |= 1<<i;
		}else{
			it=it->next[opposite xor 1];
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	trie=new node();
	insert(0);

	vector<int> rmax(n+1,0);
	int R=0;
	for (int i = n-1; i >=0; i--)
	{
		R=R xor a[i];
		if(i!=n-1){
			rmax[i]=max(rmax[i+1],query(R));
			insert(R);
		}else{
			rmax[i]=query(R);
			insert(R);
		}
	}

	free(trie);

	trie= new node();
	insert(0);
	int ans=0;
	int L=0;
	for (int i = 0; i < n; ++i)
	{
		L=L  xor a[i];
		ans =max(ans,rmax[i+1]+query(L));
		insert(L);
	}

	cout<<ans<<endl;
	return 0;
}