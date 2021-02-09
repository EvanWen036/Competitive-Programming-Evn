#include "grader.h"
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
vector<int> adj[100005];
int depth[100005];
int stz[100005];
int anc[100005][25];
int xPos[100005];
int yPos[100005];
pii ranges[100005];
int N;
int timer = 0;
void dfs(int v, int p){
    stz[v] = 1;
    ranges[v].f = ++timer;
    for(int u : adj[v]){
        if(u == p)continue;
        depth[u]= depth[v]+1;
        anc[u][0] = v;
        dfs(u,v);
        stz[v] += stz[u];
    }
    ranges[v].s = timer;
}
void dfs2(int v, int p, int x1, int x2, int y){
    //cout << v << " " << p << " " << x1 << " " << x2 << " " << y << "\n";
    xPos[v] = x2;
    yPos[v] = y;
    //int currX = x-s
    int sum = 0;
    for(int u : adj[v]){
        if(u == p){
            continue;
        }
        dfs2(u, v, x1+sum, x1+sum+stz[u]-1, y-sum);
        sum += stz[u];
    }
}
void fillTable(){
    for(int i = 1; i < 25; i++){
        for(int j = 0; j < N; j++){
            int mid = anc[j][i-1];
            if(mid != -1){
                anc[j][i] = anc[mid][i-1];
            }
        }
    }
}
int walk(int i, int k){
    for(int d =0; d <= 24 && i != -1; d++){
        if(((1<<d) & k)){
            i = anc[i][d];
        }
    }
    return i;
}
int lca(int i, int j){
    if(depth[i] > depth[j]){
        i = walk(i, depth[i] - depth[j]);
    }
    if(depth[j] > depth[i]){
        j = walk(j, depth[j] -depth[i]);
    }
    //cout << i << " " << j << endl;
    if(i == j){
        return i;
    }
    for(int d= 24; d >= 0; d--){
        if(anc[i][d] != anc[j][d]){
            i = anc[i][d];
            j = anc[j][d];
        }
    }
    return anc[i][0];
}
int underLca(int i, int j){
    if(depth[i] > depth[j]){
        i = walk(i, depth[i] - depth[j]);
    }
    if(depth[j] > depth[i]){
        j = walk(j, depth[j] -depth[i]);
    }
    //cout << i << " " << j << endl;
    if(i == j){
        return i;
    }
    for(int d= 24; d >= 0; d--){
        if(anc[i][d] != anc[j][d]){
            i = anc[i][d];
            j = anc[j][d];
        }
    }
    return i;
    

}
void addRoad(int a, int b){
	// Fill in code here
    adj[a].pb(b);
    adj[b].pb(a);
}

void buildFarms(){
	//Fill in code here
    //root the tree and calculate lca
    N = getN();
    depth[0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 25; j++){
            anc[i][j] = -1;
        }
    }
    dfs(0,-1);
    fillTable();
    dfs2(0, -1, 1, N, N); 
    //call setFarmLocation for all N
    for(int i  =0; i < N; i++){
        //int x1, y1;
        setFarmLocation(i, xPos[i], yPos[i]);
    }
}

void notifyFJ(int a, int b){
	// Fill in code here
    int loca = lca(a,b);
    if(a == loca){
        //we only need one box
        addBox(xPos[b],yPos[b], xPos[loca], yPos[loca]);
    }
    else if(b == loca){
        addBox(xPos[a], yPos[a], xPos[loca], yPos[loca]);
    }
    else{
        int underLCA = underLca(a,b);
        //if(ranges[underLCA].f >= ranges[a].f && ranges[underLCA].f <= ranges[a].s){
        addBox(min(xPos[a],xPos[underLCA]),min(yPos[underLCA],yPos[a]), max(xPos[a],xPos[underLCA]),max(yPos[a], yPos[underLCA]));
        addBox(min(xPos[loca],xPos[b]), min(yPos[loca],yPos[b]), max(xPos[b],xPos[loca]), max(yPos[b],yPos[loca]));
    } 
        
}
/**
int main(){
    //int N;
    cin >> N;
    for(int i =0; i < N-1;i ++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        addRoad(a,b);
    }
    buildFarms();
    for(int i = 0; i < N; i++){
        cout << i << " " << xPos[i] << " " << yPos[i] << "\n";
    }
}
**/
