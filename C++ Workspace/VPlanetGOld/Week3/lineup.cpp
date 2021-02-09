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
int N, K;
vector<int> b;
int main(){
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for(int i = 0; i < N;i ++){
		int x;
		cin >> x;
		b.pb(x);
	}	
	int lp = 0;
	multiset<int> s;
	int curr = 0;
	int ans = 0;
	for(int rp = 0; rp < N; rp++){
		s.insert(b[rp]);
		if(s.count(b[rp]) == 1)curr++;
		while(curr > K+1){
			s.erase(s.find(b[lp]));
			if(s.count(b[lp]) == 0)curr--;
			lp++;
		}
		ans = max(ans, (int)s.count(b[rp]));
	}
	cout << ans << '\n';

}
