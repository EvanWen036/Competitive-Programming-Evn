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
ll dist[205][205];
int main(){
	freopen("vacation.in", "r", stdin);
	freopen("vacation.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	for(int i = 1; i <= N;i ++){
		for(int j =1;j <= N;j ++){
			dist[i][j] = 1e15;
			if(i == j)dist[i][j] = 0;
		}
	}
	for(int i = 0; i < M;i ++){
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for(int k = 1;k <= N;k ++){
		for(int i = 1; i <= N;i ++){
			for(int j =1;j <= N;j ++){
				if(dist[i][k] != 1e15 && dist[k][j] != 1e15){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
	int good = 0;
	ll sum = 0;
	for(int i = 1; i <= Q; i++){
		int a, b;
		cin >> a >> b;
		ll ans = 1e18;
		for(int j = 1;j <= K;j ++){
			if(dist[a][j] != 1e15 && dist[j][b] != 1e15){
				ans = min(ans, dist[a][j] + dist[j][b]);
			}
		}
		if(ans == 1e18)continue;
		good++;
		sum += ans;
	}
	cout << good << '\n' << sum << '\n';


}
