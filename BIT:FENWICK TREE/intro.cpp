#include<bits/stdc++.h>

using namespace std;

// To find the rightmost set bit of a number x -> (x&-x)
// To remove the righmost set bit of x, x = x-(x&-x)
// BIT Tree index stores a partial range sum
// BIT array index 'i' stores the range sum of array from index j+1 to i, where j = i-(i&-i) i.e number obtained after removing the righmost set bit of i
// BIT 13, 13 = 1101, i = 13, j = 1100 = 12 => BIT 13 stores the sum from 13 to 13
// BIT 12, 12 = 1100, i = 12, j = 1000 = 8 => BIT 12 stores the sum from 9 to 12


// CALC RANGE SUM FROM 1 to i :-
// Keep adding BIT[i], to sum and then remove the right most set bit from i till i becomes 1.
// BIT[i] -> sum from j to i, so by adding sum from j+1 to i, we need sum from some num to j, so we use BIT[j] and j = i-(i&-i)
// for(;i>0;i-=(i&-i)){
//	ans+=bit[i]
//}
// Complexity O(logn) -> coz we are removing one bit after each iteration and at max n bits

// sum[l:r] = sum[1:r]-sum[1:l-1]




// To update an index 'k' in array to x,we have to update all partial sums in BIT array that have 'k' in the range
// To find such ranges, keep adding the rightmost set bit to the number starting from k till k is in the range and last range is less than n
// 
// for(;i<=N;i+=(i&(-i))){
// 	bit[i]+=(x-arr[k]) // updating arr[k] to x, so sum that includes k,increases by x-arr[k]
// }

// To increase an index 'k' in array by x,we have to update all partial sums in BIT array that have 'k' in the range
// To find such ranges, keep adding the rightmost set bit to the number starting from k till k is in the range and last range is less than n
// 
// for(;i<=N;i+=(i&(-i))){
// 	bit[i]+=x // updating arr[k] to x, so sum that includes k,increases by x-arr[k]
// }



const int N = 1e5+10;
vector<int> BIT(N);

int sum(int i){ // sum from 1 to i
	int ans = 0;
	for(;i>0;i-=(i&-i)){
		ans+=BIT[I];
	}
	return ans;
}

void update(int i,int x){
	for(;i<N;i+=(i&-i)){
		BIT[I]+=x;
	}
}


int main(){

}