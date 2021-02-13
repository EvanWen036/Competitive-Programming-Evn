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
#define int long long
int N, K;
int mat[405][405];
int newMat[2505][2505];
int pSum[2505][2505];
int32_t main(){
	freopen("lazy.in", "r", stdin);
	freopen("lazy.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N;j ++){
			cin >> mat[i][j];	
			//cout << mat[i][j] << " ";
		}
		//cout << '\n';
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1;j <= N;j ++){
			assert(i-j+500 >= 0);
			newMat[i-j + 500][i+j+500] = mat[i][j];
		}
	}
	for(int i = 1;i <= 2500; i++){
		for(int j = 1;j <= 2500;j ++){
			pSum[i][j] = newMat[i][j] + pSum[i-1][j] + pSum[i][j-1] - pSum[i-1][j-1];
		}
	}
	int ans = 0;
	int rectSize = (2*K+1);
	for(int i = 1;i + rectSize-1 <= 2500; i++){
		for(int j = 1;j + rectSize-1 <= 2500;j ++){
			int i2 = i + rectSize-1;
			int j2 = j + rectSize-1;

			ans = max(ans, pSum[i2][j2]-pSum[i-1][j2] - pSum[i2][j-1] + pSum[i-1][j-1]);
		}
	}
	cout << ans << '\n';
}
