// creating a BAlanced BST using a given sorted array
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
node* sortedToBst( int arr[],int start, int end){
	if(start>end){
		return NULL;
	}
	int mid=(start+end)/2;
	node* root=new node(arr[mid]);
	root->left=sortedToBst(arr,start,mid-1);
	root->right=sortedToBst(arr,mid+1,end);

	return root;
}
void preorder(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main(){
	int arr[]={10,20,30,40,50};
	node* root=sortedToBst(arr,0,4);
	preorder(root);
	cout<<endl;

	return 0;
}