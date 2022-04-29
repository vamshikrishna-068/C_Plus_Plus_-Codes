// Catalan numbers application

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
int catalan(int n){
	if(n<=1){
		return 1;
	}
	int res=0;
	for(int i=0;i<n;i++){
		res+=catalan(i)*catalan(n-i-1);
	}
	return res;
}
vector<node*> constructtress(int start, int end){
	vector<node*> trees;
	if(start>end){
		trees.push_back(NULL);
		return trees;
	}
	for(int i=start;i<=end;i++){
			vector<node*> leftsubtrees=constructtress(start,i-1);
			vector<node*> rightsubtrees=constructtress(i+1,end);
			for(int j=0;j<leftsubtrees.size();j++){
				node* left=leftsubtrees[j];
				for(int k=0;k<rightsubtrees.size();k++){
					node* right=rightsubtrees[k];
					node* n=new node(i);
					n->left=left;
					n->right=right;
					trees.push_back(n);
				}
			}
	}
	return trees;
}
void preorder(node* root){
	// cout<<"BUSI"<<endl;
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main(){
	// for(int i=0;i<10;i++){
	// 	cout<<catalan(i)<<" ";
	// }
	// cout<<endl;
	vector<node*> totaltrees=constructtress(1,3);
	cout<<totaltrees.size()<<endl;
	for(int i=0;i<totaltrees.size();i++){
		cout<<i+1<<": ";
		preorder(totaltrees[i]);
		cout<<endl;
	}
	return 0;
}