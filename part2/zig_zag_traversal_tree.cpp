// zig zag traversal of a tree by using two stacks
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
void zigzag(node* root){
	if(root==NULL){
		return ;
	}
	stack<node*> curlevel;
	stack<node*> nextlevel;
	bool lefttoright=true;
	curlevel.push(root);
	while(!curlevel.empty()){
		node* temp=curlevel.top();
		curlevel.pop();
		if(temp){
			cout<<temp->data<<" ";
			if(lefttoright){
				if(temp->left)
					nextlevel.push(temp->left);
				if(temp->right)
					nextlevel.push(temp->right);
			}
			else{
				if(temp->right)
					nextlevel.push(temp->right);
				if(temp->left)
					nextlevel.push(temp->left);
			}
		}
		if(curlevel.empty()){
			lefttoright=!lefttoright;
			swap(curlevel,nextlevel);
		}
	}
}
int main(){
	node* root=new node(12);
 	root->left=new node(9);
 	root->right=new node(15);
 	root->left->left=new node(5);
 	root->left->right=new node(10);
 	zigzag(root);
	return 0;
}