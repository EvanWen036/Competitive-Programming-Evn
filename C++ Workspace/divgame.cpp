#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n;
    cin >> n;
    //unordered_map<ll, int> count;
    //count.reserve(1024);
    vector<pair<ll, int>> factors;
    ll ans = 0;
    for(ll i = 2; i *i <= n; i++){
        int cnt = 0;
        while(n % i == 0){
            cnt++;
            //ans = max(ans, count[i]);
            //ans -= count[i]/2;
            //ans += (count[i]+1)/2;
            n/=i;
            //factors.pb(i);
        }
        factors.pb(mp(i, cnt));
    }
    if(n != 1){
        factors.pb(mp(n,1));
        //count[n]++;
        //ans += 1; 
    }
    for(auto it : factors){
        int times = it.s;
        //int times = count[it];
        int curr = 1;
        while(times - curr >= 0){
            times -= curr;
            curr++;
            ans++;
        }
    }
    cout << ans << endl;

}

