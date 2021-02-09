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
int N, M;
vector<int> desks;
bool ok(int x){
	int placed = 0;
	int prev = -1;
	for(int i = 0; i < N; i++){
		if(prev == -1 || desks[i] - prev >= x){
			placed++;
			prev = desks[i];
		}
	}
	return placed >= M;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0;i < N;i ++){
		int x;
		cin >> x;
		desks.pb(x);
	}
	sort(desks.begin(), desks.end());
	int lo = 0;
	int hi = 1e9;
	while(lo < hi){
		int mi = (lo+hi+1)/2;
		if(ok(mi)){
			lo = mi;
		}
		else{
			hi = mi-1;
		}
	}
	cout << lo << '\n';
}
