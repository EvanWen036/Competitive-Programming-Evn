#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
void solve(){
    ll n;
    cin >> n;

    ll ans = 0;
    for(ll i = 1; i <= n; i *= 2){
        ans += n/i;
    }
    cout << ans << "\n";
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

