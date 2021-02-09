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
	int n;
	cin >> n;
	map<string, int> cnt;
	for(int i = 0;i < n;i++){
		int x;
		cin >> x;
		for(int j =0;j<x;j++){
			string s;
			cin >> s;
			cnt[s]++;
		}
	}
	int ans = 0;
	for(auto it : cnt){
		if(it.s == n)ans++;
	}
	cout << ans << '\n';


}
