#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1e9+7;
ll s(ll start, ll end){
    if(start == end)return start;
    start %= mod;
    end %= mod;
    ll pos1 = (end*(end+1))/2 % mod;
    ll pos2 = (start * (start-1))/2 % mod;
    ll ans = pos1 - pos2;
    if(ans < 0)ans += mod;
    return ans;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n;
    cin >> n;
    ll ans = 0;
    //ll mod = 1e9+7;
    for(ll i = 1; n/i >= (ll)(sqrt(n)); i++){
        ans += n/ i * i;
        ans %= mod;
    }
    //cout << ans << endl;
    for(ll i = (ll)(sqrt(n))-1; i >= 1; i--){
        ll top = n/i;
        ll bot = n/(i+1) + 1;
        //cout << bot << " " << top << endl;
        ans += (i * s(bot, top));
        ans %= mod;
        //cout << ans << endl;
    }
    cout << ans << endl;

}

