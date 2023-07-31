include<bits/stdc++.h>
using namespace std;

vector<int>segTree(4*100005);

void buildMax(vector<int>& a,int ind,int low,int high){
	if(low==high){
		segTree[ind] = a[low];
		return;
	}
	int mid = (low+high)/2;
	buildMax(2*ind+1,low,mid);
	buildMax(2*ind+2,mid+1,high);
	segTree[ind] = max(segTree[2*ind+1],segTree[2*ind+2]);
}

int maxQuery(vector<int>&a,int ind,int low,int high,int l,int r){
	if(low>=l && high<=r){ // Range completely lies
		return seg[ind];
	}

	if(high<l || low>r){ // Range outside
		return INT_MIN;
	}
	int mid = (low+high)/2;
	int left = maxQuery(2*ind+1,low,mid,l,r);
	int right = maxQuery(2*ind+2,mid+1,high,l,r)

}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}

	buildMax(a,0,0,n-1)l
}