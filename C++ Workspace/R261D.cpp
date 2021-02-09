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
int cnt[1000005];
int BIT[1000005];
void update(int idx, int val){
	for(int i = idx ;i <= 1000000;i += i&-i){
		BIT[i] += val;
	}
}
int query(int idx){
	int sum = 0;
	for(int i = idx; i >= 1; i -= i & -i){
		sum += BIT[i];
	}
	return sum;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N;i ++){
		cin >> A[i];
	}	
	unordered_map<int, int> mp;
	mp.reserve(512);
	for(int i = 0 ; i < N; i++){
		mp[A[i]]++;
		cnt[i] = mp[A[i]];
		update(cnt[i], 1);
	}
	unordered_map<int,int> mp2;
	mp2.reserve(512);
	ll ans = 0;
	for(int i= N-1; i >= 0; i--){
		update(cnt[i], -1);
		mp2[A[i]]++;
		int amt = mp2[A[i]];
		ans += query(1000000) - query(amt);
		//cout << query(1000000) << " " << query(amt) << "\n";
	}
	cout << ans << '\n';



}
