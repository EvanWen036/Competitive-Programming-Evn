#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll N;
    cin >> N;
    ll A[N];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    ll edgeWeight[N][N];
    for(int i = 0; i < N;i ++){
        for(int j = 0; j < N;j ++){
            edgeWeight[i][j] = -1*(A[i] ^ A[j]);
        }
    }
    ll mst[N];
    bool vis[N];
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < N; i++){mst[i] = 1000000000000;}
    mst[0] = 0;
    for(int i = 0; i < N-1; i++){
        ll min = 1000000000005;
        int min_index = 0;
        for(int v =0; v < N; v++){
            if(!vis[v] && mst[v] < min){
                min = mst[v];
                min_index = v;
            }
        }
        vis[min_index]=true;
        for(int v= 0; v < N; v++){
            if(!vis[v] && edgeWeight[min_index][v] < mst[v]){
                mst[v] = edgeWeight[min_index][v];
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += mst[i];
    }
    cout << ans * -1 << endl;
    


}

