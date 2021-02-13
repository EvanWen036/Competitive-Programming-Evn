// the constraints hint that a O(n^2logn) approach works
// consider all shortest paths starting at some node i
// run dijkstra from each node
// now we consider for each edge, whether or not it is feasible or not to keep that edge
// you can keep an edge connecting node u, v, with weight w, if dist[v] = dist[u] + w
// this edge is directed, so this means that if (u, v) is kept, (v, u) won't be kept
// we notice that the directed edges that are kept form a DAG
// now for each node j, we can do a simple dp to calculate how many ways there are to reach node j from i (let's call this to[j]), 
// and how many ways are there to reach another node k from j (let's call this from[j])
// this DP can be calculated in O(n)
// then for each directed edge connecting u, v, the contribution can be calculated as to[u] * from[v]
// repeat this process for each node i from 1 -> n
// final complexity O(n * nlogn)
 
 
/*
ID: varunra2
LANG: C++
TASK: roadhelp
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "lib/debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define debug_arr(...) \
  cerr << "[" << #__VA_ARGS__ << "]:", debug_arr(__VA_ARGS__)
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC diagnostic ignored "-Wunused-parameter"
//#pragma GCC diagnostic ignored "-Wunused-variable"
#else
#define debug(...) 42
#endif
 
#define int long long
 
#define EPS 1e-9
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define x first
#define y second
 
const double PI = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;
 
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
#pragma GCC diagnostic ignored "-Wsign-compare"
// util functions
 
int n, m;
vector<VII> adj;
 
VII edgs;
VI ret;
vector<MPII> which;
 
VVI dag;
VVI rdag;
VI from;
VI to;
VI dists;
 
void init() {
  adj.resize(n);
  edgs.resize(m);
  ret.resize(m);
  which.resize(n);
}
 
void init_solve() {
  dag.clear();
  dag.resize(n);
  rdag.clear();
  rdag.resize(n);
  to.assign(n, 0);
  from.assign(n, 0);
  dists.assign(n, INF);
}
 
void dijk(int src) {
  vector<bool> vis(n, false);
  priority_queue<PII, VII, greater<PII>> pq;
  pq.push(MP(0, src));
  dists[src] = 0;
  while (!pq.empty()) {
    auto x = pq.top();
    pq.pop();
    int u = x.y;
    if (vis[u]) continue;
    vis[u] = true;
    for (auto& xx : adj[u]) {
      if (vis[xx.x]) continue;
      if (dists[xx.x] > dists[u] + xx.y) {
        dists[xx.x] = dists[u] + xx.y;
        pq.push(MP(dists[xx.x], xx.x));
      }
    }
  }
}
 
void gen_dag() {
  for (int u = 0; u < n; u++) {
    for (auto& x : adj[u]) {
      int v = x.x;
      int w = x.y;
      if (dists[u] + w == dists[v]) {
        dag[u].PB(v);
        rdag[v].PB(u);
      }
    }
  }
}
 
int dfs_to(int u, vector<bool>& vis) {
  if (vis[u]) return to[u];
  vis[u] = true;
  for (auto& x : rdag[u]) {
    to[u] += dfs_to(x, vis);
  }
  to[u] %= MOD;
  return to[u];
}
 
int dfs_from(int u, vector<bool>& vis) {
  if (vis[u]) return from[u];
  vis[u] = true;
  from[u] = 1;
  for (auto& x : dag[u]) {
    from[u] += dfs_from(x, vis);
  }
  from[u] %= MOD;
  return from[u];
}
 
void gen_to(int src) {
  to[src] = 1;
  vector<bool> vis(n, false);
  vis[src] = true;
  for (int i = 0; i < n; i++) {
    dfs_to(i, vis);
  }
}
 
void gen_from(int src) {
  vector<bool> vis(n, false);
  for (int i = 0; i < n; i++) {
    dfs_from(i, vis);
  }
}
 
void combine() {
  for (int u = 0; u < n; u++) {
    for (auto& x : dag[u]) {
      int cnt = (to[u] * from[x]) % MOD;
      int ind = which[u][x];
      // debug(ind, cnt);
      ret[ind] += cnt;
      ret[ind] %= MOD;
    }
  }
}
 
void solve(int src) {
  init_solve();
  dijk(src);
  gen_dag();
  gen_to(src);
  gen_from(src);
  // debug(to);
  combine();
}
 
int32_t main() {
#ifndef ONLINE_JUDGE
  freopen("roadhelp.in", "r", stdin);
  freopen("roadhelpC.out", "w", stdout);
#endif
  cin.sync_with_stdio(0);
  cin.tie(0);
 
  cin >> n >> m;
 
  init();
 
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].PB(MP(v, w));
    adj[v].PB(MP(u, w));
    edgs[i] = MP(u, v);
    ret[i] = 0;
    which[u][v] = i;
    which[v][u] = i;
  }
 
  // debug("here");
 
  for (int i = 0; i < n; i++) {
    solve(i);
  }
 
  // debug("here");
 
  for (int i = 0; i < m; i++) {
    cout << ret[i] << '\n';
  }
 
  return 0;
}