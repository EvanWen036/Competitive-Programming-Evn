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
vector<pii> jobs;
int N, D;
bool ok(int x){
	vector<int> last(x);
	for(int i = 0; i < jobs.size(); i++){
		int machine = i%x;
		last[machine] = max(last[machine]+1, jobs[i].f);
		if(last[machine] - jobs[i].f > D)return false;
		if(last[machine] > N)return false;
	}
	return true;
}
void print(int x){
	vector<int> operations[N+1];
	vector<int> last(x);
	for(int i = 0; i < jobs.size(); i++){
		int machine = i%x;
		last[machine] = max(last[machine]+1, jobs[i].f);
		operations[last[machine]].pb(jobs[i].s);
	}
	for(int i = 1; i <= N;i ++){
		for(int u : operations[i]){
			cout << u+1 << " ";
		}
		cout << 0 << '\n';
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M;
	cin >> N >> D >> M;
	for(int i = 0; i < M;i ++){
		int x;
		cin >> x;
		jobs.pb({x,i});
	}
	sort(jobs.begin(), jobs.end());
	int lo = 1;
	int hi = 1000000;
	while(lo < hi){
		int mid = (lo+hi)/2;
		if(ok(mid)){
			//answer could be lower
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	cout << lo << '\n';
	print(lo);
}
