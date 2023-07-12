
// Solve two type of quereies
// Type1 : i x : replace ith index by value x
// Type 2 : l r : find sum from l to r


#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
vector<int> BIT(N);

void update(int i,int x){
	for(;i<N;i+=(i&-i)){
		BIT[i]+=x;
	}
}

int sum(int i){
	int ans = 0;
	for(;i>0;i-=(i&-i)){
		ans+=BIT[i];
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]);
	}


	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int i,x;
			cin>>i>>x;
			update(i,x-a[i]);
		}
		else{
			int l,r;
			cin>>l>>r;
			int ans = sum(r)-sum(l-1);
			cout<<ans<<endl;
		}
	}


}