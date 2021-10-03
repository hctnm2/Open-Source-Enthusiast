#include <iostream>
#include<stack>

using namespace  std;


class Node{

public:
	int data;
	Node *left,*right;
	Node(int val){
		data=val;
		left=right=NULL;
	}
};


void zig_zag(Node *root){

	if(root==NULL){
		return;
	}
	stack<Node*>  currLevel;
	stack<Node*>  nextLeve;
	bool leftToRight=true;
	currLevel.push(root);
	while(!currLevel.empty()){
		Node *temp=currLevel.top();
		currLevel.pop();

		if(temp){
			cout<<temp->data<<" ";


			if(leftToRight){

				if(temp->left){
					nextLeve.push(temp->left);
				}

				if(temp->right){
					nextLeve.push(temp->right);
				}
			}else{

				if(temp->right){
					nextLeve.push(temp->right);
				}
				if(temp->left){
					nextLeve.push(temp->left);
				}

			}
		}

		if(currLevel.empty()){
			leftToRight=!leftToRight;
			swap(currLevel,nextLeve);
		}
	}
}

int main(){


	Node *root=new Node(12);
	root->left=new Node(9);
	root->right=new Node(15);
	root->left->left=new Node(5);
	root->left->right=new Node(10);
	zig_zag(root);
	cout<<endl;


	return 0;
}