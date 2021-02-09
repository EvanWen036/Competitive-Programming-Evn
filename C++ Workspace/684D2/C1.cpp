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
int mat[105][105];
int cnt = 0;
int zeroes [5] = {0, 2, 2, 0, 0};
int ones [5] = {0, 1, 1, 3, 3};
vector<vector<pii>> moves;
void go(int i, int j){
	int amt = 0;
	//cout << mat[i][j] << " " << mat[i+1][j] << " " << mat[i][j+1] << " " << mat[i+1][j+1] << endl;
	if(mat[i][j] == 1)amt++;
	if(mat[i+1][j] == 1)amt++;
	if(mat[i+1][j+1] == 1)amt++;
	if(mat[i][j+1] == 1)amt++;
	if(amt == 0){
		//cout << moves.size() << '\n';
		return;
	}
	//cout << amt << endl;
	int cnt0 = 0;
	int cnt1 = 0;
	cnt++;
	vector<pii> curr;
	for(int x = 0; x <= 1; x++){
		for(int y = 0; y <= 1; y++){
			if(cnt0 < zeroes[amt] && mat[i+x][j+y] == 0){
				cnt0++;
				curr.pb({i+x,j+y});
			}
			else if(cnt1 < ones[amt] && mat[i+x][j+y] == 1){
				cnt1++;
				curr.pb({i+x,j+y});
			}
		}
	}
	for(auto it : curr){
		mat[it.f][it.s] = (mat[it.f][it.s] == 0 ? 1:0);
	}
	moves.pb(curr);
	go(i,j);
}
void solve(){
	int n, m;
	cin >> n >> m;
	//cout << n << " " << m << " " << moves.size() << "\n";
	bool not1 = false;
	for(int i = 1; i <= n;i ++){
		string s;
		cin >> s;
		for(int j =1 ;j <= m;j ++){
			mat[i][j] = s[j-1] - '0';
			if(mat[i][j] == 0)not1 = true;
		}
	}
	if(!not1 && (n*m)%2 == 1){
		mat[1][1] = 0;
		mat[1][2] = 0;
		mat[1][3] = 0;
		mat[2][1] = 0;
		mat[2][2] = 0;
		mat[2][3] = 0;
		vector<pii> m1;
		m1.pb({1,1});
		m1.pb({1,2});
		m1.pb({2,1});
		moves.pb(m1);
		vector<pii> m2;
		m2.pb({2,2});
		m2.pb({2,3});
		m2.pb({1,3});
		moves.pb(m2);
	}
	for(int i = 1 ; i< n;i +=2){
		for(int j = 1; j< m;j += 2){
			go(i,j);
		}
		if(m % 2 == 1){
			go(i, m-1);
		}
	}
	if(n % 2 == 1){
		for(int j = 1; j < m; j+=2){
			go(n-1, j);
		}
		if(m % 2){
			go(n-1, m-1);
		}
	}
	assert(moves.size() <= n * m);
	cout << moves.size() << '\n';
	for(auto it : moves){
		assert(it.size() == 3);
		for(int i =0; i < 3; i++){
			cout << it[i].f << " " << it[i].s << " "; 
		}
		cout << '\n';
	}
	moves.clear();
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}


}
