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
	freopen("input.in", "r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	/**
	set<int> sums; 
	for(int i = 0; i < 200; i++){
		int x;
		cin >> x;
		sums.insert(x);
		if(sums.count(2020-x)){
			cout << (2020-x)*x << '\n';
			return 0;
		}
	}
	**/
	int N = 6;
	map<int,pii> sums;
	for(int i = 0; i < 200; i++){
		int x;
		cin >> x;
		v.pb(x);
	}
	for(int i = 0; i < 200; i++){
		for(int j = i + 1; j<200; j++){
			sums[v[i] + v[j]] = {i,j};
		}
	}
	for(int i = 0; i < 200; i++){
		if(sums.count(2020-v[i])){
			cout << v[i] * v[sums[2020-v[i]].f] * v[sums[2020-v[i]].s] << '\n';
			return 0;
		}
	}



}
