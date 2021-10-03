#include <iostream>
using namespace  std;

class Node{

public:
	int data;
	Node *left,*right;

	Node(int val) {
		data=val;
		left=right=NULL;
		}
};

void InorderPrint(Node *root){
	if(root==NULL){
		return;
	}
	InorderPrint(root->left);
	cout<<root->data<<" ";
	InorderPrint(root->right);
}


void Preorder(Node *root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}


void Postorder(Node *root){
	if(root==NULL){
		return;
	}

	Preorder(root->left);
	Preorder(root->right);
	cout<<root->data<<" ";;
}


int main(){

	 b 
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->right->right=new Node(5);
	root->left->right=new Node(6);
	root->right->left=new Node(7);

	cout<<"This is Inorder Print"<<endl;
	InorderPrint(root);
	cout<<endl;
	cout<<"This is Preorder Print"<<endl;
	Preorder(root);
	cout<<endl;
	cout<<"This is Postorder Print"<<endl;
	Postorder(root);
	cout<<endl;

	return 0;
}