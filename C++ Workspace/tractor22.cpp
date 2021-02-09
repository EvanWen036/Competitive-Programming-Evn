#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
pii dsu[505][505];
int sz[505][505];
vector<pair<int, pair< pii, pii > > > edges;
pii find(pii p){
    if(dsu[p.first][p.second] == p){
        return dsu[p.first][p.second];
    }
    return dsu[p.first][p.second] = find(dsu[p.first][p.second]);
}
void merge(pii u, pii v){
    u = find(u);
    v = find(v);
    if(u == v)return;
    if(sz[v.first][v.second] > sz[u.first][u.second])swap(u,v);
    //u is the bigger one
    dsu[v.first][v.second] = u;
    sz[u.first][u.second] += sz[v.first][v.second];
}
int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int N;
    cin >> N;
    int mat[N][N];
    for(int i= 0; i < N;i ++){
        for(int j = 0; j < N;j ++){
            cin >> mat[i][j];
            dsu[i][j] = make_pair(i,j);
            sz[i][j] = 1;
        }
    }
    for(int i = 0;i <  N-1;i ++){
        for(int j = 0;j  < N-1; j++){
            edges.push_back(make_pair(abs(mat[i][j] - mat[i+1][j]), make_pair(make_pair(i, j), make_pair(i+1,j))));
            edges.push_back(make_pair(abs(mat[i][j] - mat[i][j+1]), make_pair(make_pair(i,j), make_pair(i,j+1))));
        }
    }
    sort(edges.begin(), edges.end());
    int goal = (N*N+1)/2;
    for(int i = 0; i < edges.size(); i++){
        merge(edges[i].second.first, edges[i].second.second);
        cout << sz[edges[i].second.first.first][edges[i].second.first.second] << " " << sz[edges[i].second.second.first][edges[i].second.second.second] << endl;

        if(sz[edges[i].second.first.first][edges[i].second.first.second] >= goal || sz[edges[i].second.second.first][edges[i].second.second.second] >= goal){
            cout << edges[i].first << endl;
        }
    }

}

