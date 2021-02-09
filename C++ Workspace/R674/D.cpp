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
    int ans = 0;
    set<ll> curr;
    curr.insert(0);
    ll sum = 0;
    for(int i =0;i < n;i ++){
        ll next;
        cin >> next;
        sum += next;
        if(curr.count(sum)){
            ans++;
            curr.clear();
            curr.insert(0);
            sum = next; 
        }
        curr.insert(sum);
    }
    cout << ans << "\n";
}
