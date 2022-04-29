// Search in BST
// Delete in BST **** WRONG ANSWER ****
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
node* insertBST(node *root, int val){
	if(root==NULL){
		return new node(val);
	}
	if(val<root->data){
		root->left=insertBST(root->left,val);
	}
	else{
		root->right=insertBST(root->right,val);
	}
	return root;
}

// Search in BST

node* SearchinBST(node* root, int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		return root;
	}
	if(root->data>key){
		return SearchinBST(root->left,key);
	}
	return SearchinBST(root->right,key);
}
node* inorderSuccesor(node* root){
	node* cur=root;
	while(cur && cur->left!=NULL){
		cur=cur->left;
	}
	cout<<"Busi"<<cur->data<<endl;
	return cur;
}
void inorderPrint(node* root){
	if(root==NULL){
		return;
	}
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}
// Delete in BST

node* deleteinBST(node* root,int key){
	if(key<root->data){
		root->left=deleteinBST(root->left,key);
	}
	if(key>root->data){
		root->right=deleteinBST(root->right,key);
	}
	else{
		if(root->left==NULL){
			node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			node* temp=root->left;
			free(root);
			return temp;
		}
		node* temp=inorderSuccesor(root->right);
		root->data=temp->data;
		root->right=deleteinBST(root->right,temp->data);
	}
	return root;
}
int main(){
	node *root=NULL;
	root=insertBST(root,4);
	insertBST(root,2);
	insertBST(root,5);
	insertBST(root,1);
	insertBST(root,3);
	insertBST(root,6);
	// if(SearchinBST(root,50)==NULL){
	// 	cout<<"key doesn't exist"<<endl;
	// }
	// else{
	// 	cout<<"key exist"<<endl;
	// }
	inorderPrint(root);
	cout<<endl;
	root=deleteinBST(root,2);
	cout<<endl;
	inorderPrint(root);
	return 0;
}