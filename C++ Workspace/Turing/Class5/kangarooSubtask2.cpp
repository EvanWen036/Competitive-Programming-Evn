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
int cnt = 0;
bool vis[2005];
int cf;
int n;
void dfs(int curr, int prev){
	//cout << curr << " " << prev << '\n';
	if(curr == cf){
		for(int i = 1;i <= n; i++){
			if(!vis[i])return;
		}
		cnt++;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			if(prev == -1){
				vis[i] = true;
				dfs(i, curr);
				vis[i] = false;
			}
			else if(prev < curr && i < curr){
				vis[i] = true;
				dfs(i, curr);
				vis[i] = false;
			}
			else if(prev > curr && i > curr){
				vis[i] = true;
				dfs(i, curr);
				vis[i] = false;
			}
		}
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cs;
	cin >> n >> cs >> cf;
	vis[cs]=true;
	dfs(cs, -1);
	cout << cnt << '\n';

}
