#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    vector<pii> points;
    for(int i= 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        points.pb(mp(x,y));
    }
    sort(points.begin(), points.end());
    int ti = 0;
    for(int i = 0; i < n; i++){
        ti = max(ti, points[i].f);
        ti += points[i].s;
    }
    cout << ti << endl;


}

