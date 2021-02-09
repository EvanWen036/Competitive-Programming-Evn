#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int values[100005];
pii range[100005];
vector<int> graph[100005];
int BIT[100005];
void update(int ind, int val){
    for(int i = ind; i <= 100000;i += i &-i){
        BIT[i] += val;
    }
}
int query(int ind){
    int sum = 0;
    for(int i = ind; i >= 1; i-= i&-i){
        sum += BIT[i];
    }
    return sum;
}
int r= 0;
void dfs(int curr, int par){
    values[curr] = ++r;
    range[curr].f = r;
    for(int u : graph[curr]){
        if(u != par)dfs(u, curr);
    }
        range[curr].s = r;
}
int main(){
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
    cin >> N;
    pii p[N];
    for(int i = 0; i < N;i ++){
        int pi; cin >> pi;
        p[i] =mp(pi, i);
    }
    sort(p, p+N);
    for(int i = 1; i < N; i++){
        int x; cin >> x; x--;
        graph[x].pb(i);
    }
    dfs(0, -1);
    vector<int> ans(N);
    memset(BIT, 0, sizeof(BIT));
    for(int i = N-1; i >= 0; i--){
        ans[p[i].s] = query(range[p[i].s].s)-query(range[p[i].s].f);
        update(values[p[i].s], 1);
    }
    for(int i = 0; i < N;i ++){
        cout << ans[i] << endl;
    }

}

