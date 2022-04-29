
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
void calpointers(node* root, node** first, node** mid, node** last, node** prev){
	if(root==NULL){
		return;
	}
	calpointers(root->left,first,mid,last,prev);
	if(*prev && root->data <(*prev)->data){
		if(!*first){
			*first=*prev;
			*mid=root;
		}
		else{
			*last=root;
		}
	}
	*prev=root;
	calpointers(root->right,first,mid,last,prev);
}
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void restoreBST(node* root){
	node* first,*mid,*last,*prev;
	first=NULL;
	mid=NULL;
	last=NULL;
	prev=NULL;
	calpointers(root,&first,&mid,&last,&prev);
	if(first&&last){
		swap(&(first->data), &(last->data));
	}
	else if(mid&&first){
		swap(&(mid->data), &(first->data));
	}
}
void inorder( node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
/*	initial tree
			6
		  /   \
		9		3
	  /  \        \
	1	  4        13

*/
	node* root=new node(6);
	root->left=new node(9);
	root->right=new node(3);
	root->left->left=new node(1);
	root->left->right=new node(4);
	root->right->right=new node(13);
	inorder(root);
	cout<<endl;
	restoreBST(root);
	inorder(root);
	
	return 0;
}