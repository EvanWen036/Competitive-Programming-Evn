#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[5*10000 + 5];
int t[5*100005];
map<int,int> degree[5*100005];
multiset<int> val[5*100005];
bool print[5*100005];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m;i ++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);    
    }
    for(int i = 1; i <= n;i ++){
        cin >> t[i];
    }
    for(int i = 1; i <= n;i ++){

        for(auto it : adj[i]){
            degree[i][it]++;
            //degree[it][i]++;
            if(degree[i][it] != 1){
                val[i].erase(degree[i][it]-1);
            }
            val[i].insert(degree[i][it]);
            if(t[it] == t[i]){
                cout << -1 << "\n";
                return 0;
            }
        }
        if(t[i] > (int)adj[i].size()+1){
            cout << -1 << "\n";
            return 0;
        }
    }
    auto compare = [](int u, int v){ return t[u] > t[v];};
    priority_queue<int, vector<int>, decltype(compare)> q(compare);
    for(int i =1;  i <= n; i++){        
        //cout << "\n";
        if(val[i].size() == 0 || *(--val[i].end())< 2){
            print[i] = true;
            q.push(i);
        }
    }
    while(!q.empty()){
        int tp = q.top(); q.pop();
        print[tp] = true;
        cout << tp << " ";
        for(auto it : adj[tp]){
            val[it].erase(degree[it][t[tp]]);
            degree[it][t[tp]]--;
            if(degree[it][t[tp]] != 0){
                val[it].insert(degree[it][t[tp]]);
            }
            if(val[it].size() == 0 || *(--val[it].end()) < 2){
                if(print[it])continue;
                q.push(it);
            }
        }
    }
        
	


}

