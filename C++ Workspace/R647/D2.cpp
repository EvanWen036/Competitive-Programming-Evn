#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int t[5*100005];
vector<int> adj[5*100005];
int degree[100005];
struct cmp{
    
    bool compare(int const& u, int const& v){
         return t[u] < t[v];
    }
};
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
        degree[a]++;
        degree[b]++;
    }
    for(int i = 1; i <= n;i ++){
        cin >> t[i];
    }
    priority_queue<int, vector<int>, cmp> pq;
    for(int i= 1; i <= n; i++){
        if(degree[i] == 1){
            pq.push(i);
        }
    }
    
    

}

