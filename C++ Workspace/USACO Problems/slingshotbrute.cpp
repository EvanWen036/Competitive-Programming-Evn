#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    freopen("slingshot.in", "r", stdin);
    freopen("slingshot.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<pair<pair<ll, ll>, ll>> sling(N);
    vector<pair<long, long>> manure(M);
    for(int i = 0; i < N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        sling[i] = mp(mp(a,b),c);
    }
    for(int i =0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        manure[i] = mp(a,b);
    }
    for(int i =0; i < M; i++){
        ll ans = 10000000000000000;
        ll st = manure[i].f;
        ll en = manure[i].s;
        for(int j=0; j < N; j++){
            ll st2 = sling[j].f.f;
            ll en2 = sling[j].f.s;
            ans = min(ans, abs(st2 - st) + abs(en2 - en) + sling[j].s);
            ans = min(abs(en - st), ans);
        }
        cout << ans << "\n";
    }


}

