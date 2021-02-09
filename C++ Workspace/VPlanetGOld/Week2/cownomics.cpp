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
int N, M;
string genes[1005];
bool ok(int x){
	//our window is of size x
	for(int i = x-1; i < M;i ++){
		set<string> spotty;
		for(int j = 0; j < N;j ++){
			spotty.insert(genes[j].substr(i-x+1, x));
		}
		bool wrks = true;
		for(int j =0;j < N;j ++){
			string curr = genes[j+N].substr(i-x+1,x);
			if(spotty.count(curr))wrks = false;
		}
		if(wrks)return true;
	}
	return false;
}
int main(){
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < 2 * N;i ++){
		cin >> genes[i];
	}
	int lo = 1;
	int hi = M;
	while(lo < hi){
		int mid = (lo+hi)/2;
		if(ok(mid)){
			//we can try lower
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	cout << lo << '\n';

}
