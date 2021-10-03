#include <bits/stdc++.h>
using namespace  std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define  rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

class Node{
public:
	int data;
	Node *left,*right;
	Node(int val){
		data=val;
		left=right=NULL;
	}
};


void getverticalOrder(Node *root,int hids,map<int,vi> &m){

	if(root==NULL){
		return;
	}

	m[hids].push_back(root->data);
	getverticalOrder(root->left,hids-1,m);
	getverticalOrder(root->right,hids+1,m);

}

int main(){

	Node *root=new Node(10);
	root->left=new Node(7);
	root->right=new Node(4);
	root->left->left=new Node(3);
	root->left->right=new Node(11);
	root->right->left=new Node(14);
	root->right->right =new Node(6);
	std::map<int, vector<int>> m;
	int hids=0;
	getverticalOrder(root,hids,m);
	map<int,vi> :: iterator it;
	for(it=m.begin();it!=m.end();it++){

		for (int i = 0; i < (it->ss).size(); ++i)
		{
				cout<<(it->ss)[i]<<" ";
		}

		cout<<endl;
	}
	return 0;
}