#include <bits/stdc++.h>
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
int N;
int arr[200005];
int lastOcc[200005];
vector<pii> queries;
ll BIT[200005];
void update(int idx, int val){
	for(int i = idx; i <= 200000; i+= i&-i){
		BIT[i] += val;
	}
}
ll query(int idx){
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
	//p1
	cin >> N;
	for(int i = 1; i <= N;i ++)cin >> arr[i];
	//figure out for each value that could be starting point where it's ending point must be
	lastOcc[arr[N]] = N;
	for(int i = N-1; i >= 1; i--){
		int pre = (lastOcc[arr[i]] == 0 ? N:lastOcc[arr[i]]-1);
		lastOcc[arr[i]] = i;
		queries.pb({pre, i+1});
		//cout << i+1 << " " << pre << '\n';
	}
	//do distinct value queries to figure out ans
	sort(queries.begin(), queries.end());
	ll ans = 0;
	int ind = 0;
	memset(lastOcc, -1, sizeof(lastOcc));
	for(int i = 1; i <= N;i ++){
		if(lastOcc[arr[i]] != -1){
			update(lastOcc[arr[i]], -1);
		}
		lastOcc[arr[i]] = i;
		update(i,1);
		while(ind != queries.size() && queries[ind].f == i){
			ans += query(queries[ind].f) - query(queries[ind].s-1);
			ind++;
		}
	}
	cout << ans << '\n';
}
