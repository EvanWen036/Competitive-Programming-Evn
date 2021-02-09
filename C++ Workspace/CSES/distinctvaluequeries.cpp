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
int arr[200005]; 
map<int, int> lastOcc;
int BIT[200005];
void update(int idx, int val){
	for(int i = idx; i <= 200000; i+= i&-i){
		BIT[i] += val;
	}
}
int query(int idx){
	//cout << idx << endl;
	int sum = 0;
	if(idx == 0)return 0;
	for(int i = idx; i >= 1; i -= i & -i){
		sum += BIT[i];
	}
	return sum;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n;i ++){
		cin >> arr[i];
		lastOcc[arr[i]] = -1;
	}
	vector<pair<pii, int>> queries;
	for(int i =0; i < q; i++){
		int a, b;
		cin >> a >> b;
		queries.pb({{b,a},i});
	}
	sort(queries.begin(), queries.end());
	int ind = 0;
	vector<int> ans(q);
	for(int i =1; i<= n;i++){
		//cout << "hi" << endl;
		if(lastOcc[arr[i]] != -1){
			update(lastOcc[arr[i]], -1);
		}
		lastOcc[arr[i]] = i;
		update(i, 1);
		while(ind != queries.size() && queries[ind].f.f == i){
			ans[queries[ind].s] = query(queries[ind].f.f) - query(queries[ind].f.s-1);
			ind++;
		}
	}
	for(int u : ans){
		cout << u << '\n';
	}
}
