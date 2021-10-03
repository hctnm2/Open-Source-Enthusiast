#include<iostream>
#include<string>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
node* build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}
bool identical(node* root1, node* root2){
    if(root1==NULL && root2 == NULL){
        return true;
    }
    if(root1!=NULL && root2!=NULL){
        if(root1->data==root2->data && identical(root1->left,root1->right) && identical(root2->left,root2->right))
            return true;
        else    
            return false;   
    }
    return false;
}
int main() {
    string s1,s2;
    cin >> s1;
    cin.get();
    cin >> s2;
    node* root1 = NULL;
    root1 = build(s1);
    node* root2 = NULL;
    root2 = build(s2);
    if(identical(root1,root2)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}