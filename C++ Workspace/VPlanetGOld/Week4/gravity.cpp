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
int mat[505][505];
int r1, c1 = 0;
int r2, c2 = 0;
bool vis[505][505][2];
int yDir[2] = {1, -1};
//int dist[505][505][2];
int main(){
	freopen("gravity.in", "r", stdin);
	freopen("gravity.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	for(int i = 0; i < N;i ++){
		string s;
		cin >> s;
		for(int j = 0; j < M;j ++){
			if(s[j] == '#'){
				mat[i][j] = 1;
			}
			else if(s[j] == 'D'){
				mat[i][j] = 2;
			}
			else{
				mat[i][j] = 0;
			}
			if(s[j] == 'C'){
				r1 = i;
				c1 = j;
			}
			if(s[j] == 'D'){
				r2 = i;
				c2 = j;
			}
		}
	}
	bool chill = false;
	for(int i = r1; i < N; i++){
		if(mat[i][c1] == 1){
			chill = true;
			r1 = i-1;
			break;
		}
	}
	if(!chill){
		cout << -1 << '\n';
		return 0;
	}
	//cout << r1 << " " << c1 << '\n';
	int ans = 1e9;
	priority_queue<pair<int, pair<pii,int>>, vector<pair<int, pair<pii,int>>>, greater<pair<int, pair<pii,int>>>> pq;
	pq.push({0,{{r1,c1},0}});
	while(!pq.empty()){
		pair<int, pair<pii, int>> curr = pq.top(); pq.pop();
		if(vis[curr.s.f.f][curr.s.f.s][curr.s.s])continue;
		vis[curr.s.f.f][curr.s.f.s][curr.s.s] = true;
		//cerr << curr.f << " " << curr.s.f.f << " " << curr.s.f.s << " " << curr.s.s << '\n';
		if(curr.s.f.f == r2 && curr.s.f.s == c2){
			assert(mat[curr.s.f.f][curr.s.f.s] == 2);
			cout << curr.f << '\n';
			return 0;
		}
		assert(mat[curr.s.f.f][curr.s.f.s] != 1);
		//move to right
		if(curr.s.f.s != M-1){
			int newR = curr.s.f.f;
			int dR = yDir[curr.s.s];
			while(newR +dR >= 0 && newR + dR < N && mat[newR][curr.s.f.s+1] != 1 && mat[newR+dR][curr.s.f.s+1] != 1){
				if(mat[newR][curr.s.f.s+1] == 2){
					pq.push({curr.f, {{newR, curr.s.f.s+1}, curr.s.s}});
				}
				newR += dR;
			}
			//falls through
			//cerr << newR << " " << curr.s.f.s+1 << '\n';
			if(mat[newR][curr.s.f.s+1] == 2){
				pq.push({curr.f, {{newR, curr.s.f.s+1}, curr.s.s}});
			}
			if(newR + dR >= 0 && newR + dR < N && mat[newR][curr.s.f.s+1] != 1 && !vis[newR][curr.s.f.s+1][curr.s.s]){
				pq.push({curr.f, {{newR, curr.s.f.s+1}, curr.s.s}});
			}
		}
		//move to left
		if(curr.s.f.s != 0){
			int newR = curr.s.f.f;
			int dR = yDir[curr.s.s];
			while(newR +dR >= 0 && newR + dR < N && mat[newR][curr.s.f.s-1] != 1 &&  mat[newR+dR][curr.s.f.s-1] != 1){
				if(mat[newR][curr.s.f.s-1] == 2){
					pq.push({curr.f, {{newR, curr.s.f.s-1}, curr.s.s}});

				}
				newR += dR;
			}
			if(mat[newR][curr.s.f.s-1] == 2){
				pq.push({curr.f, {{newR, curr.s.f.s-1}, curr.s.s}});
			}
			//falls through
			if(newR + dR >= 0 && newR + dR < N && mat[newR][curr.s.f.s-1] != 1 && !vis[newR][curr.s.f.s-1][curr.s.s]){
				pq.push({curr.f, {{newR, curr.s.f.s-1}, curr.s.s}});
			}
		}
		//switch up gravity
		int newDr = (curr.s.s+1)%2;
		int dR = yDir[newDr];
		int newR = curr.s.f.f;

		while(newR + dR >= 0 && newR + dR < N && mat[newR][curr.s.f.s] != 1 && mat[newR+dR][curr.s.f.s] != 1){
			if(mat[newR][curr.s.f.s] == 2){
				//assert(false);
				pq.push({curr.f+1, {{newR, curr.s.f.s}, newDr}});
			}	
			newR += dR;
		}
		//cerr << newR << " " << curr.s.f.s << '\n';
		//fall through if switch
		if(mat[newR][curr.s.f.s] == 2){
			pq.push({curr.f+1, {{newR, curr.s.f.s}, newDr}});
		}
		if(newR + dR >= 0 && newR + dR < N && !vis[newR][curr.s.f.s][newDr]){
			//assert(mat[newR][curr.s.f.s] != 1);
			pq.push({curr.f+1, {{newR, curr.s.f.s}, newDr}});
		}
	}
	cout << -1  << '\n';
}
