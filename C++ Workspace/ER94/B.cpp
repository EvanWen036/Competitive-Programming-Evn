#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int p, f;
int cnts, cntw;
int s, w;

void solve(){
    cin >> p >> f;
    cin >> cnts >> cntw;
    cin >> s >> w;
    int ans = 0;
    
    if(s > w){
        swap(s,w);
        swap(cnts,cntw);
    }
    /**
    if(f > p)swap(f, p);
    //s is the cheaper one
    //p is bigger
    while(p - (s+w) >= 0 && cnts > 0 && cntw > 0){
        p -= s+w;
        //f -= s+w;
        cnts--;
        cntw--;
        ans += 2;
    }
    while(f - (s+w) >= 0 && cnts > 0 && cntw > 0){
        f -= s+w;
        cnts--;
        cntw--;
        ans += 2;
    }
    while(p - s >= 0 && cnts > 0){
        cnts--;
        p -= s;
        ans ++;
    }
    while(f - s >= 0 && cnts > 0){
        cnts--;
        f -= s;
        ans ++;
    }
    while(p - w >= 0 && cntw > 0){
        cntw--;
        p -= w;
        ans++;
    }
    while(f - w >= 0 && cntw > 0){
        cntw--;
        f  -= w;
        ans++;
    }**/
    int combo = p + f;
    int og = cntw;
    while(combo - s >= 0 && cnts){
        cnts--;
        ans++;
        combo -= s;
    }
    while(combo - w >= 0 && cntw){
        cntw--;
        ans++;
        combo -= w;
    }
    if(cntw == og && combo == 0 && p % s + f % s >= s){
        ans--;
    }
    //int remainder = p + f;
    //cout << remainder << " " << cntw << endl;
    cout << ans << endl;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }


}

