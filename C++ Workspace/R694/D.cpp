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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int,int> count[n];
	int allEven = 0;
	map<int,boolean> even;
	for(int i = 0; i < n;i++){
		cin >> a[i];
	}
	for(int i = 0; i < n;i ++){
		for(int p = 2; p * p <= a[i]; p++){
			while(a[i]%p == 0){
				count[i][p]++;
				a[i]/=p;
			}
		}
		if(a[i] != 1){
			count[i][a[i]]++;
		}
		bool all = true;
		for(auto it : count[i]){
			if(it.s % 2 != 0){
				all = false;
			}
			even[it.f] = true;	
		}
		if(all)allEven++;
	}
	//d doesn't change?
	int q;
	cin >> q;
	for(int i =0;i < q;i ++){
		ll w;
		cin >> w;

	}

}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}


}
