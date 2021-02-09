#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N, M;
bool special[100005];
int dsu[100005];
int sz[100005];
int amt[100005];
int find(int u){
    if(dsu[u] == u){
        return u;
    }
    return dsu[u] = find(dsu[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)return;
    if(sz[v] > sz[u])swap(u,v);
    //u is the bigger one merge v into u
    dsu[v] = u;
    amt[u] += amt[v];
    sz[v] += sz[u];
}
int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> M;
    vector<int> a(N+1);
    int cnt = 0;
    for(int i=  1; i <= N; i++){
        cin >> a[i];
        if(a[i] != i){
            special[i] = true;
            cnt++;
        }
    }
    vector<pair<int,pii>> edges;
    for(int i = 0; i < M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb(mp(w,mp(a,b)));
    }
    sort(edges.begin(), edges.end(), greater<pair<int,pii>>());
    if(cnt == 0){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= N; i++){
        dsu[i] = i;
        if(special[i]){
            //cout << i << endl;
            amt[i] = 1;
        }
        sz[i] = 1;
    }
    //cout << cnt << endl;
    for(int i = 0; i < M; i++){
        //cout << edges[i].f  << endl;
        merge(edges[i].s.f, edges[i].s.s);
        edges[i].s.f = find(edges[i].s.f);
        edges[i].s.s = find(edges[i].s.s);
        //cout << edges[i].s.f << " " << amt[edges[i].s.f] << " " << edges[i].s.s << " " << amt[edges[i].s.s] << endl;
        if(amt[edges[i].s.f] >= cnt || amt[edges[i].s.s] >= cnt){
            cout << edges[i].f;
            return 0;
        }
    }


}

