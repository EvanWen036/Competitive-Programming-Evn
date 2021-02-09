#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N, M, T;
vector<int> adj[100005];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> T;
    for(int i = 0; i < M;i ++){
        int a, b,c ; cin >> a >> b >> c;
        a--; b--;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }


}

