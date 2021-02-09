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
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
char dir[4] = {'R','D','L','U'};
pii pre[1005][1005];
int mat[1005][1005];
bool vis[1005][1005];
int dist[1005][1005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	queue<pii> q;	
	int endR = 0;
	int endC = 0;
	int sR=0;
	int sC = 0;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < m; j++){
			if(s[j] == '#'){
				mat[i][j] = 1;
			}
			if(s[j] == 'A'){
				q.push({i,j});
				sR = i;
				sC = j;
				vis[i][j]=true;
				dist[i][j] = 0;
			}
			if(s[j] == 'B'){
				endR = i;
				endC = j;
			}
		}
	}
	//cout << sR << " " << sC << '\n';
	while(!q.empty()){
		pii top = q.front(); q.pop();
		if(top.f == endR && top.s == endC){
			cout << "YES\n";
			cout << dist[top.f][top.s] << '\n';
			int currR = endR; int currC = endC;
			string ans = "";
			while(currR != sR || currC != sC){
				
 				pii ne = pre[currR][currC];
				if(ne.f < currR){
					ans += "D";
				}
				if(ne.s < currC){
					ans += "R";
				}
				if(ne.f > currR){
					ans += "U";
				}
				if(ne.s > currC){
					ans += "L";
				}
				currR = ne.f;
				currC = ne.s;
				//cout << currR << " " << currC << '\n';
			}
			reverse(ans.begin(), end(ans));
			cout << ans << '\n';
			return 0;
		}
		for(int i = 0; i < 4; i++){
			int newR = top.f + dr[i];
			int newC = top.s + dc[i];
			if(newR < 0 || newR >= n || newC < 0 || newC >= m || vis[newR][newC] || mat[newR][newC])continue;
			vis[newR][newC] = true;
			dist[newR][newC] = dist[top.f][top.s] + 1;
			//cout << dir[i] << " " << top.s << " " << top.s + dir[i] << '\n';
			pre[newR][newC] = {top.f,top.s};
			q.push({newR,newC});
		}
	}
	cout << "NO\n";
}
