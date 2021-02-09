#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
int dsu[505*505];
int size[505*505];
int starting[505*505];
int lb[505][505];
int ans = 0;
int T;
int find(int i){
    if(dsu[i] == i){
        return i;
    }
    return dsu[i] = find(dsu[i]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(size[v] > size[u]){
        swap(u,v);
    }
    //i, j is the bigger one
    dsu[v] = u;
    size[u] += size[v];
    starting[u] += starting[v];
}
int32_t main(){
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int M, N, T;
    cin >> M >> N >> T;
    int mat[M][N];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
    }
    bool isStart[M][N];
    for(int i = 0; i < M; i++){
        for(int j = 0;j < N;j ++){
            cin >>isStart[i][j];
        }
    }
    vector<pair<int, pii>> edges;
    int cnt = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j< N; j++){
            lb[i][j] = ++cnt;
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(i != 0){
                edges.pb({abs(mat[i][j] - mat[i-1][j]), {lb[i][j], lb[i-1][j]}});
            }
            if(j != 0){
                edges.pb({abs(mat[i][j] - mat[i][j-1]), {lb[i][j], lb[i][j-1]}});
            }
        }
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            dsu[lb[i][j]] = lb[i][j];
            size[lb[i][j]] = 1;
            starting[lb[i][j]] = isStart[i][j];
        }
    }
    sort(edges.begin(), edges.end());
    for(auto it : edges){
        int weight = it.f;
        int u = it.s.f;
        int v = it.s.s;
        //cout << weight << " " << u << " " << v << '\n';
        if(find(u) != find(v)){
            bool uL = false;
            bool vL = false;
            if(size[find(u)] < T){
                uL = true;
            }
            if(size[find(v)] < T){
                vL = true;
            }
            int s1 = starting[find(u)];
            int s2 = starting[find(v)];
            merge(u,v);
            if(size[find(u)] >= T){
                if(uL){
                    ans += weight * s1;
                }
                if(vL){
                    ans += weight * s2;
                }
            }
        }
        //cout << ans << '\n';
    }
    cout << ans << '\n';


}

