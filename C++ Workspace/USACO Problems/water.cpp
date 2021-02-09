#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool operator<(const pair<int, int>&p1, const pair<int, int>& p2){
    return p1.first < p2.first;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
    cin >> N;
    int cost[N];
    int minVal = 100000000;
    int start = -1;
    for(int i = 0 ; i < N; i++){
        cin >> cost[i];
        if(cost[i] < minVal){
            start = i;
            minVal = cost[i];
        }
    }
    int edgeweight[N][N];
    for(int i = 0; i < N; i ++){
        for(int j =0; j < N; j++){
            cin >> edgeweight[i][j];
            edgeweight[i][j] = min(edgeweight[i][j], cost[j]);
            //cout << edgeweight[i][j] << " ";
        }
        //cout << endl;
    }
    int dist[N];
    for(int i = 0; i < N; i++){
        dist[i] = 1000000000;
    }
    bool vis[N];
    memset(vis, false, sizeof(vis));
    dist[start] = minVal;
    priority_queue<pair<int, int>, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(minVal,start));
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        //cout << u << endl;
        vis[u] = true;
        for(int i = 0; i < N; i++){
            //cout << i << " " << dist[i] << " " << edgeweight[u][i] << endl;
            if(!vis[i] && dist[i] > edgeweight[u][i]){

                dist[i] = edgeweight[u][i];
                pq.push(make_pair(dist[i], i));
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += dist[i];
    }
    cout << ans << endl;


}

