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


void zigzagTraversal(Node *root){

	if(root==NULL){
		return;
	}

	stack<Node*> currLevel;
	stack<Node*> nextLevel;

	bool lefttoright=true;
	
	currLevel.push(root);

	while(!currLevel.empty()){

		Node* temp=currLevel.top();
		currLevel.pop();

		if(temp){
			cout<<temp->data<<" ";
		
		if(lefttoright){

			if(temp->left){
				nextLevel.push(temp->left);

			}
			if(temp->right){
				nextLevel.push(temp->right);
			}
		}
		else{
			if(temp->right){
				nextLevel.push(temp->right);
			}
			if(temp->left){
				nextLevel.push(temp->left);
			}	
		}
	  }
	  if(currLevel.empty()){
	  	lefttoright=!lefttoright;
	  	swap(currLevel,nextLevel);
	  }
   }
}



int main(){

	Node *root=new Node(12);
	root->left=new Node(9);
	root->right=new Node(15);
	root->left->left=new Node(5);
	root->left->right=new Node(10);
	zigzagTraversal(root);
	cout<<endl;

	return 0;
}
