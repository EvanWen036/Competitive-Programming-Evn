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
int n, m;
int mat[1005][1005];
int r[1005][1005];
void dfs(int i, int j){
	if(i >= n || i < 0 || j >= m || j < 0 || mat[i][j] == 0 || r[i][j] != -1)return;
	r[i][j] = 1;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n;i ++){
		string s;
		cin >> s;
		for(int j = 0;j < m; j++){
			mat[i][j] = s[j]=='.' ? 1:0;
		}
	}
	int ans = 0;
	memset(r, -1, sizeof(r));
	for(int i = 0; i < n; i++){
		for(int j = 0;j < m; j++){
			if(mat[i][j] == 1 && r[i][j] != 1){
				ans++;
				dfs(i,j);
			}
		}
	}
	cout << ans << '\n';


}
