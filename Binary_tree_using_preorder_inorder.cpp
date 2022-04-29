// creating binary tree using preorder and inorder
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	 Node(int val){
	 	data=val;
	 	left=NULL;
	 	right=NULL;
	 }
};
int search(int inorder[], int start, int end, int curr){
	for(int i=0;i<=end;i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;
}
Node* buildtree(int preorder[],int inorder[],int start, int end){
	if(start>end){
		return NULL;
	}
	static int idx=0;
	int curr=preorder[idx];
	Node* node=new Node(curr);
	idx++;
	if(start==end){
		return node;
	}
	int pos=search(inorder,start,end,curr);
	node->left=buildtree(preorder,inorder,start,pos-1);
	node->right=buildtree(preorder,inorder,pos+1,end);

	return node;
}	
void inorder_print(struct Node* root){
	if(root==NULL){
		return;
	}
	inorder_print(root->left);
	cout<<root->data<<" ";
	inorder_print(root->right);
}
int main(){
	int preorder[]={1,2,4,3,5};
	int inorder[]={4,2,1,5,3};
	Node* root= buildtree(preorder,inorder,0,4);
	inorder_print(root);
	return 0;
}