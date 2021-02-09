#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
vector<int> adj[100005];
int indegree[100005];
bool push[100005];
int main()
{
  int N, m;
  cin >> N >> m;
  memset(indegree, 0, sizeof(indegree));
  set<pair<int,int>> edge;
  for(int i = 0; i< m; i++){
    int a, b;
    cin >> a >> b;
    if(edge.count(mp(a,b)) != 0)continue;
    edge.insert(mp(a,b));
    adj[a].push_back(b);
    indegree[b]++;
  }
  priority_queue<int> pq;
  for(int i = 1; i <= N;i ++){
      if(indegree[i] == 0)pq.push(-1 * i);
  }
  while(!pq.empty()){
    int v = pq.top(); v*=-1;
    pq.pop();
    cout << v << " ";
    for(int u : adj[v]){
        //if(v==4)cout << u << endl;
        indegree[u]--;
        if(indegree[u] == 0)pq.push(-1 * u);
    }
  }
  cout << "\n";
}
