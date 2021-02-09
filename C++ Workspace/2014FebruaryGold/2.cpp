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
int dp[(1 << 20) + 5];
vector<pii> bonuses[25];
int mat[25][25];
int main(){	
	freopen("dec.in", "r", stdin);
	freopen("dec.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, B;
	cin >> N >> B;
	for(int i = 0; i < B;i ++){
		int k, p, a;
		cin >> k >> p >> a;
		bonuses[k].pb({p,a});
	}
	for(int i = 0; i < N;i ++){
		for(int j = 0; j < N; j++){
			cin >> mat[i][j];
		}
	}
	//bitmask dp
	for(int i = 0; i < 1<<N; i++){
		int next = __builtin_popcount(i)+1;
		for(int j = 0;j < N;j ++){
			//transition
			//if this bit is not toggled try it 
			if(!(i & 1 << j)){
				int score = mat[j][next-1];
				int b=0;
				for(pii x : bonuses[next]){
					if(dp[i] + score >= x.f){
						b += x.s;
					}
				}
				dp[i + (1 << j)] = max(dp[i+(1<<j)], dp[i]+score+b);
			}
		}
		//cout << i << " " << dp[i] << '\n';
	}
	cout << dp[(1 << N) - 1]<<'\n';


}
