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
int mat[105][105];
int pref[105][105];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = N; i >= 1; i--){
		for(int j = 1;j <= N;j ++){
			cin >> mat[i][j];
		}
	}
	for(int i = 1; i <= N;i ++){
		for(int j = 1;j <= N;j ++){
			pref[i][j] = mat[i][j];
			pref[i][j] += pref[i-1][j];
			pref[i][j] += pref[i][j-1];
			pref[i][j] -= pref[i-1][j-1];
			//cout << pref[i][j] << " ";
		}
		//cout << '\n';
	}
	int ans = 0;
	for(int r1 = 1; r1 <= N; r1++){
		for(int c1 = 1; c1 <= N; c1++){
			for(int r2 = r1; r2 <= N; r2++){
				for(int c2 = c1; c2 <= N; c2++){
					int sum = pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1];
					//cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << sum << '\n';
					ans = max(ans, sum);
				}
			}
		}
	}
	cout << ans << '\n';

}
