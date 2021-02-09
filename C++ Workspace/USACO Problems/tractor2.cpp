#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
int dsu[505*505];
int k[505][505];
int size[505*505];
int count =  0;
int goal;
struct Edge{
    int a, b, weight;
    bool operator<(const Edge other){
        return weight < other.weight;
    }
};
int find(int u){
    if(dsu[u] == u)return u;
    return dsu[u] = find(dsu[u]);
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u ==v)return;
    if(size[v] > size[u])swap(u,v);
    dsu[v] = u;
    size[u] += size[v]; 
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N;
    int mat[N][N];
    int val = 0;
    for(int i = 0; i < N;i ++){
        for(int j = 0; j < N;j ++){
            k[i][j] = ++val;
            //cout << i << " " << j << " " << k[i][j] << endl;
            dsu[k[i][j]] = k[i][j];
            size[k[i][j]] = 1;
            cin >> mat[i][j];
        }
    }
    vector<Edge> edges;
    for(int i = 0; i < N-1; i++){
        for(int j = 0;j < N-1; j++){
               edges.push_back(Edge{k[i][j], k[i+1][j], abs(mat[i][j] - mat[i+1][j])});
               edges.push_back(Edge{k[i][j], k[i][j+1], abs(mat[i][j] - mat[i][j+1])});
            
        }
    }
    cout << edges.size() << endl;
    sort(edges.begin(), edges.end());
    goal = (N*N+1)/2;
    cout << goal << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0;j < N; j++){
            //cout << k[i][j] << " " << dsu[k[i][j]] << " " << size[k[i][j]] << endl;
        }
    }
    for(Edge e : edges){
        cout << e.a << " " << e.b << endl;
        merge(e.a,e.b);
        cout << max(size[e.a], size[e.b]) << endl;
        if(size[e.a] >= goal || size[e.b] >= goal){
            cout << e.weight << endl;
            break;
        }
    }

}


