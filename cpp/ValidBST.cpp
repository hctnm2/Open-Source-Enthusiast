#include <iostream>
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

bool isBSTvalid(Node *root,Node *min=NULL,Node* max=NULL){

	if(root==NULL){
		return true;
	}

	if(min !=NULL && root->data<=min->data){
		return false;
	}

	if(max!=NULL && root->data>=max->data){
		return false;
	}

	bool leftvalid=isBSTvalid(root->left,min,root);
	bool rightvalid=isBSTvalid(root->right,root,max);

	return leftvalid and rightvalid;

}

int main(){

	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	// root->left=new Node(10);

	if(isBSTvalid(root,NULL,NULL)){
		cout<<"is valid BST"<<endl;
	}else{
		cout<<"is not valid"<<endl;
	}

	return 0;
}