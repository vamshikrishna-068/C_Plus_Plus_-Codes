// Creating a BST using given Preorder;
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
node* constructBST(int preorder[],int* preorderidx,int key,int min,int max, int n){
	if(*preorderidx>=n){
		return NULL;
	}
	node* root=NULL;
	if(key>min && key<max){
		root=new node(key);
		*preorderidx=*preorderidx+1;
	
	if(*preorderidx<n){
		root->left=constructBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
	}
	if(*preorderidx<n){
		root->right=constructBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
	}}
	return root;	
}
void preorderPrint(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorderPrint(root->left);
	preorderPrint(root->right);
}

int main(){
	int preorder[]={10,2,1,13,11};
	int n=5;
	int preorderidx=0;
	node* root=constructBST(preorder,&preorderidx,preorder[0],INT_MIN,INT_MAX,n);
	preorderPrint(root);
	return 0;	
}