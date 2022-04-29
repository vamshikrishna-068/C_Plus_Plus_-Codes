#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	int liss;
	node* left,*right;
	node(int val){
		data=val;
		left=NULL;
		right=NULL;
		liss=0;
	}
};
void inorder(node* root){
	if(root==NULL) return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int largest_independent_set(node* root){
	if(root==NULL) return 0;
	if(root->liss) return root->liss;
	if(root->left==NULL && root->right==NULL) return 1;
	int liss_excl=largest_independent_set(root->left)+largest_independent_set(root->right);
	// here liss_excl means exclude the current node so that we can take left and right
	int liss_incl=1;
	if(root->left){
		liss_incl+=largest_independent_set(root->left->left)+largest_independent_set(root->left->right);
	}
	if(root->right){
		liss_incl+=largest_independent_set(root->right->left)+largest_independent_set(root->right->right);

	}
	return root->liss=max(liss_incl,liss_excl);	
}
int main(){
	node* root=new node(20);
	root->left                = new node(8);
    root->left->left          = new node(4);
    root->left->right         = new node(12);
    root->left->right->left   = new node(10);
    root->left->right->right  = new node(14);
    root->right               = new node(22);
    root->right->right        = new node(25);
    // inorder(root);
    cout<<largest_independent_set(root);
	return 0;
}