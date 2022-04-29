#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second   
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
#define pb push_back
const int N=1e5+2,MOD=1e9+7;
const int INF=1e9+2;
template <typename T> istream& operator>>(istream& in, vector<T>& a) {  for (T& x : a) in >> x;     return in; }
bool cmp(vector<int> a, vector<int> b){
	return a[1]<b[1];
}
int find_ans(vector<vector<int>> &a, int n){
	sort(a.begin(),a.end(),cmp);
	int ans=0;
	vector<int> dp(n+1,0);
	// dp[0]=a[0][3];
	for(int i=0;i<n;i++){
		dp[i]=a[i][2];
	}
	ans=dp[0];
	cout<<ans<<" ";
	for(int i=1;i<n;i++){
		int low=0;
		int high=i-1;
		int last=-1;
		while(low<=high){
			int mid=(low+high)>>1;
			if(a[mid][1]<=a[i][0]){
				last=mid;
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		}
		if(last!=-1){
			dp[i]=max(dp[i],dp[last]+a[i][2]);
		}
		cout<<dp[i]<<" ";
		ans=max(ans,dp[i]);
	}
	cout<<endl;
	return ans;
}
int dearrangements(int n){
	vector<int> dp(n+1,0);
	dp[1]=0;
	dp[2]=1;
	for(int i=3;i<=n;i++){
		dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
	}
	return dp[n];
}
bool will_A_win(int n, int x, int y){
	bool dp[n+1];
	dp[0]=false;
	dp[1]=true;
for(int i=2;i<=n;i++)
{
	if(i-1>=0 && dp[i-1]==false){
		dp[i]=true;
	}
	else if(i-x>=0 && dp[i-x]==false){
		dp[i]=true;
	}
	else if(i-y>=0 && dp[i-y]==false){
		dp[i]=true;
	}
	else{
		dp[i]=false;
	}
}
return dp[n];
}
int find_max_profit_atmost_2(vi a, int n){
	vi profit(n,0);
	// profit[n-1]=/
	int max_price=a[n-1];
	for(int i=n-2;i>=0;i--){
		max_price=max(max_price,a[i]);
		profit[i]=max(max_price-a[i],profit[i+1]);
	}
	int min_price=a[0];
	vi profit1(n,0);
	for(int i=1;i<n;i++){
		min_price=min(min_price,a[i]);
		profit1[i]=max(profit1[i-1],a[i]-min_price);
	}
	int ans=max(profit1[n-1],profit[0]);
	for(int i=0;i<n-1;i++){
		ans=max(ans,profit1[i]+profit[i+1]);
	}
	return ans;
}
int find_optimal_bst(vi a, vi f, int n){
	vector<vector<int>> dp(n+1,vector<int>(n+1));
	for(int gap=0;gap<n;gap++){
		for(int i=0,j=gap;j<n;i++,j++){
		if(gap==0){
			dp[i][j]=f[i];
		}
		else if(gap==1){
			dp[i][j]=min(f[i]+2*f[j],2*f[i]+f[j]);
		}
		else{
			int fs=0;
			for(int k=i;k<=j;k++) fs+=f[k];
				int mini=INT_MAX;
			for(int k=i;k<=j;k++){
				int left=k==i?0:dp[i][k-1];
				int right=k==j?0:dp[k+1][j];
				mini=min(mini,left+right+fs);
			}
			dp[i][j]=mini;
		}
	}
	}
	return dp[0][n-1];
}
pair<int,int> sub_sum(vector<int> &a, int n){
	unordered_map<int,int> mp;
	int sum=0;
	int max_len=0;
	int ending_index=-1;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(a[i]==0) max_len=max(max_len,1); 
		if(sum==0){
			max_len=max(max_len,i+1);
			ending_index=i;
		}
		if(mp.find(sum)!=mp.end()){
			if(max_len<i-mp[sum]){
				max_len=i-mp[sum];
				ending_index=i;
			}

		}
		else{
			mp[sum]=i;
		}
	}
	pair<int,int> p={max_len,ending_index};
	return p;
}
int find_max_rectangle(vector<vector<int>> &m, int r,int c){
	// main aim is to convert into 1D array
	int starting_row=0;
	int ending_row=0;
	int starting_col=0;
	int ending_col=0;
	int final_length=INT_MIN;
	for(int i=0;i<r;i++){
		vector<int> curr_array(c,0);
		for(int j=i;j<r;j++){
			for(int col=0;col<c;col++){
				curr_array[col]+=m[j][col];
			}
			pair<int,int> p=sub_sum(curr_array,c);
			if(final_length<p.first){
				final_length=p.first;
				starting_row=i;
				ending_row=j;
				starting_col=p.second+1-p.first;
				ending_col=p.second;
			}
		}
	}
	return final_length*(ending_row-starting_row+1);
}
pair<int,int> find_sum_zero(vector<int> &a, int n){
	unordered_map<int,int> mp;
	int max_len=0;
	int ending_index=-1;
	int sum=0;
	for(int i=0;i<n;i++){
		// cout<<a[i]<<" ";
		sum+=a[i];
		if(a[i]==0){
			max_len=max(max_len,1);
			ending_index=i;
		}
		if(sum==0){
			max_len=i+1;
			ending_index=i;
		}
		if(mp.find(sum)!=mp.end()){
			if(max_len<i-mp[sum]){
				max_len=i-mp[sum];
				ending_index=i;
			}
		}
		else{
			mp[sum]=i;
		}
	}
	pair<int,int> p={max_len,ending_index};
	return p;
}
int find_max_rectangle_with_equal_ones_zeroes(vector<vector<int>> &m, int r, int c){
	int ans=INT_MIN;
	int starting_row=-1;
	int ending_row=-1;
	int starting_col=-1;
	int ending_col=-1;
	int final_length=INT_MIN;
	int area=0;
	for(int i=0;i<r;i++){
		vector<int> curr_array(c,0);
		for(int j=i;j<r;j++){
			for(int col=0;col<c;col++){
				curr_array[col]+=m[j][col]?1:-1;
			}
			pair<int,int> p=find_sum_zero(curr_array,c);

			if(p.first*(j-i+1)>area){
				area=p.first*(j-i+1);
			if(final_length<=p.first){ // Actually need to compare with area 
				final_length=p.first; // rather than length
				starting_row=i;
				ending_row=j;
				starting_col=p.second+1-p.first;
				ending_col=p.second;
			}
		}
		}

	}
	return area;
}
int main(){
	// int n;cin>>n;
	// vector<vector<int>> a(n);
	// for(int i=0;i<n;i++){
	// 	int u,v,w;cin>>u>>v>>w;
	// 	a[i]={u,v,w};

	// }
	// cout<<find_ans(a,n);
	// cout<<dearrangements(n);
	// int x,y;cin>>x>>y;
	// if(will_A_win(n,x,y)) cout<<"Yooo A won";
	// else cout<<"B won :(";
	// vi a(n);cin>>a;
	// cout<<find_max_profit_atmost_2(a,n);
	// int n;cin>>n;
	// vi a(n);cin>>a;
	// vi f(n);cin>>f;	
	// cout<<find_optimal_bst(a,f,n);
	// LARGEST SUB MATRIX RECTANGLE WITH  ZERO SUM
	int r,c;cin>>r>>c;
	vector<vector<int>> mati(r,vector<int>(c));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>mati[i][j];
		}
	}
	// cout<<find_max_rectangle(mat,r,c);
	cout<<find_max_rectangle_with_equal_ones_zeroes(mati,r,c);

	 return 0;
}
/*
int longestSubsequence(int n, vector<int> &a){
	vi seq;
	seq.push_back(a[0]);
	for(int i=1;i<n;i++){
		if(seq.back()<a[i]) seq.push_back(a[i]);
		else{
			int idx=lower_bound(seq.begin(),seq.end(),a[i])-seq.begin();
			seq[idx]=a[i];
		}
	}
	return seq.size();
}
int maxSumIS(int arr[], int n)  
{  
   int dp[n+1];
   for(int i=0;i<n;i++) dp[i+1]=arr[i];
   for(int i=1;i<=n;i++){
       for(int j=1;j<i;j++){
           if(arr[j-1]<arr[i-1]) dp[i]=max(dp[i],dp[j]+arr[i-1]);

           cout<<dp[i]<<" ";
       }
       // cout<<dp[i]<<endl;
       cout<<"\n";
   }
   int ans=1;
   for(int i=0;i<n;i++){
   	// cout<<dp[i+1]<<endl;
       ans=max(ans,dp[i+1]);
   }
   return ans;
}  
vector<int> ans;
int dp[1000][10000];
int find_ans(vi a, int n, int k, int p){
	if(n==0){
	 if(p<k) return 1;
	 return 0;
	}

	if(dp[n][p]!=-1) return dp[n][p];
	if(p*a[n-1]<k){
		dp[n][p]=find_ans(a,n-1,k,p*a[n-1])+find_ans(a,n-1,k,p);
	}
	else{
		dp[n][p]=find_ans(a,n-1,k,p);
	}
	return dp[n][p];
}
*/