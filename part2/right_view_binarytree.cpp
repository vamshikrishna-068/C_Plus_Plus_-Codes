// right most element in every level-> is called right right_view
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
void right_view(node* root){
	if(root==NULL){
		return;
	}
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		int n=q.size();
		for(int i=0;i<n;i++){
			node* cur=q.front();
			q.pop();
			if(i==n-1){
				cout<<cur->data<<" ";
			}
			if(cur->left){
				q.push(cur->left);
			}
			if(cur->right){
				q.push(cur->right);
			}
		}
	}
}
int main(){
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right= new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	right_view(root);
	return 0;
}