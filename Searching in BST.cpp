#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
    Node(int v) : key(v), right(NULL), left(NULL) {}
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
Node *search(Node *root,int key){
if(root==NULL || root->key==key){
    return root;

}
if(key<root->key){
    return search(root->left,key);

}
return search(root->right,key);

}
int main(){
Node * root=NULL;
int keys[]={50, 30, 70, 20, 40, 60, 80};

for(int key:keys){
    root=insert(root,key);

}

int keytosearch=40;
Node *result=search(root,keytosearch);
if(result!=NULL){
    cout<<"Key"<<" "<<keytosearch<<" Found in BST:"<<endl;

}
else{
    cout<<"Key"<<" "<<keytosearch<<"Not Found in BST:"<<endl;

}

}
