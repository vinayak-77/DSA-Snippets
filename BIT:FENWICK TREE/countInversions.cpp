#include<bits/stdc++.h>

using namespace std;

int maxi = 1e5+10;
vector<long long> BIT(maxi+1,0);

void update(int i){
    for(;i<maxi;i+=(i&-i)){
        BIT[i]++;
    }
}

long long sum(int i){
    long long ans = 0;
    for(;i>0;i-=(i&-i)){
        ans+=BIT[i];
    }
    return ans;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    map<long long,int> mp;
    for(int i = 0;i<n;i++){
        mp[arr[i]];
    }

    int ind = 1;
    for(auto it = mp.begin();it!=mp.end();it++){
        mp[it->first] = ind;
        ind++;
    }

    for(int i = 0;i<n;i++){
        arr[i] = mp[arr[i]];
    }

    long long ans = 0;
    for(int i = 0;i<n;i++){
        ans+=(sum(maxi)-sum(arr[i]));
        update(arr[i]);
    }
    return ans;
}