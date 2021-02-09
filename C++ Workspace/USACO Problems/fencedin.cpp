#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int dsu[2000*2000+5];
int sz[2000*2000+5];
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
   //u is the bigger one
   dsu[v] = u;
   sz[u] += sz[v];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int A, B, n, m;
    cin >> A >> B >> n >> m;
    vector<int> vert;
    vector<int> horz;
    vert.push_back(0);
    horz.push_back(0);
    for(int i = 1; i <= n; i++){
        int x; 
        cin >> x; 
        vert.push_back(x);
    }
    for(int i = 1; i <= m; i++){
        int x; 
        cin >> x; 
        horz.push_back(x);

    }    
    ll ans = 0;
    vert.push_back(A); horz.push_back(B);
    sort(vert.begin(), vert.end());
    sort(horz.begin(), horz.end());
    vector<pair<pii, pii>> fields;
    map<pii, int> k;
    int x = 0;
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            k[make_pair(i,j)] = x;
            dsu[x] = x;
            sz[x] = 1;
            x++;
            fields.push_back(make_pair(make_pair(horz[i], horz[i+1]), make_pair(vert[j], vert[j+1])));
        }
    }
    vector<pair<ll, pair<int, int>>> edges;
    for(int i = 0; i <= n; i++){
        for(int j =0;j <= m; j++){
            pii curr = mp(i,j);
            int currK = k[curr];
            if(i != 0){
                //we can add an edge to the one above
                edges.push_back(make_pair(fields[currK].s.f, make_pair(currK, k[mp(i-1,j)])));
            }
            if(j != 0){
                edges.push_back(mp(fields[currK].f.f, mp(currK, k[mp(i,j-1)])));
            }
            if(i != n){
                edges.push_back(mp(fields[currK].s.s, mp(currK, k[mp(i+1,j)])));
            }
            if(j != m){
                edges.push_back(mp(fields[currK].f.s, mp(currK, k[mp(i,j+1)])));
            }

        }
    }
    sort(edges.begin(), edges.end());
    for(auto it : edges){
       cout << it.f << " " << it.s.f << " " << it.s.s << endl;
       if(find(it.s.f) != find(it.s.s)){
           merge(it.s.f, it.s.s);
           ans += it.f;
       }
    }
    cout << ans << endl;
}

