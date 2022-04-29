// max sum path from one node to another
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
int maxpathSumUtil(node *root, int &ans){
	if(root==NULL){
		return 0;
	}
	int left=maxpathSumUtil(root->left,ans);
	int right=maxpathSumUtil(root->right,ans);
	int nodemax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
	ans=max(ans,nodemax);
	int singlepath=max(root->data,max(root->data+left,root->data+right));
	return singlepath;
}
int maxpathsum(node* root){
	int ans=INT_MIN;
	maxpathSumUtil(root, ans);
	return ans;
}
int main(){
	//		1
	//	2    	3
	//4       6   5
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	// root->left->right= new node(5);
	root->right->left=new node(6);
	root->right->right=new node(5);
	cout<<maxpathsum(root)<<endl;
	return 0;
}