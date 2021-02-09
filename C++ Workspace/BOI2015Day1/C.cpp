#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<ll, ll> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
vector<int> adj[500005];
bool isLeaf[500005];
set<int> leafs[500005];
vector<pii> links;
int root = -1;
int N;
void dfs(int v, int p){
	//cout << v << endl;
	assert(v >= 0 && v < N);
	for(int u : adj[v]){
		if(u == p)continue;
		isLeaf[v] = false;
		dfs(u,v);
	}
	if(isLeaf[v]){
		//cout << v << '\n';
		leafs[v].insert(v);
	}
	vector<int> one;
	vector<int> two;
	map<int, int> imp;
	for(int u : adj[v]){
		if(u == p)continue;
		if(leafs[u].size() == 1)one.pb(u);
		if(leafs[u].size() == 2)two.pb(u);
		if(v == root){
			imp[u] = *leafs[u].begin();
		}
		assert(leafs[u].size() == 1 || leafs[u].size() == 2);
		for(int x : leafs[u]){
			leafs[v].insert(x);
		}
	}
	//cout << v << " " << leafs[v].size() << " " << (int)leafs[v].size()-2 << endl;
	//cout << v << " " << one.size() << " " << two.size() << "\n";
 	
	while((ll)leafs[v].size() - 2 >= 1LL){
		//cout << "hi\n";
		assert(leafs[v].size() == one.size() + 2 * two.size());
		if(!two.empty()){
			int tw = two[two.size()-1];
			two.pop_back();
			int o = -1;
			if(!two.empty()){
				o = two[two.size()-1];		
				two.pop_back();	
				one.push_back(o);
			}
			else{
				assert(!one.empty());
				o = one[one.size()-1];
				one.pop_back();
			}
 
			one.push_back(tw);
			assert(o != -1 && tw != o);
			//cout << tw << " " << o << '\n';
			//cout << *leafs[tw].begin() << " " << *leafs[o].begin() << '\n';
			//cout << *leafs[tw].begin() << " " << *(--leafs[tw].end()) << '\n';
			//link with back of one
			links.pb({*leafs[tw].begin(), *leafs[o].begin()});
			leafs[v].erase(*leafs[tw].begin());
			leafs[v].erase(*leafs[o].begin());
			leafs[tw].erase(*leafs[tw].begin());
			leafs[o].erase(*leafs[o].begin());
 
		}
		else{
			assert(one.size() >= 2);
			int ba = one[one.size()-1];
			one.pop_back();
			int ba2 = one[one.size()-1];
			one.pop_back();
			assert(ba != ba2);
			links.pb({*leafs[ba].begin(), *leafs[ba2].begin()});
			leafs[v].erase(*leafs[ba].begin());
			leafs[v].erase(*leafs[ba2].begin());
			leafs[ba].erase(*leafs[ba].begin());
			leafs[ba2].erase(*leafs[ba2].begin());
		}
	}
	if(v == root){
		//remove the final ones
		assert(p == -1);
		assert(leafs[v].size() == 1 || leafs[v].size() == 2 || leafs[v].size() == 0);
		if(leafs[v].size() == 0){
			assert(one.size() == 0 && two.size() == 0);
			return;
		}
		else if(leafs[v].size() == 2){
			assert(one.size() == 2 && two.size() == 0);
			assert(one[0] != one[1]);
			links.pb({*leafs[v].begin(), *(--leafs[v].end())});
		}
		else{
			//cout << *leafs[one[0]].begin() << '\n';
			assert(one.size() == 1 && two.size() == 0);
			for(int u : adj[v]){
				if(u != p && u != one[0]){
					//cout << u << '\n';
					//cout << *leafs[u].begin() << '\n'
					assert(imp[u] != *leafs[one[0]].begin());
					links.pb({imp[u], *leafs[one[0]].begin()});
					break;
				}
			}
		}
	}
}
int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for(int i =0;i < N-1; i++){
		int a, b;
		cin >> a >> b;
		isLeaf[i]=true;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	isLeaf[N-1]=true;
	for(int i = 0; i < N; i++){
		if(adj[i].size() > 1){
			root = i;
			isLeaf[root] = false;
			break;
		}
	}
	assert(root != -1);
	dfs(root, -1);
	int leafs = 0;
	for(int i = 0; i < N; i++){
		if(isLeaf[i])leafs++;
	}
	cout << links.size() << '\n';
	assert((ll)links.size() == (1LL * leafs+1)/2);
	for(int i = 0; i < (int)links.size(); i++){
		assert(links[i].f != links[i].s);
		assert(links[i].f >= 0 && links[i].f < N);
		assert(links[i].s >= 0 && links[i].s < N);
		cout << links[i].f + 1 << " " << links[i].s + 1 << '\n';
	}
}