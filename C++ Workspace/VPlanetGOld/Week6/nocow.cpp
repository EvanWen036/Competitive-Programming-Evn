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
const int maxSz = 3005;
vector<string> possible[maxSz];
set<string> val[maxSz];
vector<string> bad[105];
int main(){
	freopen("nocow.in", "r", stdin);
	freopen("nocow.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;	
	int sz = 0;
	for(int i = 0; i < N;i ++){
		string a,b,c,d;
		//fj has no 
		cin >> a >> b >> c >> d;
		string next;
		cin >> next;
		int cnt = 0;
		while(next != "cow."){
			//cout << next << " ";
			val[cnt].insert(next);
			bad[i].pb(next);
			cin >> next;
			cnt++;
		}
		sz = cnt;
		//cout << '\n';
	}
	//sort 
	for(int i = 0; i < sz; i++){
		for(auto it : val[i]){
			possible[i].pb(it);
		}
		//cout << possible[i].size() << '\n';
	}
	vector<int> lT;
	int ovr = 1;
	for(int i = 0; i < N;i ++){
		int p = 0;
		int mult = 1;
		for(int j= sz-1;j >= 0; j--){
			int pos = find(begin(possible[j]), end(possible[j]), bad[i][j]) - possible[j].begin();
			//cout << pos << " ";
			p += pos * mult;
			mult *= possible[j].size();
		}
		ovr = mult;
		p++;
		lT.pb(p);
	}
	sort(lT.begin(), lT.end());
	for(int i = 0; i < lT.size(); i++){
		if(lT[i] <= K)K++;
	}
	//cout << K << '\n';
	vector<string> adj;
	for(int i = 0; i < sz; i++){
		ovr /= sz(possible[i]);
		//cout << ovr << '\n';
		int curr = (K-1)/ovr;
		adj.pb(possible[i][curr]);
		K %= ovr;
		if(K == 0)K = ovr;
	}
	for(int i = 0; i < sz;i ++){
		cout << adj[i] << (i == sz-1 ? "":" ");
	}
}
