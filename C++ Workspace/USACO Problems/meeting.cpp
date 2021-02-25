#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){
	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> adj[N];
    for(int i = 0; i < M; i++){
        int a, b, c ,d;
        cin >> a >> b >> c >> d;
        a--; b--;
        adj[a].pb(mp(b, mp(c,d)));
    }
    bool bessie[N][100*100+5];
    bool elsie[N][100*100+5];
    for(int i = 0; i < N; i++){
        for(int j= 0; j <= 100 * 100; j++){
            bessie[i][j] = false;
            elsie[i][j] = false;
        }
    }
    bessie[0][0] = true;
    elsie[0][0] = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 100*100; j++){
            if(bessie[i][j]){
                for(auto it : adj[i]){
                    bessie[it.f][it.s.f + j] = true;
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 100 * 100; j++){
            if(elsie[i][j]){
                for(auto it : adj[i]){
                    elsie[it.f][it.s.s + j] = true;
                }
            }
        }
    }

    for(int i = 0; i <= 100 * 100; i++){
        if(bessie[N-1][i] && elsie[N-1][i]){
            cout << i << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;

}

