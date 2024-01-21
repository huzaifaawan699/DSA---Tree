#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(int v) : key(v), left(NULL), right(NULL) {}
};
Node * insert(Node*root,int key){
if(root==NULL){
    return new Node(key);

}
if(key<root->key){

    root->left=insert(root->left,key);

}
else if(key>root->key){
    root->right=insert(root->right,key);

}
return root;

}
void inorder(Node*root){
if(root){
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);

}

}
int main(){
Node * root=NULL;
int keys[]={50,30,70,20,40,60,80};

for(int key:keys){
    root=insert(root,key);

}
cout<<"Inorder Traversal:"<<endl;
inorder(root);
}



