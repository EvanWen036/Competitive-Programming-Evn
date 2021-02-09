#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> adj[N];
    int indegree[N];
    vector<int> adj2[N];
    int indegree2[N];
    vector<pii> edges(M);
    fill(indegree, indegree+N, 0);
    fill(indegree2, indegree2+N, 0);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj2[b].push_back(a);
        edges[i] = make_pair(a,b);
        indegree[b]++;
        indegree2[a]++;
    }
    queue<int> q;
    int ans1[N];
    fill(ans1, ans1+N, 0);
    for(int i = 0; i < N; i++){
        if(indegree[i] == 0){
            q.push(i);
            ans1[i] = 1;
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            ans1[v] += ans1[u];
            indegree[v]--;
            if(indegree[v] <= 0){
                q.push(v);
            }
        }
    }
    queue<int> q2;
    int ans2[N];
    fill(ans2, ans2+N, 0);
    for(int i = 0; i < N; i++){
        if(indegree2[i] == 0){
            q2.push(i);
            ans2[i] = 1;
        }
    }
    while(!q2.empty()){
        int u = q2.front(); q2.pop();
        for(int v: adj2[u]){
            ans2[v] += ans2[u];
            indegree2[v]--;
            if(indegree2[v] <= 0){
                q2.push(v);
            }
        }
    }
    int ans = 0;
    for(int i= 0; i < M; i++){
        ans = max(ans, ans1[edges[i].first] * ans2[edges[i].second]);
    }
    cout << ans << endl;

}

