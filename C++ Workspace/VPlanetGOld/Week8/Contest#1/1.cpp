#include <bits/stdc++.h>
#include "cycle.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
int pos = 2;
int amt =6;
bool jump(int steps){
	//cout << steps << " ";
	pos += steps;
	pos %= amt;	
	//cout << pos << '\n';
	if(pos == 0)return true;
	if(pos + amt/2 >= amt)return true;
	return false;
}**/
int pre = 0;
void escape(int n){
	int lo = 0;
	int hi = n-1;
	while(lo < hi){
		int mid = (lo+hi+1)/2;
		if(jump((mid+pre)%n)){
			lo = mid;
			pre = n-mid;
			//jump(n-mid);
			
		}
		else{
			hi = mid-1;
			pre = n-mid;
			//jump(n-mid);
			
		}
	}
	jump((pre+lo)%n);
}
/**
int main(){
	escape(6);
}**/
