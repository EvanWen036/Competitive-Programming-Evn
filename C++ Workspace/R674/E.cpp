#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
//#define int long long
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll pref[200005];
map<ll, ll> occ;
map<ll, ll> dist;
signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n+1);
    
    pref[0] = 0;
    dist[0] = 100000000;
    for(int i = 1; i <= n;i ++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
        occ[pref[i]] = 0;
        dist[i] = 100000000;
        //cout << pref[i] << "\n";
    }
    for(int i = 1; i <= n;i ++){
        if(occ[pref[i]] != 0 || pref[i] == 0){
            //this is a subarray with sum 0
            dist[i - occ[pref[i]]]++;
        }
        occ[pref[i]] = i;
    }
    ll curr = 0;
    ll ans = 0;
    for(map<ll,ll>::iterator it = dist.begin(); it != dist.end(); it++){
        //if(curr < n){
            if(it->second == 100000000 || curr > n)continue;
            curr += it->first * it ->second;
            ans += it->second;
        
    }
    cout << ans << "\n";
}

