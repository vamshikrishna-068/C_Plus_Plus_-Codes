// check whether given tree is BST or not 
#include <bits/stdc++.h>
using namespace std;
struct  node
{
	int data;
	node* left;
	node* right;

	node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};

bool isBST(node* root, node* min, node* max){

	if(root==NULL){
		return true;
	}
	if(min!=NULL && min->data>=root->data){
		return false;
	}
	if(max!=NULL && max->data<= root->data){
		return false;
	}
	bool leftvalid=isBST(root->left,min,root);
	bool rvalid=isBST(root->right,root,max);
	return leftvalid && rvalid;
}
 int main(){
 	node* root=new node(2);
 	root->left=new node(1);
 	root->right=new node(3);
 	if(isBST(root,NULL,NULL)){
 		cout<<"IS valid BST"<<endl;
 	}
 	else{
 		cout<<"Not valid BST"<<endl;
 	}
 	return 0;
 }