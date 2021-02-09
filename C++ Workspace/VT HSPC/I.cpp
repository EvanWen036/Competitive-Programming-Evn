#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int H, W;
	cin >> H >> W;
	vector<ll> he(W+1);
	ll sum = 0;
	for(int i = 0;i < W;i ++){
		cin >> he[i];
		sum += he[i];
	}
	int lo = 0;
	int hi = H;
	ll bestBal = (1LL * H * W) - sum;
	ll height = 0;
	ll amt = 0;
	while(lo <= hi){
		ll water = 0;
		ll mid = (lo+hi+1)/2;
		//cout << lo << " " << hi << " " << mid << '\n';
		sum = 0;
		ll air = 0;
		for(int i = 0;i  < W;i ++){
			water += max(mid - he[i], 0LL); 
			air += H - max(mid, he[i]);
		}
		//cout << mid << " " << water << " " << air << '\n';
		if(abs(air - water) < bestBal){
			bestBal = abs(air-water);
			amt = water;
			height = mid;
		}
		if(abs(air-water) == bestBal && mid < height){
			bestBal = abs(air-water);
			amt = water;
			height = mid;
		}
		if(air > water){
			//try a higher
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}
	cout << height << " " << amt << '\n';


}
