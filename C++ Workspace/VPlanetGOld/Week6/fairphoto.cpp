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
vector<pair<int, string>> cows;
int ans = 0;
bool ok(int x){
	assert(x <= N);
	bool wrks = false;
	int w = 0;
	int s = 0;
	for(int i = 0; i < x; i++){
		if(cows[i].s == "W")w++;
		else{s++;}
	}
	if(w >= s){
		ans = max(ans,cows[x-1].f - cows[0].f);
		wrks=true;
	}
	for(int i = 1; i + x < N; i++){
		//remove i-1
		if(cows[i-1].s == "W")w--;
		else{s--;}
		//add i+x
		if(cows[i+x].s == "W")w++;
		else{s++;}
		if(w >= s){
			ans = max(ans,cows[i+x].f - cows[i].f);
			wrks = true;
		}
	}
	return wrks;
}
int main(){
	freopen("fairphoto.in", "r", stdin);
	freopen("fairphoto.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i = 0; i < N;i ++){
		int x; string c;
		cin >> x >> c;
		cows.pb({x,c});
	}
	sort(cows.begin(), cows.end());
	int lo = 0;
	int hi = N/2;
	while(lo < hi){
		int mid = (lo+hi+1)/2;
		//assert(mid % 2 == 0);
		if(ok(2*mid)){
			lo = mid;
		}
		else{
			hi = mid-1;
		}
	}
	ok(N);
	cout << ans << '\n';
}
