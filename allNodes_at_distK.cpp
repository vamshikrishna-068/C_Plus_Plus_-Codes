// printing nodes at k dist from a node to children and ancestors

#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
	node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};
// case - 1
void printsubtreeNodes(node* root,int k ){
	if(root==NULL || k<0){
		return ;
	}
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printsubtreeNodes(root->left,k-1);
	printsubtreeNodes(root->right,k-1);
}
// case-2

 int printnodes(node* root, node* target, int k){
 	if(root==NULL){
 		return -1;
 	}
 	if(root==target){
 		printsubtreeNodes(root,k);
 		return 0;
 	}
 	int dl=printnodes(root->left,target,k);
 		if(dl!=-1){
 			if(dl+1==k){
 				cout<<root->data<<" ";
 			}
 			else{
 				printsubtreeNodes(root->right,k-dl-2);
 			}
 			return dl+1;
 		}

 		 	int dr=printnodes(root->right,target,k);
 		if(dr!=-1){
 			if(dr+1==k){
 				cout<<root->data<<" ";
 			}
 			else{
 				printsubtreeNodes(root->left,k-dr-2);
 			}
 			return dr+1;
 		}
 		return -1;

 }
int main(){
	node* root=new node(4);
	root->left=new node(9);
	root->right=new node(5);
	root->left->left=new node(1);
	root->left->right= new node(3);
	root->right->right=new node(6);
	printnodes(root,root->left,1);
	return 0;
}